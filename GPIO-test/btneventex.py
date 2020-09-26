import RPi.GPIO as GPIO
import time

# callable class
class BtnEventEx:
    def __init__(self):
        # 사용할 GPIO핀의 번호를 선정합니다.
        self.button_pin = 16
        self.led_pin = 18
        # 버튼핀의 INPUTm PULL DOWN 설정
        GPIO.setup(self.button_pin, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
        GPIO.setup(self.led_pin, GPIO.OUT)
        self.light_on = False

    def button_callback(self, channel):
        if self.light_on == False:
            GPIO.output(self.led_pin,1)
            print("LED ON!")
        else :
            GPIO.output(self.led_pin,0)
            print("LED OFF!")
        self.light_on = not self.light_on

    def __call__(self):
        self.light_on = False
        GPIO.add_event_detect(self.button_pin, GPIO.RISING, 
                            callback=self.button_callback, 
                            bouncetime=10)
        try:
            while 1:
                time.sleep(0.1)
        except KeyboardInterrupt:
            GPIO.remove_event_detect(self.button_pin)