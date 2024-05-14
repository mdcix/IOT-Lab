//Arduino_qn_3
#define BUTTON_PIN 2
#define LED_PIN 13

int buttonState = 0;

void setup()
{
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop(){

  buttonState = digitalRead(BUTTON_PIN); // read the state of the pushbutton value

  if (buttonState == HIGH) {
    digitalWrite(LED_PIN, HIGH);
  } 
  else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
