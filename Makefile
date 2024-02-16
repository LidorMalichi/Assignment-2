CC = gcc
CFLAGS = -Wall -g
KNAPSACK = my_Knapsack.c
GRAPH = my_graph.c
MATRIX = libmy_mat.so
OBJ = my_mat.c
HEADER = my_mat.h
SRC = my_graph.c my_mat.c

.PHONY: all clean

all: my_graph my_Knapsack

my_Knapsack: $(KNAPSACK:.c=.o)
	$(CC) $(CFLAGS) $^ -o $@

my_graph: $(GRAPH:.c=.o) $(MATRIX)
	$(CC) $(CFLAGS) $< ./$(MATRIX) -o $@

MATRIX: $(OBJ:.c=.o)
	$(CC) -shared $(CFLAGS) $^ -o $@

$(SRC:.c=.o): $(SRC) $(HEADER)
	$(CC) $(CFLAGS) -fPIC -c $^

$(KNAPSACK:.c=.o): $(KNAPSACK)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f my_Knapsack my_graph *.so *.o





