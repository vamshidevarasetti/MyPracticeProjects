#!/bin/bash

SRC_DIR=${1:-./data}
DEST_DIR="./backup"

backup_file() {
    file=$1
    cp "$file" "$DEST_DIR/"
    echo "✔ Backed up: $(basename "$file")"
}

mkdir -p "$DEST_DIR"

for f in "$SRC_DIR"/*; do
    if [ -f "$f" ]; then 
        backup_file "$f"
    fi
done
