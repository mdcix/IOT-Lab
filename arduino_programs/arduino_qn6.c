//Arduino_qn_6

#define raindropSensorPin A0
#define buzzerPin 8
#define threshold 500
int sensorValue;

void setup() {
  pinMode(raindropSensorPin, INPUT);  // Set raindrop sensor pin as INPUT
  pinMode(buzzerPin, OUTPUT);  // Set buzzer pin as OUTPUT
  
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(raindropSensorPin);

  if (sensorValue > threshold) {
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Raindrop detected!");
  }
  else {
    digitalWrite(buzzerPin, LOW);
  }
  delay(100);  // Debounce delay
}
