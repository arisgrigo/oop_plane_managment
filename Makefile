all: ask3

ask3: main.o Basic_Objects.o Plane.o Employee.o clone_encrypt_print.o
	g++ -std=c++11 main.o Basic_Objects.o Plane.o Employee.o clone_encrypt_print.o -o ask3

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Basic_Objects.o: Basic_Objects.cpp
	g++ -std=c++11 -c Basic_Objects.cpp

Plane.o: Plane.cpp
	g++ -std=c++11 -c Plane.cpp

Employee.o: Employee.cpp
	g++ -std=c++11 -c Employee.cpp

clone_encrypt_print.o: clone_encrypt_print.cpp
	g++ -std=c++11 -c clone_encrypt_print.cpp	

clean:
		rm -rf *o ask3
		rm -rf *o clone_encrypt_print.o
		rm -rf *o Employee.o
		rm -rf *o Plane.o
		rm -rf *o Basic_Objects.o
		rm -rf *o main.o
