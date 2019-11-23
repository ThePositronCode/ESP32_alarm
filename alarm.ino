#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
HTTPClient http;
int httpCode=0;
String payload="";


void setup() {
  Serial.begin(115200);
  pinMode(16, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, INPUT_PULLUP);

  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting to WiFi..");
    delay(500);
  }
  Serial.println("Connected to the WiFi network");
  
  alarm();

  http.begin("https://maker.ifttt.com/trigger/door_closed/with/key/YOUR_IFTTT_WEBHOOK_KEY");
  httpCode = http.GET();//Make the request

  WiFi.disconnect();
  
  Serial.println("Alarm ended, going to sleep!");
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_4,HIGH);
  esp_deep_sleep_start();
}


void loop(){
  
}


void alarm(){
  //Web alarm
  http.begin("https://maker.ifttt.com/trigger/door_opened/with/key/YOUR_IFTTT_WEBHOOK_KEY"); //Specify the URL
  if ((WiFi.status() == WL_CONNECTED)) {
     httpCode = http.GET();//Make the request
    /*Debug purpose only
    if (httpCode > 0) { //Check for the returning code
 
        payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
    }else {
      Serial.println("Error on HTTP request");
    }
    */
    http.end();
  }
  
  //Sound alarm
  while(digitalRead(4)!=LOW){
    int time=millis();
    while((millis()-time)<71){
      digitalWrite(16, HIGH);
      digitalWrite(5, LOW);
      delayMicroseconds(125);
      digitalWrite(5, HIGH);
      digitalWrite(16, LOW);
      delayMicroseconds(125);
    }
    time=millis();
    while((millis()-time)<71){
      digitalWrite(16, HIGH);
      digitalWrite(5, LOW);
      delayMicroseconds(103);
      digitalWrite(5, HIGH);
      digitalWrite(16, LOW);
      delayMicroseconds(103);
    }
  }
}
