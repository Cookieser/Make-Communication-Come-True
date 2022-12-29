server client simulate : 
	$(shell if [ ! -e bin ];then mkdir -p bin; fi)
	g++ -g -o bin/server src/server.cpp src/socket.cpp  source/ClientDetail.cpp source/ServerDetail.cpp   -lgmp -lgmpxx
	g++ -g -o bin/client src/client.cpp src/socket.cpp  source/ClientDetail.cpp source/ServerDetail.cpp   -lgmp -lgmpxx
	g++ -g -o bin/simulate src/simulate.cpp src/socket.cpp  source/ClientDetail.cpp source/ServerDetail.cpp   -lgmp -lgmpxx


clean:
	rm rm -f *.o bin/server bin/client bin/simulate
      

