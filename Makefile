CC = g++
COPTS = -Wall
OBJECTS = particle.o driver.o interaction.o

simulation.exe: $(OBJECTS)
	$(CC) $(COPTS) -o $@ $(OBJECTS)

%.o:%.cpp
	$(CC) $(COPTS) -c $<

.PHONY: clean
clean:
	-rm *.o *.exe
