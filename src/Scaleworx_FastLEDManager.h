//
//  Scaleworx_FastLEDManager.h
//  
//
//  Created by Blain Hamon on 5/2/19.
//

#ifndef Scaleworx_FastLEDManager_h
#define Scaleworx_FastLEDManager_h

#include <Adafruit_DotStar.h>
#include <Scaleworx_LEDManager.h>
#include <FastLED.h>

class Scaleworx_FastLEDManager : public Scaleworx_LEDManager {
protected:
  FastLED * pixels;
  void setup();
  void sendPixels() {
    pixels->show();
  };
  int16_t pixelCount() {
    return pixels->numPixels();
  };
  Scaleworx_LEDRange * createRange(int16_t start, int16_t count);
public:
  Scaleworx_FastLEDManager(uint8_t dataPin, uint8_t clockPin, uint16_t count): Scaleworx_LEDManager(dataPin), pixels(new FastLED(count, dataPin, clockPin)) {};
  Scaleworx_FastLEDManager(uint8_t dataPin, uint8_t clockPin, uint16_t count, uint8_t ptype): Scaleworx_LEDManager(dataPin), pixels(new FastLED(count, dataPin, clockPin, ptype)) {};

  static Scaleworx_LEDGroup singleGroup(uint8_t dataPin, uint8_t clockPin, uint16_t count);

  static Scaleworx_LEDGroup singleGroup(uint8_t dataPin, uint8_t clockPin, uint16_t count, uint8_t ptype);
};

#endif /* Scaleworx_FastLEDManager_h */
