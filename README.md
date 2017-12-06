# EasyCrossPlatform
Source Code for EasyCrossPlatform, only for development purpose.  
Language: <a href="README-ch.md">中文</a>  
## Introduction
A easy-to-use cross-platform C++ library designed for PHP and Python Users.  
Powered by <a href="http://www.xsyds.cn/" target="_blank">BlueAirTechGroup</a>  
Contribution List: <a href="https://github.com/ToiletCommander">Windy</a>  
Libs: MultiThreadPool | MultiThread | FileIO | TCP & UDP Sockets | MySQL / MariaDB (Using MariaDB C Connector) | Encryption(In Progress) | <strike>HTTP(s)_Requests</strike>  
Test Env: Windows 10 + Visual Studio 2017 | Ubuntu LTS16.04LTS + g++  
Require Support: Unix / Linux / Windows System + C++ 11 Support  
## Credit
The development of EasyCrossPlatform is given power by the following lib:  
[CppSocket](https://github.com/itomi/CppSocket) - CrossPlatform Socket Completely built based on it, but I fixed several bugs that affected the compile process, and also fixed several bugs on runtime.  
[Crypto++](https://github.com/weidai11/cryptopp) - Encryption Lib, EasyCrossPlatform Encryption will be built based on it.  
[MariaDB](https://mariadb.com/downloads/mariadb-tx/connector) - MySQL / MariaDB Connector Lib.  
## Why not GUI?
GUI requires too much dependencies, and we are considering using "mygui". However, the OpenGL environment in each machine can be different, and if you want to use a GUI Lib, we recommend MyGUI with OpenGL2.0 Implemention  
## Develop Theory
Everybody Loves C++, but there is actually no user-friendly libs for beginners to start using C++ with full support of network and multithreading function, while covering the hardware and underlying technologies.   
Influenced by <a href="http://reasoning.biz" target="_blank">Reasoning</a> Library, however, that library is no longer maintained since 2008  
With less code, developers can develop more safe code preventing memory leaks and debug less. EasyCrossPlatform also brings noticeable performance while enabling developers to develop codes fast and secure.  
## Build
This project is not even released with beta and it is still in its early stage of development.  
If you cannot wait to see it, 
1) Enter the lib/mariadb directory and put the correct Files in the lib directory  
2) simply run xmake in the directory to generate a static/shared library that you can use.  
Remeber that the lib file generated is not cross-platform betweeen Win and Linux, and between different versions of Linux.  
You need to generate lib file each time when you are switching platforms.  
## Contribute
You can fork this project and request a Pull Request.   
You can also help improve this project by testing.   
Remember that you need to test your API first before you submit the request. Thank you!  