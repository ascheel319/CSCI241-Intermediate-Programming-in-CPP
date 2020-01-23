#
# PROGRAM:	assign8 
# PROGRAMMER:	Andrew Scheel
# LOGON ID:	z1790270
# DATE DUE:	11/9/17
#
# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign8: assign8.o
	g++ $(CCFLAGS) -o assign8 assign8.o

# Rule to compile source code file to object code
assign8.o: assign8.cpp sorts.h quicksort.h mergesort.h
	g++ $(CCFLAGS) -c assign8.cpp

# Pseudo-target to remove object code and executable file
clean:
	-rm *.o assign8
