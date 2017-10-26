#include<iostream>
#include <string>
#include <windows.h>
#include <mpi.h>
#include "Initial.h"
#include "Other.h"
using namespace std;

 bool correct=false;

extern string pass; 
extern char msg[20];
extern int world_size;

string AcquirePathSavingFile(){

	OPENFILENAME ofn;

    char szFileName[MAX_PATH] = "";

    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(ofn); 
    ofn.hwndOwner = NULL;
    ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = "txt";

    if(GetSaveFileName(&ofn)){
	string path=  ofn.lpstrFile;
	return path;}

	else{MyQuit();}

}


 void Error_handler(){
    int count=0;
	int ErrorChar=0; 
	
			caseOne(count);
			
	       caseTwo(count);
	


}


 void caseOne(int count){
	 
		int d; int X=-1;
		correct=false;
		while(!correct){

		    cin >> msg; 
			 pass=msg; 

			
			


		if(pass.length()>15){  //1 0 2
		             if(count>0&&count<=2)                                                      // tasti: annulla, riprova, ignora    // icona    // tasto riprova selezionato di default
			                     d=MessageBox(0, "ATTENZIONE!\nERRORE!  La password deve contenere al massimo 15 caratteri alfanumerici.", "  FATAL ERROR   ",MB_ABORTRETRYIGNORE|MB_SETFOREGROUND| MB_ICONWARNING|MB_DEFBUTTON2);
		             
					      else // 0
			                  d=MessageBox(0, "ERRORE! Lunghezza password superiore a 15!", "    FATAL ERROR   ",MB_RETRYCANCEL| MB_SETFOREGROUND|MB_ICONHAND|MB_DEFBUTTON1);

       		if(count>2&& d==4){                                                      // tasti SI NO cancel
		                  	d=MessageBox(0, "Password ancora errata....\n\nSI VUOLE RIPROVARE ANCORA?", "  FATAL ERROR   ",MB_YESNOCANCEL| MB_SETFOREGROUND|MB_ICONWARNING|MB_DEFBUTTON1);

			if(d==6){  // SI
				
		             formInseert();
		             continue;
			       }
				
			if(d==7)  {//No
		         d=MessageBox(0, "SI E' SICURI DI VOLERE ABBANDONARE LA PROCEDURA DI RECUPERO PASSWORD ?\n\n", "  ULTIMATE WARNING   ",MB_YESNO| MB_SETFOREGROUND|MB_ICONWARNING|MB_DEFBUTTON1);
				   if(d==6){  
					 for (int i=1;i<world_size;i++)
					 MPI_Send(&correct, 1, MPI_C_BOOL, i, 0, MPI_COMM_WORLD);
				
					 myExit_Error();
		             exit(-1);  }
				   if(d==7){
					   formInseert();
					   continue;
				   }
	                  }
			
		                    }

                     		    if(d==11){ 
		                               formInseert();
                           	           count++;
								continue;}
	

	                           if(d==2){  //Annulla
								   
								   for (int i=1;i<world_size;i++){ 
									   MPI_Send(&correct, 1, MPI_C_BOOL, i, 0, MPI_COMM_WORLD);}
								   MPI_Finalize();
								   myExit_Error();
								   
								   exit(-1);}
	  
                    	      if(d==4)   {  // Riprova
								  
		                          count++; 
								  
	                               formInseert();
	                               continue;
								   
							  }
	
                             if(d==3){ // Annulla 
								 for (int i=1;i<world_size;i++)
								   MPI_Send(&correct, 1, MPI_C_BOOL, i, 0, MPI_COMM_WORLD);
								 MPI_Finalize();
		                           myExit_Error(); 
								   exit(-1);
		                          }

	                      }

                    	                        if(d==5){  // Ignora
													for (int i=1;i<world_size;i++)
								   MPI_Send(&correct, 1, MPI_C_BOOL, i, 0, MPI_COMM_WORLD);
		                                             myExit_Error(); 
													 exit(-1); 
		                                            }
	
	                       
					                            else{
													correct=true;
	
		                                              return ;
		                                            
												    }
	
             	            }


	}


 	boolean alphanumeric(){

				int num=0; 




					size_t i = 0;  boolean findErrorChar=false;
size_t len = pass.length();
while(i < len){
    if (!isalnum(pass[i]) || pass[i] == ' '){
		num++;
        pass.erase(i,1);
        len--;
    }else
        i++;
}

if(num>0){
	findErrorChar=true;

}
return findErrorChar;

	}




 void	caseTwo(int count){

		string OrigianlPass;  int d;
		correct=false;
char NewPass[300];   boolean findErrorChar;


		while(!correct){
if(count>0)	              
		     cin >> msg; 
			 pass=msg;
            OrigianlPass=pass;
			findErrorChar=alphanumeric();
			if(findErrorChar){  count++;
                           if(count>0&&count<=2){                                       // tasti: annulla, riprova, ignora    // icona    // tasto riprova selezionato di default                   
			                     d=MessageBox(0, "ATTENZIONE!\nERRORE!  La password deve contenere esclusivamente caratteri alfanumerici.", "  FATAL ERROR   ",MB_ABORTRETRYIGNORE|MB_SETFOREGROUND| MB_ICONWARNING|MB_DEFBUTTON2);
					 sprintf(NewPass," PASSWORD INSERITA:  %s\n\nPASSWORD CORRETTA:  %s\n", OrigianlPass.c_str(),pass.c_str());
				
						   }
					 
       		if(count>2){                                                      // tasti SI NO cancel
				d=MessageBox(0, "Password ancora errata....\n\nSI VUOLE RIPROVARE ANCORA?", "  FATAL ERROR   ",MB_YESNOCANCEL| MB_ICONWARNING|MB_DEFBUTTON1);
				sprintf(NewPass," PASSWORD INSERITA:  %s\n\nPASSWORD CORRETTA:  %s\n", OrigianlPass.c_str(),pass.c_str());
				//
		                  	
							
	
								             

			if(d==6){  // SI
				
				formInseert();
				MessageBox(0, NewPass, "WARNING  ", MB_OK | MB_ICONINFORMATION | MB_SETFOREGROUND | MB_RIGHT);
		          continue;
			       }
				
			if(d==7)  {//No
				//cout<<"EE"<<endl;
				for (int i=1;i<world_size;i++)
                    MPI_Send(&correct, 1, MPI_C_BOOL, i, 0, MPI_COMM_WORLD);
		         myExit_Error();
		         exit(-1);
	                  }
			if(d==2)  //Annulla
				
				for (int i=1;i<world_size;i++)
				       MPI_Send(&correct, 1, MPI_C_BOOL, i, 0, MPI_COMM_WORLD);
			     myExit_Error();
				exit(-1);
			}

	  
                    	      if(d==4)   {  // Riprova
		                          
								  MessageBox(0, NewPass, "USO CORRETTO DEL PASSWORD FINDER  ", MB_OK | MB_ICONINFORMATION | MB_SETFOREGROUND | MB_RIGHT);	
								  formInseert();
	                               count++;
	                               continue;
							  }
	
                             if(d==3){  // Annulla 
				
								 for (int i=1;i<world_size;i++)
				       MPI_Send(&correct, 1, MPI_C_BOOL, i, 0, MPI_COMM_WORLD);
								 
		                          myExit_Error();
		                          exit(-1);}

			
							 }
                    	                        if(d==5){  // Ignora
				
													for (int i=1;i<world_size;i++)
				       MPI_Send(&correct, 1, MPI_C_BOOL, i, 0, MPI_COMM_WORLD);
		                                             myExit_Error();
		                                             exit(-1);}
	
                        	                    if(d==3){  // Annulla
				
													for (int i=1;i<world_size;i++)
				       MPI_Send(&correct, 1, MPI_C_BOOL, i, 0, MPI_COMM_WORLD);
		                                            myExit_Error();
		                                            exit(-1);}
			
												if(findErrorChar==0){
		                                               correct=true;  
													   for (int i=1;i<world_size;i++)
								                       MPI_Send(&correct, 1, MPI_C_BOOL, i, 0, MPI_COMM_WORLD);
													   return;
													
												    }
 	
		}
	
	}