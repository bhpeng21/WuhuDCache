.PHONY:run clean
run:go
TcpClient.o:TcpClient.cpp TcpClient.h
	g++ -c TcpClient.cpp
client.o:client.cpp TcpClient.h
	g++ -c client.cpp
go:client.o TcpClient.o
	g++ -o go client.o TcpClient.o
	./go
clean:
	rm -r *.o
