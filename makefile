Ass5: Democrat_Party.o Democrat_Politician.o Republican_Party.o Republican_Politician.o Politician.o Party.o Democratic_Leader.o Democratic_Socialist.o Republican_Leader.o Republican_Socialist.o PoliticalSys.o main.o
	g++ Democrat_Party.o Democrat_Politician.o Republican_Party.o Republican_Politician.o Politician.o Party.o Democratic_Leader.o Democratic_Socialist.o Republican_Leader.o Republican_Socialist.o PoliticalSys.o main.o -o Ass5

Democrat_Party.o: Democrat_Party.cpp Democrat_Party.h Democrat_Politician.h Party.h
	g++ -c  Democrat_Party.cpp
	
Democrat_Politician.o: Democrat_Politician.cpp Democrat_Politician.h Democrat_Party.h Republican_Party.h  Politician.h
	g++ -c  Democrat_Politician.cpp
	
Republican_Party.o: Republican_Party.cpp Republican_Party.h Republican_Politician.h Party.h
	g++ -c  Republican_Party.cpp
	
Republican_Politician.o: Republican_Politician.cpp Republican_Politician.h Republican_Party.h Democrat_Party.h Politician.h
	g++ -c  Republican_Politician.cpp
	
Politician.o: Politician.cpp Politician.h
	g++ -c  Politician.cpp

Party.o: Party.cpp observer_pattern.h Party.h Politician.h
	g++ -c  Party.cpp

Democratic_Leader.o: Democratic_Leader.cpp Democratic_Leader.h Democrat_Politician.h
	g++ -c  Democratic_Leader.cpp
	
Democratic_Socialist.o: Democratic_Socialist.cpp Democratic_Socialist.h Democrat_Politician.h
	g++ -c  Democratic_Socialist.cpp

Republican_Leader.o: Republican_Leader.cpp Republican_Leader.h Republican_Politician.h
	g++ -c  Republican_Leader.cpp
	
Republican_Socialist.o: Republican_Socialist.cpp Republican_Socialist.h Republican_Politician.h
	g++ -c  Republican_Socialist.cpp
	
PoliticalSys.o: PoliticalSys.cpp PoliticalSys.h Politician.h Party.h Republican_Socialist.h Republican_Leader.h Democratic_Socialist.h Democratic_Leader.h SysException.h 
	g++ -c  PoliticalSys.cpp
	
main.o: main.cpp PoliticalSys.h
	g++ -c  main.cpp
	
clean:
	rm -f *.o
