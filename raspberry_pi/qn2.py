#raspberry qn 2
import RPi.GPIO as GPIO
import time

# Light sensor and LED pins
LDR_PIN = 18
LED_PIN = 17

# Threshold light intensity value
THRESHOLD = 1000  # You may need to adjust this value based on your environment

def setup():
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(LDR_PIN, GPIO.IN)
    GPIO.setup(LED_PIN, GPIO.OUT)
    GPIO.output(LED_PIN, GPIO.LOW)

def get_light_intensity():
    # Read LDR value
    ldr_value = GPIO.input(LDR_PIN)
    return ldr_value

def main():
    try:
        setup()
        while True:
            light_intensity = get_light_intensity()
            print(f"Light Intensity: {light_intensity}")

            if light_intensity < THRESHOLD:
                GPIO.output(LED_PIN, GPIO.HIGH)
                print("High-intensity LED turned ON")
            else:
                GPIO.output(LED_PIN, GPIO.LOW)
                print("High-intensity LED turned OFF")

            time.sleep(1)
    except KeyboardInterrupt:
        GPIO.cleanup()

if __name__ == "__main__":
    main()
