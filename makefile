.PHONY: clean run compile
compile runme:  main.o
	@gcc -o runme main.o
main.o: main.c 
	@gcc -c main.c
run: runme
	@./runme
clean:
	rm *.o
	rm runme