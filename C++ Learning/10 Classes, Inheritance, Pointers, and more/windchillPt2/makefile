# Author: Orlando Cerralta
# Date:   06/04/21
# Focus:  Understanding makefiles
CC = g++
CFLAGS = -Wall -g
out: main.o temperatureImp.o windchillImp.o
	$(CC) main.o temperatureImp.o windchillImp.o -o windchill
	(clean)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

temperatureImp.o: temperatureImp.cpp temperature.h
	$(CC) $(CFLAGS) -c temperatureImp.cpp

windchillImp.o: windchillImp.cpp windchill.h
	$(CC) $(CFLAGS) -c windchillImp.cpp

clean:
	rm *.o
