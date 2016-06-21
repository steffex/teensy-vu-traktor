#include <Adafruit_NeoPixel.h>

#define DEBUG 0
#define DATAPIN 6
#define PIXELSIZE 8
#define BRIGHTNESS 32

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXELSIZE, DATAPIN, NEO_GRB + NEO_KHZ800);

uint32_t offColor = pixels.Color(0, 0, 0);
uint32_t greenColor = pixels.Color(0, 255, 0);
uint32_t yellowColor = pixels.Color(255, 128, 0);
uint32_t redColor = pixels.Color(255, 0, 0);
uint32_t blueColor = pixels.Color(0, 128, 253);

void setup() {
  if (DEBUG) {
    Serial.begin(115200);
  }
  usbMIDI.setHandleNoteOff(OnNoteOff);
  usbMIDI.setHandleNoteOn(OnNoteOn);
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);
  pixels.show();
}

void loop() {
  usbMIDI.read(); // USB MIDI receive
}


void OnNoteOn(byte channel, byte note, byte velocity) {
  setPixels(String(velocity, DEC));
  if (DEBUG) {
    Serial.print("Note On, ch=");
    Serial.print(channel, DEC);
    Serial.print(", note=");
    Serial.print(note, DEC);
    Serial.print(", velocity=");
    Serial.print(velocity, DEC);
    Serial.println();
  }
}

void OnNoteOff(byte channel, byte note, byte velocity) {
  if (DEBUG) {
    Serial.print("Note Off, ch=");
    Serial.print(channel, DEC);
    Serial.print(", note=");
    Serial.print(note, DEC);
    Serial.print(", velocity=");
    Serial.print(velocity, DEC);
    Serial.println();
  }
}

void setPixels(String value) {
  int velocity = value.toInt();
  noPixels();
  
  if (velocity > 16) {
//    pixels.setPixelColor(0, greenColor);
    pixels.setPixelColor(0, blueColor);
  }
  if (velocity > 32) {
//    pixels.setPixelColor(1, greenColor);
    pixels.setPixelColor(1, blueColor);
  }
  if (velocity > 48) {
//    pixels.setPixelColor(2, greenColor);
    pixels.setPixelColor(2, blueColor);
  }
  if (velocity > 64) {
//    pixels.setPixelColor(3, yellowColor);
    pixels.setPixelColor(3, blueColor);
  }
  if (velocity > 80) {
//    pixels.setPixelColor(4, yellowColor);
    pixels.setPixelColor(4, blueColor);
  }
  if (velocity > 96) {
//    pixels.setPixelColor(5, yellowColor);
    pixels.setPixelColor(5, blueColor);
  }
  if (velocity > 112) {
    pixels.setPixelColor(6, redColor);
  }
  if (velocity >= 122) {
    pixels.setPixelColor(7, redColor);
  }
  pixels.show();
}

void noPixels()
{
  for (int i=0; i<PIXELSIZE; i++) {
    pixels.setPixelColor(i, offColor);
  }
  pixels.show();
}

