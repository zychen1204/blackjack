a.out:main.cpp Card.h Player.h Player.cpp Card.cpp 
	g++ -g -o a.out main.cpp Player.cpp Card.cpp 
clean:
	rm -f a.out