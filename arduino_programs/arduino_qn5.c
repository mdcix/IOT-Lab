//Arduino_qn_5

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

float temperature;
float humidity;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {

    temperature = dht.readTemperature();  // Read temperature as Celsius
    humidity = dht.readHumidity();  // Read humidity

    if (isnan(temperature) || isnan(humidity)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
    Serial.println("--------------------");

    delay(2000);
  
}

