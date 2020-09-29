import picamera

from time import sleep

with picamera.PiCamera() as camera:
    camera.start_preview()
    
    for i in range(5):
        sleep(5)
        camera.capture(format('/home/pi/workspace/pycamera/image{i}.jpg'))
    
    camera.stop_preview()