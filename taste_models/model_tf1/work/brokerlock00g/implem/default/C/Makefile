VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/brokerlock00g.h \
                  src/brokerlock00g.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
