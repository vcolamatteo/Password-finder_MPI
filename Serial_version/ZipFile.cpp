#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include<vector>
#include<string>


#include "zip.h"
//#include "unzip.h"

#include<iostream>
using namespace std;


vector<string> path_vector;
vector<string> names;


vector<string> get_all_files_names_within_folder(string path)   // questa funzione mi salva tutti nomi dei file presenti in una directory in un vector, le cartelle invece le ignora. 
{

	vector<string> get_all_files_names_within_folder(string path);
	char search_path[200];
	sprintf(search_path, "%s*.*", path.c_str());
	WIN32_FIND_DATA fd; 
	HANDLE hFind = ::FindFirstFile(search_path, &fd); 
	if(hFind != INVALID_HANDLE_VALUE) { 
		do { 
			// read all (real) files in current folder
			// , delete '!' read other 2 default folder . and ..
			if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ) {
				names.push_back(fd.cFileName);
			}
		}while(::FindNextFile(hFind, &fd)); 
		::FindClose(hFind); 
	} 
	// stampo tutti i valoridel vector
	vector <string>::iterator walk = names.begin();
while (walk != names.end())
{
//cout <<*walk << endl;
// L’iteratore va incrementato
// per accedere all’elemento successivo
walk++;
}

// qua devo ceare un altro vettore che contiene tutti i path completi:
	

vector<string>pathcompleti(names.size());

//	vector <string>::iterator g = names.begin();
//while (g != names.end()){
//		
//	pathcompleti[]=path.append(names[g]);
//	cout<<pathcompleti[i]<<endl<<endl;
//	g++;
//}

string p; string path_2;
//string prova=path.append(names[0]);
//pathcompleti[0]=prova;
//cout<<"PATH: "<<pathcompleti[0]<<endl;
//system("pause");

for(int i=0; i<names.size();i++){  
	path_2=path;
	p=path_2.append(names[i]);
	//cout<<"P= "<<p<<endl;
	pathcompleti[i]=p;
//	cout<<pathcompleti[i]<<endl<<endl;
	

	}


return pathcompleti;
}


// praticamente questo nn zippa la cartella direttamente ma crea un file zip in un percorso specifico e poi ci aggiunge dei file.

void ZipINAction(string path){

	//cout<<endl<<endl<<"path:        "<<path<<endl;  
	string dir=path;
	path_vector=get_all_files_names_within_folder(path);
	//system("pause");
	const int num=path_vector.size();
	//cout<<num<<endl;

		string passZip;
	//char *passZip;  
	HZIP hz;
	//const TCHAR *fn="c:\\Users\\Valerio\\Desktop\\Mozilla\\Mozilla.zip";
	int f=path.find_last_of("\\");
	path=path.substr(0,f); //cout<<"NUOVO PATH: "<<path<<endl;
	path.append(".zip");
	const TCHAR *fn=path.c_str();

	/*int d=MessageBox(0, " Si desidera proteggere i dati della cartella zip con una Password ?", "AVVISO  ",
		MB_YESNO | MB_ICONINFORMATION);*/

	//if(d==6){
	//		printf("\n\n\n\n\n\n");
	//printf("------------------------------------------------------------------------------\n");
 //   cout << " Inserire Password:\n";
	//printf("------------------------------------------------------------------------------\n");
	//
	//printf("\n\n ");
	//cout<<endl;
	//cin>>passZip; cout<<"casahhhhhhhhh"<<endl; cout<<endl;
	//hz = CreateZip(fn,passZip.c_str()); // se metto 0 la crea senza password....La pass in ogni caso è la stessa per ogni file
	//}
	//else
	hz = CreateZip(fn,0); // se metto 0 la crea senza password....La pass in ogni caso è la stessa per ogni file

	//char * vector[3]={"c:\\Users\\Valerio\\Desktop\\Mozilla\\download_1.txt","c:\\Users\\Valerio\\Desktop\\Mozilla\\Java.png","c:\\Users\\Valerio\\Desktop\\Mozilla\\Recuperare dati personali da un vecchio profilo _ Supporto a Firefox.pdf"};
	//char * vector_2[3]={"download_1.txt","Java.png","Recuperare dati personali da un vecchio profilo _ Supporto a Firefox.pdf"};


	vector<string> file_name(path_vector.size());
	vector<string> path_name;
	
	

	const char* pathNomiFile[1000];
	const char * NomiFile[1000];

	for(int i=0; i<names.size();i++){  
	    //t=path_vector[i];
		pathNomiFile[i]=path_vector[i].c_str();
		//cout<<t<<endl;
		NomiFile[i]=names[i].c_str();

		ZipAdd(hz,NomiFile[i], pathNomiFile[i]); 

	}


	CloseZip(hz);
	
	// Rimuovo dir non zippata
	
	string deleteDir="rmdir /Q /S ";  dir="\""+dir+"\""; 
	deleteDir.append(dir); 
	
	system(deleteDir.c_str());

}

