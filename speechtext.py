import speech_recognition as sr
from adafruit_servokit import ServoKit

r = sr.Recognizer()

kit = ServoKit(channels=16)

mic = sr.Microphone(device_index=3)

with mic as source:
	while 1:
		r.adjust_for_ambient_noise(source)
		audio = r.listen(source)
		text = r.recognize_google(audio, language="en-in")
		print(text)
		if "palm" in text:
			kit.servo[0].angle = 0
			kit.servo[1].angle = 0
			kit.servo[2].angle = 0
			kit.servo[3].angle = 0
			kit.servo[4].angle = 0
		elif "fist" in text:
			kit.servo[0].angle = 180
			kit.servo[1].angle = 180
			kit.servo[2].angle = 180
			kit.servo[3].angle = 180
			kit.servo[4].angle = 180
		elif "thumb" in text:
			if "close" in text:
				kit.servo[0].angle = 180
			elif "open" in text:
				kit.servo[0].angle = 0
			elif "half" in text:
				kit.servo[0].angle = 90
		elif "index" in text:
			if "close" in text:
				kit.servo[1].angle = 180
			elif "open" in text:
				kit.servo[1].angle = 0
			elif "half" in text:
				kit.servo[1].angle = 90
		elif "middle" in text:
			if "close" in text:
				kit.servo[2].angle = 180
			elif "open" in text:
				kit.servo[2].angle = 0
			elif "half" in text:
				kit.servo[2].angle = 90
		elif "ring" in text:
			if "close" in text:
				kit.servo[3].angle = 180
			elif "open" in text:
				kit.servo[3].angle = 0
			elif "half" in text:
				kit.servo[3].angle = 90
		elif "pinky" in text:
			if "close" in text:
				kit.servo[4].angle = 180
			elif "open" in text:
				kit.servo[4].angle = 0
			elif "half" in text:
				kit.servo[4].angle = 90
		elif "thumbs up" in text:
			kit.servo[0].angle = 0
			kit.servo[1].angle = 180
			kit.servo[2].angle = 180
			kit.servo[3].angle = 180
			kit.servo[4].angle = 180
