Some tests can be compiled from the top directory while others have their own
CMakeLists.txt


# Compile and run (Linux)

To compile tests from the top directory do:

    $ git clone https://github.com/plexoos/my-tests.git
    $ cd my-tests && mkdir build && cd build
    $ cmake ../ && cmake --build .

Some targets may require additional flags. For example,

* **test-StiTrackNode-errPropag6**

      -D EIGEN_INCLUDE_DIR=~/eigen-67e894c6cd8f/
      -D CMAKE_CXX_FLAGS="-march=native"


# Links to some studies

<dl>

<dt>
<a href="root-branch-compress/">root-branch-compress</a>
</dt>
<dd>
We study the precision and compression of different packing modes of the
`Double32_t` and `Float16_t` types in ROOT
</dd>

<dt>
<a href="sti-profiling/">star-tracking-optimization</a>
</dt>
<dd>
A study to explore various optimization techniques for the track reconstruction
code used at the STAR experiment
</dd>

</dl>
