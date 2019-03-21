CXX = g++

EXEC = output
SOURCES = main.cpp Menu.cpp inputInteger.cpp Space.cpp Board.cpp Block.cpp Door.cpp QuestionBlock.cpp Flag.cpp Spike.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(EXEC): ${OBJECTS}
	${CXX} ${OBJECTS} -o $(EXEC)
	
${OBJECTS}: ${SOURCES}
	${CXX} -std=c++0x -c ${@:.o=.cpp}
	
run: 
	./output
	
clean:
	rm *.o output
	
	
	
	
