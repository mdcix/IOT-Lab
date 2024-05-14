#raspberry qn 3
import RPi.GPIO as GPIO
import time

# GPIO pins for push button and LED
BUTTON_PIN = 18
LED_PIN = 17

def setup():
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(BUTTON_PIN, GPIO.IN)
    GPIO.setup(LED_PIN, GPIO.OUT)
    GPIO.output(LED_PIN, GPIO.LOW)

def main():
    try:
        setup()
        while True:
            button_state = GPIO.input(BUTTON_PIN)
            
            # Check if button is pressed or sensor detected
            if button_state == GPIO.HIGH:  # Button pressed or sensor detected
                print("Button pressed or sensor detected: Turning LED ON")
                GPIO.output(LED_PIN, GPIO.HIGH)
            else:  # Button released or sensor not detected
                print("Button released or sensor not detected: Turning LED OFF")
                GPIO.output(LED_PIN, GPIO.LOW)

            time.sleep(0.1)
    except KeyboardInterrupt:
        GPIO.cleanup()

if __name__ == "__main__":
    main()
