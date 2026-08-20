VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/test_death_report.h \
                  src/test_death_report.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
