Compile and run (Linux)
-----------------------

    $ git clone https://github.com/plexoos/my-tests.git
    $ cd my-tests && mkdir build && cd build
    $ cmake -D CMAKE_BUILD_TYPE=Release ../
    $ cmake --build .

Some targets may require additional flags. For example,

* **test-StiTrackNode-errPropag6**

      -D EIGEN_INCLUDE_DIR=~/eigen-67e894c6cd8f/
      -D CMAKE_CXX_FLAGS="-march=native"


Link to test results (gihub.io pages)
-------------------------------------

[test-StiTrackNode-errPropag6](https://plexoos.github.io/my-tests/test-StiTrackNode-errPropag6/)
