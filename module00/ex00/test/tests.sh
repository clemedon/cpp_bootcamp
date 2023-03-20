#!/bin/bash

echo -n "produce: "
./megaphone "shhhhh... I think the students are asleep..."
echo "excpect: SHHHHH... I THINK THE STUDENTS ARE ASLEEP..."
echo ""

echo -n "produce: "
./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
echo "excpect: DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF."
echo ""

echo -n "produce: "
./megaphone
echo "excpect: * LOUD AND UNBEARABLE FEEDBACK NOISE *"
echo ""

