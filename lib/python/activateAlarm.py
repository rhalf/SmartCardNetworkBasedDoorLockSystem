#!/usr/bin/env python

import sys
import RPi.GPIO as GPIO
import time
#from time import sleep

def main():

	if len(sys.argv)>1:
		iArg1 = int(sys.argv[1])
	else:
		iArg1 = 0
	
	#print (sys.argv[1])
	#print (sys.argv[2])
	
	#Pin Configuration
	#GPIO.setmode(GPIO.BOARD)
	GPIO.setmode(GPIO.BCM)
	
	#Warnings
	GPIO.setwarnings(True)
	
	#Pin Direction
	GPIO.setup(27,GPIO.OUT)
	#set High
	GPIO.output(27,GPIO.HIGH)
	
	
	if iArg1>0:
		time.sleep(iArg1)
	#set Low
	GPIO.output(27,GPIO.LOW)
	GPIO.cleanup()
	
try: 
	main()
except KeyboardInterrupt:
  print "  Quit" 
  # Reset GPIO settings
  GPIO.cleanup()
