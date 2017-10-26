#include <iostream>
#include<conio.h>

using namespace std;


void MyEntry(){   // customized starting point
	
	printf( "Premi un tasto per iniziare:\n" );
	_getch();

}

void MyQuit()     // customized ending point
{   
	system("cls");




	printf("\n\n\n");
			printf("################################################################################");
			printf("--------------------------  S. E. P.  --  2014 / 2015 -------------------------\n\n\n");
			printf("	                 ESECUZIONE TERMINATA CON SUCCESSO:                       \n");
			printf("	        Attacco Brute Force a dizionario con paradigma MPI                 \n\n");
			printf("        V. Colamatteo  matr.: 0040204    --    V. Testa  matr.: xxxxxxx     \n\n\n");
			printf("--------------------------  S. E. P.  --  2014 / 2015 -------------------------\n");
			printf("################################################################################\n\n");
			printf("\n\n\n");

			
	printf( "\n\nPremi un tasto per terminare definitivamente:\n" );
	_getch();
	_getch();
	exit(0);
}

void starter(){





	printf("\n\n\n");
			printf("################################################################################");
			printf("--------------------------  S. E. P.  --  2014 / 2015 -------------------------\n\n\n");
			printf("                             Elaborato di fine corso:                            \n");
			printf("	        Attacco Brute Force a dizionario con paradigma MPI                 \n\n");
			printf("                                Valerio Colamatteo\n");
			printf("                                  matr.: 0040204\n\n");
			printf("                                Valerio Testa\n");
			printf("                                  matr.: xxxxxxx\n\n\n");
			printf("--------------------------  S. E. P.  --  2014 / 2015 -------------------------\n");
			printf("################################################################################\n\n");
			printf("\n\n\n");

			
			MyEntry();
			system("cls");


}


void formInseert(){
system("cls");
			          printf("\n\n\n\n\n\n");
	printf("*******************************************************************************\n");
    cout << " Reinserire Password prego...\n";
	printf("*******************************************************************************\n");
	printf("\n\n ");

}

void myExit_Error() {
	system("cls");


		printf("\n\n\n");
			printf("################################################################################");
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
	_getch();
	_getch();

}





void FinalResult(string pass, long int attempt, double time){

	system("cls");

printf("\n\n\n"); 
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