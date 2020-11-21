#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int button = 2;
int t = 2, f, timeON = 0, second = 0, Minutes = 0, Hours = 0, minutes = 0, hours = 0;
int buttonState = 1;
const int ledgreen = 13;
int tx = 1;
int rx = 0;
char inSerial[15];
void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();

  pinMode(ledgreen, OUTPUT);
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
}

void loop() {
  if (timeON == 0) {
    f = t % 2;
    Serial.println("YO!!!");
    buttonState = 1;
    if (f == 0)
    {
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(21, 19);
      display.println("AM");
    }
    else
    {
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(21, 19);
      display.println("PM");
    }
    if (second >= 1200)
    {
      second = 0;
      minutes++;


    }
    if (minutes >= 10)
    {
      minutes = 0;
      Minutes++;
    }
    if (Minutes >= 6)
    {
      second = 0;
      minutes = 0;
      Minutes = 0;
      hours++;
    }
    if (hours >= 10)
    {
      second = 0;
      minutes = 0;
      hours = 0;
      Hours++;
    }
    if (Hours >= 1)
    {
      if (hours >= 3)
      {
        second = 0;
        minutes = 0;
        hours = 1;
        Hours = 0;
        t++;
      }
    }
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(18, 29);
    display.println(Hours);
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(35, 29);
    display.println(hours);
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(52, 29);
    display.println(":");
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(69, 29);
    display.println(Minutes);
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(88, 29);
    display.println(minutes);
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 29);
    display.println("INCOMING CALL.. ");
    if (buttonState == '1')
    {
      delay(1000);
      buttonState = Serial.read();
      Serial.print(buttonState);
      if (buttonState == '2')
      {
        Minutes++;
      }
      else
      {
        minutes++;
      }
    }
    else
    {
      second++;
    }
    display.clearDisplay();
  }
  else
  {
    delay(200);
  }
  digitalWrite(ledgreen, LOW);
  int i = 0;
  int m = 0;
  if (Serial.available() > 0) {
    while (Serial.available() > 0) {
      inSerial[i] = Serial.read();
      i++;
    }
    inSerial[i] = '\0';
    Check_Protocol(inSerial);
  }
}
void Check_Protocol(char inStr[]) {
  int i = 0;
  int m = 0;
  Serial.println(inStr);
  if (!strcmp(inStr, "newSMS")) { //Led on
    digitalWrite(ledgreen, HIGH);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("NEW MESSAGE   ");
    delay(600);
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("NEW MESSAGE.  ");
    delay(600);
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("NEW MESSAGE.. ");
    delay(600);
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("NEW MESSAGE...");
    delay(600);
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("NEW MESSAGE.. ");
    delay(1000);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("NEW MESSAGE   ");
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("NEW MESSAGE.  ");
    delay(600);
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("NEW MESSAGE.. ");
    delay(600);
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("NEW MESSAGE...");
    delay(600);
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("");
    delay(1500);
    display.clearDisplay();
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("");
    display.clearDisplay();
  }
  if (!strcmp(inStr, "newCALL")) {
    digitalWrite(ledgreen, HIGH);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("INCOMING CALL   ");
    delay(600);
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("INCOMING CALL.  ");
    delay(600);
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("INCOMING CALL.. ");
    delay(600);
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("INCOMING CALL...");
    delay(600);
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("INCOMING CALL.. ");
    delay(1000);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("INCOMING CALL   ");
    delay(600);
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("INCOMING CALL.  ");
    delay(600);
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("INCOMING CALL.. ");
    delay(600);
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("INCOMING CALL...");
    delay(600);
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("");
    delay(1500);
    display.clearDisplay();
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("");
    display.clearDisplay();
  }
  if (!strcmp(inStr, "timeON")) {
    timeON = 0;
  }
  if (!strcmp(inStr, "timeOFF")) {
    timeON = 1;
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(21, 35);
    display.println("INCOMING CALL.. ");
    display.clearDisplay();
  }
}
