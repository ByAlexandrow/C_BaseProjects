CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
MATH_FLAG = -lm

TARGET = calculator
CALCULATOR = calculator.c
OBJECTS = $(CALCULATOR:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(MATH_FLAG)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
