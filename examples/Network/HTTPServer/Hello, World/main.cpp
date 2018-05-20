#include <EasyCrossPlatform.h>
#include <iostream>
using namespace EasyCrossPlatform::Network::Socket;

class MyHTTPResponse {
public:
	static void OnResponse(const EasyCrossPlatform::Parser::HTTP::HTTPRequest& RequestClass, EasyCrossPlatform::Parser::HTTP::HTTPResponse& ResponseClass) {
		ResponseClass.OriginalData = "<!DOCTYPE HTML><html><title>Hello World</title><head></head><body><h1>Hello, World!</h1></body></html>";
		ResponseClass.ResponseCode = 200U;
		ResponseClass.ResponseDescription = "OK";
	}
};
int main(int argc, char** args) {
	IpAddr ListeningAddr = IpAddr("0.0.0.0", 25565U);
	SocketWorker mWorker;
	TCP::TCPAsyncServerSocket mServer = TCP::TCPAsyncServerSocket(ListeningAddr, &mWorker, 500);
	EasyCrossPlatform::Network::HTTPServer::HTTPServer mHTTPServer = EasyCrossPlatform::Network::HTTPServer::HTTPServer(&mServer, 1U, 120.0F);
	mHTTPServer.AcceptWebsocket = false;
	mHTTPServer.setOnRequestCallBack(MyHTTPResponse::OnResponse);
	std::cout << "Press any key to start listen" << std::endl;
	std::cin.get();
	mHTTPServer.StartListen();
	std::cout << "Press any key to exit" << std::endl;
	std::cin.get();
	mHTTPServer.StopListen();
	return 0;
}