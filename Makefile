bmpedit : bmpedit.c
	gcc -o bmpedit -std=c11 -Wall bmpedit.c

run : 
	gcc -o bmpedit -std=c11 -Wall bmpedit.c
	./bmpedit cup.bmp

clean : 
	rm out.bmp
	rm -f bmpedit

view : 
	feh out.bmp

help : 
	./bmpedit -h