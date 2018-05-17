﻿#include <EasyCrossPlatform.h>
#include <iostream>
using namespace EasyCrossPlatform::Network::Socket;

class MySocket {
public:
	static void ConnectCB(bool Succeeded, TCPAsyncClientSocket* ClassPtr) {
		EasyCrossPlatform::Network::Socket::TLSAsyncClientSocket* MyClass = ClassPtr;
		if (Succeeded) {
			std::cout << "Socket Connected" << std::endl;
			MyClass->SendMsg("GET / HTTP/1.1\r\nHOST:www.kvm.ink\r\nConnection: Keep-Alive\r\n\r\n");
		}
	}
	static void MsgCB(const std::string& Msg, TCPAsyncClientSocket* ClassPtr) {
		EasyCrossPlatform::Network::Socket::TLSAsyncClientSocket* MyClass = ClassPtr;
		std::cout << Msg;
	}
	static void DisconnectCB(void* ClassPtr) {
		EasyCrossPlatform::Network::Socket::TLSAsyncClientSocket* MyClass = ClassPtr;
		std::cout << "SocketDis" << std::endl;
	}
	static void ErrorCB(int errCode, const std::string& errDescription, TCPAsyncClientSocket* ClassPtr) {
		EasyCrossPlatform::Network::Socket::TLSAsyncClientSocket* MyClass = ClassPtr;
		std::cout << "Error:" << errDescription << std::endl;
	}
};

int main(int argc, char** args) {
	std::string myTrustedCA = EasyCrossPlatform::File::FileIO::ReadFile("E:\\C++\\EasyCrossPlatform_VS\\CALIST.txt");
	TLSAsyncClientSocket myClient;
	SocketWorker myWorker;
	myClient.setWorker(&myWorker);
	myClient.ConnectCallBack = MySocket::ConnectCB;
	myClient.DisconnectCallBack = MySocket::DisconnectCB;
	myClient.MsgCallBack = MySocket::MsgCB;
	myClient.ErrorCallBack = MySocket::ErrorCB;
	myClient.VerifyServerCert = true;
	myClient.Init();
	myClient.setRemoteIPAddr(IpAddr("104.27.184.99", 443, true));
	myClient.setTrustedCAChain(myTrustedCA);
	myClient.serverHostName = "www.kvm.ink";
	system("pause");
	myClient.Connect();
	system("pause");
	myClient.Disconnect();
	myClient.Destroy();

}