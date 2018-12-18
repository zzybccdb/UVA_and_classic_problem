runfile:a.out
	./a.out < input > output
a.out: main.cpp
	g++ main.cpp
clean:
	rm a.out