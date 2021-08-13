CPP=g++
CARGS=-std=c++17 -Wall -Werror -O2 -g3

clean:
	rm -rf M M.out

M: M.cpp
	$(CPP) $(CARGS) M.cpp -o M
	./M < M.in > M.out
	diff M.out M.res

