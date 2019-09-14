//
//  Scaleworx_LEDGroup.cpp
//  
//
//  Created by Blain Hamon on 4/25/19.
//

#include "Scaleworx_LEDGroup.h"
#include "Scaleworx_LEDRange.h"

void Scaleworx_LEDGroup::setPixMap(const uint8_t *map, uint8_t width, uint8_t height) {
  range->setPixMap(map, width, height);
}
void Scaleworx_LEDGroup::setXY(uint8_t x, uint8_t y, Scaleworx_RGBColor color, uint8_t white) {
  range->setXY(x,y,color,white);
}
void Scaleworx_LEDGroup::setXY(uint8_t x, uint8_t y, Scaleworx_RGBColor color) {
  range->setXY(x,y,color);
}
void Scaleworx_LEDGroup::setColumn(uint8_t x, Scaleworx_RGBColor color, uint8_t white) {
  range->setColumn(x,color,white);
}
void Scaleworx_LEDGroup::setColumn(uint8_t x, Scaleworx_RGBColor color) {
  range->setColumn(x,color);
}
void Scaleworx_LEDGroup::setRow(uint8_t y, Scaleworx_RGBColor color, uint8_t white) {
  range->setRow(y,color,white);
}
void Scaleworx_LEDGroup::setRow(uint8_t y, Scaleworx_RGBColor color) {
  range->setRow(y,color);
}

void Scaleworx_LEDGroup::set(uint16_t i, Scaleworx_RGBColor color) {
  range->set(i, color);
}
void Scaleworx_LEDGroup::fill(Scaleworx_RGBColor color) {
  range->fill(color);
}
void Scaleworx_LEDGroup::fill(Scaleworx_RGBColor color, uint8_t white) {
  range->fill(color,white);
}
void Scaleworx_LEDGroup::off() {
  Scaleworx_RGBColor black = {0,0,0};
  range->fill(black);
}
uint8_t Scaleworx_LEDGroup::pulseWhite(uint8_t white, uint32_t period, uint32_t time) {
  return range->pulseWhite(white,period,time);
}
void Scaleworx_LEDGroup::chase(Scaleworx_RGBColor *colors, uint16_t count, uint32_t timeStep, uint16_t colorStep){
  range->chase(colors,count,timeStep,colorStep);
}
void Scaleworx_LEDGroup::chase(Scaleworx_RGBColor *colors, uint8_t *whites, uint16_t count, uint32_t timeStep, uint16_t colorStep){
  range->chase(colors,whites,count,timeStep,colorStep);
}
void Scaleworx_LEDGroup::setRandom(Scaleworx_RGBColor color) {
  range->setRandom(color);
}
void Scaleworx_LEDGroup::setRandom(Scaleworx_RGBColor color, uint8_t white) {
  range->setRandom(color,white);
}
