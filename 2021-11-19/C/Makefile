CPP=g++
CARGS=-std=gnu++2a -Wall -Werror -O0 -g3

clean:
	rm -rf C C.out

C: C.cpp
	$(CPP) $(CARGS) C.cpp -o C
	./C < C.in > C.out
	diff C.out C.res
