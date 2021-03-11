main_executable: main.o myint.o
	g++ -g -o main main.o myint.o
	chmod 755 main

main.o: main.cpp myint.h
	g++ -g -c main.cpp
    
myint.o: myint.cpp myint.h
	g++ -g -c myint.cpp    

clean:
	rm -f *.o