//
//  Scaleworx_LEDRange.h
//
//
//  Created by Blain Hamon on 4/25/19.
//

#ifndef Scaleworx_LEDRange_h
#define Scaleworx_LEDRange_h

#include <inttypes.h>
#include <Scaleworx_RGBColor.h>

#if (ARDUINO >= 100)
 #include <Arduino.h>
#endif

class Scaleworx_LEDManager;

class Scaleworx_LEDRange {
protected:
  Scaleworx_LEDRange *next;
  uint16_t rangeStart;
  uint16_t rangeEnd;
  uint8_t pixMapWidth;
  uint8_t pixMapHeight;
  uint8_t *pixMap;
  uint16_t lookupXY(uint8_t x, uint8_t y) {
    if ((x>=pixMapWidth) || (y>=pixMapHeight)) {
        return 0xFFFF;
    }
    return rangeStart + pixMap[x+y*pixMapWidth];
  }

  virtual void setUnsafe(uint16_t i, Scaleworx_RGBColor color) = 0;
  virtual void setUnsafe(uint16_t i, Scaleworx_RGBColor color, uint8_t white) = 0;

public:
  Scaleworx_LEDRange(uint16_t s, uint16_t l) : next(0), rangeStart(s), rangeEnd(s + l), pixMapWidth(0), pixMapHeight(0), pixMap(0) {}
  void setPixMap(const uint8_t *map, uint8_t width, uint8_t height) {
    pixMapWidth = width;
    pixMapHeight = height;
    pixMap = (uint8_t *)map;
  }
  void setXY(uint8_t x, uint8_t y, Scaleworx_RGBColor color, uint8_t white) {
    uint16_t index = lookupXY(x,y);
    if (index <= rangeEnd) {
      setUnsafe(index, color, white);
    }
  }
  void setXY(uint8_t x, uint8_t y, Scaleworx_RGBColor color) {
    uint16_t index = lookupXY(x,y);
    if (index <= rangeEnd) {
      setUnsafe(index, color);
    }
  }
  void setColumn(uint8_t x, Scaleworx_RGBColor color, uint8_t white) {
    if (x>=pixMapWidth) {
        return;
    }
    uint16_t index = x;
    for (uint8_t y=0; y<pixMapHeight; y++) {
        uint16_t pixel = rangeStart + pixMap[index];
        if (pixel <= rangeEnd) {
          setUnsafe(pixel, color, white);
        }
        index+=pixMapWidth;
    }
  }
  void setColumn(uint8_t x, Scaleworx_RGBColor color) {
    if (x>=pixMapWidth) {
        return;
    }
    uint16_t index = x;
    for (uint8_t y=0; y<pixMapHeight; y++) {
        uint16_t pixel = rangeStart + pixMap[index];
        if (pixel <= rangeEnd) {
          setUnsafe(pixel, color);
        }
        index+=pixMapWidth;
    }
  }
  void setRow(uint8_t y, Scaleworx_RGBColor color, uint8_t white) {
    if (y>=pixMapHeight) {
        return;
    }
    uint16_t index = y * pixMapWidth;
    uint16_t indexEnd = index + pixMapWidth;
    for (; index<indexEnd; index++) {
        uint16_t pixel = rangeStart + pixMap[index];
        if (pixel <= rangeEnd) {
          setUnsafe(pixel, color, white);
        }
    }
  }
  void setRow(uint8_t y, Scaleworx_RGBColor color) {
    if (y>=pixMapHeight) {
        return;
    }
    uint16_t index = y * pixMapWidth;
    uint16_t indexEnd = index + pixMapWidth;
    for (; index<indexEnd; index++) {
        uint16_t pixel = rangeStart + pixMap[index];
        if (pixel <= rangeEnd) {
          setUnsafe(pixel, color);
        }
    }
  }

  void set(uint16_t i, Scaleworx_RGBColor color) {
    if ((i + rangeStart) > rangeEnd) {return;}
    setUnsafe(i + rangeStart, color);
  }
  void set(uint16_t i, Scaleworx_RGBColor color, uint8_t white) {
    if ((i + rangeStart) > rangeEnd) {return;}
    setUnsafe(i + rangeStart, color, white);
  }
  void fill(Scaleworx_RGBColor color) {
    for(uint16_t i = rangeStart; i < rangeEnd; i++) {
      setUnsafe(i,color);
    }
  }
  void fill(Scaleworx_RGBColor color, uint8_t white) {
    for(uint16_t i = rangeStart; i < rangeEnd; i++) {
      setUnsafe(i,color,white);
    }
  }
  void off() {
    Scaleworx_RGBColor black = {0,0,0};
    fill(black);
  }
  uint8_t pulseWhite(uint8_t white, uint32_t period, uint32_t time) {
    float t = (time % period)/(float)period;
    return white * (4.0*t*(1-t));
  }
  void chase(Scaleworx_RGBColor *colors, uint16_t count, uint32_t timeStep, uint16_t colorStep = 1){
    uint32_t offset = millis() / timeStep;
    for(uint16_t i = rangeStart; i < rangeEnd; i++) {
      setUnsafe(i,colors[offset % count]);
      offset+=colorStep;
    }
  }
  void chase(Scaleworx_RGBColor *colors, uint8_t *whites, uint16_t count, uint32_t timeStep, uint16_t colorStep = 1){
    uint32_t offset = millis() / timeStep;
    for(uint16_t i = rangeStart; i < rangeEnd; i++) {
      setUnsafe(i,colors[offset % count],whites[offset % count]);
      offset+=colorStep;
    }
  }
  void setRandom(Scaleworx_RGBColor color) {
    setUnsafe(random(rangeStart, rangeEnd), color);
  }
  void setRandom(Scaleworx_RGBColor color, uint8_t white) {
    setUnsafe(random(rangeStart, rangeEnd), color, white);
  }
  friend class Scaleworx_LEDManager;
  friend class Scaleworx_LEDGroup;
};

#endif /* Scaleworx_LEDRange_h */
