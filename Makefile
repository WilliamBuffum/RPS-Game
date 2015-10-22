main.exe: main.o playgame.o RPSgame.o Tool.o Rock.o Paper.o Scissors.o
	g++ main.o playgame.o RPSgame.o Tool.o Rock.o Paper.o Scissors.o -o main.exe

main.o: main.cpp
	g++ -c main.cpp

playgame.o: playgame.cpp
	g++ -c playgame.cpp

RPSgame.o: RPSgame.cpp
	g++ -c RPSgame.cpp

Tool.o: Tool.cpp
	g++ -c Tool.cpp

Rock.o: Rock.cpp
	g++ -c Rock.cpp

Paper.o: Paper.cpp
	g++ -c Paper.cpp

Scissors.o: Scissors.cpp
	g++ -c Scissors.cpp

clean:
	rm -f *.o *.out *.exe
