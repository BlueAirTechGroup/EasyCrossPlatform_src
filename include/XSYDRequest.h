#ifndef __XSYDREQUESTFILE__
	#define __XSYDREQUESTFILE__
	#include <EasyCP_Common.h>
	#include <XSYDHTTPParser.h>
	#include <XSYDTCPSocket.h>
	#include <XSYDTLSSocket.h>
	#include <XSYDStringUtil.h>
	#include <XSYDDNS.h>
	#include <XSYDHTTPMethodDec.h>
	#include <XSYDTrustedCert.h>
	#include <XSYDChrono.h>
	namespace EasyCrossPlatform {
		namespace Network {
			namespace Request {
				const constexpr char* acceptEncodings[4] = { "br","gzip","deflate","identity" };
				const constexpr float acceptEncodingWeights[4] = { 1.0F, 0.9F, 0.8F, 0.1F };
				const constexpr unsigned int acceptEncodingNum = 4U;
				const constexpr double ReqTimeout = 10.0;
				std::vector<std::pair<std::string, float>> generateAcceptEncodingList();
				struct WebsiteRequestInfo {
					int ConnectionErrorNum;
					EasyCrossPlatform::Parser::HTTP::HTTPResponse ResponseContent;
				};
				class WebsiteRequest {
				private:
					
				protected:
					EasyCrossPlatform::Network::Socket::DNSRequest m_DNSRequest;
					EasyCrossPlatform::Network::Socket::SocketWorker m_SharedSocketWorker;
					EasyCrossPlatform::Network::Socket::TCPAsyncClientSocket m_ClientSocket;
					EasyCrossPlatform::Network::Socket::TLSAsyncClientSocket m_TLSClientSocket;
					bool m_IsProcessing = false;
					bool m_IsHTTPS = false;
					bool m_operationSucceed = false;
					static void m_TCPMsg_CB(const std::vector<byte>& Msg, void* ClassPtr);
					static void m_TCPConn_CB(bool Succeed, void* ClassPtr);
					static void m_TCPDisConn_CB(void* ClassPtr);
					static void m_TCPErr_CB(int ErrNo, const std::string& ErrDescription, void* ClassPtr);
					static void m_TLSMsg_CB(const std::vector<byte>& Msg, void* ClassPtr);
					static void m_TLSConn_CB(bool Succeed, void* ClassPtr);
					static void m_TLSDisConn_CB(void* ClassPtr);
					static void m_TLSErr_CB(int ErrNo, const std::string& ErrDescription, void* ClassPtr);
					std::string m_MsgWaitingForRead = "";
				public:
					void cleanUp();
					void cleanRequest();
					std::string RequestURL = "";
					bool SucceedRequest = true;
					EasyCrossPlatform::Parser::HTTP::HTTPRequest m_ResquestContent;
					EasyCrossPlatform::Parser::HTTP::HTTPResponse ResponseContent;
					RequestMethod Method = RequestMethod::GET;
					std::string RequestData;
					std::string ResponseOriginalData;
					bool VerifyHTTPSCert = true;
					void performRequest(); //Performs the request, operation would block. Throws runtime error when protocol not recognized
				};
			}
		}
	}
#endif