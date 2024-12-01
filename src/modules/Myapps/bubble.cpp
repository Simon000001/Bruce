#include "bubble.h"
#include "core/globals.h"
#include "core/mykeyboard.h"
#include "core/display.h"

void bubble_start(){
  MPU6886 mpu;
  int spotPosX=160;
  int spotPosY=68;  
  float gx;
  float gy;
  float gz;
      mpu.Init();

  while(!returnToMenu){
      //render loopy thing

      mpu.getAccelData(&gx, &gy, &gz);
    //   Serial.printf("Accel Data: X:%f Y:%f Z:%f\n", gx, gy, gz);
      float newSpotY = std::max(0.0f, std::min(67.5f + (gx * spotPosY), 135.0f));
      float newSpotX = std::max(0.0f, std::min(120.0f + (gy * spotPosX), 240.0f));
       tft.fillScreen(bruceConfig.bgColor);
       tft.drawLine(80,0,80,135,bruceConfig.priColor);
       tft.drawLine(160,0,160,135,bruceConfig.priColor);
       tft.drawLine(0,68,240,68,bruceConfig.priColor); 
       tft.drawCircle(newSpotX,newSpotY,20,bruceConfig.priColor);
      // // tft.setCursor(20, 20);
      // // tft.setTextColor(bruceConfig.priColor);
      // // tft.setTextSize(FP);
      // // tft.setTextFont(SMOOTH_FONT); // Set the text font to font number 2
      // //tft.printf("gx,gy,gz");
      // //tft.printf("%5.2f %5.2f %5.2f G", gx, gy, gz);
      delay(5);
      //checkEscPress();
  }
  delay(100);
  tft.fillScreen(bruceConfig.bgColor);
}