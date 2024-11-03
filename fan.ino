#include <DHT.h>

// DHT 핀 7번

//변수 선언
float t;
DHT dht(7, DHT11);
int motor = 3;
int speed = 127;
void setup() {
  Serial.begin(9600); //시리얼 통신을 초기화하고 통신속도를 9600bps로 설정합니다.
  dht.begin();
}

void loop() {
  t = dht.readTemperature();
  //시리얼모니터에 온도값을 출력합니다.
  Serial.println(t);
 
  //DHT센서에 주어진 값이 25보다 클 경우 DC모터가 작동합니다.
  if(t > 25) {
    analogWrite(motor, speed);
  }
  else{analogWrite(motor,0);}
  delay(1000);
}