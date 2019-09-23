#include <Wire.h>
#include <BH1750.h>
BH1750 lightMeter;
#include "DHT.h"
#define DHTTYPE DHT11
int pinPower = DS;
int pinRelay = D7;
#define DHTPIN D6
DHT dht(DHTPIN, DHTTYPE);
unit16_t lux;
int temp;
int humid;
int moist;
int moistr;
long time blink = 0;
int flag_blink = 0;

void procReadSensors(){
  digitalWrite(pinPower, HIGH);
  delay(500);
  for ( int i = 0; i < 30; i++) {
    delay(100);
    temp = dht.readTemperature();
    humid = dht.readHumidity();
    if ( temp < 100 && humid < 101) break;
  } // 21~26 줄은 온습도 센서값이 비정상으로 읽히는 현상이 있기 때문에 정상적인 값이 읽힐때까지 반복
  
 lux = lightMeter.readLightLevel();
 moistr = analogRead(A0);
 moist = map(moistr,1023,0,0,100);
 degitalWrite(pinPower, LOW);
 Serial.print("temp="); Serial.print(temp);
 Serial.print(",humid=");Serial.print(humid);
 Serial.print(",lux =");Serial.print(lux);
 Serial.print(",moist=");Serial.print(moist);
} //18~35 줄은 전체 센서값들을 읽는 기능을 모아 별도 함수로 설정

}
void setup() {
 Wire.begin();
 pinMode(pinPower, OUTPUT);
 digitalWrite(pinPower, LOW);
 pinMode(pinRelay, OUTPUT);
 digitalWrite(pinRelay, LOW);
 pinMode(LED_BUILTIN, OUTPUT);
 lightMeter.begin();
 dht.begin();
 Serial.begin(115200);
 Serial.println("==waterman IOT START==");
}


void loop() {
if ( millis() - time_blink > 1000 * 3 ) {
  procReadSensors();
  if ( flag_blink ==1 ){
    digitalWrite(LED_BUILTIN, HIGH);
    flag_blink = 0;
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(pinRelay, LOW);
    flag_blink = 1;
  }
  time_blink = millis();
 }
}
  
  }

}
// 49~62 번줄은 3초간격으로 led 깜빡깜빡
