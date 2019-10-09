FILE=date
SRCS=main.c
PROG=$(SRCS:.c=)
OBJS=$(SRCS:.c=.o)
INPUT=$(FILE).in
OUTPUT=$(FILE).out
CC=gcc
FLAGS=-o

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(FLAGS) $@ $^ 

run: $(PROG)
	./$(PROG) $(INPUT) $(OUTPUT)

clean: 
	rm $(PROG)
