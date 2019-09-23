#include "DHT.h"
#define DHTTYPE DHT11
#define DHTPIN D6
DHT dht(DHTPIN, DHTTYPE);
int temp;
int humid;

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  temp = dht.readTemparature();
  humid = dht.readHumidity();
  Serial.print("temp="); Serial.print(temp);
  Serial.print(",humid="); Serial.println(humid);
  delay(1000);

}
