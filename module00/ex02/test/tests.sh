# @author    Clément Vidon
# @created   230324 11:42:33  by  clem@spectre
# @modified  230324 11:42:33  by  clem@spectre
# @filename  tests.sh

#!/bin/bash

r='\033[0;31m'
g='\033[0;32m'
b='\033[0;34m'
y='\033[0;33m'
c='\033[0;36m'
m='\033[0;35m'
x='\033[0m'

tests() {
    $1 > out
    vimdiff out 19920104_091532.log
    rm -f out
}

next() {
    echo -en "${g}Please press enter to continue...${x}"
    printf "%s"
    read ans
}

run() {
    make clean
    make $1
    clear
    echo -e "${g}Testing $3...${x}"
    tests "$2"
    next
}

program="$1"
leaks="$2"

run "asan" "./$program" "a dev build with fsanitize"
run "all" "$leaks ./$program" "a prod build with valgrind"
make clean

