#ifndef __XSYDCommonHeaderFile__
	#define __XSYDCommonHeadersFile__
	#define NULL 0 //NULL can be interpreted using 0
	typedef unsigned char byte; //Byte is unsigned char, you can cast it just from char
	//Defineϵͳ����
	#define EASYCROSSPLATFORM_VERSION 1;
	#include <CrossPlatform_OSDetection.h>
	//***************************************
	#include <stdio.h>
	#include <algorithm>
	#include <memory>
	#include <string> //��׼�ַ���
	#if defined(EASYCROSSPLATFORM_PLATFORM_UNIX)
		#include <string.h>
	#endif
	#include <chrono> //ʱ��
	#include <assert.h>
	#include <cassert> //Debug��
	#include <exception> //Exception�쳣��
	#include <stdexcept> //StdExceptionͨ���쳣��
	#include <vector> //STD��̬����Vector
	#include <deque> //STD����[˫������]Deque
	#include <list> //STD�б�
	#include <map> //STD Dictionary
	#include <utility> //Utilities, now using pairs in them.
	#include <stdlib.h> //StdLib
#endif
