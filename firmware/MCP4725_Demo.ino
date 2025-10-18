#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;

void setup() {
  Serial.begin(9600);
  dac.begin(0x60);  // default I2C address
  Serial.println("MCP4725 DAC Ramp Demo");
}

void loop() {
  // Ramp up
  for (uint16_t i = 0; i < 4096; i += 16) {
    dac.setVoltage(i, false);
    delay(1);
  }

  // Ramp down
  for (int i = 4095; i >= 0; i -= 16) {
    dac.setVoltage(i, false);
    delay(1);
  }
}
