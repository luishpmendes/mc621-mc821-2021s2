CPP=g++
CARGS=-std=gnu++2a -Wall -Werror -O0 -g3

clean:
	rm -rf E E.out

E: E.cpp
	$(CPP) $(CARGS) E.cpp -o E
	./E < E.in > E.out
	diff E.out E.res
