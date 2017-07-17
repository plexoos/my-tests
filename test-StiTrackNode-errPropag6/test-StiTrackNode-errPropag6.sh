#!/usr/bin/env bash

TEST_DIR=~/my-tests
RESULT_DIR=~/my-tests/test-StiTrackNode-errPropag6/results

# Declare array of cxx options to test
CXX_OPTIONS=(
    "-march=native -O2 -m32 -mno-avx"
    "-march=native -O2 -m64 -mno-avx"
    "-march=native -O2 -m32 -mavx"
    "-march=native -O2 -m64 -mavx"
    "-march=native -O3 -m32 -mno-avx"
    "-march=native -O3 -m64 -mno-avx"
    "-march=native -O2 -m32 -fno-tree-vectorize -D EIGEN_DONT_VECTORIZE"
    "-march=native -O2 -m64 -fno-tree-vectorize -D EIGEN_DONT_VECTORIZE"
)

BUILD_DIRS=()

ARGS1=( "eigen" "smatrix" "trasat" "orig" "orig_no_branch" )
#ARGS3=( -1 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 )
ARGS3=( -1 )


echo "The following variables are set:"
echo -e "\t ARGS1:      ${ARGS1[*]}"
echo -e "\t ARGS3:      ${ARGS3[*]}"


function make_build_dirs
{
    cd $TEST_DIR

    for CXX_OPTION in "${CXX_OPTIONS[@]}"
    do
        BUILD_DIR="build_"
        TMP_CXX_OPTION=`echo ${CXX_OPTION} | sed 's/ /_/g'`
        TMP_CXX_OPTION=`echo ${TMP_CXX_OPTION} | sed 's/=/_/g'`
        BUILD_DIR+=$TMP_CXX_OPTION

        mkdir -p $BUILD_DIR

        BUILD_DIRS+=($BUILD_DIR)
    done

    for BUILD_DIR in "${BUILD_DIRS[@]}"
    do
        echo -e "\t BUILD_DIR: ${BUILD_DIR}"
    done
}


function run_build
{
    cd $TEST_DIR

    for index in ${!CXX_OPTIONS[*]}
    do
        echo "$ cd ${BUILD_DIRS[$index]}"
        cd ${BUILD_DIRS[$index]}

        cmd="cmake -D EIGEN_INCLUDE_DIR=~/eigen-67e894c6cd8f/ -D CMAKE_CXX_FLAGS=\" ${CXX_OPTIONS[$index]} -D NDEBUG\" ../"
        echo "$ $cmd"
        eval $cmd

        cmd="cmake --build . --target test-StiTrackNode-errPropag6 -- VERBOSE=1"
        echo "$ $cmd"
        eval $cmd

        cd ../
    done
}


function run_tests
{
    for index in ${!CXX_OPTIONS[*]}
    do
        BUILD_DIR=${BUILD_DIRS[$index]}

        for ARG1 in "${ARGS1[@]}"
        do
           for ARG3 in "${ARGS3[@]}"
           do
              cmd="${BUILD_DIR}/test-StiTrackNode-errPropag6 ${ARG1} -1 ${ARG3} &>> ${BUILD_DIR}/log"

              echo $cmd >> ${BUILD_DIR}/log

              echo "Running cmd:"
              echo "$ $cmd"
              eval "$cmd"
              echo

              echo >> ${BUILD_DIR}/log

           done
        done

    done
}


function extract_result
{
    for BUILD_DIR in "${BUILD_DIRS[@]}"
    do
        cmd="grep elapsed ${BUILD_DIR}/log > ${RESULT_DIR}/${BUILD_DIR}.csv"

        echo "Running cmd:"
        echo "$ $cmd"
        eval "$cmd"
        echo
    done
}


# The main part starts here

make_build_dirs
run_build
run_tests
extract_result
