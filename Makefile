bmpedit : bmpedit.c
	gcc -o bmpedit -std=c11 -Wall bmpedit.c

run : 
	gcc -o bmpedit -std=c11 -Wall bmpedit.c
	./bmpedit

clean : 
	rm cupth.bmp
	rm -f bmpedit

view : 
	feh cupth.bmp

help : 
	./bmpedit -h