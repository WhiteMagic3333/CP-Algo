#!/bin/bash

# Prompt for folder name
read -p "Enter folder name: " folder_name

# Create the folder
mkdir "$folder_name" || { echo "Failed to create folder"; exit 1; }

# Navigate into the new folder
cd "$folder_name" || exit

# Create 5 C++ files (A.cpp, B.cpp, C.cpp, D.cpp, E.cpp)
for file in A B C D E; do
  touch "$file.cpp"
done

# Create inputf.in and outputf.out
touch inputf.in outputf.out

# Check if magic.h exists and copy it into the folder
if [[ -f ../magic.h ]]; then
  cp ../magic.h ./
else
  echo "magic.h not found in the parent directory."
  exit 1
fi

# Precompile magic.h using g++ (C++11 or C++14 as per the requirement)
g++ -std=c++11 magic.h || { echo "Failed to precompile magic.h"; exit 1; }

# Notify user
echo "Folder '$folder_name' created with files A.cpp, B.cpp, C.cpp, D.cpp, E.cpp, inputf.in, outputf.out, and precompiled magic.h."

# Close all files, set layout, and open files in specific groups
subl --command "close_all" && \
subl --command "set_layout {\"cols\": [0.0, 0.5, 1.0], \"rows\": [0.0, 0.5, 1.0], \"cells\": [[0, 0, 1, 2], [1, 0, 2, 1], [1, 1, 2, 2]]}" && \
subl --command "focus_group {\"group\": 1}" && subl inputf.in && \
subl --command "focus_group {\"group\": 2}" && subl outputf.out && \
subl --command "focus_group {\"group\": 0}" && subl E.cpp && subl D.cpp && subl C.cpp && subl B.cpp && subl A.cpp
