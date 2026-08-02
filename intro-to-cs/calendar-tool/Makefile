CC = gcc
TARGET = calendar_tool
OBJS = calendar.o main.o

all = $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.c
	$(CC) -c main.c -o main.o

calendar.o: calendar.c
	$(CC) -c calendar.c -o calendar.o

clean:
	rm -f $(OBJS) $(TARGET)