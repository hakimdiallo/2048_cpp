#!/bin/bash

if [[ ! -f "main" ]]; then
  make mrproper
  make
fi

./main
