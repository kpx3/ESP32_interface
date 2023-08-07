
#define POTENTIOMETER_PIN  4   
#define ALARM         27  // ESP32 pin GPIO27 connected to Relay's pin
#define VOLTAGE_THRESHOLD  2.5 

void setup() {
  pinMode(ALARM, OUTPUT); // set ESP32 pin to output mode
}

void loop() {
  int analogValue = analogRead(POTENTIOMETER_PIN);      // read the input on analog pin
  float voltage = floatMap(analogValue, 0, 1023, 0, 5); // Rescale to potentiometer's voltage

  if(voltage > VOLTAGE_THRESHOLD)
    digitalWrite(RELAY_PIN, HIGH); // turn on Relay
  else
    digitalWrite(RELAY_PIN, LOW);  // turn off Relay
}

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
