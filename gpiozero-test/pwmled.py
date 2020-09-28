from gpiozero import PWMLED
# from time import sleep #1
from signal import pause #2

led = PWMLED(17)

# while True:                             #1
#     led.value = 0 # off                 #1
#     sleep(1)                            #1
#     led.value = 0.5 # half brightness   #1
#     sleep(1)                            #1
#     led.value = 1 # full brightness     #1
#     sleep(1)                            #1

led.pulse()        #2

pause()            #2