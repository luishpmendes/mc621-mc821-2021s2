CPP=g++
CARGS=-std=c++17 -Wall -Werror -O0 -g3

clean:
	rm -rf L L.out

L: L.cpp
	$(CPP) $(CARGS) L.cpp -o L
	./L < L.in > L.out
	diff L.out L.res

