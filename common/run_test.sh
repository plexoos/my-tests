#!/usr/bin/env bash
#
# $ run_test.sh <test_name>
#
# <test_name>:
#    
#    test-StiTrackNode-errPropag6
#    test-StiTrackNodeHelper-joinTwo
#

TEST_DIR=~/my-tests
TEST_NAME=$1
RESULT_CSV=~/my-tests/${TEST_NAME}/results.csv

# Declare array of cxx options to test
CXX_OPTIONS=(
    "-O2 -m32 -msse -mno-avx -ftree-vectorize"
    "-O2 -m32 -msse -mno-avx -fno-tree-vectorize"
    "-O2 -m32 -msse -mno-avx -ftree-vectorize -D EIGEN_DONT_VECTORIZE"
    "-O2 -m32 -msse -mno-avx -fno-tree-vectorize -D EIGEN_DONT_VECTORIZE"

    "-O3 -m32 -msse -mno-avx -ftree-vectorize"
    "-O3 -m32 -msse -mno-avx -fno-tree-vectorize"
    "-O3 -m32 -msse -mno-avx -ftree-vectorize -D EIGEN_DONT_VECTORIZE"
    "-O3 -m32 -msse -mno-avx -fno-tree-vectorize -D EIGEN_DONT_VECTORIZE"

    "-O2 -m64 -msse -mno-avx -ftree-vectorize"
    "-O2 -m64 -msse -mno-avx -fno-tree-vectorize"
    "-O2 -m64 -msse -mno-avx -ftree-vectorize -D EIGEN_DONT_VECTORIZE"
    "-O2 -m64 -msse -mno-avx -fno-tree-vectorize -D EIGEN_DONT_VECTORIZE"

    "-O3 -m64 -msse -mno-avx -ftree-vectorize"
    "-O3 -m64 -msse -mno-avx -fno-tree-vectorize"
    "-O3 -m64 -msse -mno-avx -ftree-vectorize -D EIGEN_DONT_VECTORIZE"
    "-O3 -m64 -msse -mno-avx -fno-tree-vectorize -D EIGEN_DONT_VECTORIZE"
)

# Additional cmake options corresponding to CXX_OPTIONS
CMAKE_OPTIONS=(
    "-D EIGEN_INCLUDE_DIR=~/eigen-67e894c6cd8f/ -D ROOT_CONFIG_EXECUTABLE=/afs/rhic.bnl.gov/star/ROOT/5.34.30/.sl68_gcc482/rootdeb/bin/root-config"
    "-D EIGEN_INCLUDE_DIR=~/eigen-67e894c6cd8f/ -D ROOT_CONFIG_EXECUTABLE=/afs/rhic.bnl.gov/star/ROOT/5.34.30/.sl68_gcc482/rootdeb/bin/root-config"
    "-D EIGEN_INCLUDE_DIR=~/eigen-67e894c6cd8f/ -D ROOT_CONFIG_EXECUTABLE=/afs/rhic.bnl.gov/star/ROOT/5.34.30/.sl68_gcc482/rootdeb/bin/root-config"
    "-D EIGEN_INCLUDE_DIR=~/eigen-67e894c6cd8f/ -D ROOT_CONFIG_EXECUTABLE=/afs/rhic.bnl.gov/star/ROOT/5.34.30/.sl68_gcc482/rootdeb/bin/root-config"
    "-D EIGEN_INCLUDE_DIR=~/eigen-67e894c6cd8f/ -D ROOT_CONFIG_EXECUTABLE=/afs/rhic.bnl.gov/star/ROOT/5.34.30/.sl68_gcc482/rootdeb/bin/root-config"
    "-D EIGEN_INCLUDE_DIR=~/eigen-67e894c6cd8f/ -D ROOT_CONFIG_EXECUTABLE=/afs/rhic.bnl.gov/star/ROOT/5.34.30/.sl68_gcc482/rootdeb/bin/root-config"
    "-D EIGEN_INCLUDE_DIR=~/eigen-67e894c6cd8f/ -D ROOT_CONFIG_EXECUTABLE=/afs/rhic.bnl.gov/star/ROOT/5.34.30/.sl68_gcc482/rootdeb/bin/root-config"
    "-D EIGEN_INCLUDE_DIR=~/eigen-67e894c6cd8f/ -D ROOT_CONFIG_EXECUTABLE=/afs/rhic.bnl.gov/star/ROOT/5.34.30/.sl68_gcc482/rootdeb/bin/root-config"
    "-D EIGEN_INCLUDE_DIR=~/eigen-67e894c6cd8f/ -D ROOT_CONFIG_EXECUTABLE=/afs/rhic.bnl.gov/star/ROOT/5.34.30/.sl68_x8664_gcc482/rootdeb/bin/root-config"
    "-D EIGEN_INCLUDE_DIR=~/eigen-67e894c6cd8f/ -D ROOT_CONFIG_EXECUTABLE=/afs/rhic.bnl.gov/star/ROOT/5.34.30/.sl68_x8664_gcc482/rootdeb/bin/root-config"
    "-D EIGEN_INCLUDE_DIR=~/eigen-67e894c6cd8f/ -D ROOT_CONFIG_EXECUTABLE=/afs/rhic.bnl.gov/star/ROOT/5.34.30/.sl68_x8664_gcc482/rootdeb/bin/root-config"
    "-D EIGEN_INCLUDE_DIR=~/eigen-67e894c6cd8f/ -D ROOT_CONFIG_EXECUTABLE=/afs/rhic.bnl.gov/star/ROOT/5.34.30/.sl68_x8664_gcc482/rootdeb/bin/root-config"
    "-D EIGEN_INCLUDE_DIR=~/eigen-67e894c6cd8f/ -D ROOT_CONFIG_EXECUTABLE=/afs/rhic.bnl.gov/star/ROOT/5.34.30/.sl68_x8664_gcc482/rootdeb/bin/root-config"
    "-D EIGEN_INCLUDE_DIR=~/eigen-67e894c6cd8f/ -D ROOT_CONFIG_EXECUTABLE=/afs/rhic.bnl.gov/star/ROOT/5.34.30/.sl68_x8664_gcc482/rootdeb/bin/root-config"
    "-D EIGEN_INCLUDE_DIR=~/eigen-67e894c6cd8f/ -D ROOT_CONFIG_EXECUTABLE=/afs/rhic.bnl.gov/star/ROOT/5.34.30/.sl68_x8664_gcc482/rootdeb/bin/root-config"
    "-D EIGEN_INCLUDE_DIR=~/eigen-67e894c6cd8f/ -D ROOT_CONFIG_EXECUTABLE=/afs/rhic.bnl.gov/star/ROOT/5.34.30/.sl68_x8664_gcc482/rootdeb/bin/root-config"
)

