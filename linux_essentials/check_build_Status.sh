#!/bin/bash

BUILD_DIR=${1:-./build}

echo "Checking build directory: $BUILD_DIR"
echo "-----------------------------------"

# 1️⃣ Check if directory exists
if [ ! -d "$BUILD_DIR" ]; then
    echo "❌ Build directory does not exist"
    exit 2
fi

# 2️⃣ Check if directory is empty
if [ -z "$(ls -A "$BUILD_DIR")" ]; then
    echo "⚠️ Build directory exists but is empty"
    exit 3
fi

# 3️⃣ Determine build status using files
STATUS="UNKNOWN"

if [ -f "$BUILD_DIR/success.flag" ]; then
    STATUS="SUCCESS"
elif [ -f "$BUILD_DIR/failure.flag" ]; then
    STATUS="FAILURE"
elif [ -f "$BUILD_DIR/in_progress.flag" ]; then
    STATUS="IN_PROGRESS"
fi

# 4️⃣ Case statement to handle status
case "$STATUS" in
    SUCCESS)
        echo "✅ Build completed successfully"
        exit 0
        ;;
    FAILURE)
        echo "❌ Build failed"
        exit 1
        ;;
    IN_PROGRESS)
        echo "⏳ Build is still in progress"
        exit 4
        ;;
    *)
        echo "❓ Build status unknown"
        exit 5
        ;;
esac
