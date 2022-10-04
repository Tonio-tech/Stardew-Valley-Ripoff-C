CXX = g++
CXXFLAGS = -Wall

AgItem.o: AgItem.cpp AgItem.h
	$(CXX) $(CXXFLAGS) -c AgItem.cpp

Vegetable.o: AgItem.o Vegetable.cpp Vegetable.h
	$(CXX) $(CXXFLAGS) -c Vegetable.cpp

Animal.o: AgItem.o Animal.cpp Animal.h
	$(CXX) $(CXXFLAGS) -c Animal.cpp

Fruit.o: Fruit.cpp Fruit.h
	$(CXX) $(CXXFLAGS) -c Fruit.cpp

Tree.o: AgItem.o Fruit.o Tree.cpp Tree.h
	$(CXX) $(CXXFLAGS) -c Tree.cpp

Farm.o: AgItem.o Vegetable.o Tree.o Animal.o Farm.h Farm.cpp
	$(CXX) $(CXXFLAGS) -c Farm.cpp

proj4: AgItem.o Vegetable.o Tree.o Animal.o Farm.o Fruit.o proj4.cpp
	$(CXX) $(CXXFLAGS) AgItem.o Vegetable.o Tree.o Animal.o Farm.o Fruit.o proj4.cpp -o proj4

run:
	./proj4

val:
	valgrind ./proj4

Veg: AgItem.o Vegetable.o
	$(CXX) $(CXXFLAGS) AgItem.o Vegetable.o Vegetable.cpp -o Veg