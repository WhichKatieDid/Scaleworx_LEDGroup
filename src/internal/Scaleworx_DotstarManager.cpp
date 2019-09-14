//
//  Scaleworx_DotstarManager.cpp
//  
//
//  Created by Blain Hamon on 5/2/19.
//

#include "Scaleworx_DotstarManager.h"
#include "Scaleworx_DotStarRange.h"

Scaleworx_LEDGroup Scaleworx_DotstarManager::singleGroup(uint8_t dataPin, uint8_t clockPin, uint16_t count) {
  return (new Scaleworx_DotstarManager(dataPin, clockPin,count))->addGroup(-1);
}

Scaleworx_LEDGroup Scaleworx_DotstarManager::singleGroup(uint8_t dataPin, uint8_t clockPin, uint16_t count, uint8_t ptype) {
  return (new Scaleworx_DotstarManager(dataPin, clockPin,count, ptype))->addGroup(-1);
}

void Scaleworx_DotstarManager::setup() {
  if (firstRange == 0) {
      addGroup(-1);
  }
  dotstars->begin();
};
Scaleworx_LEDRange * Scaleworx_DotstarManager::createRange(int16_t start, int16_t count) {
  return new Scaleworx_DotStarRange(dotstars, start, count);
};

