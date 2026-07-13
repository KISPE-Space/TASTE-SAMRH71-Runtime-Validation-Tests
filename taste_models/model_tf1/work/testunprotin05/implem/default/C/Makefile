VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/testunprotin05.h \
                  src/testunprotin05.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
