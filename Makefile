# Makefile to compile and run the application
# Author: Lindelani Mbatha
# Date: March 2021

CC=g++			# using g++ 9.3.0
OPT=-std=c++2a -lm	# using c++20

# default - compiles the entire application 
driver: driver.cpp tags.cpp tags.h
	$(CC) -o driver tags.cpp driver.cpp $(OPT)

# compile tags.cpp and the hearder file
tags.o: tags.cpp tags.h
	$(CC) -c tags.cpp

# compile driver.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp

# delete all the object code files
clean:
	@rm -f *.o
	@rm driver