
program: Main.o Graph.o Algorithms.o Edge.o 
	g++ -o program Main.o Graph.o Algorithms.o Edge.o

Main.o: Main.cpp
	g++ -c Main.cpp -o Main.o

Graph.o: Graph.cpp
	g++ -c Graph.cpp -o Graph.o

Algorithms.o: Algorithms.cpp
	g++ -c Algorithms.cpp -o Algorithms.o

Edge.o: Edge.cpp
	g++ -c Edge.cpp	-o Edge.o

Main: program
	./program

valgrind: program	
	valgrind ./program

clean:
	rm -f Main.o Graph.o Queue.o Stack.o Algorithms.o Edge.o MinHeap.o program