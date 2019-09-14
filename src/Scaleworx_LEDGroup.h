//
//  Scaleworx_LEDGroup.h
//  
//
//  Created by Blain Hamon on 4/25/19.
//

#ifndef Scaleworx_LEDGroup_h
#define Scaleworx_LEDGroup_h

#include <inttypes.h>
#include <Scaleworx_RGBColor.h>

#if (ARDUINO >= 100)
 #include <Arduino.h>
#endif

class Scaleworx_LEDManager;
class Scaleworx_LEDRange;

class Scaleworx_LEDGroup {
protected:
  Scaleworx_LEDRange *range;
public:
  Scaleworx_LEDGroup() : range(0) {}
  Scaleworx_LEDGroup(Scaleworx_LEDRange *newRange) : range(newRange) {}
  void setPixMap(const uint8_t *map, uint8_t width, uint8_t height);
  void setXY(uint8_t x, uint8_t y, Scaleworx_RGBColor color, uint8_t white);
  void setXY(uint8_t x, uint8_t y, Scaleworx_RGBColor color);
  void setColumn(uint8_t x, Scaleworx_RGBColor color, uint8_t white);
  void setColumn(uint8_t x, Scaleworx_RGBColor color);
  void setRow(uint8_t y, Scaleworx_RGBColor color, uint8_t white);
  void setRow(uint8_t y, Scaleworx_RGBColor color);
  void set(uint16_t i, Scaleworx_RGBColor color);
  void fill(Scaleworx_RGBColor color);
  void fill(Scaleworx_RGBColor color, uint8_t white);
  void off();
  uint8_t pulseWhite(uint8_t white, uint32_t period, uint32_t time);
  void chase(Scaleworx_RGBColor *colors, uint16_t count, uint32_t timeStep, uint16_t colorStep = 1);
  void chase(Scaleworx_RGBColor *colors, uint8_t *whites, uint16_t count, uint32_t timeStep, uint16_t colorStep = 1);
  void setRandom(Scaleworx_RGBColor color);
  void setRandom(Scaleworx_RGBColor color, uint8_t white);
};

#endif /* Scaleworx_LEDGroup_h */
