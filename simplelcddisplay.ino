#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 32, &Wire, -1);

const float V_REF = 5.0;     // Analog reference voltage
const float R_BITS = 10.0;   // ADC resolution (bits)
const float ADC_STEPS = (1 << int(R_BITS)) - 1; // 1023 for 10-bit ADC

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay(); display.display();
}

void loop() {
  int fsr = analogRead(A0);
  int pot = analogRead(A1);

  float v_fsr = (fsr / ADC_STEPS) * V_REF;
  float v_pot = (pot / ADC_STEPS) * V_REF;

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("FSR: "); display.println(v_fsr, 3);
  display.print("POT: "); display.println(v_pot, 3);
  display.display();
  delay(50);
}