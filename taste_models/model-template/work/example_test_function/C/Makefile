VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/example_test_function.h \
                  src/example_test_function.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
