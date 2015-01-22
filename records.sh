#!/bin/bash

#Script for showing last N records from database in reversed order (newest first).
#Script accepts one argument - number of newest records to display.
#If argument is not defined, default ammount of 10 is used.

# number of records to display (default = 10)
record_number=10

regexp='^[0-9]+$'
# checking if argument supplied
if [ -n "$1" ] ; then
    # checking if argument is valid unsigned integer
    if ! [[ $1 =~ $regexp ]] ; then
        # not a valid unsigned integer
        echo "Warning: Argument is not a valid number! Using default setting."
    else
        # a valid unsigned integer
        record_number=$1 # number of records to display from argument
    fi
fi

# configuration file name
filename="config"

# reading configuration file
config_entries=()
i=0
while read -r line
do
    config_entries[i]=$line
    i=$(($i + 1))
done < "$filename"

#executing MySQL command
mysql -h ${config_entries[0]} -u ${config_entries[1]} -p${config_entries[2]} -e "USE ${config_entries[3]}; SELECT * FROM ${config_entries[4]} ORDER BY id DESC LIMIT $record_number;"
