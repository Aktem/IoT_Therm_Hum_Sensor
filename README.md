# _IOT Thermometer and Humidity Sensor_

This project uses an ESP32 development board, RGB LED, and a DHT22 humidity sensor to create an IOT device that supports WiFi in Access Point and Station modes, an HTTP Server which is used to display sensor information as well as interact with the user in other ways, allows for OTA firmware updates, and has synchronised timing using SNTP. The RGB LED is used to indicate the status of the server and wifi connection as it is not possible to display their status through the server when either of them is working improperly.

