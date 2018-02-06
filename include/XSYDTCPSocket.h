#ifndef __EasyCrossPlatform_TCPSocketFile__
	#define __EasyCrossPlatform_TCPSocketFile__
	#include <EasyCP_Common.h>
	#include <XSYDMultiTask.h>
	#include <libuv/uv.h>
	#include <XSYDSocketResImpl.h>
	namespace EasyCrossPlatform{
		namespace Network{
			namespace Socket{
				typedef void(*TCPClientMsgCallBack)(const std::string&, void*);
				typedef void(*TCPClientConnectCallBack)(bool, void*);
				typedef void(*TCPClientDisconnectCallBack)(void*);
				typedef void(*TCPServerNewConnectionCallBack)(void*, void*);
				typedef void(*TCPClientErrorCallBack)(int, const std::string&, void*);
				typedef void(*TCPServerErrorCallBack)(int, const std::string&, void*);
				class TCPAsyncClientSocket {
					friend class TCPAsyncServerSocket;
					private:
						
					protected:
						static std::map<uv_tcp_t*, std::vector<TCPAsyncClientSocket*>> m_MyClassPtrs;
						IpAddr m_remoteAddr;
						std::shared_ptr<uv_tcp_t> m_ClientSocketHandle;
						bool m_Connected;
						bool Inited;
						bool Closing;
						static std::mutex sharedMutex;
						static void m_uv_connect_cb(uv_connect_t* req, int status);
						static void m_uv_close_cb(uv_handle_t* handle);
						static void m_uv_read_cb(uv_stream_t* stream, ssize_t nread, const uv_buf_t* buf);
						static void m_uv_shutdown_cb(uv_shutdown_t* req, int state);
						static void m_uv_write_cb(uv_write_t* req, int status);
						static void m_uv_alloc_buffer(uv_handle_t* handle, size_t suggested_size, uv_buf_t* buf);

						SocketWorker* mySocketWorker;
						void onConnected(bool Succeeded);
						void onMsg(const std::string& Msg);
						void onDisconnect();
						void onError(int errCode, const std::string& errDescription);
					public:
						TCPAsyncClientSocket();
						TCPAsyncClientSocket(const IpAddr& RemoteIP);
						TCPAsyncClientSocket(const TCPAsyncClientSocket& oldClient);
						
						void setWorker(SocketWorker& socketWorker);
						void Init();
						void Connect();
						void setRemoteIPAddr(const IpAddr& newIP);
						IpAddr getMyIpAddr();
						IpAddr getRemoteAddr();
						void SendMsg(const std::string& Msg);
						void Disconnect();
						void Destroy();

						TCPClientConnectCallBack ConnectCallBack;
						TCPClientMsgCallBack MsgCallBack;
						TCPClientErrorCallBack ErrorCallBack;
						TCPClientDisconnectCallBack DisconnectCallBack;

						~TCPAsyncClientSocket();
				};

				class TCPAsyncServerSocket {
					private:

					protected:
						void onConnection(TCPAsyncClientSocket* newClient);
						void onError(int errCode, const std::string& errorDescription);
						
						static std::map<uv_tcp_t*, std::vector<TCPAsyncServerSocket*>> m_MyClassPtrs;
						static void m_uv_connection_cb(uv_stream_t* server, int status);

						std::shared_ptr<uv_tcp_t> m_SocketHandle;
						IpAddr m_myIP;
						bool isListening;
						bool hasInted;
						int m_QueueLength;
						SocketWorker* myListenWorker;
						std::deque<SocketWorker*> myClientWorker;
					public:
						TCPAsyncServerSocket();
						TCPAsyncServerSocket(const IpAddr& myIP, int QueLength);
						TCPAsyncServerSocket(const TCPAsyncServerSocket& oldServer);

						void setWorkers(SocketWorker& listeningWorker, std::deque<SocketWorker*>& clientWorkers);
						void Init();
						void Destroy();

						void setIP(const IpAddr& myIP, int QueLength = 0);
						IpAddr getIP();
						void Listen();
						void Listen(const IpAddr& myIP, int QueLength = 0);
						void StopListen();

						TCPClientConnectCallBack ClientConnectCallBack;
						TCPClientMsgCallBack ClientMsgCallBack;
						TCPClientErrorCallBack ClientErrorCallBack;
						TCPClientDisconnectCallBack ClientDisconnectCallBack;
						TCPServerNewConnectionCallBack ServerNewConnCallBack;
						TCPServerErrorCallBack ServerErrorCallBack;

						~TCPAsyncServerSocket();
				};
			}
		}
	}
#endif