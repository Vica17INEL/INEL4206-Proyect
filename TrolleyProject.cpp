#include <Wifi.h>
#include "PubSubClient.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <driver/gpio.h>
#include <string.h>

#define MONITORWIFI_PERIOD 5000
#define MYTASK_PERIOD 2000
#define STARTUP_DELAY 3000
#define LED_GPIO GPIO_NUM_2
#define ON 1


const char *mqttServer = "34.199.250.106";
const char *topic = "testing";
const int mqttPort = 1883;
const char *mqtt_username = "FFF";
const char *mqtt_password = "0123456789";

QueueHandle_t publish_queue;
WiFiClient espClient;
PubSubClient client(espClient);

void callback (char* topic, byte* payload, unsigned int length) { };

void initWiFi() {

const char* ssid = "Fernando";
const char* password = "Fernando";

WiFi.mode(WIFI_STA);
WiFi.begin(ssid, password);
 
 pinMode(LED_GPIO, GPIO_MODE_OUTPUT);
 digitalWrite(LED_GPIO, ON);

while (WiFi.status() != WL_CONNECTED) {

Serial.print(".");

delay(1000);

}

Serial.println(WiFi.localIP());

}

void connectToBroker()
{
client.setServer(mqttServer, mqttPort);
client.setCallback(callback);
while (!client.connected())
{
String client_id = "esp32-client-";
client_id += String(WiFi.macAddress());
Serial.printf("The client is connected\n", client_id.c_str());
if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
Serial.println("Connected");
} else {
Serial.print("Not connected");
Serial.print(client.state());
delay(2000);
}
}
client.publish(topic, "Localizing your trolley, please wait");
client.subscribe(topic);

}

void monitor_wifi_task(void *p) {

int n;

while(1) {

//WiFi.disconnect();

//delay(100);

n = WiFi.scanNetworks();

Serial.println("scan done");

if (n == 0) {

Serial.println("no networks found");

} else {

Serial.print(n);

Serial.println(" networks found");

for (int i = 0; i < n; ++i) {

// Print SSID for each network found

Serial.print(i + 1);

Serial.print(": ");

Serial.println(WiFi.SSID(i));

delay(10);


String st = "Stefani Building";
String sh = "Chardome";
String si = "RUMNET";

if((WiFi.SSID(i-1) ==  st)){
Serial.println("Your trolley in Stephanie");
client.setServer(mqttServer, mqttPort);
client.setCallback(callback);
client.publish(topic, "Your trolley in Stephanie");
client.subscribe(topic);
break;
}

else if(WiFi.SSID(i-1) == sh){
Serial.println("Your trolley is in Chardome");
client.setServer(mqttServer, mqttPort);
client.setCallback(callback);
client.publish(topic, "Your trolley is in Chardome");
client.subscribe(topic);
break;
}

else if(WiFi.SSID(i-1) == si){
Serial.println("Your trolley is in Lucchetti");
client.setServer(mqttServer, mqttPort);
client.setCallback(callback);
client.publish(topic, "Your trolley is in Lucchetti");
client.subscribe(topic);
break;
}
else{
Serial.println("No location found");
client.setServer(mqttServer, mqttPort);
client.setCallback(callback);
client.publish(topic, "Your trolley was not found");
client.subscribe(topic);

}

}

}
Serial.println("");

xQueueSend(publish_queue, &n, (TickType_t) 0);

//WiFi.reconnect();

vTaskDelay(MONITORWIFI_PERIOD / portTICK_PERIOD_MS);

}

}

void my_task(void *p) {

int n;

while (1) {

if ( xQueueReceive(publish_queue, &n, (TickType_t) 0) == pdTRUE ) {

Serial.print("In my task got the message that we discovered this number of hotspots: ");

Serial.println(n);

}

vTaskDelay(MYTASK_PERIOD / portTICK_PERIOD_MS);

}

}

int main(){

// Initialize serial port

Serial.begin(115200);

// Small Delay so that we don't miss the first few items printed

vTaskDelay(STARTUP_DELAY / portTICK_PERIOD_MS);

// Initialize WiFi and Connection to MQTT Broker

Serial.println("Localizing your trolley, please wait");

initWiFi();
connectToBroker();

Serial.println("Starting All Tasks");

// Create a task that monitors the WiFi hotspots

xTaskCreate(&monitor_wifi_task, "monitor_wifi_task", 2048,NULL,5,NULL );

// Start Task and a Queue that will receive the events from the wifi monitoring

publish_queue = xQueueCreate(10, sizeof(int));
xTaskCreate(&my_task, "my_task", 2048,NULL,5,NULL );

}

void setup() { main(); }

void loop(){}
