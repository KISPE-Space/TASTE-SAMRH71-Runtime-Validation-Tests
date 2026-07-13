VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj
edit:
	echo "project tmp_adatest is For Source_Dirs use (\"src\", \"../../dataview/Ada/\"); end tmp_adatest;" > tmp_adatest.gpr
	gnat-gps -P tmp_adatest.gpr
	rm tmp_adatest.gpr

compile-linux:
	mkdir -p obj && cd obj && ADA_INCLUDE_PATH=../../../dataview/Ada gnat make ../src/adatest
