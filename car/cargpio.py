from gpiozero

def forward(tf):
    init()
    gpio.output(7, False)
    gpio.output(7, False)
    gpio.output(7, False)
    gpio.output(7, False)
    gpio.output(7, False)
    time.sleep(tf)
    gpio.cleanuog
