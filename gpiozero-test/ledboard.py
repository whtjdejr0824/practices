from gpiozero import LEDBoard
from time import sleep
from signal import pause

leds = LEDBoard(5,6,13)

# 모두 다 같이 동작
leds.on()
sleep(1)
leds.off()
sleep(1)

leds.value = (1, 0, 1)
sleep(1)
leds.blink()

pause()