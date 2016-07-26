OS:=	$(shell uname)
CC		= /opt/local/bin/g++-mp-5
CHOSTFLAGS	= -fopenmp
CFLAGS		= -g -O3 -std=c++14

CLINKER		= $(CC) 
RM		= /bin/rm

default:	node.o edge.o lattice.o 

node.o: ./src/node.cc ./inc/node.h
	$(CC) -c ./src/node.cc -o $@ $(INCFLAGS) $(CFLAGS) $(LDFLAGS) $(CHOSTFLAGS)

edge.o: ./src/edge.cc ./inc/edge.h
	$(CC) -c ./src/edge.cc -o $@ $(INCFLAGS) $(CFLAGS) $(LDFLAGS) $(CHOSTFLAGS)

lattice.o: ./src/lattice.cc ./inc/lattice.h
	$(CC) -c ./src/lattice.cc -o $@ $(INCFLAGS) $(CFLAGS) $(LDFLAGS) $(CHOSTFLAGS)

graphtest.o: ./src/graphtest.cc
	$(CC) -c ./src/graphtest.cc -o $@ $(INCFLAGS) $(CFLAGS) $(LDFLAGS) $(CHOSTFLAGS)

all:		node.o edge.o lattice.o 

.c.o:
	$(CC) $(INCFLAGS) $(CFLAGS) -c $<

clean:
	rm -rf ./*.o
