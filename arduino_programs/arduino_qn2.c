//Arduino_qn_2

#define lightSensorPin A0  // Analog pin to which light sensor is connected
#define ledPin 13  // Digital pin to which LED is connected

int lightThreshold = 500;  // Predefined threshold light intensity value

void setup() {
  pinMode(lightSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(lightSensorPin);  // Read light sensor value
  
  Serial.print("Light Intensity: ");
  Serial.println(lightValue);

  if (lightValue < lightThreshold) {
    digitalWrite(ledPin, HIGH);  // Turn ON the LED
    Serial.println("LED ON");
  } else {
    digitalWrite(ledPin, LOW);  // Turn OFF the LED
    Serial.println("LED OFF");
  }
  
  delay(1000);  // Delay for 1 second
}

