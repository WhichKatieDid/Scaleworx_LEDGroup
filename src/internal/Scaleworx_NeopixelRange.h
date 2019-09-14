//
//  Scaleworx_NeoPixelRange.h
//  
//
//  Created by Blain Hamon on 5/2/19.
//

#ifndef Scaleworx_NeoPixelRange_h
#define Scaleworx_NeoPixelRange_h

#include <inttypes.h>

#include <Scaleworx_RGBColor.h>
#include "Scaleworx_LEDRange.h"
#include <Adafruit_NeoPixel.h>

class Scaleworx_NeopixelManager;

class Scaleworx_NeoPixelRange : public Scaleworx_LEDRange {
  Adafruit_NeoPixel *pixels;
  void setUnsafe(uint16_t i, Scaleworx_RGBColor color) {
    pixels->setPixelColor(i, color.red, color.green, color.blue);
  }
  void setUnsafe(uint16_t i, Scaleworx_RGBColor color, uint8_t white) {
    pixels->setPixelColor(i, color.red, color.green, color.blue, white);
  }
public:
  Scaleworx_NeoPixelRange(Adafruit_NeoPixel *p, uint16_t s, uint16_t l) : Scaleworx_LEDRange(s, l), pixels(p) {}
  inline Adafruit_NeoPixel * neoPixels(){return pixels;}
  friend class Scaleworx_NeopixelManager;
};

#endif /* Scaleworx_NeoPixelRange_h */
