#raspberry qn 5
import Adafruit_DHT
import time

# DHT11 sensor connected to GPIO 4
DHT_SENSOR = Adafruit_DHT.DHT11
DHT_PIN = 4

def main():
    try:
        while True:
            # Try to grab a sensor reading
            humidity, temperature = Adafruit_DHT.read_retry(DHT_SENSOR, DHT_PIN)

            # If successful, print temperature and humidity
            if humidity is not None and temperature is not None:
                print(f"Temperature: {temperature:.1f}°C, Humidity: {humidity:.1f}%")
            else:
                print("Failed to retrieve data from DHT11 sensor")

            time.sleep(2)  # Wait for 2 seconds before the next reading
    except KeyboardInterrupt:
        print("Program terminated by user")
    finally:
        print("Exiting...")

if __name__ == "__main__":
    main()
