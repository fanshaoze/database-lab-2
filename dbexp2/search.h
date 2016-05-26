#pragma once

#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <WinSock2.h>
#include <windows.h>
#include <string.h>
#include <mysql.h>
using namespace std;

BOOL mathod(MYSQL *mysql_conn_d,MYSQL_RES *mysql_result,string command);
