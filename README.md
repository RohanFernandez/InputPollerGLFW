# InputPollerGLFW

Input functionality in C++ for use with the GLFW library on Windows.
Instead of events in this Input library you have to test for if the button is pressed in an update function.

Allows to check 
* If a keyboard button was just pressed this frame
* If a keyboard button was just release this frame
* If a keyboard button is down/held down

* If a mouse button was just pressed this frame
* If a mouse button was just release this frame
* If a mouse button is held down
* Get mouse scroll value
* Set visibility of mouse cursor
* Get position of mouse cursor

Provides an example that is combined with the GLFW simple window example
