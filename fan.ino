#include <DHT.h>

// DHT 핀 7번

//변수 선언
float t;
DHT dht(7, DHT11);
int motor = 3;
int speed = 255;
void setup() {
  dht.begin();
}

void loop() {
  t = dht.readTemperature();
 
  //DHT센서에 주어진 값이 25보다 클 경우 DC모터가 작동합니다.
  if(t > 26) {
    analogWrite(motor, speed);
  }
  else{analogWrite(motor,0);}
}
