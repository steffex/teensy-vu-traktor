# Teensy MIDI VU-meter

Use a Teensy with a NeoPixel strip as a VU-meter for Native Instruments Traktor or any other MIDI compatible DJ software.

## Requirements
- Teensy 2.0 (and required [Teensyduino](https://www.pjrc.com/teensy/teensyduino.html) stuff)
- [Adafruit NeoPixel Stick](https://www.adafruit.com/products/1426)
- [NeoPixel library](https://github.com/adafruit/Adafruit_NeoPixel) installed in your Arduino IDE

## Wiring
Use a [basic wiring diagram](https://learn.adafruit.com/adafruit-neopixel-uberguide/basic-connections) from Adafruit to connect the NeoPixel Stick.

## Teensy configuration
Turn serial debugging on(1) or off(0):
```
#define DEBUG 0
```

The pin on the Teensy used to communicate with the NeoPixels (default D1 or 6):
```
#define DATAPIN 6
```

The amount of Pixels in the NeoPixel Stick (should be 8):
```
#define PIXELSIZE 8
```

The Pixel brightness, default library value is way to bright (I recommend nothing larger than 64).
```
#define BRIGHTNESS 32
```

The colors used for the different pixels:
```
uint32_t offColor = pixels.Color(0, 0, 0); // used to turn of a pixel
uint32_t greenColor = pixels.Color(0, 255, 0);
uint32_t yellowColor = pixels.Color(255, 128, 0);
uint32_t redColor = pixels.Color(255, 0, 0);
uint32_t blueColor = pixels.Color(0, 128, 253); // for an alternative vu color
```

## Teensy settings
Use the following settings for the Teensy inside the Arduino IDE:

![teensy settings](https://raw.githubusercontent.com/steffex/teensy-vu-traktor/master/assets/teensy_settings.png)

## Traktor setup
Open up the controller mappings and create a new **Generic MIDI** mapping:

![generic midi](https://raw.githubusercontent.com/steffex/teensy-vu-traktor/master/assets/generic_midi.png)

Set the output device to the Teensy (it must be up and running at this point):

![output device](https://raw.githubusercontent.com/steffex/teensy-vu-traktor/master/assets/output_device.png)

Set the device target to **deck A**:

![device target](https://raw.githubusercontent.com/steffex/teensy-vu-traktor/master/assets/device_target.png)

Add a out mapping and select the **deck pre-fader level (l+r)**:

![out button](https://raw.githubusercontent.com/steffex/teensy-vu-traktor/master/assets/out.png)
![out type](https://raw.githubusercontent.com/steffex/teensy-vu-traktor/master/assets/out_type.png)

Add a MIDI note on a desired channel that won't conflict with your other mappings:

![add note](https://raw.githubusercontent.com/steffex/teensy-vu-traktor/master/assets/device_mapping.png)


## TODO
- [ ] Configurable MIDI channel
- [ ] 1 MIDI note per pixel
- [ ] Configurable color settings
- [ ] Allow for larger or lesser amount of NeoPixels
- [ ] Optimize code
