#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>
#include<vector>
#include<fstream>
#include <windows.h>
#include <mpi.h>
#include <stdlib.h>

#include "FolderBrowserDialog.h"
#include "Initial.h"
#include "Other.h"
#include "Output.h"
#include "passFinder.h"
#include"ReverseFounder.h"
using namespace std;


extern long int attempt;
extern string test;

string pass;   
const char *passChar ;

extern bool correct;
string timeCurrentStart;
char* dt;

int world_size;
int world_rank;
int root;


char msg[200];
char date[100];

	
int main(){	


	// Initialize the MPI environment
    MPI_Init(0,0);
					MPI_Status status; 
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
	MPI_Get_processor_name(processor_name, &name_len); 

	if(world_rank==0){


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
   
	 root=rootProcessorIdentifier(msg,pass);

	 


   for (int i=1;i<world_size;i++){
   MPI_Send(&root, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
  // MPI_Send(&mem,1,MPI_INT,i,0,MPI_COMM_WORLD);
   MPI_Send(timeCurrentStart.c_str(), timeCurrentStart.length(), MPI_CHAR, i, 0, MPI_COMM_WORLD);
   MPI_Send(pass.c_str(), pass.length(), MPI_CHAR, i, 0, MPI_COMM_WORLD);}
	
 
	}
	
	else{
	
	MPI_Recv(&correct, 1, MPI_C_BOOL, 0, 0, MPI_COMM_WORLD, &status);
	if(correct==false){
		MPI_Finalize();}
	
	MPI_Recv(&root, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
//	MPI_Recv(&mem,1,MPI_INT,0,0,MPI_COMM_WORLD,&status); cout<<"mem  "<<*mem<<endl; //system("pause");
	MPI_Recv(&date, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status);
	MPI_Recv(&msg, 20, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status);
	timeCurrentStart=date;
	pass=msg;
	//CreateArrayProc();

		}
		hackPassword();


    return 0;
}

