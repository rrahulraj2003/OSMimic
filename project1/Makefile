all: stack

stack:
	gcc -g -Wall -fsanitize=address -std=gnu11 -m32 -w stack.c -o stack

stackres:
	rm -rf stack
	gcc -g -Wall -fsanitize=address -std=gnu11 -m32 -w stack.c -o stack

thread:
	gcc -g -Wall -fsanitize=address -std=gnu11 -m32 -lpthread threads.c -o thread

clean:
	rm -rf stack thread