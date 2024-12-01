#include "MyappsMenu.h"
#include "core/display.h"
#include "modules/Myapps/bubble.h"

void MyAppsMenu::optionsMenu() {
  options = {
    {"bubble level",        [=]() { bubble_start(); }},
    {"Main Menu",           [=]() { backToMenu(); }}
  };
  delay(200);
  loopOptions(options,false,true,"MyApps");
  
}

String MyAppsMenu::getName(){
  return _name;
}

void MyAppsMenu::draw(){
  // Clear background
  tft.fillRect(iconX, iconY, 80, 80, bruceConfig.bgColor);

  // Draw APPS LOGO
  tft.drawRoundRect(5 + iconX,10 + iconY, 65, 65 , 10, bruceConfig.priColor);
  tft.fillRoundRect(15 + iconX,20 + iconY, 20, 20 , 4, bruceConfig.priColor);
  tft.fillRoundRect(15 + iconX,45 + iconY, 20, 20 , 4, bruceConfig.priColor);
  tft.fillRoundRect(40 + iconX,20 + iconY, 20, 20 , 4, bruceConfig.priColor);
  tft.fillRoundRect(40 + iconX,45 + iconY, 20, 20 , 4, bruceConfig.priColor);
}