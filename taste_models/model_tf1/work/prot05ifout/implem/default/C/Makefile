VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/prot05ifout.h \
                  src/prot05ifout.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
