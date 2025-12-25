#!/bin/bash

# Default values if env vars are not set
BUILD_ENV=${BUILD_ENV:-dev}
DEBUG=${DEBUG:-true}
OPTIMIZE=${OPTIMIZE:-true}
CLEAN=${CLEAN:-false}

echo "🔧 Build Configuration"
echo "---------------------"
echo "Environment : $BUILD_ENV"
echo "Debug Mode  : $DEBUG"
echo "Optimize    : $OPTIMIZE"
echo "Clean Build : $CLEAN"
echo "---------------------"

BUILD_DIR="build"

# Clean build
if [ "$CLEAN" = "true" ]; then
    echo "🧹 Cleaning build directory..."
    rm -rf "$BUILD_DIR"
fi

mkdir -p "$BUILD_DIR"

# Simulate build steps
if [ "$DEBUG" = "true" ]; then
    echo "⚙️ Building with DEBUG flags"
    echo "debug=true" > "$BUILD_DIR/config.txt"
else
    echo "⚙️ Building without debug"
    echo "debug=false" > "$BUILD_DIR/config.txt"
fi

if [ "$OPTIMIZE" = "true" ]; then
    echo "⚡ Applying optimizations"
    echo "optimize=true" >> "$BUILD_DIR/config.txt"
else
    echo "optimize=false" >> "$BUILD_DIR/config.txt"
fi

echo "env=$BUILD_ENV" >> "$BUILD_DIR/config.txt"

# Simulate artifact
echo "binary data" > "$BUILD_DIR/app.bin"
touch "$BUILD_DIR/success.txt"

echo "✅ Build completed successfully"
