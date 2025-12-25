#!/bin/bash

DIR=${1:-.}

echo "listing files in directory: $DIR"
echo "------------------------------"

for file in "$DIR"/*; do
    echo "$("$file")"  
done