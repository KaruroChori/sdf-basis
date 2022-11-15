Just few notes about the solution I am presenting, to explain its rationale and what I considered in its optimization.

This implementation is using [SDF](https://en.wikipedia.org/wiki/Signed_distance_function) (Signed Distance Fields) to perform the computation needed. An external library [glm](https://github.com/g-truc/glm) is used, since it provides the same primitives as in GSGL, a C like shader language for Vulkan/OpenGL/etc.
This is desirable since that could can be used almost 1-1 to implement a compute shader, and offload it to GPUs. This means that milions of points could be evaluated as fast as one would take on a normal processor. SDF are usually used in conjunction with ray-marching for 2d and 3d rendering of boundary shapes. This is common in CAD software and game engines alike.

It is not going to be the most optimized solution for the restricted domain of the original assignment, but given the optional sub-task, and what would be any realistic extension of that, I think it is the most suitable.

The current code could be trivially extended to include any kind of parametric boudary shape for which an SDF is known or derivable in a closed form, like Bezeir curves.
Basically, my final submission is just a simplified version of how a Sketch would be implemented in a 2d CAD environment.
