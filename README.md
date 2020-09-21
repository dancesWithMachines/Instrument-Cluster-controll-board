# Instrument-Cluster-controll-board
Controll your instrument cluster with single arduino! No can-bus module needed!

The instrument cluster controll board allows to take controll of 4 gauges and should work with instrument clusters using X25 stepper motors or similar.
In my case I used instrument cluster from Jaguar X-type 2.0d.

![Insides](/pics/insides.jpg)

## Table of Contents
* [YouTube video](#Video)
* [Why do I need this?](#Why-do-I-need-this?)
* [What do I need?](#What-do-I-need?)
* [Making it](#Making-it)
* [Coding](#Coding)
* [Souces / Additional information](#Sources)
* [Licence](#Licence)

## Video
In process of making

## Why do I need this?
Have you become the owner of the inctrument cluster of the car you don't own, don't have diagrams or don't know the CAN-BUS headers?
This solution plugs directly into stepper motors on the pcb, and allows you to take controll of the needles, skiping CAN-BUS and rest of the pcb electronics.
It requires no additional motor controllers, just Arduino.

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
I modified example sketch to accept data in suitable units and to controll all 4 motors.
Data feed pattern: "rmp;speed(km/h);temp(*C 120 max); fuel (max 100);"
![Instances](/pics/instances.png) </br>
Remember, change the pins to suit your needs ( ͡~ ͜ʖ ͡°)
 
## Sources

[Switec X25 library](https://github.com/clearwater/SwitecX25), for controlling the stepper motors.

[Ardonaut's ariticle](https://arduining.com/2012/04/22/arduino-driving-a-micro-stepper-motor/), about controlling stepper motors using arduino.

[The pcb](https://www.tindie.com/products/TheRengineer/analog-gauge-stepper-breakout-board/) I was basing on, [Source files](https://github.com/TheRengineer/GaugeStepperBreakout)

## Licence
![Board JPG](/pics/board.jpg)
