# Instrument-Cluster-control-board
Control your instrument cluster with single arduino! No can-bus module needed!

The instrument cluster control board allows to take control of 4 gauges and should work with instrument clusters using X25 stepper motors or similar.
In my case I used instrument cluster from Jaguar X-type 2.0d.

![Insides](/pics/insides.jpg)

## Table of Contents
* [YouTube video](#Video)
* [Why do I need this?](#Why-do-I-need-this?)
* [What do I need?](#What-do-I-need?)
* [Making it](#Making-it)
* [Coding](#Coding)
* [Souces](#Sources)
* [Problems](#Common-problems)
* [Licence](#Licence)

## Video

<p align="center">
 <a href="https://youtu.be/XNLJWUMKByM">
  <img alt="YouTube video" src="/pics/ytVid.png">
 </a>
</p>

## Why do I need this?
Have you become the owner of the inctrument cluster of the car you don't own, don't have diagrams or don't know the CAN-BUS headers?
This solution plugs directly into stepper motors on the pcb, and allows you to take control of the needles, skiping CAN-BUS and rest of the pcb electronics.
It requires no additional motor controlers, just Arduino.

![Board Gif](/pics/sweep.gif)

## What do I need?
 * Arduino nano (soldered)
 * 32x 1N4001 rectifying diodes (8 for each motor)
 * At least 23x17 perfboard
 * Some steel wire (for perfboard)
 * 0,25mm cable wire (for connecting to stepper mottors)
 * female connectors (for connecting arduino)
 * Instrument cluster (duh)
 
## Making it

![Diagram](/Breadboard%20wiring%20diagram/Breadboard%20Diagrams%20NEW.png)
![Board Gif](/pics/board.gif)

## Coding
 
You'll need Switec X25 library, which you can find [here](https://github.com/clearwater/SwitecX25).
I modified example sketch to accept data in suitable units and to control all 4 motors.
Data feed pattern: "rmp;speed(km/h);temp(*C 120 max); fuel (max 100);"
![Instances](/pics/instances.png) </br>
Remember, change the pins to suit your needs ( ͡~ ͜ʖ ͡°)
 
## Sources

[Switec X25 library](https://github.com/clearwater/SwitecX25), for controlling the stepper motors.

[Ardonaut's ariticle](https://arduining.com/2012/04/22/arduino-driving-a-micro-stepper-motor/), about controlling stepper motors using arduino.

[The pcb](https://www.tindie.com/products/TheRengineer/analog-gauge-stepper-breakout-board/) I was basing on, [source files](https://github.com/TheRengineer/GaugeStepperBreakout)

## Common problems

Two issues I found working with Switec X25 library were related to delay speeds declared in the library code (File: SwitecX25.cpp).
* If the ,,zero" function only buzzes your motors, but does not rewind them to 0 position, you must increase ,,RESET_STEP_MICROSEC" definition (2000 works for me)
* If the motors are working, but stop in the middle and disrupt the gauge, you must edit the "defaultAccelTable", and increase delay times from the bottom (my lowest is 1500)

## Licence

MIT License

Copyright (c) 2020 Mateusz Kusiak (Timax)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.


![Board JPG](/pics/board.jpg)
