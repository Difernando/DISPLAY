# DISPLAY
This repository is to use a 7-segment display with a maximum of 4 digits on the Arduino plate  through Atmel Studio, please use the README to understand the configuration and remember this library it's just for the Common Cathode model.


## INCLUDE
To use this library in your project you need copy the library items **DISPLAY.C** and **DISPLAY.H** in your project and use the code line **#include "DISPLAY.h"** 
before your code, use the next items to active the ussage and the display ports

### ADD THE EXISTING ITEM
   Right-click in the general folder solution, then select Add, and click 
   on the existing item
    
![Select Add Existing Item](https://user-images.githubusercontent.com/62871064/163727870-93efdc7f-ef82-443c-85d7-3dbdd5eb36a6.png)
    
   Select the items named DISPLAY.c and DISPLAY.h
    
![Select the items in the image](https://user-images.githubusercontent.com/62871064/163727906-994c4fe7-e5f2-4412-90a4-5989812dd165.png)
    
   You can see the archives in you solution explorer and you are ready to use the library

![The Explorer Project](https://user-images.githubusercontent.com/62871064/163727927-82e9a9dd-7513-44c1-8ccf-768866831a92.png)

### INICIALIZATION 
Below the main() code line use **DISP_init();** to active the lines where the displays are connected, the Pin's are PortC Register bits 0 - 3 to give the 
power of the displays, and the PortB register for the differents segments in the display 7Segments so tha's it the bits 0 - 7, be carefull with it to avoid 
errors in your code if you need to use those Registers
### USSAGE
To show the numbers (remember maximun 4 digits numbers) in the display use **DISP_SHOW(H);** changing the **H** char for your number or variable, you can use 
number type float or number type int, the system can select automatically the decimal point position according the number structure

# EXAMPLE
## **Sample 1:** Showing the float type number on the display in Proteus Simulator using the microcontroller Atmega328P

![Four Digits with a Decimal](https://user-images.githubusercontent.com/62871064/163726517-c658cced-766f-42b7-881a-2d4e38cc5dfe.png)
![Four Digits without decimal values](https://user-images.githubusercontent.com/62871064/163726518-a4542f7a-6ac7-4555-ac01-276809ce01d7.png)
![3 Digits and 1 Decimal](https://user-images.githubusercontent.com/62871064/163726514-0f2a0612-d540-4225-8714-8f66e5d77d7e.png)
![2 Digits and 2 Decimals](https://user-images.githubusercontent.com/62871064/163726512-4f46ce5c-911e-4d5a-9be7-bc1fa4393682.png)
![1 Digit and 3 Decimals](https://user-images.githubusercontent.com/62871064/163726522-2a078943-2e02-4b30-9c22-cdb9b982094f.png)
![Just Decimals](https://user-images.githubusercontent.com/62871064/163726520-692bc4d7-259b-40f3-a06f-972ce44b1556.png)

## **Sample 2:** Showing the int type number on the display in Proteus Simulator using the microcontroller Atmega328P

![4 Digits](https://user-images.githubusercontent.com/62871064/163727033-a52d140b-cd75-4029-9169-66c40d8d3a8c.png)
![3 Digits](https://user-images.githubusercontent.com/62871064/163727032-ce1c6cf5-79b5-4920-ac18-f421f1bf6f07.png)
![2 Digits](https://user-images.githubusercontent.com/62871064/163727029-2b4f9487-12e4-4299-aefc-a19edbdda8af.png)
![1 Digit](https://user-images.githubusercontent.com/62871064/163727028-f81eaf4c-9feb-47d6-84f9-347968b62fe1.png)
![Digit 0](https://user-images.githubusercontent.com/62871064/163727027-cbcf3115-bd03-470f-b930-9390579c3681.png)
