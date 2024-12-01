#include "bubble.h"
#include "core/globals.h"
#include "core/mykeyboard.h"
#include "core/display.h"

void bubble_start(){
  MPU6886 mpu;
    Serial.println("I2C Diagnostic Scan:");
    
    // Test general I2C communication
    Wire.begin(21, 22);
    Wire.setClock(400000);

    Serial.println("Checking MPU6886 Specific Address:");
    Wire.beginTransmission(0x68);  // MPU6886 Address
    int result = Wire.endTransmission();
    
    switch(result) {
        case 0: Serial.println("0: Success"); break;
        case 1: Serial.println("1: Data too long"); break;
        case 2: Serial.println("2: NACK on address"); break;
        case 3: Serial.println("3: NACK on data"); break;
        case 4: Serial.println("4: Other error"); break;
        default: Serial.println("Unknown error"); break;
    }

    // Broad I2C scan
    Serial.println("\nScanning I2C68evices:");
    for (byte address = 1; address < 127; address++) {
        Wire.beginTransmission(address);
        result = Wire.endTransmission();
        
        if (result == 0) {
            Serial.printf("Device found at 0x%02X\n", address);
        }

}
  mpu.Init();
  int spotPosX=160;
  int spotPosY=68;  
  float gx;
  float gy;
  float gz;
  mpu.getAccelData(&gx,&gy,&gz);
  for(;;){
      //render loopy thing

      Serial.printf("Accel Data: X:%f Y:%f Z:%f\n", gx, gy, gz);
      tft.fillScreen(bruceConfig.bgColor);
      tft.drawLine(80,0,80,135,bruceConfig.priColor);
      tft.drawLine(160,0,160,135,bruceConfig.priColor);
      tft.drawLine(0,68,240,68,bruceConfig.priColor); 
      tft.setCursor(20, 20);
      tft.setTextColor(bruceConfig.priColor);
      tft.setTextSize(FP);
      tft.setTextFont(SMOOTH_FONT); // Set the text font to font number 2
      tft.printf("gx,gy,gz");
      tft.printf("%5.2f %5.2f %5.2f G", gx, gy, gz);
      float newSpotX = std::max(0.0f, std::min(spotPosX + (gx * spotPosX), 240.0f));
      float newSpotY = std::max(0.0f, std::min(spotPosY + (gy * spotPosY), 135.0f));
      tft.drawSpot(newSpotX,newSpotY,20,bruceConfig.priColor);
      delay(100);
      if(checkEscPress()){
        returnToMenu = true;
        break;
      } 
    }
  delay(100);
  tft.fillScreen(bruceConfig.bgColor);

}