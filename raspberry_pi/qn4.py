#raspberry qn 4
import RPi.GPIO as GPIO
import time

# GPIO pins for IR sensor, push button, and LED
IR_PIN = 18
BUTTON_PIN = 23
LED_PIN = 17

def setup():
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(IR_PIN, GPIO.IN)
    GPIO.setup(BUTTON_PIN, GPIO.IN)
    GPIO.setup(LED_PIN, GPIO.OUT)
    GPIO.output(LED_PIN, GPIO.LOW)

def main():
    try:
        setup()
        while True:
            ir_state = GPIO.input(IR_PIN)
            button_state = GPIO.input(BUTTON_PIN)
            
            # Check if IR sensor is triggered or button is pressed
            if ir_state == GPIO.HIGH or button_state == GPIO.HIGH:
                print("IR sensor triggered or button pressed: Turning LED ON")
                GPIO.output(LED_PIN, GPIO.HIGH)
            else:
                print("IR sensor not triggered and button not pressed: Turning LED OFF")
                GPIO.output(LED_PIN, GPIO.LOW)

            time.sleep(0.1)
    except KeyboardInterrupt:
        GPIO.cleanup()

if __name__ == "__main__":
    main()
