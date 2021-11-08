CPP=g++
CARGS=-std=gnu++2a -Wall -Werror -O0 -g3

clean:
	rm -rf I I.out

I: I.cpp
	$(CPP) $(CARGS) I.cpp -o I
	./I < I.in > I.out
	diff I.out I.res
