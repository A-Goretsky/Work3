randlist: class.c
	gcc -o randlist class.c

run: randlist
	./randlist
