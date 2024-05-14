#include <reg51.h>

#define UART_BAUD_RATE 9600
#define TIMER_RELOAD_VALUE 0xFFFF - 60000 // Timer reload value for 5ms delay (assuming 12MHz crystal)

// Function prototypes
void init_uart();
void init_timer();
unsigned char calculate_checksum(unsigned char *d, unsigned char length);
void send_byte_uart(unsigned char byte);
void send_string_uart(unsigned char *str);
void receive_payload(unsigned char *payload);

void main() {
    unsigned char payload[3];
    unsigned char checksum;

    init_uart();
    init_timer();

    while (1) {
        receive_payload(payload);
        checksum = calculate_checksum(payload, 3);

        // Transmit payload and checksum over UART
        send_string_uart("Payload: ");
        send_byte_uart(payload[0]);
        send_byte_uart(payload[1]);
        send_byte_uart(payload[2]);
        send_string_uart(", Checksum: ");
        send_byte_uart(checksum);
        send_string_uart("\r\n");
    }
}

void init_uart() {
    TMOD |= 0x20;       // Timer 1, mode 2 (8-bit auto-reload)
    TH1 = 256 - (unsigned char)(65536 - (int)(12000000UL / (12UL * UART_BAUD_RATE))); // Set baud rate
    TR1 = 1;            // Start Timer1
    TI = 0;             // Clear transmit interrupt flag
    SCON = 0x50;        // Mode 1, 8-bit UART, enable receiver
}

void init_timer() {
    TMOD |= 0x01;       // Timer 0, mode 1 (16-bit timer)
    TH0 = TIMER_RELOAD_VALUE >> 8;
    TL0 = TIMER_RELOAD_VALUE & 0xFF;
    TR0 = 1;            // Start Timer0
}

unsigned char calculate_checksum(unsigned char *d, unsigned char length) {
    unsigned char checksum = 0;
    while (length--) {
        checksum += *d++;
    }
    return checksum;
}

void send_byte_uart(unsigned char byte) {
    SBUF = byte;        // Load byte to be transmitted
    while (!TI);        // Wait for transmit interrupt flag
    TI = 0;             // Clear transmit interrupt flag
}

void send_string_uart(unsigned char *str) {
    while (*str) {
        send_byte_uart(*str++);
    }
}

void receive_payload(unsigned char *payload) {
    unsigned char i;
    for (i = 0; i < 3; i++) {
        // Wait for 5ms to receive each segment of payload
        while (!TF0);    // Wait for Timer0 overflow (5ms delay)
        TF0 = 0;         // Clear Timer0 overflow flag
        payload[i] = P1; // Read payload segment from port P1
    }
}
