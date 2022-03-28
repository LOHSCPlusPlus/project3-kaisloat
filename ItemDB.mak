ItemDB : ItemDB.o ItemClass.o ReadUtils.o ItemMain.o 
	g++ ItemDB.o ItemClass.o ReadUtils.o ItemMain.o -o ItemDB

ItemDB.o : ItemDB.cpp ItemDB.h ReadUtils.h ItemClass.h 
	g++ -Wall -c ItemDB.cpp  -o ItemDB.o


ItemClass.o : ItemClass.cpp ReadUtils.h ItemClass.h 
	g++ -Wall -c ItemClass.cpp  -o ItemClass.o

ReadUtils.o : ReadUtils.cpp ReadUtils.h 
	g++ -Wall -c ReadUtils.cpp  -o ReadUtils.o

ItemMain.o : ItemMain.cpp ReadUtils.h ItemClass.h ItemDB.h 
	g++ -Wall -c ItemMain.cpp  -o ItemMain.o

