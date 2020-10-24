#include <SoftwareSerial.h>

#include <Wire.h>
#include <BH1750.h>
BH1750 lightMeter(0x23);
SoftwareSerial hc06(3,4);

uint16_t minuteDelay = 1;
uint16_t baudRate = 9600;

void setup() {
  
  Wire.begin();
  lightMeter.begin(BH1750::ONE_TIME_HIGH_RES_MODE);
  hc06.begin(baudRate);
  minuteDelay = minuteDelay * 1000 * 60;
}

void loop() {
  uint16_t luxValue = lightMeter.readLightLevel(true);

  if (luxValue > 0){
    //Serial.println(luxValue);
    hc06.write('l');
    hc06.print(luxValue);
    hc06.write('e');
    //Serial.println(bytesSent);
  }
  
  //Wait 15 minutes
  delay(minuteDelay);
  //delay(10000);
}
