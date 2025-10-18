#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;

void setup() {
  dac.begin(0x60);
  Serial.begin(9600);
  Serial.println("MCP4725 Triangle Wave Output");
}

void loop() {
  for (uint16_t i = 0; i < 4096; i += 8) {
    dac.setVoltage(i, false);
    delayMicroseconds(300);
  }
  for (int i = 4095; i >= 0; i -= 8) {
    dac.setVoltage(i, false);
    delayMicroseconds(300);
  }
}
