build:
	gcc main.c task.c struct.h graph.c cozi.c stive.c liste.c -o clasament -lm

clean:
	rm -f clasament