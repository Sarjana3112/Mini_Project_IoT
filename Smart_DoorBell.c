#define BLYNK_TEMPLATE_ID "TMPL37veM9Dju" 
#define BLYNK_TEMPLATE_NAME "Door bell" 
#define BLYNK_AUTH_TOKEN "aCe81V_Ol6zIdeYQVRnBaDNAjUXKIaNR" 
#include <BlynkSimpleEsp8266.h> 
#define IR_SENSOR 4  // IR sensor connected to digital pin D2 
#define BUZZER 5     
 // Buzzer connected to digital pin D1 
char ssid[] = "WIN-2D50D5N302S 3633"; 
char pass[] = "12345678"; 
const int LED_PIN= 2; 
void setup() { 
pinMode(IR_SENSOR, INPUT); 
pinMode(BUZZER, OUTPUT); 
Serial.begin(9600); 
WiFi.setSleepMode(WIFI_NONE_SLEEP); 
// Attempt Wi-Fi connection until successful 
Serial.print("Connecting to Wi-Fi"); 
WiFi.begin(ssid, pass); 
int attempt = 0; 
while (WiFi.status() != WL_CONNECTED) { 
for (int i = 0; i < 5; i++) { 
digitalWrite(LED_PIN, LOW); 
delay(250); 
digitalWrite(LED_PIN, HIGH); 
delay(250); 
Serial.print("."); 
} 
attempt++; 
if (attempt > 10) { // Give up after 10 attempts 
} 
Serial.println("\nWi-Fi connected ✅"); 
Serial.println("\nFailed to connect to Wi-Fi ❌"); 
return; 
} 
 Smart Door Bell  
 
    Serial.print("IP Address: "); 
    Serial.println(WiFi.localIP()); 
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); 
} 
void loop() { 
     Blynk.run(); 
    int sensorValue = digitalRead(IR_SENSOR); // Read IR sensor output 
    if (sensorValue == LOW) {  // Object detected (IR sensors usually return LOW when 
blocked) 
        Serial.println("Motion Detected! Playing Buzzer Tone..."); 
        Blynk.logEvent( 
        "door_surveillance", 
        "🚪 Visitor detected at Smart Door" 
        ); 
        playMelody(); // Play a nice doorbell tone 
        delay(1000); // Small delay before detecting again 
    } 
} 
// Function to play a simple doorbell melody 
void playMelody() { 
    tone(BUZZER, 1000, 200); // Play 1000Hz for 200ms 
    delay(250); 
    tone(BUZZER, 1200, 200); // Play 1200Hz for 200ms 
    delay(250); 
    tone(BUZZER, 1400, 300); // Play 1400Hz for 300ms 
    delay(350); 
    noTone(BUZZER); // Stop buzzer 
}