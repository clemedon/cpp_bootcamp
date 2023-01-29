#!/bin/bash
test_replace "sed c"
echo ""
function    test_replace()
{
    touch testinput.replace
    echo "While sed is for losers, sediments are settling to the bottom of liquids." > testinput
    cmd="valgrind -q ./replace $@"
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

make
clear
test_replace "testinput sed c" # all good
test_replace "testinput sed" # missing arg
test_replace "" # missing arg
test_replace "testinput losers WINNERS" # all good
test_replace "testinput While =>" # all good
test_replace "testinput liquid solid vivid" # too many args
test_replace "testinput torchon serviette" # nothing to do
test_replace "testinput are are" # nothing to do
test_replace "where are you" # infile not found
rm -f testinput.replace
