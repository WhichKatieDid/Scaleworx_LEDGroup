#include <Scaleworx_LEDGroup.h>
#include <Scaleworx_PixmapConstants.h>

const int pinEyeData = 14;
const int pinEyeClock = 15;


// Use the following for use with dotstar matrices

#include <Adafruit_DotStar.h>
#include <Scaleworx_DotstarManager.h>

Scaleworx_DotstarManager synthEyes = Scaleworx_DotstarManager(pinEyeData, pinEyeClock, 128, DOTSTAR_BGR);

// Alternatively use the following for use with neopixel matrices

// #include <Adafruit_NeoPixel.h>
// #include <Scaleworx_NeopixelManager.h>
//
// Scaleworx_DotstarManager synthEyes = Scaleworx_NeopixelManager(pinEyeData, 128, DOTSTAR_BGR);


#include "bitmaps.h"

Scaleworx_LEDGroup leftEye;
Scaleworx_LEDGroup rightEye;

Scaleworx_RGBColor white = {30,30,30};
Scaleworx_RGBColor red = {50,10,10};
Scaleworx_RGBColor green = {10,50,10};

void applyColorRowBits(Scaleworx_LEDGroup group, Scaleworx_RGBColor color, uint8_t bits, uint8_t row) {
    if (bits & 0x80) {group.setXY(0, row, color);}
    if (bits & 0x40) {group.setXY(1, row, color);}
    if (bits & 0x20) {group.setXY(2, row, color);}
    if (bits & 0x10) {group.setXY(3, row, color);}

    if (bits & 0x08) {group.setXY(4, row, color);}
    if (bits & 0x04) {group.setXY(5, row, color);}
    if (bits & 0x02) {group.setXY(6, row, color);}
    if (bits & 0x01) {group.setXY(7, row, color);}
}

void applyColorBits(Scaleworx_LEDGroup group, Scaleworx_RGBColor color, const uint8_t bytes[]) {
    applyColorRowBits(group, color, bytes[0], 0);
    applyColorRowBits(group, color, bytes[1], 1);
    applyColorRowBits(group, color, bytes[2], 2);
    applyColorRowBits(group, color, bytes[3], 3);

    applyColorRowBits(group, color, bytes[4], 4);
    applyColorRowBits(group, color, bytes[5], 5);
    applyColorRowBits(group, color, bytes[6], 6);
    applyColorRowBits(group, color, bytes[7], 7);
}

void setup() {
  leftEye = synthEyes.addGroup(64);
  rightEye = synthEyes.addGroup(64);
  leftEye.setPixMap(map8x8BottomRightLeftward, 8, 8);
  rightEye.setPixMap(map8x8TopRightLeftward, 8, 8);
  Scaleworx_LEDManager::setupAll();
  
  //Start for two seconds showing which is left and which is right.
  
  leftEye.off();
  rightEye.off();
  applyColorBits(leftEye, white, eyeLeft);
  applyColorBits(rightEye, red, eyeRight);
  Scaleworx_LEDManager::showAll();
  delay(2000);
}

Scaleworx_RGBColor flashyColor(uint32_t t) {
  Scaleworx_RGBColor color = {t % 0xFF, t>>4 % 0xFF, t>>8 % 0xFF};
}

void loop() {
  uint32_t t = millis();

  leftEye.off();
  rightEye.off();

  switch ((t/100) % 50) {
    case 1: case 7:
      applyColorBits(leftEye, green, eyeBlink1);
      applyColorBits(rightEye, green, eyeBlink1);
    break;

    case 2: case 6: case 28: case 30:
      applyColorBits(leftEye, green, eyeBlink2);
      applyColorBits(rightEye, green, eyeBlink2);
    break;

    case 3: case 5:
      applyColorBits(leftEye, green, eyeBlink3);
      applyColorBits(rightEye, green, eyeBlink3);
    break;

    case 4: case 29:
      applyColorBits(leftEye, green, eyeBlink4);
      applyColorBits(rightEye, green, eyeBlink4);
    break;

    case 20: case 21: case 22: case 23: case 24:
    case 25: case 26: case 27: case 31: case 32:
      applyColorBits(leftEye, green, eyeWide);
      applyColorBits(rightEye, green, eyeWide);
    break;

    case 40: case 41: case 42: case 43: case 44:
      applyColorBits(leftEye, green, eyeUp);
      applyColorBits(rightEye, green, eyeUp);
    break;

    default:
      applyColorBits(leftEye, green, eyeDefault);
      applyColorBits(rightEye, green, eyeDefault);
    break;
  }
  
  Scaleworx_LEDManager::showAll();
  int32_t wait = t+20 - millis();
  if (wait > 0) delay(wait);
}
