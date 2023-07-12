//#include <ESP8266WiFi.h>
//#include <WiFiClient.h>
//#include <WiFiUdp.h>
//           
//#include <ESP8266HTTPClient.h>
//           
//const char* ssid = "";
//const char* pswd = "";
//           
//WiFiClient client;
//int server_port = 3333;
//           
//void wifi_Setup() {
//  Serial.println("wifiSetup");  
//   WiFi.begin(ssid, pswd);
//           
// while (WiFi.status() != WL_CONNECTED) 
// {
//    Serial.println("trying ...");     
//    delay(200);
// }  
//  Serial.println("Connected to network");
//}
//                      
//String GetData() {
//
//  String ret = "Error";
//  HTTPClient http;
//  String dataURL = "";
// dataURL+=String(data);
//  http.begin(client, "http://.../R/line_R"+ dataURL);
//  int httpCode = http.GET();
//  Serial.println(httpCode);
//  if (httpCode == HTTP_CODE_OK) {
//      Serial.print("HTTP response code ");
//      Serial.println(httpCode);
//      String Res = http.getString();
//      Serial.println(Res);
//      ret = Res;
//    }
//      http.end();
//           
//   return ret;
//}
//           
