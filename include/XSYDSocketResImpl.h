#ifndef __EasyCrossPlatform_SocketResImplFile__
	#define __EasyCrossPlatform_SocketResImplFile__
	#include <EasyCP_Common.h>
	#include <libuv/uv.h>
	#include <XSYDMultiTask.h>
	namespace EasyCrossPlatform {
		namespace Network {
			namespace Socket {
				//IpV4��ȫ��������0.0.0.0
				//IpV6��ȫ��������::
				class IpAddr {
					friend class UDPAsyncSocket;
					friend class TCPAsyncClientSocket;
					friend class TCPAsyncServerSocket;
					friend class DNSRequest;
					protected:
						sockaddr m_Addr;
						bool m_isIpV4 = true;
					public:
						IpAddr();
						IpAddr(const std::string& IpAddress, const unsigned short Port, bool AddrIpV4);
						IpAddr(const char* IpAddress, const unsigned short Port, bool AddrIpV4);
						IpAddr(const sockaddr& newAddr);
						IpAddr(const IpAddr& oldAddr);
						bool setIPAddress(const std::string& IpAddress, const unsigned short Port, bool AddrIpV4);
						bool setIPAddress(const char* IpAddress, const unsigned short Port, bool AddrIpV4);
						bool setIPAddress(const sockaddr& newAddr);
						std::string getIPString();
						bool addrIsIPV4();
						unsigned short getPort();
						sockaddr getIPAddress();
				};
				class SocketParam {
					private:

					protected:
						static EasyCrossPlatform::Thread::SingleWork m_MTManager;
					public:
						static unsigned int m_num_Client;
						static uv_loop_t m_uv_loop;
						static void Start();
						static void Stop();
						
						static void m_MultiThread_Job(std::thread::id ThreadID, void* Parameters, bool * RunningSign, std::mutex *Mutex);
				};
				class SocketWorker {
					private:
						
					protected:

					public:
						SocketWorker();
						SocketWorker(SocketWorker& LeftSocket);
						unsigned int m_num_Client = 0U;
						std::shared_ptr<uv_loop_t> m_uv_loop;
						EasyCrossPlatform::Thread::SingleWork m_MTManager;
						void Start();
						void Stop();
						static void m_MultiThread_Job(std::thread::id ThreadID, void* Parameters, bool * RunningSign, std::mutex *Mutex);
						~SocketWorker();
				};
			}
		}
	}
#endif