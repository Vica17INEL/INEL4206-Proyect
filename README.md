# INEL4206-Project (Where is my Trolley?)

# Introduction:

The project consists of having an ESP32 that's capacle of locating the position of a trolley constantly while publishing that information in the cloud.

## Project Step by Step	
1.	Create a code that permits the ESP32 to locate a trolley.
2.	Connect the ESP32 to Wi-Fi using the Wi-Fi library functions and pubsubclient.
3.	Create an online cloud server.
4.	Create the keys for the server to control the cloud server.
5.	Install Node-red using our machine through AWS.
6.	Use Node-red to create a workflow that receives the information via aedes MQTT and upload the information to the server.
7.	Create an interface using the dashboard nodes and dashboard option on Node-red.
8.	Create a shortcut in our smartphone to access the Node-red dashboard by voice commands.

## Software needs:
-	GitHub
-	Visual studio code (CH340 drivers, Platform IO and C/C++ compilers)
-	Node-red
-	Ubuntu
-	Aedes MQTT

## Needed materials:
-	EP32 microcontroller
-	Breadboard
-	USB 2.0 – USB mini cable
-	Light Emitter Diode (LED)
-	Resistor
-	Batterie holder
-	Two 1.5v batteries
-	Connecting cables

## Instructions:
### Start
Before starting the project, you need to have completed all the requirements:
-	Have the ESP32 microcontroller with all the materials needed.
-	Have VS code with the PlatformIO extension installed.
-	Completed code.
-	Node-red flow and dashboard.
-	Smartphone shortcut.
-	WI-FI hotspot.
-	AWS server.

### How to upload the code to the cloud
1. Create a code that allows us to connect the ESP32 to a Wi-Fi network, this will allow us to constantly receive the trolley’s location.
2. Connect the ESP32 to Wi-Fi.
   -  We use a light emitter diode (LED) to confirm that the ESP32 has stablish the connection to the WI-FI, as shown below:

![Wifi connection](https://github.com/Vica17INEL/INEL4206-Proyect/blob/main/WIFI_Connected.jpg)

4. Create a server in the cloud:
   -  Must create an AWS account and buy a remote machine.
   -  Must create an Ubuntu to add the IP address that’s going to be used.

### Create the safety keys
This is going to allow you to control the server with your computer.
-	Enter the server through your computer.
-  Assign a Public IP to our server.
-  Use PuTTYgen to create a public and private key.
-  Add this keys to our Linux cloud host.

## Powering our ESP32

For an independent power supply to our device (ESP32) we used a Batterie holder with two 1.5v batteries to feed our circuit:

1. Insert the two 1.5v batteries in the batterie holder, be sure you are placing the batteries with the correct polarities.
2. Connect two connecting cables, one on each side of the baterrie holder connector.
   -  The red side of the connector has to be connected to the 3.3v pin on the ESP32.
   -  The black side of the connector has to be connected to the GND pin on the ESP32.
4. Has soon as the 2 pins are connected to the batterie holder a green light on the ESP32 will turn on indicating the ESP32 has power.

![](https://github.com/Vica17INEL/INEL4206-Proyect/blob/main/PowerSupply_Connection.jpg)


## Results:
The code worked as expect identifying the strongest WI-FI connection as the location of the trolley, the trolley being represented as the ESP32 and sending that data to the cloud server. Publishing that data on the Node-red dashboard for easy access.
