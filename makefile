CXX	=	gcc
FLAGS	=	-Wall -O3 -ggdb
LIBS	=	-lm
SOURCE	=	main.c
BIN	=	main

all:
	$(CXX) $(FLAGS) $(SOURCE) -o $(BIN) $(LIBS)

clean:
	rm -f *~ $(BIN)
