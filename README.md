# tinyraytracer
This is a ray tracer that I build for educational purposes. 

This ray tracer is created based on the book Creating A Ray Tracer in One Weekend that's available here: 
https://raytracing.github.io/books/RayTracingInOneWeekend.html

To run this, 
compile by running: `g++ -std=c++11 -o output.a main.cpp`
and then running the executable output: `./output.a`

This will create an image based on whatever is defined in the main file. 

This is currently what it does as we just created 2 spheres. 

<img width="402" alt="image" src="https://github.com/ysoo/tinyraytracer/assets/17395031/b1e6ad6b-7aa1-48d7-aacf-93c928624b10">


### hittable_list
This is a list of shared pointers to the objects that will be available in the image. 

### camera
This creates the camera within the world. 
Please define the aspect_ratio and the image_width.

Calling `camera.render(world)` where world is a hittable_list would create the image. 


### TODO (As of 11/19/2023)
1. More color options and ability to vary color.
2. Adding more intersectable objects, ray-plane, ray-box, and ray-disk
3. Positionable Camera
4. Diffuse Materials/Lights
5. Motion Blur (Moving Objects) 
