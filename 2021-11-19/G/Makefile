CPP=g++
CARGS=-std=gnu++2a -Wall -Werror -O0 -g3

clean:
	rm -rf G G.out

G: G.cpp
	$(CPP) $(CARGS) G.cpp -o G
	./G < G.in > G.out
	diff G.out G.res
