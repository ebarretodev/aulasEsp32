const byte BT_PINO = 32;
const byte TOUCH_PINO = 33;
const byte LED_PIN = 2;
const byte VRX_PIN = 35;
const byte VRY_PIN = 34;


void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BT_PINO, INPUT_PULLUP);

  for (int i = 0; i < 4; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(300);
    digitalWrite(LED_PIN, LOW);
    delay(300);
  }
}

void loop() {
  int vrxVal = analogRead(VRX_PIN);
  Serial.print(vrxVal);
  Serial.print(", ");
  
  int vryVal = analogRead(VRY_PIN);
  Serial.print(vryVal);
  Serial.print(", ");
  
  int touchVal = touchRead(TOUCH_PINO);
  Serial.print(touchVal);
  Serial.print(", ");
  bool button = !digitalRead(BT_PINO);
  Serial.println(button);
  if (touchVal < 50) {
    digitalWrite(LED_PIN, HIGH);
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }

  //  digitalWrite(LED_PIN, );
}
