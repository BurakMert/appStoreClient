#include <string.h>
#include "cJSON.h"
#include <stdio.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <curl/curlbuild.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <openssl/sha.h>
#include <dbus/dbus.h>

using namespace std;


enum ACTION{
	INDEX,
	SHOW,
	DOWNLOAD
};
struct application {
		int id;
		string name;
		string developerName;
		string iconName;
		string hashValue;
		string binaryPath;
		string binaryName;
		string packagePath;
		int isDownloaded;
		int isInstalled;
		int error;
		string errorCode;		
};
struct applications {
	int size;	
	application* apps;
};	

class HTTPPerform {

public:
	HTTPPerform();
	~HTTPPerform();
	applications* perform(ACTION, int);
	int getError();
	string getErrorMessage();
private:
	void* curl;	
	int errorFlag;
	string errorMessage;
	int install(const string&, application*);
	int download(const string&, application*);
	int getContent(string,string&);
	applications* parseString(string);
};

