all: stack

stack:
	gcc -g -Wall -fsanitize=address -std=gnu11 -m32 -w stack.c -o stack

stackres:
	rm -rf stack
	gcc -g -Wall -fsanitize=address -std=gnu11 -m32 -w stack.c -o stack

clean:
	rm -rf stack