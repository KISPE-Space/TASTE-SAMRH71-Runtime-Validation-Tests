VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/prot00if.h \
                  src/prot00if.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
