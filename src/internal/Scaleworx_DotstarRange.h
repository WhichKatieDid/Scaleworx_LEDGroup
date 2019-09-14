//
//  Scaleworx_DotStarRange.h
//  
//
//  Created by Blain Hamon on 5/2/19.
//

#ifndef Scaleworx_DotStarRange_h
#define Scaleworx_DotStarRange_h

#include <inttypes.h>

#include <Scaleworx_RGBColor.h>
#include "Scaleworx_LEDRange.h"
#include <Adafruit_DotStar.h>

class Scaleworx_DotstarManager;

class Scaleworx_DotStarRange : public Scaleworx_LEDRange {
  Adafruit_DotStar *pixels;
  void setUnsafe(uint16_t i, Scaleworx_RGBColor color) {
    pixels->setPixelColor(i, color.red, color.green, color.blue);
  }
  void setUnsafe(uint16_t i, Scaleworx_RGBColor color, uint8_t white) {
    pixels->setPixelColor(i, color.red, color.green, color.blue);
  }
public:
  Scaleworx_DotStarRange(Adafruit_DotStar *p, uint16_t s, uint16_t l) : Scaleworx_LEDRange(s, l), pixels(p) {}
  inline Adafruit_DotStar * dotstars(){return pixels;}
  friend class Scaleworx_DotstarManager;
};

#endif /* Scaleworx_DotStarRange_h */
