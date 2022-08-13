# Install the ESP8266 board support package in Arduino IDE
### Installing with Boards Manager

Starting with 1.6.4, Arduino allows installation of third-party platform packages using Boards Manager. We have packages available for Windows, Mac OS, and Linux (32 and 64 bit).

- Install the current upstream Arduino IDE at the 1.8.9 level or later. The current version is on the [Arduino website](https://www.arduino.cc/en/main/software).
- Start Arduino and open the Preferences window.
![Arduino_IDE_File_Menu](https://github.com/SinkuKumar/Blynk_Firebase/raw/main/Assets/Arduino_IDE_File_Menu.png "Arduino_IDE_File_Menu")

- Enter ```https://arduino.esp8266.com/stable/package_esp8266com_index.json``` into the *File>Preferences>Additional Boards Manager URLs* field of the Arduino IDE. You can add multiple URLs, separating them with commas.
![Arduino_IDE_Preferences](https://github.com/SinkuKumar/Blynk_Firebase/raw/main/Assets/Arduino_IDE_Preferences.png "Arduino_IDE_Preferences")
- Click on "OK"
  
- Open Boards Manager from Tools > Board menu
![Arduino_IDE_Tools_Board_Menu](https://github.com/SinkuKumar/Blynk_Firebase/raw/main/Assets/Arduino_IDE_Tools_Board_Menu.png "Arduino_IDE_Tools_Board_Menu")

- And install *esp8266* platform 
![Arduino_IDE_Tools_Board_Manager](https://github.com/SinkuKumar/Blynk_Firebase/raw/main/Assets/Arduino_IDE_Tools_Board_Manager.png "Arduino_IDE_Tools_Board_Manager")

- Once esp8266 board support is installed click on "Close"
![Arduino_IDE_Tools_ESP8266_Installation_Done](https://github.com/SinkuKumar/Blynk_Firebase/raw/main/Assets/Arduino_IDE_Tools_ESP8266_Installation_Done.png "Arduino_IDE_Tools_ESP8266_Installation_Done")

- (And don't forget to select your ESP8266 board from Tools > Board menu after installation).
![Arduino_IDE_ESP8266_Board_Selection](https://github.com/SinkuKumar/Blynk_Firebase/raw/main/Assets/Arduino_IDE_ESP8266_Board_Selection.png "Arduino_IDE_ESP8266_Board_Selection")
