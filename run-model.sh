#!/bin/bash

binfile=$1
shift 1 

# setup to convert fifo stream
mkfifo $$.fifo
while read -r line
do
	echo $line | ./csv2bin >> $binfile
done < $$.fifo &

# run model
$@ output refresh=${refresh:-100} file=$$.fifo

# clean up
rm $$.fifo
