import socket
def r():
	print("right")     
	s.sendall(b'0;100;100')
def main():

	r()
      
if __name__ == '__main__':
	HOST = "192.168.202.216"
	PORT = 9090
	try:
		print(f"Connection to the {HOST} {PORT}")
		s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
		s.connect((HOST, PORT))
		print("Connecting")
		main()
	except Exception as _ex:
		print(f"Check server or client {_ex}")
		s.close()

	