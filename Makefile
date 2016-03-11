bmpedit : bmpedit.c
	gcc -o bmpedit -std=c11 -Wall bmpedit.c

run : 
	gcc -o bmpedit -std=c11 -Wall bmpedit.c
	./bmpedit -t 0.1

clean : 
	rm cupth.bmp

view : 
	feh cupth.bmp
