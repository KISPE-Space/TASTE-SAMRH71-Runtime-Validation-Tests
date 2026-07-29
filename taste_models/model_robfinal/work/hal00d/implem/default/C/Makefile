VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/hal00d.h \
                  src/hal00d.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
