//
//  Scaleworx_LEDManager.h
//
//
//  Created by Blain Hamon on 5/2/19.
//

#ifndef Scaleworx_LEDManager_h
#define Scaleworx_LEDManager_h

#include <inttypes.h>
#include <Scaleworx_LEDGroup.h>

class Scaleworx_LEDRange;

class Scaleworx_LEDManager {
protected:
  Scaleworx_LEDRange * firstRange;
  void registerPin(uint8_t pin);

  virtual void setup() = 0;
  virtual void sendPixels() = 0;
  virtual Scaleworx_LEDRange * createRange(int16_t start, int16_t count) =0;
  virtual int16_t pixelCount() =0;

public:
  Scaleworx_LEDManager(uint8_t pin): firstRange(0) {registerPin(pin);};

  static void showAll();
  static void setupAll();

  Scaleworx_LEDGroup addGroup(int16_t start, int16_t count);
  Scaleworx_LEDGroup addGroup(int16_t count);
  void fill(Scaleworx_RGBColor color);
};


#endif /* Scaleworx_LEDManager_h */
