#include <FirebaseESP32.h>
#include <WiFi.h>
FirebaseData firebaseData;
const char* ssid = "Jessika";
const char* password = "Jessika123";
#define led 2
String numero = "";

void setup() {
Serial.begin(115200);
delay(10);
Serial.println();
Serial.print("Connecting with ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}

pinMode(led, OUTPUT);
Serial.println("");
Serial.print("WiFi conected. IP: ");
Serial.println(WiFi.localIP());
Firebase.begin("https://pruebaand12-default-rtdb.firebaseio.com/", "cQqbFYmw1NC3QC965vskO7uVSxT1zGRFmmHpLgCQ");
}
void loop() {
if (Firebase.getString(firebaseData, "/Fire1Pri/Test/LED")) {  
String numero_fb = firebaseData.stringData();           
             
if(numero_fb == "1"){
  digitalWrite(led,HIGH);
  Serial.println("Encendido");
}
else{
  digitalWrite(led,LOW);
  Serial.println("Apagado");
}
delay(500);
}

}
