all:
	gcc -o shmegegge shmegegge.o

shmegegge.o: shmegegge.c
	gcc -c shmegegge.c

clean:
	rm shmegegge shmegegge.o

run:
	./shmegegge
