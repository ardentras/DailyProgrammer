CC=gcc

CCFLAGS=-O3 -std=c99

OBJS=main.o
TARGET=main.exe

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm $(TARGET) *.o
