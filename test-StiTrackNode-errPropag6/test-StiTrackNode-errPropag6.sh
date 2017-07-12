#!/usr/bin/env bash

ARGS1=( "eigen" "smatrix" "trasat" "orig" "orig_no_branch" )
ARGS3=( -1 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 )


echo "The following variables are set:"
echo -e "\t ARGS1:      ${ARGS1[*]}"
echo -e "\t ARGS3:      ${ARGS3[*]}"


for ARG1 in "${ARGS1[@]}"
do
   for ARG3 in "${ARGS3[@]}"
   do
      cmd="./test-StiTrackNode-errPropag6 ${ARG1} -1 ${ARG3}"

      echo "Running cmd:"
      echo "$ $cmd"
      eval $cmd
      echo
   done
done
