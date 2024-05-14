#Raspberry qn 1
import RPi.GPIO as GPIO
import time

# Ultrasonic sensor pins
TRIG_PIN = 23
ECHO_PIN = 24

def setup():
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(TRIG_PIN, GPIO.OUT)
    GPIO.setup(ECHO_PIN, GPIO.IN)

def get_distance():
    # Trigger pulse
    GPIO.output(TRIG_PIN, GPIO.HIGH)
    time.sleep(0.00001)
    GPIO.output(TRIG_PIN, GPIO.LOW)

    # Measure the time for sound to return
    while GPIO.input(ECHO_PIN) == GPIO.LOW:
        pulse_start = time.time()
    while GPIO.input(ECHO_PIN) == GPIO.HIGH:
        pulse_end = time.time()

    # Calculate distance
    pulse_duration = pulse_end - pulse_start
    distance = pulse_duration * 17150  # Speed of sound is approximately 343 m/s
    distance = round(distance, 2)
    
    return distance

def main():
    try:
        setup()
        while True:
            distance = get_distance()
            print(f"Distance to object: {distance} cm")
            time.sleep(1)
    except KeyboardInterrupt:
        GPIO.cleanup()

if __name__ == "__main__":
    main()
