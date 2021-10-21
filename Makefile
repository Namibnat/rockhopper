CC=gcc

rockhopper: rockhopper.o
	$(CC) rockhopper.o -o rockhopper

rockhopper.o: rockhopper.c
	$(CC) -c rockhopper.c

clean: rockhopper.o rockhopper
	rm rockhopper.o rockhopper
