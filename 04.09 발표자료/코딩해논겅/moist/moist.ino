#include <Wire.h>
int pinPower = D5;
int moist;
int moistr;

void setup() {
 Serial.begin(115200);
}


void loop() {
  Wire.begin();
  digitalWrite(pinPower, HIGH);
  delay(500);
  moistr = analogRead(A0);
  moist = map(moistr,1023,0,0,100) ;
  digitalWrite(pinpower, LOW);
  Serial.print("moist="); Serial.println(moist);
  delay(1000);

}
// 수분의 값을 0~1023 값으로 변환하여 맵핑함 
