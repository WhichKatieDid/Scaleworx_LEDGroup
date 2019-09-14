//
//  Scaleworx_NeopixelManager.h
//  
//
//  Created by Blain Hamon on 5/2/19.
//

#ifndef Scaleworx_NeopixelManager_h
#define Scaleworx_NeopixelManager_h

#include <inttypes.h>
#include <Adafruit_NeoPixel.h>
#include <Scaleworx_LEDManager.h>

class Scaleworx_NeopixelManager : public Scaleworx_LEDManager {
protected:
  Adafruit_NeoPixel * neoPixels;
  void setup();
  Scaleworx_LEDRange * createRange(int16_t start, int16_t count);

public:
  Scaleworx_NeopixelManager(uint8_t pin, uint16_t count): Scaleworx_LEDManager(pin), neoPixels(new Adafruit_NeoPixel(count, pin)) {};
  Scaleworx_NeopixelManager(uint8_t pin, uint16_t count, neoPixelType ptype): Scaleworx_LEDManager(pin), neoPixels(new Adafruit_NeoPixel(count, pin)) {neoPixels->updateType(ptype);};
  Scaleworx_NeopixelManager(Adafruit_NeoPixel * pixels) : Scaleworx_LEDManager(pixels->getPin()), neoPixels(pixels) {};

  static Scaleworx_LEDGroup singleGroup(uint8_t pin, uint16_t count);

  void sendPixels() {
    neoPixels->show();
  };
  int16_t pixelCount() {
    return neoPixels->numPixels();
  };
};


#endif /* Scaleworx_NeopixelManager_h */
