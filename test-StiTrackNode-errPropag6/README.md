Compile and run
---------------

To compile the test do:

    $ cd my-tests
    $ mkdir build && cd build
    $ cmake -D CMAKE_BUILD_TYPE=RelWithDebInfo ../
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
