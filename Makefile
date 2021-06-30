compile:
		@gcc -c main.c
		@gcc -c poly.c
		@gcc -c menu.c
		@gcc main.o poly.o menu.o -o main
		@echo Done!
		
clean:
		@rm -rvf main.o poly.o menu.o
		@echo Done!