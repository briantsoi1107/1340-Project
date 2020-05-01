Main: Main.o Action.o
	g++ Main.o Action.o -o Main

Main.o: Main.cpp
	g++ -c Main.cpp

Action.o: Action.cpp
	g++ -c Action.cpp

clean:
	rm *.o Main
	
.PHONY: clean