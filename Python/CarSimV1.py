import serial
import vgamepad
import time
import math

portNumber = 15
baudrate = 115200
exponential_gradient = 0.7

gamepad = vgamepad.VX360Gamepad()
arduino = serial.Serial(f"COM{portNumber}", baudrate=baudrate)

prevClutchValue = 0

time.sleep(3)

while True:
    try:
        data = arduino.readline().decode('utf-8')[:-2].split(",")

        encoderPos = int(data[2])

        # Normalize to -1.0 to 1.0 range, assuming encoder goes from -10 to 10
        norm_input = encoderPos / 6.0

        curved_input = (abs(norm_input) ** exponential_gradient) * (1 if norm_input >= 0 else -1)    # exponential



        # Scale to joystick range (±32767) and offset to start at ±2000
        joystick_value = int(curved_input * (32767 - 2000))  # subtract offset range
        if encoderPos > 0:
            joystick_value += 2000
        elif encoderPos < 0:
            joystick_value -= 2000
        else:
            joystick_value = 0

        joystick_value = max(-32768, min(32767, joystick_value))

        clutchValue = int(data[3])
        shifterValue = int(data[4])

        if clutchValue != prevClutchValue:
            if clutchValue == 0:
                gamepad.release_button(button=vgamepad.XUSB_BUTTON.XUSB_GAMEPAD_LEFT_SHOULDER)
            else:
                gamepad.press_button(button=vgamepad.XUSB_BUTTON.XUSB_GAMEPAD_LEFT_SHOULDER)

        if shifterValue != 0:
            if shifterValue == 1:
                gamepad.press_button(button=vgamepad.XUSB_BUTTON.XUSB_GAMEPAD_B)
            elif shifterValue == -1:
                gamepad.press_button(button=vgamepad.XUSB_BUTTON.XUSB_GAMEPAD_X)
        else:
            gamepad.release_button(button=vgamepad.XUSB_BUTTON.XUSB_GAMEPAD_B)
            gamepad.release_button(button=vgamepad.XUSB_BUTTON.XUSB_GAMEPAD_X)


        # Send values to gamepad
        gamepad.left_joystick(x_value=joystick_value, y_value=0)
        gamepad.right_trigger(value=int(data[0]))
        gamepad.left_trigger(value=int(data[1]))
        gamepad.update()
        prevClutchValue = clutchValue

    except KeyboardInterrupt or serial.SerialException or PermissionError:
        exit(0)

    except:
        pass
