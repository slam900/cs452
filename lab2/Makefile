all: Head Node

Head: Head.c uwecSocket.c bit.c
	gcc -o Head Head.c uwecSocket.c bit.c

Node: Node.c uwecSocket.c bit.c
	gcc -o Node Node.c uwecSocket.c bit.c

clean:
	rm -i Head Node
