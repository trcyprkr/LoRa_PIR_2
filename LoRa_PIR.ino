/* 1byte LORa SX1278 TRANSMITTER example.
  /* Tutorial link: http://electronoobs.com/eng_arduino_tut97.php
   Code: http://electronoobs.com/eng_arduino_tut97_code1.php
   Scheamtic: http://electronoobs.com/eng_arduino_tut97_sch1.php
   Youtube Channel: http://www.youtube/c/electronoobs

  Module SX1278 // Arduino UNO/NANO
    GND         ->   GND
    Vcc         ->   3.3V
    MISO        ->   D12
    MOSI        ->   D11
    SLCK        ->   D13
    Nss         ->   D10
    Di00        ->   D2
    RST         ->   D9
*/
#include <SPI.h>
#include <LoRa.h> //Download here: http://electronoobs.com/eng_arduino_LoRa_SX1278.php.php
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int pir = 4;
int LEDPIN = LED_BUILTIN;
int counter = 0;


void setup() {
  Serial.begin(9600);
  pinMode(pir, INPUT);
  pinMode(LEDPIN, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
    display.clearDisplay();

    delay(2000);

  }
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 14);
    while (!Serial);
    Serial.println("LoRa Ready");
    display.print("LoRa Ready");
    display.display();
    delay(1000);
    display.clearDisplay();
    if (!LoRa.begin(914E6)) { // or 914E6, the MHz speed of yout module
      Serial.println("Starting LoRa failed!");

      display.setTextColor(WHITE);
      display.setCursor(0, 14);
      display.print("Starting LoRa failed!");
      display.display();
      delay(1000);
      display.clearDisplay();
      
      while (1);
      // LoRa.setSpreadingFactor(12);
    }
}
    
void loop() {
    Serial.print("Sending packet: ");
    
    display.setTextColor(WHITE);
    display.setCursor(0, 14);
    display.print("Sending packet: ");
    display.println(counter);
    display.display();
    delay(1000);
    display.clearDisplay();
    
    Serial.println(counter);
    //int pirstate = digitalRead(4);
    // if (pirstate == HIGH) {
    digitalWrite(LEDPIN, HIGH);
    //int val = map(analogRead(pot),0,1024,0,255);
    LoRa.beginPacket();
    Serial.println("Sending");

    //display.setTextColor(WHITE);
    //display.setCursor(0, 14);
    //display.print("Sending");
    //display.display();
    //delay(1000);
    //display.clearDisplay();

    display.setTextColor(WHITE);
    display.setCursor(64, 14);
    //display.print(counter);
    display.display();
    //delay(1000);
    display.clearDisplay();

    LoRa.print("Message: ");
    LoRa.println("Parker ");
    Serial.print("Message: ");
    Serial.println("Parker ");
    
    display.setTextColor(WHITE);
    display.setCursor(0, 14);
    display.print("Message: ");
    display.println("Parker ");
    display.display();
    delay(1000);
    display.clearDisplay();
    
    LoRa.print(counter);
    LoRa.endPacket();
    Serial.println("Done");
    
    display.setTextColor(WHITE);
    display.setCursor(0, 14);
    display.print("Done");
    display.display();
    display.clearDisplay();
    counter++;

    //      Serial.println(spreadingFactor());
    delay(2000);
    //  }
}
 
