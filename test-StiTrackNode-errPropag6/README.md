
This directory currently contains two tests for the
`StiTrackNode::errPropag6()` function:

* `main-errPropag6-vs-trasat-output.cxx` compares the output of `errPropag6()`
to that of `TCL::trasat()`. Both functions are supposed to calculate the matrix
operation given by `ASA^T` with A, S, and A^T being 6x6 matrices. The test can
be compiled at ideone (http://ideone.com/tI1MgY) or by simply doing:

    $ g++ -std=c++11 main-errPropag6-vs-trasat-output.cxx

* `main.cxx` profiles `errPropag6()` in its original and modified versions. See
below for details.


Compile and run
---------------

To compile the test do:

    $ cd my-tests
    $ mkdir build && cd build
    $ cmake -D EIGEN_INCLUDE_DIR=~/eigen-eigen-67e894c6cd8f/ -D CMAKE_CXX_FLAGS="-march=native" -D CMAKE_BUILD_TYPE=Release ../
    $ make

Benchmark one of the versions of `StiTrackNode::errPropag6()` by running the
test as:

    $ test-StiTrackNode-errPropag6 before
    $ test-StiTrackNode-errPropag6 after

The two versions [before.h](before.h) and [after.h](after.h) test the effect of
the CPU branch prediction by removing the check for non-zero matrix elements
inside the nested for-loops.


Results
-------

* With realistic distribution of zeros in the F and G matrices (see below)

      before: 5.745004423 s
      after:  6.694923842 s

* With zero rate `f` in all matrix elements

  * f = 0.05

        before: 9.584304128
        after:  6.662425031


  * f = 0.10

        before: 11.655979576
        after:   6.406468481

  * f = 0.50

        before: 17.545420334
        after:   6.710300206

  * f = 0.90

        before: 7.158184174
        after:  6.679330367


For realistic simulation 10k calls were made to sample the inputs.

Frequency of zeros in F matrix by element index

![h_F_zero_rate.png](https://plexoos.github.io/my-tests/test-StiTrackNode-errPropag6/h_F_zero_rate.png)

Frequency of zeros in G matrix by element index

![h_G_zero_rate.png](https://plexoos.github.io/my-tests/test-StiTrackNode-errPropag6/h_G_zero_rate.png)
