def connect(HOST, PORT):
	try:
		print(f"Connection to the {HOST} {PORT}")
		s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
		s.connect((HOST, PORT))
		print("Connecting")
		
	except Exception as _ex:
		print(f"Check server or client {_ex}")
		s.close()
def r():
	print("right")     
	s.sendall(b'r')
      

def l():
	print("left")       
	s.sendall(b'l')	

def stop():
	print("stop")
	s.sendall(b's')
	sleep(0.2)

