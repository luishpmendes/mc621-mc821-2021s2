CPP=g++
CARGS=-std=c++17 -Wall -Werror -O0 -g3

clean:
	rm -rf K K.out

K: K.cpp
	$(CPP) $(CARGS) K.cpp -o K
	./K< K.in > K.out
	diff K.out K.res

