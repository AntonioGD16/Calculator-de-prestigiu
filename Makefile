build:
	gcc main.c task.c struct.h cozi.c stive.c liste.c -o clasament -lm

clean:
	rm -f clasament