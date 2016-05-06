
<h1>Soft Matter Detection</h1>
<p>
Soft Matter is a deformable piece of matter, like a plastic bag, tumbleweed, hair, cloth, etc.  We consider a case example for self-driving cars for this tutorial.
</p> 

<h3>Example</h3>

<p>
Lets say you need to build the vision component to the software that operates a self-driving car. Your codes needs to be able to decide weather a car should stop, or keep driving if a piece of matter flies into your lane.  This requires your code to distinguish between hard or soft objects.  In the case of hard objects, the problem is easy, the car needs to stop or manuver to avoid the object.  Hard object detection is straitforward, soft matter detection not so much. 
</p>

<p>
  Determining if an object is soft, like a plastic bag, a piece of cardboard, a tumbleweed, a pillow falling from a truck, etc...Is important, because in these instances a car does not need to perform any sort of evasive action to avoid the object that might otherwise put the passengers at risk,
</p>

<p>
Instead of using any sort of pre-trained Object detection algroithm to detect and classify hard or soft objects, we will be using equations from a discipline called Statistical Physics.
</p>
