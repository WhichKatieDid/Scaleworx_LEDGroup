//
//  Scaleworx_NeopixelManager.cpp
//  
//
//  Created by Blain Hamon on 5/2/19.
//

#include "Scaleworx_NeopixelManager.h"
#include "Scaleworx_NeoPixelRange.h"

Scaleworx_LEDGroup Scaleworx_NeopixelManager::singleGroup(uint8_t pin, uint16_t count) {
  return (new Scaleworx_NeopixelManager(pin,count))->addGroup(-1);
}

void Scaleworx_NeopixelManager::setup() {
  if (firstRange == 0) {
      addGroup(-1);
  }
  neoPixels->begin();
};
Scaleworx_LEDRange * Scaleworx_NeopixelManager::createRange(int16_t start, int16_t count) {
  return new Scaleworx_NeoPixelRange(neoPixels, start, count);
};
