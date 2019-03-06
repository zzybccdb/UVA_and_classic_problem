runfile:a.out
	./a.out < input.txt > output.txt
a.out: main.cpp
	g++ main.cpp
clean:
	rm a.out