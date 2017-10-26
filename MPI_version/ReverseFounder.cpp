#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


extern int world_size;



int Processor(string pass,string alphabet,int num){


	

	int proc;

	  
		int val=num/world_size; 
		//cout<<"valori alfabeto per ogni processo:  "<<val<<endl; 
		int x=alphabet.find(pass[0])+1;
		//cout<<"posizione della cifra iniziale della pass in alfabeto:  "<<x<<endl;  // pos di pass[0] in alphabet...
		//proc=x/world_rank;
		//cout<<"x/val"<<ceil(x/val)<<endl;
		if(((float)x/val)  <=  1)
			proc=0;
		else{
			proc=ceil((float)x/val)-1;
			if(proc>(world_size-1))
				proc=world_size-1;
		}
		return proc;
}

int rootProcessorIdentifier(char* passChar,string pass) {

	                string alphabet1 = "0123456789";             
                    string alphabet2 = "abcdefghijklmnopqrstuvwxyz";
                    string alphabet3 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                    string alphabet4 = "0123456789abcdefghijklmnopqrstuvwxyz";
                    string alphabet5 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                    string alphabet6 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";             
                    string alphabet7 = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	
	int num=0;
	int maiusc=0;
	int minusc=0;
	

	int alphabetNum=10; int alphabetMin=26;  int alphabetMaiusc=26;  int alphabetNum_Minusc=36;  int alphabetNum_Maiusc=36;  int alphabetMin_Maiusc=52;  int alphabetNum_Minusc_Maiusc=62;

	int proc;  int temp=0;
	
	for(int i=0;i<pass.length();i++){
	if((int)passChar[i]>=48&&(int)passChar[i]<=57)
		//cout<<"YES"<<endl;
			num++;

	if((int)passChar[i]>=65&&(int)passChar[i]<=90)
		maiusc++;
    if((int)passChar[i]>=97&&(int)passChar[i]<=122)
		minusc++;
	}
	 
	if(num>0&&minusc==0&&maiusc==0){
		//cout<<"alfabeto soli numeri"<<endl;
		proc= Processor(pass,alphabet1,alphabetNum);
		//cout<<"Proc N:  "<<proc<<endl;
	}

	if(num>0&&minusc>0&&maiusc==0){
		//cout<<"alfabeto numeri e minuscole"<<endl;
		proc= Processor(pass,alphabet4,alphabetNum_Minusc);
		//cout<<"Proc N:  "<<proc<<endl;
	}

	if(num>0&&minusc==0&&maiusc>0){
		//cout<<"alfabeto numeri e maiscole"<<endl;
		proc= Processor(pass,alphabet5,alphabetNum_Maiusc);
		//cout<<"Proc N:  "<<proc<<endl;
	}

		if(num>0&&minusc>0&&maiusc>0){
		//cout<<"alfabeto numeri,minuscole e maiscole"<<endl;
		proc= Processor(pass,alphabet7,alphabetNum_Minusc_Maiusc);
		//cout<<"Proc N:  "<<proc<<endl;
	}
	

	if(num==0&&minusc>0&&maiusc==0){
		//cout<<"alfabeto sole minuscole"<<endl;
		//cout<<"Proc N:  "<<proc<<endl;
		proc= Processor(pass,alphabet2,alphabetMin);

	}

	if(num==0&&minusc>0&&maiusc>0){
		//cout<<"alfabeto minuscole e maiscole"<<endl;
		proc= Processor(pass,alphabet6,alphabetMin_Maiusc);
		//cout<<"Proc N:  "<<proc<<endl;
	}

	if(num==0&&minusc==0&&maiusc>0){
		//cout<<"alfabeto minuscole e maiscole"<<endl;
		proc= Processor(pass,alphabet3,alphabetMaiusc);
		//cout<<"Proc N:  "<<proc<<endl;
	}
	
	///////////////////////////////////////////////////////////////////

	return proc;

	//system("pause");
}

