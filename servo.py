from time import sleep
from adafruit_servokit import ServoKit

kit = ServoKit(channels=16)

def calibration_cycle():
	for i in range(5):
		kit.servo[i].angle = 0

def movement(finger, motion):
	servono = int(finger) - 1
	if motion == "close" or motion == "Close":
		angle = 180
	elif motion == "open" or motion == "Open":
		angle = 0
	elif motion == "mid" or motion == "Mid":
		angle = 90
	kit.servo[servono].angle = angle

while True:
	Fin = input("Input finger number between 1(thumb) and 5(pinky) or 'calibrate': ")
	if Fin == "calibrate":
		calibration_cycle()
	else:
		Mot = input("Input desired motion(close, open, mid): ")
		movement(Fin, Mot)
