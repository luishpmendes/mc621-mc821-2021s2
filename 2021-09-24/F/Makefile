CPP=g++
CARGS=-std=c++17 -Wall -Werror -O0 -g3

clean:
	rm -rf F output.txt

F: F.cpp
	$(CPP) $(CARGS) F.cpp -o F
	./F
	diff output.txt result.txt

