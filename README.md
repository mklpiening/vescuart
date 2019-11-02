# vescuart
vescuart is a c++ library for controlling a VESC motor controller using the UART interface.
It provides a cmake package to allow a simple integration using cmake.
This library also allows forwarding messages to other VESCs via the CAN bus integrated into the VESCs.

## Prerequisites
To build this library you need to have the following libraries installed.
- boost-system
- boost-thread

Install these on an ubuntu based distribution by typing:
```bash
$ sudo apt install libboost-system-dev libboost-thread-dev
```

## Installation
Build and install this library by running the following commands:
```bash
$ git clone https://github.com/mklpiening/vescuart.git
$ cd vescuart
$ mkdir build && cd build
$ cmake ..
$ sudo make -j4 install
```
