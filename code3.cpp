#include <SoftwareSerial.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "P4pODDBKIyHrzw2YJW5g6Bfc8-H1bWqa";
char ssid[] = "ASUS_X00TD";
char pass[] = "suvadip1998";
BlynkTimer timer;
void moisture() {
 int rainSensor = analogRead(A0);
rainSensor = map(rainSensor, 0, 1023, 0, 350);
 Blynk.virtualWrite(V5, rainSensor);
 Serial.println(rainSensor);
}
void setup() {
 Serial.begin(9600);
 Blynk.begin(auth, ssid, pass);
 timer.setInterval(350, moisture);
}
void loop() 
{
 Blynk.run();
 timer.run();