# INEL4206-Project

#Introduction
	The project consists of having an ESP32 that can locate the position of a trolley constantly while publishing that information in the cloud.
1.	Create a code that permits the ESP32 to locate a trolley.
2.	Connect the ESP32 to Wi-Fi using the Wi-Fi library functions and pubsubclient.
3.	Create an online cloud server.
4.	Create the keys for the server to control the cloud server.
5.	Install Node-red using our machine through AWS.
6.	Use Node-red to create a workflow that receives the information via aedes MQTT and upload the information to the server.
7.	Create an interface using the dashboard nodes and dashboard option on Node-red.
8.	Create a shortcut in our smartphone to access the Node-red dashboard by voice commands.

##Software needed:
1.	GitHub
2.	Visual studio code (CH340 drivers, Platform IO and C/C++ compilers)
3.	Node-red
4.	Ubuntu
5.	Aedes MQTT

##Needed materials:
1.	EP32 microcontroller
2.	Breadboard
3.	USB 2.0 – USB mini cable
4.	Light Emitter Diode (LED)
5.	Resistor
6.	Batterie holder
7.	Two 1.5v batteries
8.	Connecting cables

##Instructions:
*	Start
Before starting the project, you need to have completed all the requirements:
-	Have the ESP32 microcontroller with all the materials needed.
-	Have VS code with the PlatformIO extension installed.
-	Completed code.
-	Node-red flow and dashboard.
-	Smartphone shortcut.
-	WI-FI hotspot.
-	AWS server.

•	How to upload the code to the cloud
	Create a code that allows us to connect the ESP32 to the Wi-Fi to constantly receive trolley’s location.
	Connect the ESP32 to Wi-Fi.
	Create a server in the cloud.
-	Must create an AWS account and buy a remote machine.
-	Must create an Ubuntu to add the IP address that’s going to be used.

	Create the safety keys.
-	This is going to allow you to control the server with your computer.
	Enter the server through your computer.
-	Once you manage to get access you can start to download node-red.
-	Download the admins packs that come with node-red.
-	Open node-red in your browser utilizing 34.199.250.106:1880.
	Open node red.
-	Once it’s open, create a flow that uses the aedes MQTT broker to receive the data collected by the ESP32.
	Modify your code.
-	add the pubsubclient library in your code so you can connect to the MQTT broker.
•	Running the code
	Build and upload the code to the ESP32 by connecting the device to your computer using the USB to USB mini cable.
	Activate the shortcut in your smartphone to get the outputs, in our case we activate our shortcut by asking to our apple smartphone “Hey Siri, Where is my Trolley?”.
Powering our ESP32
	For an independent power supply to our device (ESP32) we used a Batterie holder with two 1.5v batteries to feed our circuit.

Results:
the code worked as expect identifying the strongest WI-FI connection as the location of the trolley, the trolley being represented as the ESP32 and sending that data to the cloud server. Publishing that data on the Node-red dashboard for easy access.

}
