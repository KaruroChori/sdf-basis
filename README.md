Basic repository to have a functional environment to start coding in, tailored to suit my needs.
SDF sketch implementation.

> `git submodule update --init --recursive` > `mkdir build` > `cd build` > `cmake ..` > `make all -j32`

You can also use `make test` to execute all the tests the library comes with (after `make all`), and `make doxygen` to generate its documentation.
There might be additional dependencies to be resolved for that on your system.

- **opt**: the external components.
- **src**: the actual C++ files to be compiled into the exported library.
- **apps**: C++ subprojects to be compiled and linked based on the exported library.
- **test-suite**: C++ sub-projects used to test the library.
- **benchmark-suite**: C++ sub-projects used to test performance of the library (not used in this project).
- **scripts**: folder with utility scripts (not used in this project).
- **header**: .h files for this framework.
- **docs**: the documentation of the project.
- **private**: temporary storage for uncompleted stuff stored only locally.
