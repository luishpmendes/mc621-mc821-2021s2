CPP=g++
CARGS=-lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE

clean:
	rm -rf E E.out

E: E.cpp
	$(CPP) $(CARGS) E.cpp -o E
	./E < E.in > E.out
	diff E.out E.res

