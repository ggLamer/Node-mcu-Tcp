import cv2

cap = cv2.VideoCapture(0)
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