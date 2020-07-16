//
//  Scaleworx_FastLEDRange.h
//  
//
//  Created by Blain Hamon on 5/2/19.
//

#ifndef Scaleworx_FastLEDRange_h
#define Scaleworx_FastLEDRange_h

#include <inttypes.h>

#include <Scaleworx_RGBColor.h>
#include "Scaleworx_LEDRange.h"
#include <FastLED.h>

class Scaleworx_FastLEDManager;

class Scaleworx_FastLEDRange : public Scaleworx_LEDRange {
  FastLED *pixels;
  void setUnsafe(uint16_t i, Scaleworx_RGBColor color) {
    pixels->setPixelColor(i, color.red, color.green, color.blue);
  }
  void setUnsafe(uint16_t i, Scaleworx_RGBColor color, uint8_t white) {
    pixels->setPixelColor(i, color.red, color.green, color.blue);
  }
public:
  Scaleworx_FastLEDRange(FastLED *p, uint16_t s, uint16_t l) : Scaleworx_LEDRange(s, l), pixels(p) {}
  inline FastLED * dotstars(){return pixels;}
  friend class Scaleworx_FastLEDManager;
};

#endif /* Scaleworx_FastLEDRange_h */
