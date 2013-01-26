#!/bin/bash

make clean
rm src/*.swp
git add . -A
git commit -m "Do commit"
git push
