#!/bin/bash
set -e
g++ main.cpp -o count
./count $*
#That first line indicates that we are making a BASH script. The second line tells it to abort if any errors occur. The third line compiles your program. The fourth line runs your program. Note that the $* tells it to pass any arguments on to your program. (We will demonstrate using arguments later.)