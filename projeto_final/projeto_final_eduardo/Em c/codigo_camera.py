from picamera import PiCamera
from time import sleep

camera = PiCamera()

camera.start_preview()
for i in range(3):
    sleep(1)
    camera.capture('/home/pi/projeto_final_eduardo/python/fotos/image%s.jpg' % i)
camera.stop_preview()
