VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/faulthandler00b.h \
                  src/faulthandler00b.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
