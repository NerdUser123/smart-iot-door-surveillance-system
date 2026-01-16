import cv2
import serial
import time

ser = serial.Serial('COM5',9600)
time.sleep(4)

face_cascade = cv2.CascadeClassifier(
    cv2.data.haarcascades + 'haarcascade_frontalface_default.xml'
)

cap = cv2.VideoCapture(0)

print("SHOW FACE TO REGISTER")
authorized = None

while authorized is None:
    ret,frame = cap.read()
    gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray,1.3,5)
    if len(faces)==1:
        x,y,w,h = faces[0]
        authorized = gray[y:y+h,x:x+w]
        print("FACE SAVED")
    cv2.imshow("Register",frame)
    if cv2.waitKey(1)==27: exit()

doorOpen=False
lastFace=time.time()

while True:
    ret,frame = cap.read()
    gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray,1.3,5)

    if len(faces)>0:
        lastFace=time.time()
        if not doorOpen:
            ser.write(b"OPEN\n")
            doorOpen=True

    if doorOpen and time.time()-lastFace>7:
        ser.write(b"CLOSE\n")
        doorOpen=False

    cv2.imshow("Face Door",frame)
    if cv2.waitKey(1)==27: break

cap.release()
ser.close()
