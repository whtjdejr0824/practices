import spidev, time

class McpEx:
    def __init__(self):
        self.spi = spidev.SpiDev()
        self.spi.open(0,0) # (버스, 디바이스)
        self.spi.mode = 3
        self.spi.max_speed_hz = 1000000

    def analog_read(self, channel):
        r = self.spi.xfer2([1, (0x08+channel)<<4, 0]) # Pi -> MCP, MCP -> Pi
        adc_out = ((r[1]&0x03)<<8) + r[2] # 수신 데이터 결합
        return adc_out 

    def __call__(self):
        
        while True:
            adc = self.analog_read(0)
            voltage = adc*3.3/1023
            print("ADC = %s(%d) Voltage = %.3fV" % (hex(adc), adc, voltage))
            time.sleep(0.5)