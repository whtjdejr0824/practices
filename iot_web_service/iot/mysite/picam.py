import cv2
import io
import time
import numpy as np
from picamera.array import PiRGBArray
from picamera import PiCamera

class PiCam:
    def __init__(self, show=True, framerate=25, width=640, height=480):
        self.size = (width, height)
        self.show = show
        self.framerate = framerate
        self.init()
    
    def init(self):
        self.camera = PiCamera()
self.camera.rotation = 180
self.camera.resolution = self.size
self.camera.framerate = self.framerate
def __del__(self):
self.camera.close()