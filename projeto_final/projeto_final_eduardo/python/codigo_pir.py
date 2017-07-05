from gpiozero import MotionSensor

pir = MotionSensor(17)
while True:
    if pir.motion_detected:
        print("Movimento detectado!")
    else:
	print("Sem movimento")
