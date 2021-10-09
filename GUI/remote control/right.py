import socket

HOST = '192.168.38.109'  # The server's hostname or IP address
PORT = 9090        # The port used by the server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(b'0;0;100')
    data = s.recv(1024)

print('Received', repr(data))