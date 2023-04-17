# @author    Clément Vidon
# @created   230320 00:00:00  by  clem@spectre
# @modified  230324 11:39:29  by  clem@spectre
# @filename  checks.sh

#!/bin/bash

r='\033[0;31m'
g='\033[0;32m'
b='\033[0;34m'
y='\033[0;33m'
c='\033[0;36m'
m='\033[0;35m'
x='\033[0m'

prompt_continue() {
    echo -en "${g}Please press enter to continue...${x}"
    read -r
}

run_tests() {
    head -1 src/* include/*
    prompt_continue

    ag "(#include|class.*;)" src include
    prompt_continue

    ag "this->" src
    prompt_continue
    ag "^}$" -B 1 src -c && echo "" && ag "^  return" -B 1 src -c
    prompt_continue
    ag "for .*i++" src
    prompt_continue
    ag DEBUG src
    prompt_continue
    ag "\(\) {" src
    prompt_continue

    ag "class.*{" -A 8 include
    prompt_continue

    ag TODO src include
    ag XXX src include
    prompt_continue
}

run_tests
