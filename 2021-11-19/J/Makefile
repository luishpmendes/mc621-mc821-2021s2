CPP=g++
CARGS=-std=gnu++2a -Wall -Werror -O0 -g3

clean:
	rm -rf J J.out

J: J.cpp
	$(CPP) $(CARGS) J.cpp -o J
	./J < J.in > J.out
	diff J.out J.res
