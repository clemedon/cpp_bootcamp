#!/bin/bash

r='\033[0;31m'
g='\033[0;32m'
b='\033[0;34m'
y='\033[0;33m'
c='\033[0;36m'
m='\033[0;35m'
x='\033[0m'

tests() {
    $1
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
run "asan" "./$program" "a dev build with fsanitize"
run "all" "valgrind -q ./$program" "a prod build with valgrind"
make clean
