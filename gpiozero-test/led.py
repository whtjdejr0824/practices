from gpiozero import LED
# from time import sleep #1
from signal import pause #2


red = LED(17)

# while True: #1
#     red.on() #1
#     sleep(1) #1
#     red.off() #1
#     sleep(1) #1

red.blink()  #2 독자적인 실행 프로세스
pause() #2
print("end....") #2
