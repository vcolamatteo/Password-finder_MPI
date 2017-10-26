#include <iostream>
#include<conio.h>
#include<mpi.h>
#include "Initial.h"
using namespace std;


void MyEntry(){   // customized starting point
	
	printf( "Premi un tasto per iniziare:\n" );
	cout<<endl;
	
	//char c=getchar(); //cout<<"c=  "<<c<<endl;
	system("pause>nul");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");  // 2 in più rispetto al seriale....
	
	

}

void MyQuit()     // customized ending point
{   

	cout<<endl<<endl<<endl<<endl<<endl<<endl;


	printf("\n\n\n");
			printf("################################################################################\n");
			printf("--------------------------  S. E. P.  --  2014 / 2015 -------------------------\n\n\n");
			printf("	                 ESECUZIONE TERMINATA CON SUCCESSO:                       \n");
			printf("	        Attacco Brute Force a dizionario con paradigma MPI                 \n\n");
			printf("        V. Colamatteo  matr.: 0040204    --    V. Testa  matr.: 0040445     \n\n\n");
			printf("--------------------------  S. E. P.  --  2014 / 2015 -------------------------\n");
			printf("################################################################################\n\n");
			printf("\n\n\n");

			
	printf( "\n\nPremi un tasto per terminare definitivamente:\n" );  

	exit(0);
}

void starter(){





	printf("\n\n\n");
			printf("################################################################################\n");
			printf("--------------------------  S. E. P.  --  2014 / 2015 -------------------------\n\n\n");
			printf("                             Elaborato di fine corso:                            \n");
			printf("	        Attacco Brute Force a dizionario con paradigma MPI                 \n\n");
			printf("                                Valerio Colamatteo\n");
			printf("                                  matr.: 0040204\n\n");
			printf("                                Valerio Testa\n");
			printf("                                  matr.: 0040445\n\n\n");
			printf("--------------------------  S. E. P.  --  2014 / 2015 -------------------------\n");
			printf("################################################################################\n\n");
			printf("\n\n\n");

			
			MyEntry();
			//system("cls");
			


}


void formInseert(){

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); fflush(stdout);
	printf("*******************************************************************************\n"); fflush(stdout);
    cout << " Reinserire Password prego...\n";  fflush(stdout);
	printf("*******************************************************************************\n");  fflush(stdout);
	printf("\n\n ");   fflush(stdout);

}

void myExit_Error() {


			          printf("\n\n\n\n\n\n\n\n\n");
			printf("################################################################################\n");
			printf("--------------------------  S. E. P.  --  2014 / 2015 -------------------------\n\n\n");
			printf("                             Elaborato di fine corso:                            \n");
			printf("	        Attacco Brute Force a dizionario con paradigma MPI                 \n\n");
			printf("********************************************************************************\n");
	        printf("                     ESECUZIONE TERMINATA CON ERRORE.                           \n");
	        printf("********************************************************************************\n\n");
			printf("--------------------------  S. E. P.  --  2014 / 2015 -------------------------\n");
			printf("################################################################################\n\n");
			printf("\n\n\n");

	printf("Premere un tasto per terminare definitivamente...\n");
	MPI_Finalize();

}



void FinalResult(string pass, long int attempt, double time){

	cout<<endl<<endl<<endl<<endl<<endl;
	cout<<endl<<endl<<endl<<endl<<endl;

printf("\n\n\n"); fflush(stdout); 
	printf("################################################################################\n");fflush(stdout); 
	printf("\n\n\n");fflush(stdout); 
	printf("Riepilogo password identificata:       %s\n",pass);fflush(stdout); 
    printf("Numero di tentativi complessivo:       %ld\n",attempt);fflush(stdout); 
	if(time<60){
		printf("Time-elapsed comlessivo (secondi):     %fl\n",time);fflush(stdout); }
	else{
		printf("Time-elapsed comlessivo (minuti):     %fl\n",time/60);fflush(stdout); }
	printf("\n\n\n");fflush(stdout); 
	printf("################################################################################\n\n");fflush(stdout); 



}