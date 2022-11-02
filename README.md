# Double-Pendulum-Visualtisation
Visualise the output of a swinging pendulum attached to a second swining pendulum. The motion is classified as chaos.

REQUIRES SDL2 AND SDL2_IMAGE libraries. (Simple Directmedia Layer)

Progress 1) 4th order runge-kutta algorithm implemented succesfully.

Profress 2) SDL Library succesfully installed and used to output data to screen. At the moment I have two points travelling across the screen capped at 60FPS. These points positions simply have to be dettached from the counter that iterates their position and the solutions of the double pendulum will be what determines their positions instead.

Next 1) Input the double pendulum system functions to evaluate the double pendulum solution positions. The two points will can then move with the pendulum.

Next 2) Connect a line between the two points and the first point and the origin. This will represent the pendulum bars/strings. Presumably will require image rotation to match pendulum angles at each frame of simulation.


A single swinging pendulum exhibits periodic, predictable, non-chaotic motion. That is to say that it repeats itself (infinitely if there is no energy loss), and a small change in the initial motion of the pendulum does not create a large difference in the motion at a much later time. However, attaching a second pendulum to the bottom of the first pendulum provides an example of chaotic motion. Even a tiny change in the initial motion of the pendulum system will create massive changes at later time. In other words, two intial states extremely similar to each other will become compeletely different after a certain amount of time. The goal of this little project is to visualise the solutions in real space, in real time, rather than a create static graphs of the pendulum positions x1(t) and x2(t). Static graphs are boring, real-time simulations are fun!
