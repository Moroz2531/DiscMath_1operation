TARGET = MyProject
CC = gcc

PREFIX = ./src/

SRC = $(wildcard $(PREFIX)*.c)
OBJ = $(patsubst $(PREFIX)%.c, $(PREFIX)%.o, $(SRC))

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) -Wall $^ -o $@

%$(PREFIX).o : %$(PREFIX)*.с
	$(CC) $^ -o $@

clean:
	rm $(TARGET) $(PREFIX)*.o