import RPi.GPIO as GPIO
from time import sleep 

GPIO.setwarnings(False) 
GPIO.setmode(GPIO.BOARD)

"""
LED Interfacing
LED at Pin 7
"""

ledPin = 7

GPIO.setup(ledPin, GPIO.OUT, initial=GPIO.LOW)
while True: 
    GPIO.output(ledPin, GPIO.HIGH) 
    sleep(1.5) 
    GPIO.output(ledPin, GPIO.LOW)
    sleep(1.5)

"""
Traffic Light Interfacing
LEDs - Pin ; RED - 5 ; YELLOW - 6 ; GREEN - 13
"""

red = 5
yellow = 6
green = 13

GPIO.setup(red, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(yellow, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(green, GPIO.OUT, initial=GPIO.LOW)

while 1:
    GPIO.output(red, GPIO.HIGH)
    sleep(3)
    GPIO.output(red, GPIO.LOW)
    GPIO.output(yellow, GPIO.HIGH)
    sleep(1)
    GPIO.output(yellow, GPIO.LOW)
    GPIO.output(green, GPIO.HIGH)
    sleep(3)
    GPIO.output(green, GPIO.LOW)
    GPIO.output(yellow, GPIO.HIGH)
    sleep(1)
    
