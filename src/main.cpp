#define stopSignal 1000
#define shortSignal 400
#define longSignal 1400
#define LED 11
#include "Arduino.h"
#include <string.h>


// 1=short, 2=long, 0=end
int morseAlphabet[26][5]{
    {1, 2, 0}, // A
    {2, 1, 1, 1, 0},    // B
    {2, 1, 2, 1, 0}, // C
    {2, 1, 1, 0}, // D
    {1, 0}, // E
    {1, 1, 2, 1, 0},    // F
    {2, 2, 1, 0}, // G
    {1, 1, 1, 1, 0}, // H
    {1, 1, 0}, // I
    {1, 2, 2, 2, 0},    // J
    {2, 1, 2, 0}, // K
    {1, 2, 1, 1, 0}, // L
    {2, 2, 0}, // M
    {2, 1, 0},    // N
    {2, 2, 2, 0},    // O
    {1, 2, 2, 1, 0}, // P
    {2, 2, 1, 2, 0}, // Q
    {1, 2, 1, 0}, // R
    {1, 1, 1, 0},    // S
    {2, 0}, // T
    {1, 1, 2, 0}, // U
    {1, 1, 1, 2, 0}, // V
    {1, 2, 2, 0},    // W
    {2, 1, 1, 2, 0}, // X
    {2, 1, 2, 2, 0}, // Y
    {2, 2, 1, 1, 0}, // Z
};

void signal(char MorseChar);

void setup()
{
  Serial.begin(115200);
  Serial.println("Setup started...");
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
}

void loop()
{
  signal('s');
  signal('o');
  signal('s');
  delay(2500);
}

void signal(char MorseChar)
{
  int actualChar = MorseChar - 'a';
  Serial.println(actualChar);

    for (int j = 0; j <= 4; j++){

        switch(morseAlphabet[actualChar][j]) {
            case 0:
            break;
            case 1:
                digitalWrite(LED, HIGH);
                delay(shortSignal);
                digitalWrite(LED, LOW);
                delay(shortSignal);
                break;

            case 2:
                digitalWrite(LED, HIGH);
                delay(longSignal);
                digitalWrite(LED, LOW);
                delay(longSignal);
                break;
            default:
            digitalWrite(LED, LOW);
        }
    }
}