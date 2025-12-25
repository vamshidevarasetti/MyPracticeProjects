#!/bin/bash

LOG_FILE="app.log"

ERROR_COUNT=0

while IFS= read -r line; do
    if echo "$line" | grep -qi "ERROR"; then
        #echo "$line"
        echo "$line" | awk '{print $1, $2}'
        ((ERROR_COUNT++))
    fi
done < "$LOG_FILE"

echo "---------------------"
echo "Total ERROR lines: $ERROR_COUNT"
