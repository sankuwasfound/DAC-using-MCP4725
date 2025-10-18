#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <math.h>

Adafruit_MCP4725 dac;

void setup() {
  dac.begin(0x60);
  Serial.begin(9600);
  Serial.println("MCP4725 Sine Wave Output");
}

void loop() {
  for (int i = 0; i < 360; i++) {
    float radians = i * (3.14159 / 180);
    uint16_t value = (sin(radians) * 2047) + 2048;
    dac.setVoltage(value, false);
    delayMicroseconds(500);
  }
}
