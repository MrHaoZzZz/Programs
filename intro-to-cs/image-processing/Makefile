CC = gcc
TARGET = imgproc
OBJS = image_processing.o main.o

all = $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.c
	$(CC) -c main.c -o main.o

image_processing.o: image_processing.c
	$(CC) -c image_processing.c -o image_processing.o

clean:
	rm -f $(OBJS) $(TARGET)