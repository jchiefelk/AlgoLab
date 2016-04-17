import numpy as np
import cv2
cap = cv2.VideoCapture(0)
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
eye_cascade = cv2.CascadeClassifier('haarcascade_eye.xml')

# Video feed
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
video_capture = cv2.VideoCapture(0)
#
# Picture of Root User
# Crop out the Face
# Capture frame-by-frame
user = cv2.imread('family.jpg')
gray = cv2.cvtColor(user, cv2.COLOR_BGR2GRAY)
user_face = face_cascade.detectMultiScale(user, 1.2, 5)
for (x, y, w, h) in user_face:
    x_dim = w
    y_dim = h
    cv2.rectangle(user, (x, y), (x+w, y+h), (0, 255, 0), 2)
    cropped =  gray[y:y+h, x:x+w]
    user_resized = cv2.resize(cropped, (200, 200))
    # Display the resulting frame
    cv2.imshow('Root User', user_resized)

# When everything is done, release the capture
video_capture.release()
cv2.destroyAllWindows()