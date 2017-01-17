<h2> OpenCV in Xcode 8</h2>

<p>
It is a pain in the ass linking the OpenCV library in Xcode 8, when it is your first time.  To save others from this time-suck in the future, here is what you have to do.  These same instructions will get OpenCV working in an openFrameworks Xcode project.
</p>

<p>
First off, DO NOT use Homebrew to install OpenCV on your machine.  Instead, use <pre>cmake</pre>.  You can find the prescribed cmake instructions prepared by the immensely skilled <a href="http://charliegerard.github.io/blog/Installing-OpenCV"/>Charlie Gerard</a>
</p>

<h4>
1)  Set Other Linker Flags
</h4>
<p>
In Build Settings -> Linking, set Other Linker Flags
</p>

<pre>
-lopencv_calib3d -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_highgui -lopencv_imgproc -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab
</pre>

<h4>
2) Set Include Library Path
</h4>
<p>In Build Settings -> Search Paths, Add the following to Library Search Paths</p>
<pre>
/usr/local/lib
</pre>
<h4>
3) Set Include Header Path
</h4>
<p>In Build Settings -> Search Paths, Add the following to Header Search Paths</p>
<pre>
/usr/local/include
</pre>
