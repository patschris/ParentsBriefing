CC		= g++
CFLAGS	= -g -Wall
EXEC	= parentsBriefing
OBJS 	= main.o teacher.o parent.o list.o array.o
SRCS 	= main.cpp teacher.cpp parent.cpp list.cpp array.cpp

.PHONY : all
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

teacher.o: teacher.cpp
	$(CC) $(CFLAGS) -c teacher.cpp

parent.o: parent.cpp
	$(CC) $(CFLAGS) -c parent.cpp

list.o: list.cpp
	$(CC) $(CFLAGS) -c list.cpp

array.o: array.cpp
	$(CC) $(CFLAGS) -c array.cpp


.PHONY: clean
clean:
	rm -f $(OBJS) $(EXEC)


.PHONY: check
check:
	valgrind --leak-check=full ./$(EXEC)


.PHONY: run
run:
	./$(EXEC)