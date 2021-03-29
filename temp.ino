#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println("start");
  dht.begin();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println();
  Serial.println("READ");
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if(isnan(humidity) || isnan(temperature)){
    Serial.println("Fail");
    return;
  }
  Serial.print("Humidity (%):");
  Serial.print(humidity);
  Serial.print("Temperature ('c):");
  Serial.println(temperature);
  if(temperature>22)
  {
    Serial.println("hot");
  }
  delay(2000);
}
//온습도 측정 모듈
//항시 작동

// 팬 작동
//온도가 28도보다 높을 시 팬 작동
//온도가 27도이하가 될 시 팬 작동 해제 

//발열필름
//온도가 24도 보다 낮을 시 발열필름 가장 약하게 작동
//24도에서 26도 사이일때 작동 유지
//26도를 넘어갈시 작동 해제

//가습기 모듈
//습도가 50퍼센트 이하일 시 작동
//습도가 55퍼센트 이상일 시 작동 해제

//실리카겔(서보 모터)
//습도가 60퍼센트 이상일 실리카겔 보관함 문 개폐

//LCD 
//항시 온습도 표시
