#include<iostream>
#include <string>
#include<ctime>
#include <windows.h>
#include "Initial.h"
#include "Other.h"
#include "Output.h"
#include "passFinder.h"
using namespace std;

extern string pass;

string test;
boolean found=false;
long int attempt=0;

//clock_t start_t, end_t;



boolean passFinder(string &alphabet,int &passwordLength){
      
	   /*int passwordLength=4;*/ //int length=5; 
		int Al[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
		for (int i=0;i<passwordLength;i++)
			Al[i]=alphabet.length();

		/*for (int i=0;i<15;i++)
			cout<<Al[i]<<"\n";*/
		//system("pause");

		//cout<<"A[15]=  "<<Al[14]<<endl;

//		start_t=clock();
		/*if(passwordLength==4)
		Sleep(61000);*/

		//int Al[8+1]={8,7,6,5,4,3,2,1,0};
		int digit[15],alphabetLength=alphabet.length();
		                             //  Alphabet="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		

for(digit[14]=0;digit[14]<Al[14];digit[14]++)
    for(digit[13]=0;digit[13]<Al[13];digit[13]++)
     	for(digit[12]=0;digit[12]<Al[12];digit[12]++)
           for(digit[11]=0;digit[11]<Al[11];digit[11]++)
		
		      for(digit[10]=0;digit[10]<Al[10];digit[10]++)
                  for(digit[9]=0;digit[9]<Al[9];digit[9]++)
                     for(digit[8]=0;digit[8]<Al[8];digit[8]++)

                         for(digit[7]=0;digit[7]<Al[7];digit[7]++)
                             for(digit[6]=0;digit[6]<Al[6];digit[6]++)
                                 for(digit[5]=0;digit[5]<Al[5];digit[5]++)
                                    for(digit[4]=0;digit[4]<Al[4];digit[4]++)
                                        for(digit[3]=0;digit[3]<Al[3];digit[3]++)

		                                    for(digit[2]=0;digit[2]<Al[2];digit[2]++)
                                                for(digit[1]=0;digit[1]<Al[1];digit[1]++)
                                                    for(digit[0]=0;digit[0]<Al[0];digit[0]++){
                                                         attempt++;
                                    //                   if(attempt%2500000==0) cout << ".";
                                                         test=alphabet[digit[0]]; //cout<<"test1: "<<test<<endl;
                                                             for(int i=1;i<passwordLength;i++)
                                                                 {/*attempt++;*/test+=alphabet[digit[i]]; //cout<<"test2 "<<test<<"\n";//<<"    alphabet[digit["<<i<<"]]= "<<alphabet[digit[i]]<<endl; 
													               //system("pause");
			          										     }
            			          										  if(pass.compare(test)==0){/*cout<<"HERE"<<endl;system("pause");*/ found=true; 
				                                                                 return found;}

													                                         }
       												   	                  


				return found;
												
	}