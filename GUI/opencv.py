import cv2
import socket


HOST = '127.0.0.1'
PORT = 8080

cap = cv2.VideoCapture(0)
def getap():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        s.listen()
        conn, addr = s.accept()
        with conn:
            print('Connected by', addr)
            while True:
                data = conn.recv(1024)
                if not data:
                    break
                conn.sendall("data")

font = cv2.FONT_HERSHEY_SIMPLEX
org = (10, 50)
fontScale = 0.5
color = (255, 0, 0)
thickness = 2



while True:
    ret, img = cap.read()
    image = cv2.putText(img, f'Current_mA {org}', org, font, fontScale, color, thickness, cv2.LINE_AA)
    cv2.imshow("Camera", image)
    if cv2.waitKey(10) == 27: # Клавиша Esc
        break
cap.release()
cv2.destroyAllWindows()