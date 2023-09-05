#!/bin/bash

# Find all .c files in the current directory
c_files=$(find . -maxdepth 1 -type f -name "*.c")

# Compile each .c file into a corresponding .o file
for file in $c_files; do
    filename=$(basename "$file")
    object_file="${filename%.c}.o"
    gcc -c "$file" -o "$object_file"
done

# Create the static library liball.a from all the .o files
ar rcs liball.a *.o

# Clean up the .o files (optional)
rm -f *.o

echo "Static library liball.a created successfully."
