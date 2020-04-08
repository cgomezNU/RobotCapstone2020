OBJS	= AnlogSens.o Joint.o main.o mcp3008Spi.o PID.o Pos.o
SOURCE	= AnlogSens.cpp, Joint.cpp, main.cpp, mcp3008Spi.cpp, PID.cpp, Pos.cpp,
HEADER	= AnlogSens.h, Joint.h, mcp3008Spi.h, PID.h, Pos.h
OUT	= robotArms
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

AnlogSens.o: AnlogSens.cpp,
	$(CC) $(FLAGS) AnlogSens.cpp, 

Joint.o: Joint.cpp,
	$(CC) $(FLAGS) Joint.cpp, 

main.o: main.cpp,
	$(CC) $(FLAGS) main.cpp, 

mcp3008Spi.o: mcp3008Spi.cpp,
	$(CC) $(FLAGS) mcp3008Spi.cpp, 

PID.o: PID.cpp,
	$(CC) $(FLAGS) PID.cpp, 

Pos.o: Pos.cpp,
	$(CC) $(FLAGS) Pos.cpp, 


clean:
	rm -f $(OBJS) $(OUT)
