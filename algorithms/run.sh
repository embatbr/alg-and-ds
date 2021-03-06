#!/bin/bash


UTILS="../utils.c"

FILENAME="$1"

if [ ! -d "bin" ]; then
    mkdir bin
fi

out="`(gcc $UTILS $FILENAME.c $FILENAME.test.c -o bin/$FILENAME) 2>&1`"
if [ -z "$out" ]; then
    ./bin/$FILENAME
else
    echo "ERR: $out"
fi
