# LED Effects using "bitRead"
An example of how to use an array of up to 16 LEDs with single dimentioned effect arrays.</br>

The sketch uses a single 25mS loop duty-cycle and any longer durations are created with counter variables. This makes the sketch architecture non-blocking. 

The sketch is broken down into 4 files for easier editing:</br>

|File                         |Comment                                                   |
|:----------------------------|:---------------------------------------------------------|
|LED_EFX_using_bitRead.ino|Contains all the setups and the main loop.|
|patterns.h               |Contains the pattern arrays.|
|effect_loops.h           |Contains the pattern voids called from the switching.|
|switching.h              |Contains timing variables for the different patterns|

## Getting the HEX value for a binary state
Remember that the binary value is read right to left in relation to your LED array

![image](https://user-images.githubusercontent.com/20883620/133911114-3fb29072-572e-465c-b411-837da96a4bbe.png)

## Wiring example
Any Arduino compatible device with 16 digital ports will work and it's 18 ports if you want the buttons 

![image](https://user-images.githubusercontent.com/20883620/133911306-9f366139-a398-4e7e-993c-ec35f2e0ca13.png)

## Video of Sequence
[![Watch the video](https://img.youtube.com/vi/0hlVcpQEBLA/0.jpg)](https://youtu.be/0hlVcpQEBLA)
