#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUZZER_PIN 6
#define GREEN_LED 7
#define RED_LED 8

long readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2; // convert to cm
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  long distance = readDistanceCM();

  if (distance < 30) { // Door open
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    tone(BUZZER_PIN, 1000); // alarm sound
  } else { // Door closed
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    noTone(BUZZER_PIN); // silence
  }

  delay(200); // smooth updates
}
