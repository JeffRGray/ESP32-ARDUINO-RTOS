# ESP32-ARDUINO-RTOS
ESP32 with FreeRTOS functions, running .INO code and .CPP code under Visual Studio
*example from: https://techtutorialsx.com/2017/05/06/esp32-arduino-creating-a-task/
I am currently programming in the Visual Studio environment (with VisualGDB added to support the ESP32). The problem is, there are much fewer examples of working code/libraries for modules such as temp/humidity (BME280) RTC (DS3231), RFID, etc. in the .C and .CPP world. I have been “spoiled” by all of the support and .ino code that is out there.
The problem is, the Arduino IDE is not very easy to use with more complex projects – I need better tools, even if I have to pay for them.
So the solution I am currently pursuing is to use VisualMicro inside Visual Studio. This allows me to import .ino files and use libraries such as wire.h, arduino.h, etc. I compiled the example above (I already had FreeRTOS installed) and it ran, first time, with no errors.
So it seems that now I have the best of all worlds – Arduino code and libraries, a solid development environment, the ability to write my own functions in CPP for my custom stuff, RTOS, and the ESP32.


since this is .ino code, it is not necessary to have all the #includes such as freertos.h
This version creates two tasks in the .ino code, and defines one additional task in blink.cpp
(don't forget to declare the function prototypes in the header file).  Note that the function
blink() causes the words "blink-blink" to be printed, in addition to initiating the task to 
blink the LED.  The task is initited once, but it keeps running until it is stopped (as it is
with the "Hello..." tasks which run 10 times then are stopped.  Since blink_task is not stopped, 
it will continue to blink the LED.
Note that by assigning a higher priority number to a task, you will guarentee which task runs 
first.  When taskOne and taskTwo are both priority 1, then sometimes they run out of order.
This file was initiated by vmicro/create blank arduino project.*

The ESP32 board I used is from banggood.com, ESP32 DEVKIT V1, supposedly from doit.am  Note that doit has two different versions of this board, one with 2 x 15 pins (the one I used) and one with 2 x 18 pins.  Any ESP32 board should work OK, just check the GPIO pin that is connected to the on-board LED (mine is GPIO2)
