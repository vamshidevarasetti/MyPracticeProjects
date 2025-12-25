#!/bin/bash

THRESHOLD=10

while true; do
    USAGE=$(df / | awk 'NR==2 {print $5}' | tr -d '%')

    if [ "$USAGE" -ge "$THRESHOLD" ]; then
        echo "Warning: Disk usage is at high ${USAGE}%"
    else
        echo "Disk usage is OK :  ${USAGE}%"
    fi

    sleep 5
done
