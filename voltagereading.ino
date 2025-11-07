int analogPin = A0;
int digitalPin = A2;

const float V_REF = 5.0;     // Analog reference voltage (e.g., 5V or 3.3V)
const float R_BITS = 10.0;   // ADC resolution (bits)
const float ADC_STEPS = (1 << int(R_BITS)) - 1; // Number of steps (2^R_BITS - 1)

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  float raw = analogRead(analogPin);
  //Serial.println(raw);

  float voltage = (raw / ADC_STEPS) * V_REF;
  //Serial.print("Voltage: ");
  Serial.println(voltage, 3); // Print voltage with 3 decimal places
  //Serial.println(" V");

  //int digitalState = digitalRead(digitalPin);

  delay(100);
}
