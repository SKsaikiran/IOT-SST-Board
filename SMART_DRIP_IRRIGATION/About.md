# SMART DRIP IRRIGATION

 
 Here in this program where we have interfaced  **Esp8266** with a sensor  Soil Moisture sensor to develop a **Smart Drip Irrigation** process .The above program is to perform some task like reading soil moisture value to automatically turn on a water pump . The all the data will be displayed **BLYNK Application** in real time .

## Functionally of Sensor
 - ### Soil moisture Sensor 
 This sensor is used to read the Soil moisture of the land if the data(value) is less then certain value it initiate motor to turn ON so the required amount of water is supplied .The data will be displayed in Blynk application in real time where we can remotely monitor the status of the motor as well as the abstract values of moisture level in soil.

## Advantages

- ### Save Water And Money 
Smart Drip irrigation systems deliver exactly the amount of water that is needed. This helps keep plants and lawns healthy and beautiful.
- ### Long Term Enhanced Landscape Health 
Smart irrigation controllers can be adjusted to water yards and plants the exact amount of water needed so they can thrive.
- ### Can be monitor anytime
The Soil moisture data will be send to the cloud in real time, so by the Blynk application one can monitor the required data at any time at any place.

## Components used - 
ESP8266 , Soil moisture sensor , Relay , 5v water pump , Jump wires . 

### Pin Description
| **Sensor** | **GPIO PIN DESCRIPTION** |
|:----:|:----:|
|Soil moisture| A0|
|water pump |D2|
#### Note : Connect the ground and vcc of the sensor pin to the A0 and GND of ESP8266 correspondingly .
