.PHONY:run clean
run:go
TcpClient.o:TcpClient.cpp TcpClient.h
	g++ -c TcpClient.cpp
TcpServer.o:TcpServer.cpp TcpServer.h
	g++ -c TcpServer.cpp
utils.o:utils.cpp utils.h LRU.h TcpClient.h
	g++ -c utils.cpp
LRU.o:LRU.cpp LRU.h
	g++ -c LRU.cpp
main.o:main.cpp TcpServer.h utils.h LRU.h TcpClient.h
	g++ -c main.cpp
go:main.o TcpServer.o utils.o LRU.o TcpClient.o
	g++ -o go main.o TcpServer.o TcpClient.o utils.o LRU.o
clean:
	rm -r *.o
