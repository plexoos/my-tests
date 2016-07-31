
To verify that the output from reconstruction jobs executed over the same input
is identical, we submit a large number of small identical jobs to the farm. By
default, the `submit_jobs_reco_test.sh` script uses the provided
`filelist_reco_test.txt` filelist to create 400 jobs with 10 events each.

Clone this repository:

    $ git clone https://github.com/plexoos/my-tests.git
    $ cd my-tests/star-reco-out

From an interactive node submit the jobs as:

    $ OUT_DIR=/path/to/scratch/reco_test submit_jobs_reco_test.sh

When the jobs finish inspect the content of log files in
`$OUT_DIR/log/*_bfc.log`
