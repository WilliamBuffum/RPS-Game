main.exe: main.o playgame.o rpsgame.o tool.o rock.o paper.o scissors.o
	g++ main.o playgame.o rpsgame.o tool.o rock.o paper.o scissors.o -o main.exe

main.o: main.cpp
	g++ -c main.cpp

playgame.o: playgame.cpp
	g++ -c playgame.cpp

rpsgame.o: rpsgame.cpp
	g++ -c rpsgame.cpp

tool.o: tool.cpp
	g++ -c tool.cpp

rock.o: rock.cpp
	g++ -c rock.cpp

paper.o: paper.cpp
	g++ -c paper.cpp

scissors.o: scissors.cpp
	g++ -c scissors.cpp

clean:
	rm -f *.o *.out *.exe
