from gpiozero import Button
import socket
from Threading import Thread
from  time import sleep
from signal import pause
left = Button(14)
right = Button(15)

HOST_left = '192.168.70.218' 
HOST_right = '192.168.70.218' 
PORT = 9090

def r():
	print("right")     
	s.sendall(b'r')
      

def l():
	print("left")       
	s.sendall(b'l')	

def stop():
	print("stop")
	s.send(b's')
	sleep(0.2)



def main():
    left.when_pressed = l
	right.when_pressed = r
	sleep(0.1)
	left.when_released  = stop
	right.when_released  = stop

	pause() 



if __name__ == '__main__':
	print("Start Control ")
	try:
		print(f"Connection to the {HOST} {PORT}")
		s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
		s.connect((HOST, PORT))
		print("Connecting")
		main()
	except Exception as _ex:
		print(f"Check server or client {_ex}")
		s.close()
	#data = s.recv(1024)
	print("Close Connection")
	