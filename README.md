# ESP32_alarm
Using an ESP32 Lolin dev board to build an intruder alarm

## Hardware  
The hardware list of the components used for this project is given here, but you are free to use yours :  
- Core :
  - ESP32 Lolin OLED board (the OLED display is not needed here) : https://www.ebay.fr/itm/ESP32-S-WiFi-Bluetooth-Development-Board-0-96-OLED-Display-WROOM-32-NodeMCU/253059863624?ssPageName=STRK%3AMEBIDX%3AIT&_trksid=p2060353.m2749.l2649
  - Power bank (with connection wire of course): https://www.amazon.fr/POWERADD-EnergyCell-Batterie-Portable-Secour-Noir/dp/B07MQ4HY3H/ref=sr_1_19?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=3MTUK487S0MNE&keywords=batterie+externe&qid=1572102990&sprefix=batt%2Caps%2C226&sr=8-19
  - Door opening sensor : https://www.amazon.fr/gp/product/B00VQ3K34S/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1
  - Wires : https://www.amazon.fr/gp/product/B07FM7RRKH/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1
- Optionnal :
  - Breadboard : https://www.amazon.fr/SODIAL-Breadboard-dExperimentation-Soudure-Solderless/dp/B00JGFDKBQ/ref=sr_1_15?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&keywords=breadbord&qid=1572103636&sr=8-15
  - Buzzer Alarm : https://www.amazon.fr/gp/product/B07X4672TD/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1

## Software
This project is mainly based on the IFTTT website, specially designed to provide may ways to handle IoT connections. Here are the instructions about the software setup:

- Arduino IDE
  - Download and install the Arduino IDE
  - Add the ESP32 Lolin board to the IDE:
    - Add the link: https://dl.espressif.com/dl/package_esp32_index.json via File>Preferences>Additional Boards Manager URLs
    - Download and install the ESP32 board files via Tools>Board:>Boards Manager...> search for "esp32 by Espressif Systems"
    - Select the Wemos Lolin32 library via Tools>Board:>Wemos Lolin32
  - Select your USB com port via Tools>Port:

- IFTTT sevice
  - Create your account on https://ifttt.com
  - Subscribe to the Messenger Service via My Applets>Search: and link your Messenger account
  - Subscribe to the Webhooks service My Applets>Search:
  - Create your Applet via Create and link the two previous sevices between them. Make sure to give the same rising event names between your webhook service and your applet.

## Power consumption

The ESP32 has 6 différent states :
- Active mode : 160~260mA
- Modem sleep mode : 3~20mA
- Light sleep mode : 0.8mA
- Deep sleep mode : 10µA
- Hibernation mode : 2.5µA\
Source : https://lastminuteengineers.com/esp32-sleep-modes-power-consumption/

Here we will use the active and deep sleep modes in order to save as much power as possible, which can theoretically reach an average 7 month lifetime with the hardware I advised to use. After that, the battery will have to be recharged.

