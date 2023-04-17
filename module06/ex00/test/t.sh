#!/bin/bash

echo ""
echo ">> ./convert \"nan\""
./convert "nan"

echo ""
echo ">> ./convert \"42.0f\""
./convert "42.0f"

echo ""
echo ">> ./convert \"42\""
./convert "42"

echo ""
echo ">> ./convert \"'\t'\""
./convert "'\t'"

echo ""
echo ">> ./convert \"'t'\""
./convert "'t'"

echo ""
echo ">> ./convert \"2147483647\""
./convert "2147483647"

echo ""
echo ">> ./convert \"2147483648\""
./convert "2147483648"

echo ""
echo ">> ./convert \"2147483648f\""
./convert "2147483648f"

echo ""
echo ">> ./convert \"0.0F\""
./convert "0.0F"

echo ""
echo ">> ./convert \"-inf\""
./convert "-inf"
