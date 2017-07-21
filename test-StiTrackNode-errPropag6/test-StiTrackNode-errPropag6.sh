#!/usr/bin/env bash

TEST_DIR=~/my-tests
RESULT_CSV=~/my-tests/test-StiTrackNode-errPropag6/results.csv

# Declare array of cxx options to test
CXX_OPTIONS=(
    "-march=native -O2 -m32 -fno-tree-vectorize -D EIGEN_DONT_VECTORIZE"
    "-march=native -O2 -m32 -mavx"
    "-march=native -O2 -m32 -mno-avx"
    "-march=native -O3 -m32 -mno-avx"
    "-march=native -O2 -m64 -fno-tree-vectorize -D EIGEN_DONT_VECTORIZE"
    "-march=native -O2 -m64 -mavx"
    "-march=native -O2 -m64 -mno-avx"
    "-march=native -O3 -m64 -mno-avx"
)

BUILD_DIRS=()

ARGS1=( "eigen" "smatrix" "trasat" "orig" "orig_no_branch" )
#ARGS3=( -1 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 )
ARGS3=( -1 )


echo "The following variables are set:"
echo -e "\t TEST_DIR:      ${TEST_DIR}"
echo -e "\t RESULT_CSV:    ${RESULT_CSV}"
echo -e "\t ARGS1:         ${ARGS1[*]}"
echo -e "\t ARGS3:         ${ARGS3[*]}"


#
# Create build directories for all sets of compiler flags specified in global
# $CXX_OPTIONS
#
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


#
# Accepts an array of values, e.g. "11 22 33 44 55 66" and calculates its
# basic statistical properties by means of `awk`.
#
function calc_stats()
{
    local arr=("$@")
    local arr_string=${arr[*]}

    local stats=$(awk -v var="$arr_string" 'BEGIN{
      split(var, values," ");

      n = length(values);
      min = max = sum = values[1];       # Initialize to the first value (2nd field)
      sum2 = values[1] * values[1];     # Running sum of squares

      for (i = 2; i <= n; i++) {
        if (values[i] < min) min = values[i];    # Current minimum
        if (values[i] > max) max = values[i];    # Current maximum
        sum  += values[i];                         # Running sum of values
        sum2 += values[i] * values[i];           # Running sum of squares
      }

      print  min, max, sum/n, sqrt( ( sum2 - (sum*sum)/n )/(n-1) )
    }')

    echo $stats
}


function run_tests
{
    n_meas=$1

    printf "$(date)\n" | tee -a ${RESULT_CSV}
    printf "n_meas: $n_meas\n\n" | tee -a ${RESULT_CSV}

    for index in ${!CXX_OPTIONS[*]}
    do
        BUILD_DIR=${BUILD_DIRS[$index]}

        # The commans should match the csv_output format below
        #printf "test, , , $BUILD_DIR, sigma, \n" >> ${RESULT_CSV}
        printf "test, $BUILD_DIR, sigma, \n" >> ${RESULT_CSV}

        for ARG1 in "${ARGS1[@]}"
        do
           for ARG3 in "${ARGS3[@]}"
           do
              cmd="${BUILD_DIR}/test-StiTrackNode-errPropag6 ${ARG1} -1 ${ARG3}"  # &>> ${BUILD_DIR}/log"

              printf "$ $cmd\n"

              # Create array of measurements
              time_meas=()

              for (( i=1; i<=${n_meas}; i++ ))
              do
                 time_meas+=( $( $cmd ) )
              done

              stats=( $(calc_stats ${time_meas[@]}) )

              # Print average and variance
              #csv_output="$ARG1, $ARG3, $n_meas, ${stats[2]}, ${stats[3]}, "
              csv_output="$ARG1, ${stats[2]}, ${stats[3]}, "
              printf "$csv_output\n" | tee -a ${RESULT_CSV}

           done
        done

        printf "\n" | tee -a ${RESULT_CSV}

    done
}


# The main part starts here

make_build_dirs

# This step can be skipped if it is not the first time the script is run
run_build

# Requires at least 2 measurements to calculate statistics
run_tests 10
