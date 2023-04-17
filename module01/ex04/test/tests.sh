# @author    Clément Vidon
# @created   230324 11:57:05  by  clem@spectre
# @modified  230324 11:57:05  by  clem@spectre
# @filename  tests.sh

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

function    test_replace()
{
    touch testinput.replace
    echo "While sed is for losers, sediments are settling to the bottom of liquids." > testinput
    cmd="$@"
    echo "                      [ $cmd ]"
    echo ""
    $cmd 2>/dev/null
    echo -n "OLD "
    cat testinput
    echo -n "NEW "
    cat testinput.replace
    rm -f testinput testinput.replace
    echo ""
}

run_tests() {
    local command="$1"
    test_replace "$command testinput sed c"                 # all good
    test_replace "$command testinput sed"                   # missing arg
    test_replace "$command "                                # missing arg
    test_replace "$command testinput losers WINNERS"        # all good
    test_replace "$command testinput While =>"              # all good
    test_replace "$command testinput liquid solid vivid"    # too many args
    test_replace "$command testinput torchon serviette"     # nothing to do
    test_replace "$command testinput are are"               # nothing to do
    test_replace "$command where are you"                   # infile not found
    rm -f testinput.replace
}

run_build() {
    local build_type="$1"
    local command="$2"
    local description="$3"

    make clean
    make "$build_type"
    clear
    echo -e "${g}Running tests on $description...${x}"
    run_tests "$command"
    prompt_continue
}

program="$1"
leaks="$2"

run_build "asan" "./$program" "a development build with Address Sanitizer"
run_build "all" "$leaks ./$program" "a production build with Valgrind"
make clean
