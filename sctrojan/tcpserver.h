#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <cstdint>
#include <functional>
#include <thread>
#include <list>

#ifdef _WIN32

#include <WinSock.h>

#else 

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unitstd.h>
#include <stdio.h>
#include <stdlib.h>

#endif

static constexp uint16_t buffer_size = 4096;

struct TcpServer{
	class Client;
	typedef std::function<void(Client)> handler_function_t;
	enum class status: uint8_t{
		up = 0,
		err_socket_init = 1, 
		err_socket_bind = 2,
		err_socket_listening = 3,
		close = 4
	};
private:
	uint16_t port;
	status _status = status::close;
	handler_function_t handler;

	std::thread handler_thread;
	std::list<std::thread> client_handler_threads;
	std::list<std::thread::id> client_handling_end;
#ifdef _WIN32 
	SOCKET serv_socket = INVALID_SOCKET;
	WSAData w_data;
#else
	int serv_socket;
#endif
	void handlingLoop();
public:
	TcpServer(const uint16_t port, handler_function_t handler);
	~TcpServer();

	void setHandler
}
