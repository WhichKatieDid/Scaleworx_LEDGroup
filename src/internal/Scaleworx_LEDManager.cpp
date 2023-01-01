//
//  Scaleworx_LEDManager.cpp
//
//
//  Created by Blain Hamon on 5/2/19.
//

#include "Scaleworx_LEDManager.h"
#include "Scaleworx_LEDRange.h"

static Scaleworx_LEDManager * managers[32] = {
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0
};

void Scaleworx_LEDManager::setupAll(){
    for(int i = 0; i < 32; i++) {
        if (managers[i] != 0) {
            managers[i]->setup();
        }
    }
}

void Scaleworx_LEDManager::registerPin(uint8_t pin) {
    managers[pin] = this;
}

void Scaleworx_LEDManager::showAll() {
    for(int i = 0; i < 32; i++) {
        if (managers[i] != 0) {
            managers[i]->sendPixels();
        }
    }
}

Scaleworx_LEDGroup Scaleworx_LEDManager::addGroup(int16_t start, int16_t count) {
  Scaleworx_LEDRange ** nextGroup = &firstRange;
  while(*nextGroup != 0) {
      nextGroup = &((*nextGroup)->next);
  }
  *nextGroup = createRange(start, count);
  return Scaleworx_LEDGroup(*nextGroup);
}

Scaleworx_LEDGroup Scaleworx_LEDManager::addGroup(int16_t count) {
  Scaleworx_LEDRange ** nextGroup = &firstRange;
  uint16_t lastPix = 0;
  while(*nextGroup != 0) {
      lastPix = (*nextGroup)->rangeEnd;
      nextGroup = &((*nextGroup)->next);
  }
  if (count < 0) {
      count = pixelCount() - count - lastPix;
  }
  *nextGroup = createRange(lastPix, count);
  return  Scaleworx_LEDGroup(*nextGroup);
};

  void Scaleworx_LEDManager::fill(Scaleworx_RGBColor color) {
      Scaleworx_LEDRange * nextGroup = firstRange;
      while (nextGroup != 0) {
        nextGroup->fill(color);
        nextGroup = nextGroup->next;
      }
  }
