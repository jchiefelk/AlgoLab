<h2> Face Detection </h2>

<p>In this section you will learn how detect faces from a live video stream using Python and OpenCV.  Specifically,
you will use the Haar Cascades Algorithm to detect faces and eyes from a live video feed.  
</p>

<p>
Haar cascades is a common algroithm to detect faces in pictures.  For example, when you are using the camera on your smart phone and you see a square appear around the faces of the people in the camera's view, thats most likely Haar Cascades.  Haar Cascades is dependent upon a pre-trained classifier to detect faces in an image.  Training a classifier can take weeks, plus whatever time it takes you to write the code to do the training, or you can user OpenCV.
</p>

<p>
OpenCV is an excellent Open Source Computer Vision library, and used by many people including the following Tesla, Boston Dynamics, Apple.  OpenCV can be used with numerous programming languages.  I'm going to be using Python at first to get your feet wet with Face Detection and OpenCV.  Later we are going to switch to C++ when we move to learning Face Recognition.  The reason is performance, Face Recognition requires lots of computations. 
</p>

<h3>Getting Started</h3>

<p>
Before we do anything, we first need to know how to acquire the frames from the video feed on your laptop.
</p>

