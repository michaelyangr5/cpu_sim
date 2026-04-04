CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = cpu_sim
SRCS = main.c cpu.h cpu.c

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)
