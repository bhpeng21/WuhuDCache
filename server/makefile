.PHONY:run clean
run:go
TcpServer.o:TcpServer.cpp TcpServer.h
	g++ -c TcpServer.cpp
utils.o:utils.cpp utils.h
	g++ -c utils.cpp
server.o:server.cpp TcpServer.h utils.h
	g++ -c server.cpp
go:server.o TcpServer.o utils.o
	g++ -o go server.o TcpServer.o utils.o
	./go
clean:
	rm -r *.o
