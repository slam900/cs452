all: Head Node

Head: Head.c uwecSocket.c bit.c
	gcc -o Head Head.c uwecSocket.c bit.c -lm

Node: Node.c uwecSocket.c bit.c
	gcc -o Node Node.c uwecSocket.c bit.c -lm

clean:
	rm -i Head Node
