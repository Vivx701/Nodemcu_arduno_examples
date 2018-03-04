#include <ESP8266WiFi.h>

//This is your ip configuration 
IPAddress local_IP(192,168,4,22);
IPAddress gateway(192,168,4,9);
IPAddress subnet(255,255,255,0);

void setup()
{

            const char *ssid = "WiFi_ssid";      //This is your wifi SSID
            const char *password = "your password";   //This is your password
            
            //Starting for  serial output
            Serial.begin(115200);
            Serial.println();

            Serial.print("Starting  WiFI hotspot");            
            Serial.println( WiFi.softAPConfig(local_IP,  gateway, subnet) ? "Ready" : "Failed!");  //Starting wifi AP with ipaddress and gateway 

            Serial.print("Setting soft-AP ... ");
            Serial.println(WiFi.softAP(ssid) ? "Ready" : "Failed!");   //Setting Wifi SSID

            Serial.print("IP address = ");
            Serial.println(WiFi.softAPIP());  //Printing ipadress
}
void loop() {


}