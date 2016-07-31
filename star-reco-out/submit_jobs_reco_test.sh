#!/usr/bin/env bash
#
# Use this script to submit event reconstruction jobs to the linux farm
#

# The file with a list of zerobias data files to use in embedding
: ${INPUT_FILE_LIST:=filelist_reco_test.txt}

# $HOME/scratch/wbos_embed/
: ${OUT_DIR:=/path/to/some_dir} && mkdir -p $OUT_DIR && OUT_DIR=`cd "$OUT_DIR"; pwd`

# We use the output directory as A human readable unique request ID
REQUEST_UID=$(basename "${OUT_DIR}")
INPUT_FILE_LIST=`readlink -f ${INPUT_FILE_LIST}`


echo -e "Named arguments and their values:"
echo -e "\t INPUT_FILE_LIST:          $INPUT_FILE_LIST"
echo -e "\t OUT_DIR:                  $OUT_DIR"
echo -e "\t REQUEST_UID:              $REQUEST_UID"


# Create output directories
mkdir -p $OUT_DIR/root/
mkdir -p $OUT_DIR/log/
mkdir -p $OUT_DIR/sums/


# Form the command to submit jobs to farm
COMMAND="star-submit-template -template job_reco_test.xml \
   -entities  OUT_DIR=$OUT_DIR,INPUT_FILE_LIST=$INPUT_FILE_LIST,REQUEST_UID=$REQUEST_UID"

echo
echo "Executing..."
echo $COMMAND

eval $COMMAND
