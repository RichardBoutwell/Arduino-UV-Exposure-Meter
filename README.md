# UV Exposure Calculator

## A simple Arduino Uno-Based LCD UV Exposure Meter for Alternative Process Printing

This exposure meter uses the VEML6070 UV Sensor and 16x2 Liquid Crystal Display to show the current UV value and increment the total accumulated exposure.


The sensor records the current luminance up to 2 to 16 times per second and is set to higher accuracy wtih VEML6070_4_T in the setup function. There is an additional smoothing simple average of every two samples to display more consistent readings.

To prevent errors with integer overflow durring higher exposures, the display shows a scaled version of the current and total exposure.

The current exposure is the raw sensor output / 4
The scaled accumulated exposure on the display is the total exposure  + current exposure / 1024


### Required Libraries

- https://github.com/adafruit/Adafruit_VEML6070
- https://www.arduino.cc/reference/en/libraries/liquidcrystal/
- https://www.arduino.cc/reference/en/language/functions/communication/wire/

### Links to learn more and purchase supplies

- https://amzn.to/3zCev5x
- https://amzn.to/3xI0Lom
- https://amzn.to/3zCev5x
- https://amzn.to/3MLzSnX
- https://amzn.to/3aQmGRg
