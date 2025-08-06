# Car Simulator

This Project is a simple car simulator built using the following components:
- Arduino UNO
- Potentiometers x 2
- Limit Switches x 4
- M274 Rotary encoder

The arduino acts as the main brain for the simulator, It takes the inputs from all the sensors, switches and potentiometers, formats the data into a list and sends it to the python program through serial communication.

## Step by step breakdown of the project
The Simulator has a total of 7 controls.
- Accelerator
- Brake
- Clutch
- Steering
- Gear Up
- Gear Down
- E Brake (Handbrake)

The accelerator and brake is controlled by their respective potentiometers giving us variable control over it. The clutch is just a button, and uses a limit switch to engage and disengage. The steering uses a rotary encoder to check how much the steering wheel has been rotated and the Gear shifters (Gear Up and Down) are just two limit switches.
