CC = g++
CFLAGS = -Wall -O3 -fstrict-aliasing -std=c++0x
CFLAGS += $(shell pkg-config --cflags eigen3)
LDFLAGS =
OBJECTS = driver.o particle.o interaction.o integrator.o universe.o

simulation.exe: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o:%.cpp
	$(CC) $(CFLAGS) -c $<

.PHONY: documentation
documentation:
	doxygen Doxyfile

.PHONY: clean
clean:
	-rm -rf *.o *.exe html latex
