#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := matrix.cpp graphics_drawer.cpp tetris_object_drawable.cpp

# header files in this project
HEADERS := enums.hpp matrix.hpp graphics_drawer.hpp matrix_part.hpp matrix_port.hpp matrix_pins_rgb.hpp tetris_object_drawable.hpp

# other places to look for files for this project
SEARCH  := library

# set RELATIVE to the next higher directory 
# and defer to the Makefile.* there
RELATIVE := ..
include $(RELATIVE)/Makefile.due
