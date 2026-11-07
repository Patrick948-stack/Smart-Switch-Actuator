# Vision

## What this is

A small device that mounts next to a standard light switch and physically flips it on or off, controlled from a phone over Bluetooth. Instead of replacing the switch with a smart one, this device sits on top of the existing switch and presses it, like a robot finger.

## Why

Most "smart switch" products require rewiring your actual wall switch, which isn't possible or allowed in a dorm or rented apartment. This device solves that by never touching the switch's wiring at all. It just mounts on the wall plate and pushes the switch mechanically, the same way a finger would.

## How it works

The device uses two small motors (servos), one positioned at the top of the switch and one at the bottom.

- To turn the switch on, the bottom arm swings out, presses the switch down, then returns to its resting position.
- To turn the switch off, the top arm swings out, presses the switch up, then returns to its resting position.

Only one arm moves per command, and the device keeps track of whether the switch is currently on or off so it knows which arm to use next. It does not have a sensor to check the switch's real position; it only keeps a memory of the last action it took.

A phone app sends a simple "on" or "off" message to the device over Bluetooth. The device receives that message and moves the correct arm.

## Scope for version 1

- Targets only the most common residential switch types: standard toggle switches and rocker (paddle) switches.
- Does not support dimmer switches, smart switches, or unusual switch shapes.
- Does not include a camera or any way to visually confirm the switch's position. The device trusts its own memory of what it last did.
- Does not attempt to work with every switch on the market, only the most popular, common ones.

## Build approach

The project is being built in stages, software first:

1. Prove the control logic in a free online simulator (Wokwi) using virtual servos and a virtual button, before spending any money on parts.
2. Design the physical mount and arms in CAD (Fusion 360) once real-world switch and servo dimensions are known.
3. Order real parts (ESP32 microcontroller, two small servos, wiring) and build a real breadboard prototype.
4. 3D print a bracket that holds both servos in place against a real switch.
5. Build a simple phone app that sends "on" and "off" commands over Bluetooth.
6. Test and tune the real device: how far each arm needs to travel, how much force it needs to apply, and how reliably it fires.

## Parts and tools

**Software:** Wokwi (simulation), Arduino/C++ (the code that runs on the microcontroller), Fusion 360 or Onshape or SolidWorks (3D design of the bracket), MIT App Inventor (the phone app).

**Hardware:** ESP32 microcontroller (has Bluetooth built in), two SG90 micro servos (the motors that push the switch), a breadboard and jumper wires (for prototyping the wiring), a power source, and a 3D-printed bracket to hold everything in place.

## Current status

The control logic has been built and tested in simulation. Two virtual servos correctly alternate between an "on" push and an "off" push, triggered by a button press, with the device correctly remembering which state it's in. Bluetooth control and the physical bracket have not been built yet.