<h2> OpenCV in Xcode 7</h2>

<p>
It iss a pain in the ass linking the OpenCV library in Xcode 7.  Took a few hours to get going.  To save others from this time-suck in the future, here is what you have to get going.  These same instructions will get OpenCV working in an openFrameworks Xcode project/
</p>


<h4>
1) Other Linker Flags 
</h4>
<p>
Copy and paste the following flags, and in Xcode and paste into Other Linker Flags.
</p>

<pre>
-lopencv_calib3d -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_highgui -lopencv_imgproc -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab
</pre>
