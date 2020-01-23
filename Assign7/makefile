#
# PROGRAM:	assign7 
# PROGRAMMER:	Andrew Scheel 
# LOGON ID:	z1790270 
# DATE DUE:	11/9/17
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign7: assign7.o
	g++ $(CCFLAGS) -o assign7 assign7.o

# Rule to compile source code file to object code
assign7.o: assign7.cpp Stack.h
	g++ $(CCFLAGS) -c assign7.cpp

# Pseudo-target to remove object code and executable file
clean:
	-rm *.o assign7
