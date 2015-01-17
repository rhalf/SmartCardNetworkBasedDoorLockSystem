#!/usr/bin/env python
import sys, serial, time, string

ser = serial.Serial('/dev/ttyAMA0', timeout=None, baudrate=9600)
#, xonxoff=False, rtscts=False, dsrdtr=False)

def readLine(port):
	sReceive = ""
	time.sleep(2)
	while True:
		try:
			char = port.read()
		except:
			return ""
		sReceive += char;
		if char == '\n': #or char == '\0' or char == '\r':
			return sReceive
						
def main():
	print ("arg1: " + sys.argv[1])
	print ("arg2: " + sys.argv[2])
	print ("---------------------") 

	sAtCmd1 = "AT\r"
	sAtCmd2 = "AT+CMGF=1\r" 
	sAtCmd3 = 'AT+CMGS=\"' + sys.argv[1] + '\"' + "\r"
	sAtCmd4 = sys.argv[2] + "\n"
	sAtCmd5 = "AT+CMGD=1,4\r\n"
	
	ser.open()
	state = "Null"
	
	try:
	
		ser.write(sAtCmd1)
		time.sleep(1)
		state="Null"
		state=ser.read(ser.inWaiting())
		print(state)
		#print ("---------------------") 
		
		ser.write(sAtCmd2)
		time.sleep(1)
		state="Null"
		state=ser.read(ser.inWaiting())
		print(state)
		#print ("---------------------") 

		ser.write(sAtCmd3)
		time.sleep(1)
		state="Null"
		state=ser.read(ser.inWaiting())
		print(state)
		#print ("---------------------") 

		ser.write(sAtCmd4)
		time.sleep(1)
		state="Null"
		state=ser.read(ser.inWaiting())
		print(state)
		#print ("---------------------") 
			
		ser.write(b'\x1A')
		time.sleep(3)
		state="Null"
		state=ser.read(ser.inWaiting())
		print(state)
		#print ("---------------------") 
		
		ser.write(sAtCmd5)
		time.sleep(1)
		state="Null"
		state=ser.read(ser.inWaiting())
		print(state)
		#print ("---------------------") 
			
	except KeyboardInterrupt:
		sys.exit(1)


	ser.close()
	
	print("Exit")
	sys.exit(0)

main()