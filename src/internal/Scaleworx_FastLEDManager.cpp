//
//  Scaleworx_FastLEDManager.cpp
//  
//
//  Created by Blain Hamon on 5/2/19.
//

#include "Scaleworx_FastLEDManager.h"
#include "Scaleworx_FastLEDRange.h"

Scaleworx_LEDGroup Scaleworx_FastLEDManager::singleGroup(uint8_t dataPin, uint8_t clockPin, uint16_t count) {
  return (new Scaleworx_FastLEDManager(dataPin, clockPin,count))->addGroup(-1);
}

Scaleworx_LEDGroup Scaleworx_FastLEDManager::singleGroup(uint8_t dataPin, uint8_t clockPin, uint16_t count, uint8_t ptype) {
  return (new Scaleworx_FastLEDManager(dataPin, clockPin,count, ptype))->addGroup(-1);
}

void Scaleworx_FastLEDManager::setup() {
  if (firstRange == 0) {
      addGroup(-1);
  }
  dotstars->begin();
};
Scaleworx_LEDRange * Scaleworx_FastLEDManager::createRange(int16_t start, int16_t count) {
  return new Scaleworx_FastLEDRange(dotstars, start, count);
};

