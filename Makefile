prog1: sujet1.o
	gcc -Wall -o prog sujet1.o -lm
	
sujet1.o: sujet1.c
	gcc -Wall -c sujet1.c 
	
clean :
	rm -rf *.o
	
mrproper : clean
	rm -rf prog
