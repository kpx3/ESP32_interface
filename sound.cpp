
#define SENSOR_PIN 18 // ESP32 pin GPIO18 connected to the OUT pin of the sound sensor

int lastState = HIGH;  // the previous state from the input pin
int currentState;      // the current reading from the input pin

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the ESP32's pin as an input
  pinMode(SENSOR_PIN, INPUT);
}

void loop() {
  // read the state of the the ESP32's input pin
  currentState = digitalRead(SENSOR_PIN);

  if (lastState == HIGH && currentState == LOW)
    Serial.println("The sound has been detected");
  else if (lastState == LOW && currentState == HIGH)
    Serial.println("The sound has disappeared");

  // save the the last state
  lastState = currentState;
}
