#include<iostream>
#include <string>
#include <windows.h>

using namespace std;

extern string pass;
long int attempt=0;
string test;

boolean found=false;

int Al[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int digit[15];


boolean passFinder(string &OriginalAlphabet,string &alphabet,int &passwordLength){

	
	//	   cout<<"pid: "<<world_rank<<"\n";  fflush(stdout);

		
		for (int i=0;i<passwordLength;i++)
			Al[i]=OriginalAlphabet.length();


		Al[0]=alphabet.length();
		
		              

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
        
                                                         test=alphabet[digit[0]]; //cout<<"test1: "<<test<<endl;
                                                             for(int i=1;i<passwordLength;i++)
                                                                 {
																	 test+=OriginalAlphabet[digit[i]]; //cout<<"test2 "<<test<<"\n";

		
																	 
			          										     }
															 if(pass.compare(test)==0){
																
																     found=true; 
				                                                     return found;}

													                                  }
													

				return found;
												
	}