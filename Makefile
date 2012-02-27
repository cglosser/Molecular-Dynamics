CC = g++
COPTS = -Wall -O3 -fstrict-aliasing
OBJECTS = particle.o interaction.o integrator.o
EIGENDIR = `pwd` #Assume Eigen/ in the top-level project folder

simulation.exe: driver.cpp $(OBJECTS)
	$(CC) -I $(EIGENDIR) $(COPTS) -o $@ $< $(OBJECTS)

%.o:%.cpp
	$(CC) -I $(EIGENDIR) $(COPTS) -c $<

.PHONY: documentation
documentation:
	doxygen Doxyfile

.PHONY: clean
clean:
	-rm -rf *.o *.exe html latex
