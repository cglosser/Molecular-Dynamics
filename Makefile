CC = g++
COPTS = -Wall
OBJECTS = particle.o driver.o interaction.o integrator.o
EIGENDIR = Eigen

simulation.exe: $(OBJECTS)
	$(CC) -I $(EIGENDIR) $(COPTS) -o $@ $(OBJECTS)

%.o:%.cpp
	$(CC) -I $(EIGENDIR) $(COPTS) -c $<

.PHONY: documentation
documentation:
	doxygen Doxyfile

.PHONY: clean
clean:
	-rm *.o *.exe
