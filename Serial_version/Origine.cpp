#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>
#include<vector>
#include<fstream>
#include <windows.h>

#include "FolderBrowserDialog.h"
#include "Initial.h"
#include "Other.h"
#include "Output.h"
using namespace std;


string pass;   const char *passChar ;

extern bool correct;

string timeCurrentStart;



	char msg[200];
	char date[100];


int main(){	
timeCurrentStart=currentDatetime();



    starter();
	printf("\n\n\n\n\n\n");
	printf("*******************************************************************************\n");
    cout << " Inserire Password alfanumerica (Max 15 caratteri):\n";
	printf("*******************************************************************************\n");
	printf("\n\n ");
	
	
	Error_handler();



	int count=0;
	int ErrorChar=0; 
	
			
	 pass=msg;

	
 
			
    hackPassword();
	

	

    return 0;
}

