#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
#define BLYNK_TEMPLATE_NAME         "Device"
#define BLYNK_AUTH_TOKEN            "bw9Dlfusw60bHR6YVmZux9S_RSOmw2iM"

#include "BlynkGate.h"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "DESKTOPkxn";     // Key in your wifi name. You can check with your smart phone for your wifi name
char pass[] = "30121992"; // Key in your wifi password.

#define PCSerial    Serial
#define DBSerial(...)    Serial.println(__VA_ARGS__)
//#define DBSerial(...)    

#define KXNSHOW(x)   Serial.print(#x"\t"); Serial.println(x);
#define PIN_LED   13
// #define PIN_BTN   A3
#define PIN_SEN   A2

// BlynkGate Blynk(74);

unsigned long lastTimeSen = 0;

void setup() {
  // put your setup code here, to run once:
  // pinMode(PIN_BTN, INPUT_PULLUP);
  PCSerial.begin(9600);
  PCSerial.println(F("Start Test Uart to I2C"));
  Blynk.begin(auth, ssid, pass);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
	Blynk.run();
  // DO NOT using delay 
  // delay(100);

  // Try using millis() and use "Blynk.virtualWrite" at least 10s at a time to avoid spamming the server
  if(millis() - lastTimeSen >= 10000){
    lastTimeSen = millis();
    // if(digitalRead(PIN_BTN) == 0){
      Blynk.virtualWrite(0, analogRead(PIN_SEN));
      // Blynk.virtualWrite(245, random(0, 3));
      // PCSerial.println(F("Test Uart to I2C"));
    // }
  }
  
}


BLYNK_WRITE_DEFAULT(){
    Serial.print("input V");
    Serial.print(request.pin);
    Serial.println(":");

    // double myDouble = param.asFloat();
    // String myString = param.asString();
    int myInt = param.asInt();

    if(request.pin == 242) digitalWrite(PIN_LED, myInt);

    // KXNSHOW(myDouble);
    // KXNSHOW(myString);
    KXNSHOW(myInt);
}
