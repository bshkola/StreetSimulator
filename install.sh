#!/bin/bash

qmake -o Makefile ZPR-v1.pro
make
make clean
rm Makefile

if [ -d "bin" ]; then
  rm -rf ./bin
fi
mkdir bin

mv ZPR-v1 ./bin/.

if [ -f "config" ]; then
  cp config ./bin/.
fi
