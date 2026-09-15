%: %.cc
	g++ -std=c++23 $< -o $@

format:
	clang-format -i *.cc

clean:
	test
