
x4t3a_file_test: x4t3a_file_test.c x4t3a_file.o
	gcc x4t3a_file_test.c x4t3a_file.o -o $@

x4t3a_file.o: x4t3a_file.c x4t3a_file.h
	gcc -c x4t3a_file.c -o $@
