#ifndef __XSYDCommonHeaderFile__
	#define __XSYDCommonHeadersFile__
	#define NULL 0
	//Defineϵͳ����
	#define EASYCROSSPLATFORM_VERSION 0;
	/* 
	#if defined(linux) || defined(_UNIX) || defined(__LINUX__) || defined(__unix__)
		#define EASYCROSSPLATFORM_PLATFORM_LINUX true
	#elif defined(__WINDOWS_) || defined(_WIN32)
		#define EASYCROSSPLATFORM_PLATFORM_WINDOWS true
	#endif
	*/
	#if defined(__WINDOWS_) || defined(_WIN32) || defined(_WIN64)
        #define EASYCROSSPLATFORM_PLATFORM_WINDOWS
    #else
        #define EASYCROSSPLATFORM_PLATFORM_LINUX
    #endif
	#include <string> //��׼�ַ���
	#include <chrono> //ʱ��
	#include <cassert> //Debug��
	#include <exception> //Exception�쳣��
	#include <stdexcept> //StdExceptionͨ���쳣��
	#include <vector> //STD��̬����Vector
	#include <deque> //STD����[˫������]Deque
	#include <list> //STD�б�
#endif
