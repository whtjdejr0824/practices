import RPi.GPIO as GPIO
import time

#callable class
class LedEx :
    def __init__(self):
        self.led.pin = 18
        GPIO.setup(self.led_pin, GPIO.OUT)

    def __call__(self):
        for i in range(10):
            self.GPIO.output(led_pin,1) #LED ON
            time.sleep(1)          # 1초동안 대기상태
            self.GPIO.output(led_pin,0) #LED OFF
            time.sleep(1)          # 1초동안 대기상태

        # GPIO.cleanup() # GPIO 설정 초기화