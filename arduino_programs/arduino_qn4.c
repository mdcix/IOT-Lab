//Arduino_qn_4

#define buttonPin 2
#define irSensorPin A0
#define ledPin 13

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(irSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Read the state of the push button
  int buttonState = digitalRead(buttonPin);
  
  // Read the state of the IR sensor
  int irSensorValue = analogRead(irSensorPin);

  if (buttonState == HIGH || irSensorValue > 1000) {  
    digitalWrite(ledPin, HIGH);  // Turn ON the LED
    Serial.println("LED ON");
  } else {
    digitalWrite(ledPin, LOW);  // Turn OFF the LED
    Serial.println("LED OFF");
  }
  // Serial.println(irSensorValue);
  // Serial.println(buttonState);
  delay(100);  /
}