BUILD_DIRS=()

# The following arguments can be test dependent but we combine them into
# a single string in order to use a common functionality in run_tests()

# Arg test_func_name:
#ARGS1=( "orig" "orig_no_branch" "trasat" "smatrix" "eigen" )
ARGS1=( "orig" "eigen_NxN" )
# Arg n_iterations:
ARGS2=( "" )
# Arg zero_freq:
#ARGS3=( -1 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 )
ARGS3=( "" )

COMBO_ARGS=()


echo "The following variables are set:"
echo -e "\t TEST_DIR:      ${TEST_DIR}"
echo -e "\t RESULT_CSV:    ${RESULT_CSV}"
echo -e "\t ARGS1:         ${ARGS1[*]}"
echo -e "\t ARGS2:         ${ARGS2[*]}"
echo -e "\t ARGS3:         ${ARGS3[*]}"

# Combine arguments into a single string
for ARG1 in "${ARGS1[@]}"
do
   for ARG2 in "${ARGS2[@]}"
   do
       for ARG3 in "${ARGS3[@]}"
       do
           COMBO_ARGS+=("$ARG1 $ARG2 $ARG3")
       done
   done
done


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

        cmd="cmake ${CMAKE_OPTIONS[$index]} -D CMAKE_CXX_FLAGS=\" ${CXX_OPTIONS[$index]} \" ../"
        echo "$ $cmd"
        eval $cmd

        cmd="cmake --build . --target ${TEST_NAME}"
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

        for COMBO_ARG in "${COMBO_ARGS[@]}"
        do
            cmd="${BUILD_DIR}/${TEST_NAME} ${COMBO_ARG}"  # &>> ${BUILD_DIR}/log"

            printf "$ $cmd\n"

            # Create array of measurements
            time_meas=()

            for (( i=1; i<=${n_meas}; i++ ))
            do
               time_meas+=( $( $cmd ) )
            done

            printf "time_meas: ${time_meas[*]}\n"

            stats=( $(calc_stats ${time_meas[@]}) )

            # Print average and variance
            #csv_output="$COMBO_ARG, $n_meas, ${stats[2]}, ${stats[3]}, "
            csv_output="$COMBO_ARG, ${stats[2]}, ${stats[3]}, "
            printf "$csv_output\n" | tee -a ${RESULT_CSV}

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
