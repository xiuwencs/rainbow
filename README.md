# Description
The source codes can be used to reproduce the key experimental results reported in RAINBOW. We recommend a software environment with Linux Ubuntu 22.04, GCC 11.2.0, and CMake 3.2.
##  Directories

### (1) datasets

We put datasets and regular expression sets in this directory. 
Each dataset includes three forms: compressed, fully decompressed, and decoded.
The decompressed and decoded are converted from the compressed data.
Due to the limitation of uploading large files, we only release the Alexa dataset on Github.
You can find all the datasets on Zenodo (https://doi.org/10.5281/zenodo.7684125).

### (2) tables
    
We use a regular expression matching engine (http://regex.wustl.edu) to export DFA tables and convert the tables into state transition table form. The matching programs read these transition tables to construct the regular expression matching engine.

### (3) decoding
    
We put the source codes of decoding in this directory. They can be used to generate the decompressed and decoded data.


### (4) matching

This directory contains the source codes of the matching. Each method includes a compile.sh script and some execution scripts for generating executable programs and reproducing results.

## How-to
Please fetch the code from the repository, ensure software dependencies, and run the scripts to obtain the corresponding results. The results will be printed on the console after finishing the evaluation.

### (1) Decoding

Enter the decoding directory and run the following commands to obtain the decoding time in Fig.6.

``` bash
$ cd  decoding/scripts
$ bash GetFigure6.sh
```

(2) Matching

Enter the matching directory and run the following commands to obtain the skipped ratio and matching time in Table 2 and Fig.7. We dismiss the time of checking and recording the matched patterns in Algorithm 2.

``` bash
$ cd  matching/scripts
$ bash GetFigure7(a).sh
$ bash GetFigure7(b).sh
$ bash GetFigure7(c).sh
$ bash GetFigure7(d).sh
```

You can repeat the experiments above to obtain the results of memory consumption in Table 3. Please note that you need to hang up the process first and follow the commands to get the results.
``` bash
$ ps -aux | grep {process-id} | awk '{print $5}'
```
