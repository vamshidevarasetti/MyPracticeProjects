#!/bin/bash

LOG_FILE="app.log"
TODAY=$(date +"%Y-%m-%d")
ERROR_SUMMARY="error_summary_$TODAY.txt"

echo "Date: $TODAY"
echo "Log file: $LOG_FILE"
echo "Generating error summary..."

grep "^$TODAY" "$LOG_FILE" | grep "ERROR" >> "$ERROR_SUMMARY"

if [ ! -s "$ERROR_SUMMARY" ]; then
    echo "No errors found for today." >> "$ERROR_SUMMARY"
fi

echo "Error summary saved today $ERROR_SUMMARY"
echo "--------------------------------"

cat "$ERROR_SUMMARY" \
| awk '{$1=$2=""; print}' \
| sort \
| uniq -c \
| sort -nr


TOTAL_ERRORS=$(wc -l < "$ERROR_SUMMARY")
echo "Total errors today: $TOTAL_ERRORS"

rm -rf "$ERROR_SUMMARY"

