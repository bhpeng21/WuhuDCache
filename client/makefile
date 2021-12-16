.PHONY:run clean
run:go
TcpClient.o:TcpClient.cpp TcpClient.h
	g++ -c TcpClient.cpp
main.o:main.cpp TcpClient.h
	g++ -c main.cpp
go:main.o TcpClient.o
	g++ -o go main.o TcpClient.o
clean:
	rm -r *.o
