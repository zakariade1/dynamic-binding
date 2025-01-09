CC = g++
CPPFLAGS = -std=c++17 -g -Wall

main: main.o dog.o cat.o animal.o horse.o tree.o
	$(CC) $(CPPFLAGS) -o main main.o dog.o animal.o cat.o horse.o tree.o

main.o: main.cpp animal.h dog.h cat.h
	$(CC) $(CPPFLAGS) -c main.cpp

dog.o: dog.cpp animal.h
	$(CC) $(CPPFLAGS) -c dog.cpp
cat.o: cat.cpp animal.h
	$(CC) $(CPPFLAGS) -c cat.cpp
	
horse.o: horse.cpp animal.h
	$(CC) $(CPPFLAGS) -c horse.cpp
animal.o: animal.cpp animal.h
	$(CC) $(CPPFLAGS) -c animal.cpp
tree.o: animal.cpp dog.cpp horse.cpp cat.cpp 
	$(CC) $(CPPFLAGS) -c tree.cpp
clean:
	rm -f *.o main
leak: main
	valgrind --leak-check=full ./main
