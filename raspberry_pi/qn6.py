#raspberry qn 6
import RPi.GPIO as GPIO
import time

# GPIO pins for raindrop sensor and buzzer
RAIN_PIN = 18
BUZZER_PIN = 23

def setup():
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(RAIN_PIN, GPIO.IN)
    GPIO.setup(BUZZER_PIN, GPIO.OUT)
    GPIO.output(BUZZER_PIN, GPIO.LOW)

def main():
    try:
        setup()
        while True:
            if GPIO.input(RAIN_PIN) == GPIO.HIGH:  # Raindrop detected
                print("Raindrop detected: Buzzing the buzzer")
                GPIO.output(BUZZER_PIN, GPIO.HIGH)
                time.sleep(0.1)  # Buzz for 0.1 seconds
                GPIO.output(BUZZER_PIN, GPIO.LOW)
            
            time.sleep(0.1)  # Wait for 0.1 seconds before next check
    except KeyboardInterrupt:
        GPIO.cleanup()

if __name__ == "__main__":
    main()
