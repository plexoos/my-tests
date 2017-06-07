This directory currently contains two tests for the
`StiTrackNode::errPropag6(double G[21], const double F[6][6])` function:

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

    $ test-StiTrackNode-errPropag6 <test_func_name> <n_iterations> <freq_of_zeros>

with the following values

    <test_func_name>:  {orig, orig_no_branch, trasat, smatrix, eigen}
    <n_iterations>:    The number of measurements
    <freq_of_zeros>:   f = (0, 1] or f <= 0 for realistic simulation


Results
-------

We benchmark the following versions of the `StiTrackNode::errPropag6()`
function with 10,000,000 iterations.

* [orig.h](orig.h) - The original version used in Sti

* [orig_no_branch.h](orig_no_branch.h) - No `if` statements to check (non-)zero
  matrix elements inside the nested `for`-loops. This removes the need for CPU branch prediction

* [trasat.h](trasat.h) - Based on `TCL::trasat`

* [smatrix.h](smatrix.h) - Vectorized calculation based on `ROOT::Math::SMatrix`

* [eigen.h](eigen.h) - Vectorized calculation based on `Eigen` library

The plot below shows the time spent in the function for a set of `f` values
ranging from 0.1 to 0.9. The first point at f = 0 corresponds to the measured
rate for realistic simulation.

<iframe width="800" height="600" frameborder="0" scrolling="yes" src="//plot.ly/~plexoos/2.embed">
  <a href="https://plot.ly/~plexoos/2/?share_key=utCiob32MBUoBG1UjixSzm" target="_blank">
  <img src="https://plot.ly/~plexoos/2.png?share_key=utCiob32MBUoBG1UjixSzm" style="max-width: 100%;"  width="800"/>
  </a>
</iframe>

40% gain in speed when switching from `orig` to `eigen` saves

27% gain in speed when switching from `orig` to `smatrix` or `orig_no_branch`


#### Estimating rate of zero matrix elements

For realistic simulation we sampled inputs from 10k calls during reconstruction
of a single real event.

Frequency of zeros in F matrix by element index

![h_F_zero_rate.png](https://plexoos.github.io/my-tests/test-StiTrackNode-errPropag6/h_F_zero_rate.png)

Frequency of zeros in G matrix by element index

![h_G_zero_rate.png](https://plexoos.github.io/my-tests/test-StiTrackNode-errPropag6/h_G_zero_rate.png)
