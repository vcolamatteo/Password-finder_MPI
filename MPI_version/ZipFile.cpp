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


string p; string path_2;


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

//	cout<<endl<<endl<<"path:        "<<path<<endl; 
	string dir=path;
	path_vector=get_all_files_names_within_folder(path);
	//system("pause");
	const int num=path_vector.size();
//	cout<<num<<endl;

		string passZip;
	//char *passZip;  
	HZIP hz;
	//const TCHAR *fn="c:\\Users\\Valerio\\Desktop\\Mozilla\\Mozilla.zip";
	int f=path.find_last_of("\\");
	path=path.substr(0,f); //cout<<"NUOVO PATH: "<<path<<endl;
	path.append(".zip");
	const TCHAR *fn=path.c_str();


	hz = CreateZip(fn,0); // se metto 0 la crea senza password....La pass in ogni caso è la stessa per ogni file

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
	string deleteDir="rmdir /Q /S "; dir="\""+dir+"\"";  deleteDir.append(dir); //cout<<deleteDir<<endl;
	system(deleteDir.c_str());

}

