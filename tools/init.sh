# @author    Clément Vidon
# @created   230320 00:00:00  by  clem@spectre
# @modified  230324 11:39:29  by  clem@spectre
# @filename  init.sh

#!/bin/bash

cp $(dirname ${BASH_SOURCE[0]})/assets/Makefile .
cp $(dirname ${BASH_SOURCE[0]})/assets/tests.sh .
make clean
make init
mv *.cpp src
mv *.hpp include
mv *.sh test
make srcs
vi Makefile
