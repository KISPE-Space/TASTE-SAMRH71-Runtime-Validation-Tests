VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/samrh71core00h.h \
                  src/samrh71core00h.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
