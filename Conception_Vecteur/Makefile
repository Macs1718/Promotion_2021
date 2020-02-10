CXX = g++
CXXOPTS = -g -Wall -std=c++17 -Weffc++

OBJS = vecteur.o

test_vecteur.exe : $(OBJS)
	$(CXX) $(CXXOPTS) -o test_vecteur.exe test_vecteur.cpp $(OBJS)

.cpp.o:
	$(CXX) $(CXXOPTS) -c $<


