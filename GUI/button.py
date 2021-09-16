from gpiozero import Button
import socket
from  time import sleep
from signal import pause
left = Button(14)
right = Button(15)
HOST = '192.168.31.40' 
PORT = 8888 



def r():
	while right.value:
		print("right")     
		s.sendall(b'right')
		sleep(0.2)
      

def l():
	while left.value:
		print("left")       
		s.sendall(b'left')
		sleep(0.2)


def stop():
	print("stop")
	s.sendall(b'stop')
	
            

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
	