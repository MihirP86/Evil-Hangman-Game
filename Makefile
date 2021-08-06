CC = gcc 
CFLAGS = -Wall --std=c99
OBJECTS = main.o string.o generic_vector.o tree.o
OBJECT2 = new_key.o string.o generic_vector.o tree.o
TESTOBJ = string.o unit_test.o test_def.o 
ALL: Hangman 

Hangman: $(OBJECTS)
	$(CC)$(CFLAGS) -o Hangman $(OBJECTS)

string_driver:$(OBJECTS)
	$(CC)$(CFLAGS) -o string_driver $(OBJECTS)

main.o: main.c
	$(CC)$(CFLAGS) -c main.c -o main.o

tree.o: tree.c
	$(CC)$(CFLAGS) -c tree.c -o tree.o

generic_vector.o: generic_vector.c 
	$(CC)$(CFLAGS) -c generic_vector.c -o generic_vector.o

string.o: my_string.c
	$(CC)$(CFLAGS) -c my_string.c -o string.o

avl.o: avl.c
	$(CC)$(CFLAGS) -c avl.c -o avl.o

unit_test: $(TESTOBJ)
	$(CC)$(CFLAGS) -o unit_test $(TESTOBJ)

unit_test.o: unit_test.c
	$(CC)$(CFLAGS) -c unit_test.c -o unit_test.o

test_key: $(OBJECT2)
	$(CC)$(CFLAGS) -o test_key $(OBJECT2)

test_def.o: test_def.c
	$(CC)$(CFLAGS) -c test_def.c -o test_def.o

clean:
	rm Hangman string_driver $(OBJECTS) unit_test unit_test.o test_def.o test_key  
