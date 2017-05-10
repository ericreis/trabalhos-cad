CXX=icpc
INCLUDES=
CXXFLAGS=-c -g -O3 -openmp -std=c++0x -qopt-report5 $(INCLUDES) 


.PHONY: default

default: vec1.exe vec2.exe vec3.exe

vec1.exe: vec1.o 
	$(CXX) -openmp vec1.o -o vec1.exe $(LIBS)

vec1.o: vec1.cpp
	$(CXX) $(CXXFLAGS) -o $@ vec1.cpp

vec2.exe: vec2.o 
	$(CXX) -openmp vec2.o -o vec2.exe $(LIBS)

vec2.o: vec2.cpp
	$(CXX) $(CXXFLAGS) -o $@ vec2.cpp

vec3.exe: vec3.o 
	$(CXX) -openmp vec3.o -o vec3.exe $(LIBS)

vec3.o: vec3.cpp
	$(CXX) $(CXXFLAGS) -o $@ vec3.cpp


.PHONY: clean
clean::
	-rm -f *.exe *.o *.out *.optrpt
