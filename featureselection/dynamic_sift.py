import cv2
import numpy as np
import multiprocessing

class Data:
	image = 'None'

	def _init_(self):
		print('Image Data')

class VideoFeed(Data):
	# frame = cv2.imread('sbw.jpg')
	frame_img='Test Test'
	def _init_(self):
		print('Video Feed')

	def test(self):
		print('Thread 1 Test')

	def fetchImg(self):
		video_capture = cv2.VideoCapture(0)
		while True:
			ret, frame = video_capture.read()
			gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
			frame_img = gray
			Data.image = gray
			# cv2.imshow('video',Data.image)
			cv2.imwrite('frame.jpg',frame_img)
			if  cv2.waitKey(1) & 0xFF == ord('q'):
				break

class FeatureDetect(Data):
	
	def _init_(self):
		print('Feature Select')

	def test(self):
		print('Thread 2 test')

	def sift(self):
		while True:
			sift = cv2.SIFT()
			img = cv2.imread('frame.jpg')
			gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
			kp = sift.detect(gray,None)	
			img=cv2.drawKeypoints(gray,kp)
			# cv2.imwrite('sift_interest_points.jpg',img)
			cv2.imshow('interest points',img)
			if cv2.waitKey(1) & 0xFF ==ord('q'):
				break
#
# Main Thread
if __name__ == '__main__':
	VideoFeed = VideoFeed()
	FeatureDetect = FeatureDetect()
	thread1 = multiprocessing.Process(target=VideoFeed.fetchImg)
	thread2 = multiprocessing.Process(target=FeatureDetect.sift)
	thread1.start()
	thread2.start()
