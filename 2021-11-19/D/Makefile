CPP=g++
CARGS=-std=gnu++2a -Wall -Werror -O0 -g3

clean:
	rm -rf D D.out

D: D.cpp
	$(CPP) $(CARGS) D.cpp -o D
	./D < D.in > D.out
	diff D.out D.res
