import serial
ser = serial.Serial('COM9', 9600)
while True:
	print(ser.readline())