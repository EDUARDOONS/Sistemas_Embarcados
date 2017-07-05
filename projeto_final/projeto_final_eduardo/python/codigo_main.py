

import RPi.GPIO as GPIO
import time
from picamera import PiCamera

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(11, GPIO.IN)

camera = PiCamera()

i=0

while True:
    i+=1
    state = GPIO.input(11)
    if state==0:
        print "We're clear"
        time.sleep(0.1)
    elif state==1:
        print "STOP RIGHT THERE!"
        camera.capture('/home/pi/projeto_final/python/fotos/image{0:04d}.jpg'.format(i))
