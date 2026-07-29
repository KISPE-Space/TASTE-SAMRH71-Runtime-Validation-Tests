VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/receiver013.h \
                  src/receiver013.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
