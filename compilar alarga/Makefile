CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: a.out

a.out: main.o Utilidades.o DicPalabra.o TablaHash.o ArbolTrie.o NodoTrie.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp Utilidades.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Utilidades.o: Utilidades.cpp Utilidades.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

DicPalabra.o: DicPalabra.cpp DicPalabra.h TablaHash.h ArbolTrie.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

TablaHash.o: TablaHash.cpp TablaHash.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

ArbolTrie.o: ArbolTrie.cpp ArbolTrie.h NodoTrie.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

NodoTrie.o: NodoTrie.cpp NodoTrie.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o a.out

