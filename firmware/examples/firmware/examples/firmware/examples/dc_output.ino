#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;

void setup() {
  dac.begin(0x60);
  Serial.begin(9600);
  Serial.println("MCP4725 DC Output Example");
  
  uint16_t dcValue = 2048; // Mid-range ~2.5V at 5V supply
  dac.setVoltage(dcValue, false);
}

void loop() {
  // Nothing - static output
}
