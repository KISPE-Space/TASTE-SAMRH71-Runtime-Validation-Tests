VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/comms_hub.h \
                  src/comms_hub.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
