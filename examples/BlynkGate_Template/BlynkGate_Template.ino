// Step 1: Get this infomation from Blynk.cloud
#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
#define BLYNK_TEMPLATE_NAME         "Device"
#define BLYNK_AUTH_TOKEN            "bw9Dlfusw60bHR6YVmZux9S_RSOmw2iM"

#include "BlynkGate.h"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "DESKTOPkxn";     // Key in your wifi name. You can check with your smart phone for your wifi name
char pass[] = "30121992"; // Key in your wifi password.

unsigned long lastTimeSen = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_BTN, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println(F("Start Test Uart to I2C"));
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  // put your main code here, to run repeatedly:
	Blynk.run();
  // DO NOT using delay 
  // delay(100);

  // Try using millis() and use "Blynk.virtualWrite" at least 10s at a time to avoid spamming the server
  if(millis() - lastTimeSen >= 10000){
    lastTimeSen = millis();
    Blynk.virtualWrite(0, analogRead(A0));
  }
  
}


BLYNK_WRITE_DEFAULT(){
    // double myDouble = param.asFloat();
    // String myString = param.asString();
    int myInt = param.asInt();

    Serial.print("input V");
    Serial.print(request.pin);
    Serial.print(": ");
    Serial.println(myInt);
}
