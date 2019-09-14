//
//  Scaleworx_DotstarManager.h
//  
//
//  Created by Blain Hamon on 5/2/19.
//

#ifndef Scaleworx_DotstarManager_h
#define Scaleworx_DotstarManager_h

#include <Adafruit_DotStar.h>
#include <Scaleworx_LEDManager.h>

class Scaleworx_DotstarManager : public Scaleworx_LEDManager {
protected:
  Adafruit_DotStar * dotstars;
  void setup();
  void sendPixels() {
    dotstars->show();
  };
  int16_t pixelCount() {
    return dotstars->numPixels();
  };
  Scaleworx_LEDRange * createRange(int16_t start, int16_t count);
public:
  Scaleworx_DotstarManager(uint8_t dataPin, uint8_t clockPin, uint16_t count): Scaleworx_LEDManager(dataPin), dotstars(new Adafruit_DotStar(count, dataPin, clockPin)) {};
  Scaleworx_DotstarManager(uint8_t dataPin, uint8_t clockPin, uint16_t count, uint8_t ptype): Scaleworx_LEDManager(dataPin), dotstars(new Adafruit_DotStar(count, dataPin, clockPin, ptype)) {};

  static Scaleworx_LEDGroup singleGroup(uint8_t dataPin, uint8_t clockPin, uint16_t count);

  static Scaleworx_LEDGroup singleGroup(uint8_t dataPin, uint8_t clockPin, uint16_t count, uint8_t ptype);

  
  
};

#endif /* Scaleworx_DotstarManager_h */
