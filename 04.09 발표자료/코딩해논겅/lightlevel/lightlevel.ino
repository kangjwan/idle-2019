#include <BH1750.h>
BH1750 lightMeter;
unit16_t lux;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  lightMeter.begin();
}


void loop() {
  lux = lightMeter.readLightLevel();
  Serial.print("lux="); Serial.println(lux);
  delay(1000);

}
//조도값을 lux값으로 변환
