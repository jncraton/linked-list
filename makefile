all: test

%: %.cc
	g++ -std=c++23 $< -o $@

format:
	clang-format -i *.cc

test: linkedlist.cc
	g++ -std=c++23 $< -o $@
	./$@
	
clean:
	rm -rf linkedlist test
