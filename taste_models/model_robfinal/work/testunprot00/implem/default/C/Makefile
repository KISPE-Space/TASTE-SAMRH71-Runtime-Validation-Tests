VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/testunprot00.h \
                  src/testunprot00.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
