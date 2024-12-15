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

# Open the files in Sublime Text and set the layout
subl --command "focus_group {\"group\": 0}" && subl A.cpp && subl --command "focus_group {\"group\": 1}" && subl inputf.in && subl --command "focus_group {\"group\": 2}" && subl outputf.out && subl --command "focus_group {\"group\": 0}"