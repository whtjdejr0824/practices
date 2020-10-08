from gpiozero import Robot
from time import sleep

#left/right(전진,후진,PWM)
car = Robot(left=(17, 27, 22), right=(15, 18, 14), pwm=True)

while True:
    cmd = input(">")

    if cmd == "q":
        break
    elif cmd == "l":
        car.left(0.7)
    elif cmd == "r":
        car.right(0.7)
    elif cmd == "g":
        car.forward(0.7)
    elif cmd == "b":
        car.backward(0.7)
    elif cmd == "s":
        car.stop()
    else:
        car.stop()