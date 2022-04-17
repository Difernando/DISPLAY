# DISPLAY
This repository is to use a 7-segment display with a maximum of 4 digits on the Arduino plate  through Atmel Studio, please use the README to understand the configuration and remember this library it's just for the Cathode Comun model.


## INCLUDE
To use this library in your project you need copy the library items **DISPLAY.C** and **DISPLAY.H** in your project and use the code line **#include "DISPLAY.h"** 
before your code, use the next items to active the ussage and the display ports
### INICIALIZATION 
Below the main() code line use **DISP_init();** to active the lines where the displays are connected, the Pin's are PortC Register bits 0 - 3 to give the 
power of the displays, and the PortB register for the differents segments in the display 7Segments so tha's it the bits 0 - 7, be carefull with it to avoid 
errors in your code if you need to use those Registers
### USSAGE
To show the numbers (remember maximun 4 digits numbers) in the display use **DISP_SHOW(H);** changing the **H** char for your number or variable, you can use 
number type float or number type int, the system can select automatically the decimal point position according the number structure
