# Smart Switch Actuator

A Bluetooth-controlled device that physically flips a standard light switch on or off, without touching the switch's wiring.

## What it does

The device mounts next to a standard toggle or rocker light switch and uses two small motors to press it, the same way a finger would. One motor pushes the switch down to turn it on, the other pushes it up to turn it off. A phone sends an "on" or "off" command over Bluetooth, and the device moves the correct motor.

See `docs/vision.md` for the full project vision and design decisions.

## Current status

The control logic is built and tested in simulation, using [Wokwi](https://wokwi.com). Two virtual servos correctly alternate between an "on" push and an "off" push, triggered by a button press, with the device correctly tracking which state it's in.

Not yet built:
- Bluetooth control from a phone (currently triggered by a physical button in simulation)
- The physical bracket and mount (CAD design)
- A real hardware prototype
- The phone app

## How it works

- Two servos, one positioned to push the switch up, one to push it down
- The device keeps track of whether the switch is currently on or off, so it knows which servo to fire next
- It has no sensor to check the switch's real position, it only remembers its last action
- Only the most common switch types are targeted: standard toggle and rocker switches

## Repository structure

```
smart-switch-actuator/
├── README.md
├── docs/
│   ├── vision.md          # full project vision and scope
│   └── wokwi-circuit.png  # screenshot of the simulated circuit
├── firmware/
│   ├── esp32-servo-sweep.ino   # Arduino code
│   ├── diagram.json            # Wokwi circuit wiring
│   ├── libraries.txt           # required libraries
│   └── wokwi-project.txt       # link to the live Wokwi simulation
└── cad/                   # CAD files (not yet added)
```

## Tools and parts

**Software:** [Wokwi](https://wokwi.com) (simulation), Arduino/C++ (firmware), Fusion 360 / OnShape / SolidWorks (CAD, undecided), MIT App Inventor (phone app)

**Hardware:** ESP32 microcontroller (Bluetooth built in), two SG90 micro servos, breadboard and jumper wires, power source, 3D-printed bracket

## Build plan

1. Prove the control logic in simulation (done)
2. Measure a real switch and servo dimensions, design the bracket in CAD
3. Order parts and build a real breadboard prototype
4. 3D print the bracket
5. Build the phone app and add Bluetooth control
6. Test and tune the real device
