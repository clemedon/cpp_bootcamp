# @author    Clément Vidon
# @created   230320 00:00:00  by  clem@spectre
# @modified  230324 11:39:29  by  clem@spectre
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

run_tests() {
    echo "8 9 * 9 - 9 - 9 - 4 - 1 + =>"
    $1 "8 9 * 9 - 9 - 9 - 4 - 1 +"
    echo "Should give: 42"

    echo "77 * 7 - =>"
    $1 "77 * 7 -"
    echo "Should give: Error"

    echo "1 2 * 2 / 2 * 2 4 - + =>"
    $1 "1 2 * 2 / 2 * 2 4 - +"
    echo "Should give: 0"

    echo "(1 + 1) =>"
    $1 "(1 + 1)"
    echo "Should give: Error"

    echo "50/ =>"
    $1 "50/"
    echo "Should give: Error"


    echo "1 2 + =>"
    $1 "1 2 +"
    echo "Should give: 3"

    echo "3 4 5 * + =>"
    $1 "3 4 5 * +"
    echo "Should give: 23"

    echo "2 3 4 + * =>"
    $1 "2 3 4 + *"
    echo "Should give: 14"

    echo "5 2 - 4 * =>"
    $1 "5 2 - 4 *"
    echo "Should give: 12"

    echo "2 3 4 + * 5 6 - / =>"
    $1 "2 3 4 + * 5 6 - /"
    echo "Should give: -14"

    echo "9 3 / =>"
    $1 "9 3 /"
    echo "Should give: 3"

    echo "2 3 + 4 * =>"
    $1 "2 3 + 4 *"
    echo "Should give: 20"

    echo "8 4 / =>"
    $1 "8 4 /"
    echo "Should give: 2"

    echo "5 6 7 * + =>"
    $1 "5 6 7 * +"
    echo "Should give: 47"

    echo "4 2 + 3 * 6 - =>"
    $1 "4 2 + 3 * 6 -"
    echo "Should give: 12"

    echo "6 2 3 + - 4 * =>"
    $1 "6 2 3 + - 4 *"
    echo "Should give: 4"

    echo "9 2 3 4 * + - =>"
    $1 "9 2 3 4 * + -"
    echo "Should give: -5"

    echo "2 3 4 + - 5 * =>"
    $1 "2 3 4 + - 5 *"
    echo "Should give: -25"

    echo "7 8 9 * + 10 - =>"
    $1 "7 8 9 * + 10 -"
    echo "Should give: Error"

    echo "6 2 * 5 3 * - =>"
    $1 "6 2 * 5 3 * -"
    echo "Should give: -3"

    echo "3 4 + 5 6 + * =>"
    $1 "3 4 + 5 6 + *"
    echo "Should give: 77"

    echo "9 3 % =>"
    $1 "9 3 %"
    echo "Should give: Error"

    echo "5 6 7 8 * * * =>"
    $1 "5 6 7 8 * * *"
    echo "Should give: 1680"

    echo "9 2 3 ^ ^ =>"
    $1 "9 2 3 ^ ^"
    echo "Should give: Error"

    echo "5 6 + 7 8 * + =>"
    $1 "5 6 + 7 8 * +"
    echo "Should give: 67"

    echo "4 2 + 3 * 6 + =>"
    $1 "4 2 + 3 * 6 +"
    echo "Should give: 24"

    echo "2 3 + 4 * 5 + =>"
    $1 "2 3 + 4 * 5 +"
    echo "Should give: 25"
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
