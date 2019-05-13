
const int analogInPin = A0;  // ESP8266 Analog Pin ADC0 = A0
const uint8_t D7_PIN = 13;  // RXD2 - HSPID

const uint8_t micPin = D7_PIN;

int sensorValue = 0;  // value read from the pot
int outputValue = 0;  // value to output to a PWM pin
int digiValue = 0; // from digital pin

int minOut = 9999;
int maxOut = 0;

void setup() {
  // initialize serial communication at 115200
  Serial.begin(115200);
  Serial.println("start");
}

void loop() {
  // read the analog in value
  sensorValue = analogRead(analogInPin);
  // map it to the range of the PWM out
  outputValue = map(sensorValue, 0, 1024, 0, 255);
  // check digital pin
  digiValue = digitalRead(micPin);

  minOut = outputValue < minOut? outputValue : minOut;
  maxOut = outputValue > maxOut? outputValue : maxOut;
   
  // print the readings in the Serial Monitor
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.print(outputValue);
  Serial.print("\t min = ");
  Serial.print(minOut);
  Serial.print("\t max = ");
  Serial.print(maxOut);
  Serial.print("\t Digital = ");
  Serial.print(digiValue);
  Serial.println();// sensorValue = digitalRead(micPin);
  
  delay(20);
}
