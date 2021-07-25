# FreeRTOS on PIC32MM
This repo demonstrates FreeRTOS on a PIC32MM0256GPM064 on the PIC32MM USB Curiosity board. The demo toggles `LED1` every 500ms.

I was unable to find a working demo for FreeRTOS on the PIC32MM. The MX and MZ chips are supported but it appears the MM is not (though no reason why it can't be).

I used [this repo](https://github.com/MicrochipTech/freeRTOS-PIC24-dsPIC-PIC32MM) for reference as well as the official FreeRTOS examples for the PIC32MX.