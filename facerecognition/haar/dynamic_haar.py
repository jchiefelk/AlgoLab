# Python script to recognize face
import numpy as np
import cv2
import sys
from threading import Thread

### Pre-trained Classifiers
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
eye_cascade = cv2.CascadeClassifier('haarcascade_eye.xml')
# Video Capture
video_capture = cv2.VideoCapture(0)
cv2.namedWindow('video', cv2.WINDOW_NORMAL)

while True:
    # Capture frame-by-frame
    ret, frame = video_capture.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    cv2.imshow('video', gray)
    faces = face_cascade.detectMultiScale(gray, 1.5, 5)
    # Draw a rectangle around the faces
    for (x, y, w, h) in faces:
        cv2.rectangle(gray, (x, y), (x+w, y+h), (0, 255, 0), 2)
        cv2.imshow('video', gray)
        # face_gray = gray[y:y+h, x:x+w]
        # face_resized=cv2.resize(face_gray, (200, 200))
        font = cv2.FONT_HERSHEY_PLAIN
        text = 'Scan Human'
#        cv2.putText(frame,text,(50,50), font, 1,(255,255,255),2)
        if  cv2.waitKey(1) & 0xFF == ord('q'):
            break

# When everything is done, release the capture
video_capture.release()
cv2.destroyAllWindows()