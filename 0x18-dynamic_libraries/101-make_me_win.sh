#!/bin/bash
wget -P /tmp/printhack.so https://github.com/HucksApp/alx-low_level_programming/blob/main/0x18-dynamic_libraries/printhack.so
export LD_PRELOAD=/tmp/printhack.so
