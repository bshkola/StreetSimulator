#!/bin/bash

#Script for compilation and installation of the program.
#> ./install.sh [clean] [debug]
#
# --clean
#   clean
#  -c
#       switches script into cleaning mode - script removes all files that
#       are created during compilation and installation
#       INCLUDING ./bin directory with all contents (executable file,
#       among others)
#
# --debug
#   debug
#  -d
#       switches script into debugging mode - output from 'make' and
#       'make clean' commands will not be suppressed
#
# Both of the arguments can be used simultaneously. Combinations of '-cd' or
# '-dc' are also accepted.

################################################################################

# Command line arguments' interpretation module

clean=0 # cleaning mode flag (default = off)
debug=0 # debugging mode flag (default = off)

while [ $# -gt 0 ] ; do # if any arguments exists do for each argument
    case "$1" in # if currently processed argument is one of the following
        "clean") clean=1
            ;;
        "debug") debug=1
            ;;
        "--clean") clean=1
            ;;
        "--debug") debug=1
            ;;
        "-c") clean=1
            ;;
        "-d") debug=1
            ;;
        "-cd") debug=1
             clean=1
            ;;
        "-dc") debug=1
             clean=1
            ;;
        *) 
            ;;
    esac
    shift
done

################################################################################

# Cleaning module

if [ $clean -eq 1 ] ;  then # depend on 'clean' flag proceed cleaning instead of
                            # compilation and installation
    echo "Performing cleaning procedure. Please wait."
    if [ -d "bin" ]; then # if ./bin directory exists
        rm -rf ./bin        # purge it and it's content
    fi
    
    qmake -o Makefile ZPR-v1.pro # creating Makefile (for 'make clean' command)
    
    if [ $debug -eq 1 ] ; then #depend on 'debug' flag don't suppress output
        make clean                  # debug mode - visible output
    else
        make clean > /dev/null 2>&1 # release mode - suppresed output
    fi
    
    rm Makefile # remove Makefile
    
    echo "Cleaning finished."
    
    exit 0
fi

################################################################################

# Compilation and installation module

echo "Compiling the program. It may take a while. Please wait."
qmake -o Makefile ZPR-v1.pro # creating Makefile

if [ $debug -eq 1 ] ;  then # depend on 'debug' flag do not suppress output
    make                        # debug mode - visible output
    make clean                  # debug mode - visible output
else
    make > /dev/null 2>&1       # release mode - suppressed output
    make clean > /dev/null 2>&1 # release mode - suppressed output
fi

rm Makefile # remove Makefile
echo "Compilation finished."

echo "Installing the program."
if [ -d "bin" ]; then # if ./bin directory exists
    rm -rf ./bin/*      # purge ./bin directory's content
else                  # if ./bin directory does not exist
    mkdir bin           # create new ./bin directory
fi

mv ZPR-v1 ./bin/. # move executable file to ./bin directory

if [ -f "records.sh" ]; then # if database access script exists
    cp records.sh ./bin/.      # copy it to ./bin
fi

if [ -f "config" ]; then # if configuration file exists
    cp config ./bin/.      # copy it to ./bin
fi
echo "Installation finished."

################################################################################
