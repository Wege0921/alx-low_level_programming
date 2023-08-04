#!/bin/bash

# Compile all .c files to object files
gcc -c *.c

# Create the static library liball.a
ar -rc liball.a *.o

# Index the static library
ranlib liball.a
