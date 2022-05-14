# Abstract
Wipers are the components needed to remove raindrops and other liquids from the windshield of a vehicle. In previous systems, it was necessary to change the frequency and manually activate the wiper. As a result, the operation to increase the wiper speed changes. The goal of the project is to improve the aging car system by providing an automated transmission wiping system, improve the system by incorporating sensors and actuators, and create simple software that works perfectly with the system. Framework The principle of this proposed wiper system is comparable to that of other existing traditional wipers. Nevertheless, this system will be upgraded to an automated control system that uses a peripheral interface to remove water from the windshield.

# INTRODUCTION
 The operating speed of the wiper is controlled by the wiper speed control system according to the frequency. The pulse signal is digitally processed to provide a control signal. The wiper driver circuit receives the control signal and adjusts the operating speed and timing accordingly.
# SOFTWARE REQUIREMENTS
 STM32 CUBE IDE
# COMPONENTS
  STM32F4O7VG MICROCONTROLLER BOARD
## DESCRIPTION
# STM32F407VG
 The STM32F407  Kit takes advantage of the high-performance STM32F407 microcontrollers' capabilities to make it simple for users to create audio-based applications. It comes with an ST-LINK embedded debug tool, an ST-MEMS digital accelerometer, a digital microphone, an audio DAC with integrated class D speaker driver, LEDs, pushbuttons, and a USB OTG micro-AB connector.Ethernet connectivity, an LCD display, and other features have been added to the STM32F4 DISCOVERY kit. The STM32F405xx and STM32F407xx families are built around the high-performance Arm® Cortex®-M4 32-bit RISC core, which runs at up to 168 MHz.
 # FEATURES OF STM32F407VG MICROCONTROLLER
  * In a LQFP100 package, the STM32F407VGT6 microcontroller has a 32-bit ARM Cortex-M4 with FPU core, 1-Mbyte Flash memory, and 192-Kbyte RAM.
  * On-board ST-LINK/V2 or ST-LINK/V2-A on STM32F4 DISCOVERY (old reference) or STM32F407G-DISC1 (new order code)
  * USB ST-LINK with three separate interfaces and re-enumeration capability.
  * Virtual Com port Debug port (with new order code only)
  * Large-scale storage (with new order code only)
  * Board power is supplied through USB or an external 5 V supply source.
  * 3 V and 5 V external application power supply
 # USES
  * This Microcontroller is utilised in printing and scanning machines ,heat ventilation, air conditioning, and security systems. 
  * This module can be found in a variety of household products.
 # WORKING PRINCIPLE
 Suppose the car is a microcontroller. Press the button to turn on the first LED (red), click it again to activate the wiper and turn on the second LED (blue) at the desired speed. When you press the button again, the third LED (green) will light up and the wiper will be faster than the previous LED. Press four times to turn on the fourth LED (orange) and increase the wiper speed as it did before. The microcontroller (vehicle) turns off after the 5th click.
 
## OFF State 
 ![pic4](https://user-images.githubusercontent.com/71280538/168414861-a5566e66-f483-4399-9616-a6b6de370167.png)
 
## ON State
 ![Pic1](https://user-images.githubusercontent.com/71280538/168414894-fe978caf-b71b-433f-be3a-a3d1b307e8c8.png)

## Low Speed
![pic2](https://user-images.githubusercontent.com/71280538/168414943-f09f0f8e-dd73-4810-bc4c-1f116a9eaae9.png)

## High Speed
![pic3](https://user-images.githubusercontent.com/71280538/168414959-b4661a43-5738-4ef2-a7b9-4d58d269705c.png)


 ## 4 W'S
 # WHAT IS WIPER SYSTEM
  Windscreen wipers are necessary for maintaining sufficient view for the driver, especially in modern high-speed cars.
 # WHY WIPER SYSTEM
   To keep the windscreen clean enough to give adequate view at all times.
 # WHEN SHOULD USE WIPER SYSTEM 
  The windshield wipers remove rain and snow from the windshield, while the headlights improve visibility at night.
 # WHO DISCOVERED WIPER SYSTEM
  Mark Anderson invented on 1902
   
  

