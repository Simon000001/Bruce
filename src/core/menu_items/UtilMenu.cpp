#include "UtilMenu.h"
#include "core/display.h"
#include "modules/Util/bubble.h"

void UtilMenu::optionsMenu() {
  options = {
    {"bubble level",        [=]() {  }},
    {"Main Menu",           [=]() { backToMenu(); }}
  };
  delay(200);
  loopOptions(options,false,true,"Util");
  
}

String UtilMenu::getName(){
  return _name;
}

void UtilMenu::draw(){
  // Clear background
  tft.fillRect(iconX, iconY, 80, 80, bruceConfig.bgColor);

  // Draw gear (simplified as multiple arcs forming the gear teeth)
  tft.drawArc(40 + iconX, 40 + iconY, 30, 28, 45, 90, bruceConfig.priColor, bruceConfig.bgColor);  // Top-right tooth
  tft.drawArc(40 + iconX, 40 + iconY, 30, 28, 135, 180, bruceConfig.priColor, bruceConfig.bgColor); // Top-left tooth
  tft.drawArc(40 + iconX, 40 + iconY, 30, 28, 225, 270, bruceConfig.priColor, bruceConfig.bgColor); // Bottom-left tooth
  tft.drawArc(40 + iconX, 40 + iconY, 30, 28, 315, 360, bruceConfig.priColor, bruceConfig.bgColor); // Bottom-right tooth

  // Center circle of the gear
  tft.fillCircle(40 + iconX, 40 + iconY, 10, bruceConfig.priColor);

  // Draw wrench (diagonal rectangle with a circular head)
  tft.fillRect(15 + iconX, 45 + iconY, 5, 20, bruceConfig.priColor);                    // Wrench handle
  tft.fillCircle(15 + iconX, 45 + iconY, 5, bruceConfig.priColor);                     // Wrench head
}