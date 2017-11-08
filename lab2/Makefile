all: Head Node

Head: Head.c uwecSocket.c
	gcc -o Head Head.c uwecSocket.c

Node: Node.c uwecSocket.c primes.c
	gcc -o Node Node.c uwecSocket.c

clean:
	rm -i Head Node
