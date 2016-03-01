#include "headers/HTTPPerform.h"
#include <iostream>
#include <string>
#include <exception>
#include <stdio.h>


int main(int argc, char** argv) {
	HTTPPerform *performer = new HTTPPerform("http://10.155.10.206:8000/");
	applications* appList;	
	try {			
		appList = performer->perform(DOWNLOAD,15);	
 		if (performer->getError() == 1)
 			cout << "Error occured during HTTP request :" << performer->getErrorMessage() << endl;
 		else if (appList->apps != NULL)
 		{
 			for(int i=0;i< appList->size; i++)
				{							
					cout << "Application "<< to_string(i) << endl;
					cout << "\t" << "id: " << to_string(appList->apps[i].id)<<endl;
					cout << "\t" << "name: " << (appList->apps[i].name)<<endl;
					cout << "\t" << "developer name: " << (appList->apps[i].developerName)<<endl;
					cout << "\t" << "icon: " << (appList->apps[i].iconName)<<endl;					
				}
 		}
 		if(appList->apps->isInstalled == 1 && appList->apps->isDownloaded) 
			cout << "Application installed" << endl;			
		else 		
			cout << "Error occured: " << appList->apps->errorCode << endl;			
		
	
	}
	
	catch(exception &e)
        {
            cout << "Exception!:" << e.what() << endl;           
        }
		
	return 0;
}