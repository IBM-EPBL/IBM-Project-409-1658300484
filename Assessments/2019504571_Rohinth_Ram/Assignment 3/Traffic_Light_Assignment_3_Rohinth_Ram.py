import RPi.GPIO as GPIO # raspberry pi gipo module
from time import sleep 

GPIO.setwarnings(False) 
GPIO.setmode(GPIO.BOARD)

"""
Simple LED Interfacing
LED at Pin 8
Expected Output : Blinking LED ; 1s delay
"""

ledPin = 8

GPIO.setup(ledPin, GPIO.OUT, initial=GPIO.LOW) # pin 8 - out ; initial - low
while True: 
    GPIO.output(ledPin, GPIO.HIGH) 
    sleep(1) 
    GPIO.output(ledPin, GPIO.LOW)
    sleep(1)

"""
Traffic Light Interfacing
LEDs - Pin ; RED - 11 ; YELLOW - 13 ; GREEN - 15
Expected Output : 2 Seconds RED and 1 Seconds GREEN with 0.5 Seconds YELLOW transition
"""

red = 11
yellow = 13
green = 15

GPIO.setup(red, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(yellow, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(green, GPIO.OUT, initial=GPIO.LOW)

while 1:
    GPIO.output(red, GPIO.HIGH)
    sleep(2)
    GPIO.output(red, GPIO.LOW)
    GPIO.output(yellow, GPIO.HIGH)
    sleep(0.5)
    GPIO.output(yellow, GPIO.LOW)
    GPIO.output(green, GPIO.HIGH)
    sleep(1)
    GPIO.output(green, GPIO.LOW)
    GPIO.output(yellow, GPIO.HIGH)
    sleep(0.5)
    
