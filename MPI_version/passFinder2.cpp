#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>
#include<vector>
#include<fstream>
#include <direct.h>
#include <windows.h>
#include<mpi.h>


#include "Initial.h"
#include "Other.h"
#include "passFinder.h"
#include "Output.h"

#include "ZipFile.h"


using namespace std;
string file="C:\\Users\\Valerio\\Documents\\Visual Studio 2012\\Projects\\MPI\\MPI_BruteForce\\MPI_BruteForce\\Output.cpp";
string file_new="C:\\Users\\Valerio\\Documents\\Visual Studio 2012\\Projects\\MPI\\MPI_BruteForce\\MPI_BruteForce\\passFinder2.cpp";

double Time; 
extern string timeCurrentStart;
extern string pass;
extern long int attempt;

clock_t start_t, end_t;

 extern int world_size;
    
extern int world_rank;

extern int passFound;
int *ReducedArrayProc;

//MPI_Request request;  MPI_Status status;

char* stopwatch(clock_t stop_t,clock_t start_t){
	   
	//clock_t stop_t=clock();
Time=(stop_t-start_t)/double(CLOCKS_PER_SEC);

char* buff;

if(Time>60)
	sprintf(buff,"Time-elapsed minutes:     %fl", (Time/60)); 
	//cout<<"Time-elapsed minutes:     "<<Time/60<<"\n";	  fflush(stdout); }
else
	sprintf(buff,"Time-elapsed seconds:     %fl", Time); 
 //cout<<"Time-elapsed seconds:     "<<Time<<"\n";   fflush(stdout);



return buff;
   }


string currentDatetime(){

	   // current date/time based on current system
   time_t now = time(0);
   
   // convert now to string form
   char *dt = ctime(&now);

   string time=dt;
   return time;

}



	void OpenDialog(string Total){
	
	string path;
	int d=MessageBox(0, "SI DESIDERA SALVARE I RISULTATI SU FILE ?\n\n", "Comunication  ",MB_YESNO | MB_ICONINFORMATION);
	 if(d==6){
		 
		 boolean written=false;
		 while(!written){
       path=AcquirePathSavingFile();
written=WriteFile(path,Total);
		 }

		 int d=MessageBox(0, "SI DESIDERA SALVARE I RISULTATI INSIEME ALLE SPECIFICHE TECNICHE DI QUESTO PC ?\n\n", "Comunication  ",MB_YESNO | MB_ICONINFORMATION);
		 if(d==6){

			 // casa= FileNameWith extention   casa2=fileName
			 int c=path.find_last_of('\\');
			string FileNameWithExt=path.substr(c+1,path.length());
			c=FileNameWithExt.find_last_of('.');
			string fileName=FileNameWithExt.substr(0,c);
//			cout<<"casa2: "<<fileName<<endl;

			int c2=path.find(FileNameWithExt); 
			string dir=path.substr(0,c2-1);
			dir.append("\\");
			dir.append(fileName);
			mkdir(dir.c_str());
//			cout<<"dir:   "<<dir<<endl;
			
			
			
			dir.append("\\"); string dir2=dir;
			dir.append(FileNameWithExt);
//			cout<<"casa2:   "<<dir<<endl;
			MoveFile( path.c_str(),dir.c_str());
			
	// add specs--

			QuerySpecs(dir2);

		 }
		 

		 MessageBox(0, " SALVATAGGIO (Dati + Specs) AVVENUTO CON SUCCESSO", "AVVISO  ",
               MB_OK | MB_ICONINFORMATION);
			 

	 }
	 else{

		 MyQuit();}
	 
	 MyQuit();


	}



	string computeDistance(string word){
     int spaceOcc;  int spaceLeft;  string t; 

				spaceOcc=88+word.length();
		spaceLeft=111-spaceOcc;

		for(int i=0;i<spaceLeft;i++)   // creo la stringa di spazi da stampare immediatamente dopo il nominativo del file
	 t=t.append(" ");
 t=t.append("*");
 
		
		return t;

	}

	void time(){   

		   // current date/time based on current system
   time_t now = time(0);
   char timeRunStart[100];  char timeRunEnd[100];

timeCurrentStart;
string timeCurrentEnd=currentDatetime();
   

   sprintf(timeRunStart, "\n                                                Timedate Start:     %s\n",timeCurrentStart.c_str());  //fflush(stdin);
   sprintf(timeRunEnd, "                                                Timedate End:       %s\n",timeCurrentEnd.c_str());
   string time1=timeRunStart;  string time2=timeRunEnd;



	char buffer1[100];  char buffer2[100]; char buffer3[100];   string t; 
	
           
 
		string c1="\n\n\n";
		string c2="                              ################################################################################\n";
		string c3="                              --------------------------  S. E. P.  --  2014 / 2015 --------------------------\n\n\n";
		string c4="                              _________________________________________________________________________________\n";
		string c5="	                                                    RISULATI ESECUZIONE:                                \n";
		string c6="	                                      Attacco Brute Force a dizionario con paradigma MPI                 \n";
	    string c7="                              _________________________________________________________________________________\n\n";
		string c8="\n\n\n";
		          
		string c9="                              ********************************************************************************\n";
		string c10="                              *                                                                              *\n";
		string c11="                              *                                                                              *\n";
       
		                                    
string c11_2="                              *              Modalit� di esecuzione:                  MPI                    *\n";
		
 t=computeDistance(pass);
 sprintf(buffer1,"                              *              Riepilogo password identificata:         %s%s\n",pass.c_str(),t.c_str());

		string c12=buffer1;



		sprintf(buffer2,"%ld",attempt); 
		string temp=buffer2;  //cout<<"tentativi buffer2:  "<<temp<<endl; system("pause");
		t=computeDistance(temp);
 
 sprintf(buffer3,"                              *              Numero di tentativi complessivo:         %s%s\n",temp,t.c_str());
		
		

 string c13=buffer3;  

 
 sprintf(buffer1,"%lf",Time);
 temp=buffer1;

 t=computeDistance(temp);
 t=t.substr(1,t.length());


 		
 if(Time<60)                                                            
		sprintf(buffer1,"                              *              Time-elapsed comlessivo (sec. ):         %fl%s\n",Time,t.c_str());  
 else
	 sprintf(buffer1,"                              *              Time-elapsed comlessivo (min. ):         %fl%s\n",Time/60,t.c_str());  

		string c15=buffer1;
		string c16="                              *                                                                              *\n";
		string c17="                              *                                                                              *\n";
		string c18="                              *                                                                              *\n";	
		string c19="                              ********************************************************************************";
		
		
		string c20="\n\n\n";
		string c21="                              _______________________________________________________________________________\n";
		string c22="                                      V. Colamatteo  matr.: 0040204    --    V. Testa  matr.: 0040445     \n";
		string c23="                              _______________________________________________________________________________\n\n\n";
		string c24="                              --------------------------  S. E. P.  --  2014 / 2015 --------------------------\n";
		string c25="                              ################################################################################\n\n";
		string c26="\n\n\n";

		

		string Total=time1+time2+c1+c2+c3+c4+c5+c6+c7+c8+c9+c10+c11+c11_2+c12+c13+c15+c16+c17+c18+c19+c20+c21+c22+c23+c24+c25+c26;
		MPI_Finalize();
		//cout<<"\n\n";
			
		FinalResult(pass,attempt,Time);
    


	OpenDialog(Total);
	


	}


	void result(clock_t stop_t){
	//HWND hWnd = GetConsoleWindow();			 SetForegroundWindow(0);
    char* timeBuff=stopwatch(stop_t,start_t);
	char buff[200];
	
	sprintf(buff," PASSWORD SUCCESSFULLY CRACKED!\n\n      Password trovata:   %s from process: %d  %s    ", pass.c_str(),world_rank,timeBuff); 
	//cout<<"\n";
	MessageBox(0, buff, "Result    ", MB_OK | MB_SETFOREGROUND| MB_ICONINFORMATION | MB_RIGHT);
	
	time();
	

}
	
	
	void cutAlphabet(string alphabet,string& alpha,string& alpha2){
		string tutto[64]={};
					alpha=alphabet.substr(0,alphabet.length()/2);					
					alpha2=alphabet.substr(alpha.length(),alphabet.length());
					
	}



	void Divide(int numProcessor, string alphabet,string* tutto){
	
    int last=0;
	int lungh=alphabet.length()/numProcessor;
	
	if(alphabet.length()-(lungh*numProcessor)>0)
		last=lungh+alphabet.length()-(lungh*numProcessor);
	
	
	for (int i=0;i<numProcessor;i++){
		if(i==numProcessor-1 && last!=0){
		   tutto[i]=alphabet.substr(i*lungh,last);	
		   //cout<<"tutto["<<i<<"]= "<<tutto[i]<<endl;
		}


				if(i==numProcessor-1 && last==0){
		   tutto[i]=alphabet.substr(i*lungh,lungh);	
		   //cout<<"tutto["<<i<<"]= "<<tutto[i]<<endl;
		}

		if(i==0 && i!=numProcessor-1){
			tutto[i]=alphabet.substr(0,lungh);	
		//cout<<"tutto["<<i<<"]= "<<tutto[i]<<endl;
		}
		else if((i>0&&i!=numProcessor-1)){
	tutto[i]=alphabet.substr(i*lungh,lungh);	
	//cout<<"tutto["<<i<<"]= "<<tutto[i]<<endl;
		}

	}
	return;
}
	
	void CreateArrayProc(){
		int i=0; 
		ReducedArrayProc=new int [world_size];
		for (int x=0;x<world_size;x++)
			ReducedArrayProc[x]=x;

		while(ReducedArrayProc[i]!=world_rank)
			i++;
		//cout<<"index:  "<<i<<"  world_rank  "<<world_rank<<endl; system("pause");
		ReducedArrayProc[i]=-1;
		//cout<<"    "<<ReducedArrayProc[i]<<"  world_rank  "<<world_rank<<endl;
		for(int y=i;y<world_size-1;y++)
			ReducedArrayProc[y]=ReducedArrayProc[y+1];

	//	/*cout<<"ReducedArray[0]  "<<ReducedArrayProc[0]<<"pid "<<world_rank<<endl;;
	//cout<<"ReducedArray[1]  "<<ReducedArrayProc[1]<<"pid "<<world_rank<<endl;
	//

		/*for(int i=0;i<world_size-1;i++){
			cout<<"valore:  "<<ReducedArrayProc[i]<<" from rank "<<world_rank<<endl;  }*/
	}

void crackPassword(){   
	
	//CreateArrayProc();
    /*cout<<"ReducedArray[0]  "<<ReducedArrayProc[0]<<"pid "<<world_rank<<endl;;
	cout<<"ReducedArray[1]  "<<ReducedArrayProc[1]<<"pid "<<world_rank<<endl;
	system("pause");*/
	
	string *alpha1=new string[world_size],*alpha2=new string[world_size],*alpha3=new string[world_size],*alpha4=new string[world_size],*alpha5=new string[world_size],*alpha6=new string[world_size],*alpha7=new string[world_size]; 
	
	                string alphabet1 = "0123456789";             
					Divide(world_size,alphabet1,alpha1);
                    string alphabet2 = "abcdefghijklmnopqrstuvwxyz";
					Divide(world_size,alphabet2,alpha2);
                    string alphabet3 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
					Divide(world_size,alphabet3,alpha3);
                    string alphabet4 = "0123456789abcdefghijklmnopqrstuvwxyz";
					Divide(world_size,alphabet4,alpha4);
                    string alphabet5 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
					Divide(world_size,alphabet5,alpha5);
                    string alphabet6 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";             
					Divide(world_size,alphabet6,alpha6);
                    string alphabet7 = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
					Divide(world_size,alphabet7,alpha7);
					
		
                                 
					string alphabetAll[]={alphabet1,alphabet2,alphabet3,alphabet4,alphabet5,alphabet6,alphabet7};
					string *alpha_All[]={alpha1,alpha2,alpha3,alpha4,alpha5,alpha6,alpha7};
	
		boolean f=1;   int num=1;
		
int passFound=0;
		start_t=clock();

	   do{
		   //cout<<"\n\nNUM= "<<num<<endl;  // fflush(stdout); 
		   for (int i=0;i<7;i++){   
			   //*mem=*mem*2;
			  // for(int i=0;i<world_size;i++)
			  // MPI_Bcast(&passFound,1,MPI_INT, i,MPI_COMM_WORLD);  //MPI_Bcast(&passFound,1,MPI_INT, 0,MPI_COMM_WORLD);  
			  // if(passFound==1){//cout<<"AEEEEEEEEEEEEEEEEEEE"<<endl;
					//   MPI_Finalize();
					//   delete []alpha1,alpha2,alpha3,alpha4,alpha5,alpha6,alpha7;
		   //exit(0);}
			   //if(world_rank==1)
				   
				   f=passFinder(passFound,alphabetAll[i],alpha_All[i][world_rank],num);//}	//}
				   //cout<<"passFinder"<<passFound<<endl;
        

			   
				   //cout<<"mem:   "<<*mem<<endl; 
				   //MPI_Bcast(&passFound,1,MPI_INT, 0,MPI_COMM_WORLD);
			if(f){
				//cout<<"passFound  "<<passFound<<" from pid "<<world_rank<<endl;
								clock_t stop_t=clock();
//Time=(stop_t-start_t)/double(CLOCKS_PER_SEC);
//cout<<Time<<endl; system("pause");
				string Replace="int passFound=0;";
string ReplaceWith="int passFound=1;";
				ifstream in; ofstream out;
					 in.open(file_new,ios::in);
 out.open(file,ios::out);
 //out2.open(myfile_out_temp,ios::out);
 find_and_replace(in,out,Replace ,ReplaceWith );
 in.close();  out.close();
 cout<<"DONE"<<endl;
 //for(int i=0;i<world_size;i++){
	 
			MPI_Bcast(&passFound,1,MPI_INT, world_rank,MPI_COMM_WORLD);//}
			result(stop_t);
			
			MPI_Finalize();
	        delete []alpha1,alpha2,alpha3,alpha4,alpha5,alpha6,alpha7,ReducedArrayProc;
			//delete []alpha1,alpha2,alpha3,alpha4,alpha5,alpha6,alpha7;
			//
			exit(0);
			//
			
			}
			//if(world_rank==0 && *mem>world_size){
			//	//for(int i=0;i<world_size;i++)	
			//        MPI_Recv(&passFound,1,MPI_INT,1,0,MPI_COMM_WORLD,&status);
			//	        
			//for(int i=0;i<world_size-1;i++)
			//	
			//	MPI_Send(&passFound,1,MPI_INT,ReducedArrayProc[i],0,MPI_COMM_WORLD);

			//           }

			/*if(world_rank==0)
				cout<<"risultato pid 0  "<<*mem<<endl;
			if(world_rank==1)
				cout<<"risultato pid 1  "<<*mem<<endl;*/

			//cout<<"Prova["<<i<<"]= "<<ReducedArrayProc[0]<<"  pid "<<world_rank<<endl;
			//for(int i=0;i<world_size;i++){//cout<<"ReducedArray[0]  "<<ReducedArrayProc[i]<<"pid "<<world_rank<<endl;
			//i==0;
			
			//for(int i=0;i<world_size-1;i++)				
				//if(*mem<world_size){
//				cout<<"ReducedArray["<<0<<"]= "<<ReducedArrayProc[0]<<"  pid "<<world_rank<<endl;
	//system("pause");
				//if(y!=world_rank){
					
				
				//if(world_rank!=0){
				//if(world_size%(world_rank+1)!=world_rank){
	//			cout<<"wd= "<<world_size%(world_rank+1)<<"  pid=  "<<world_rank<<endl;
		//			const int casa=(const int)ReducedArrayProc[0] ;// cout<<"casa  "<<casa<<endl;
			//cout<<"mem:   "<<*mem<<"\n"; fflush(stdout);
			//MPI_Bcast(&passFound,1,MPI_INT,*mem ,MPI_COMM_WORLD);  }
					//cout<<"mem:   "<<*mem<<endl; //system("pause");
			//if(world_rank!=0){


			//for(int i=0;i<world_size;i++)	{
			////MPI_Probe(i,0,MPI_COMM_WORLD,&status);
			//	//MPI_Irecv(&passFound,1,MPI_INT,ReducedArrayProc[i],0,MPI_COMM_WORLD,&request);//}
			//MPI_Bcast(&passFound,1,MPI_INT,i,MPI_COMM_WORLD);  
			//   if(passFound==1){
			//	   	   MPI_Finalize();
			//		   //delete []alpha1,alpha2,alpha3,alpha4,alpha5,alpha6,alpha7,ReducedArrayProc;
			//		   delete []alpha1,alpha2,alpha3,alpha4,alpha5,alpha6,alpha7;
		 //  exit(0);

			//	}
			//                                  }

			//}


	//		if(world_rank!=1){
	//			//if(world_size%(world_rank+1)!=world_rank){
	////			cout<<"wd= "<<world_size%(world_rank+1)<<"  pid=  "<<world_rank<<endl;
	//	//			const int casa=(const int)ReducedArrayProc[0] ;// cout<<"casa  "<<casa<<endl;
	//				MPI_Bcast(&passFound,1,MPI_INT,ReducedArrayProc[y] ,MPI_COMM_WORLD);  }
		//}




			if(passFound==1){
				   cout<<"pid "<<world_rank<<endl;
				   for(int i=0;i<world_size;i++){//cout<<"RED  "<<ReducedArrayProc[i]<<"  from world rank "<<world_rank<<endl;
					   MPI_Bcast(&passFound,1,MPI_INT,i ,MPI_COMM_WORLD);  }
				   	   MPI_Finalize();
					   delete []alpha1,alpha2,alpha3,alpha4,alpha5,alpha6,alpha7,ReducedArrayProc;
					   //delete []alpha1,alpha2,alpha3,alpha4,alpha5,alpha6,alpha7;
		   exit(0);

			   }








			//if(*mem>=0&& *mem<world_size){
			//	
			//	MPI_Recv(&passFound,1,MPI_INT,*mem,0,MPI_COMM_WORLD,&status);//_sleep(10);
			//		   MPI_Finalize();
			//		   delete []alpha1,alpha2,alpha3,alpha4,alpha5,alpha6,alpha7;
		 //  exit(0);
		//MPI_Bcast(&passFound,1,MPI_INT,*mem ,MPI_COMM_WORLD); 
		//cout<<"ALLORA  "<<*mem<<endl;
		
	//}

			   //if(passFound==1){
				//}
			   
				//cout<<" proc:  "<<world_rank<<endl;
//			cout<<"\n\nCambio! Nuovo alphabeto: "<<i+1<<"  from pid  "<<world_rank<<"\n";
//			fflush(stdout);
		   }
			
			
			num++;
			
			
		}while(!f&&passFound==0);
	   
	   

 }
	
bool fexists(string filename)
{
  ifstream ifile(filename);
  return ifile;
} 

	boolean WriteFile(string dest,string bufferResult){
		
		boolean written=false;
		fstream outfile;
	
		
		string nomeFile=dest.substr(dest.find_last_of("\\")+1,dest.length());
char Path[100];


if(fexists(dest)){
	sprintf(Path,"     Il file %s � gi� esistente.\n     Sostituire il file? ",nomeFile.c_str());
   int d=MessageBox(0, Path, "Salva con Nome  ",
	   MB_YESNO | MB_ICONWARNING );     

if(d==6){
	outfile.open(dest, ios::out);
outfile<<bufferResult;
	MessageBox(0, " SALVATAGGIO DATI AVVENUTO CON SUCCESSO", "AVVISO  ",
               MB_OK | MB_ICONINFORMATION);
	outfile.close();

	written=true;
	return written;
}
else{
	    written=false;
		return written;
}
}
else 
{
outfile.open(dest, ios::out);
outfile<<bufferResult;
outfile.close();
	MessageBox(0, " SALVATAGGIO AVVENUTO CON SUCCESSO", "AVVISO  ",
               MB_OK | MB_ICONINFORMATION);
	written=true;
	return written;}



	}	


	string printTitle(){

	

string star1="\n\t\t\t /////////////////////////////////////////////////////////////////////////////////\n";
//string star2="\t\t\t//                                                                             //\n";
string star3="\t\t        //      ----      ----      GENERAL SPECS OF SYSTEM        ----      ----      //\n";
//string star4="\t\t      //                                                                             //\n";
string star5="\t\t       /////////////////////////////////////////////////////////////////////////////////\n\n\n\n\n\n\n";
	
	
	
	
//	string star1="\t\t\t*************************************************************************\n";
//string star2="\t\t\t*                                                                       *\n";
//string star3="\t\t\t*    ----        ----    GENERAL SPECS OF SYSTEM    ----        ----    *\n";
//string star4="\t\t\t*                                                                       *\n";
//string star5="\t\t\t*************************************************************************\n\n\n\n\n\n\n";
string Total=star1+star3+star5;

return Total;

}


	void QuerySpecs(string pathFolder){
		
		string specs="SystemInfo.txt";
		string file=pathFolder+specs;
		//string file="C:\\Users\\Valerio\\Desktop\\OneDrive\\SystemInfo.txt";

		string title=printTitle();

		 ofstream out;
 out.open(file,ios::out);
 out<<title;
 

     FILE *fp;
  char file_type[80];  string p[50];
  string query;
  string base;
  string header="***************************";
  
  string AllQuery[7]={"cpu get Name,SystemName,NumberOfCores,NumberOfLogicalProcessors","computersystem get Domain,Manufacturer,Model,Name,NumberOfLogicalProcessors,NumberOfProcessors","os get Caption,CSDVersion,OSArchitecture,Primary,RegisteredUser",
  "diskdrive get Model,Size","memorychip get BankLabel,Capacity,Caption","path Win32_VideoController get AdapterCompatibility,Caption, VideoModeDescription","desktopmonitor get MonitorType,ScreenHeight,ScreenWidth"};
  
  string CommandExplaination[8]={" CPU System "," PC  System "," OS  Specs "," Hard  Disk "," Memory RAM "," Graph Card "," PC Monitor "};
  string spaces ="\t\t\t";
  for (int u=0;u<7;u++){
	  base="wmic "; 
  
	  query=base.append(AllQuery[u]);
	  // cout<<"query1  "<<query<<endl; cout<<"base  "<<base<<endl;
  string Name=spaces+header+ CommandExplaination[u]+header;
  
	  out<<Name;
	  out<<endl<<endl;

  fp = _popen(query.c_str(), "r");
  if (fp == NULL) {
      printf("Failed to run command\n" );
      exit(-1);
  }
  int i=0;
  
  while (fgets(file_type, sizeof(file_type)-1, fp) != NULL) {
	  p[i]=file_type; //cout<<"p "<<p[i]<<endl; 
	
	  

		  //p[i].replace(p[i].find("NumberOfLogica	lProcessors"),27,"NumberOfLogicalProcessors");
	  
	  out<<'\t'<<p[i];
	  /*size_t found=p[i].find("NumberOfLogica	lProcessors");
	  if(found!=std::string::npos)*/
		  
	    i++;
       // puts (file_type);
	  //printf("%s", file_type);
	 
  }

  out<<"        -----------------------------------------------------------------------------------------"<<endl;
  
   
  //for(int x=0;x<i;x++)
	//cout<<p[x];
  //cout<<"--------------------------------------------------------------------"<<endl;
  
  //query="";  cout<<"query"<<query<<endl;
  query.clear();
  _pclose(fp);
  }

  out.close();

  AdjustFile(pathFolder);

	}






	void find_and_replace(ifstream &in,ofstream &out,string find, string replace ) { // problem2

	// problem1
	
        string line;
    size_t len = find.length();
	while (getline(in, line))
    {
		//cout<<"U=   "<<u<<endl;
        while (true)

{
            size_t pos = line.find(find);
            if (pos != string::npos){
				line.replace(pos, len, replace);
			//cout<<"LINE:    "<<line<<endl;
			                          }
            else 
                break;

			
        }
		//cout<<line<<endl;
		out<<line<<'\n';

    }
	
        }
 


void AdjustFile(string folder){

	//cout<<"folder:  "<<folder<<endl;//system("pause");
	ifstream in; ofstream out; 
	cout<<"CASA"<<endl;
string myfile_in= folder+"SystemInfo.txt";
string myfile_out= folder +"SystemInfo2.txt"; 

//string dir="C:\\Users\\Valerio\\Desktop\\OneDrive\\PROVA\\SystemInfo.txt"; 

string Replace[4]={"NumberOfLogica	lProcessors","Numb	erOfProcessors","Registe	redUser","c	olori"};
string ReplaceWith[4]={"NumberOfLogicalProcessors","NumberOfProcessors","RegisteredUser","colori"};

string line;
 



	 in.open(myfile_in,ios::in);
 out.open(myfile_out,ios::out);
 //out2.open(myfile_out_temp,ios::out);
 find_and_replace(in,out,Replace[0] ,ReplaceWith[0] );
 in.close();  out.close();
 //system("pause");

 //cout<<"CASA 2"<<endl;
 
 in.open(myfile_out,ios::in);
 out.open(myfile_in,ios::out);
 find_and_replace(in,out,Replace[1] ,ReplaceWith[1] );
 in.close();  out.close();


 in.open(myfile_in,ios::in);
 out.open(myfile_out,ios::out);
 find_and_replace( in,out,Replace[2] ,ReplaceWith[2] );
 in.close();  out.close();

 //cout<<"CASA  BOOOO"<<endl;
 in.open(myfile_out,ios::in);
 out.open(myfile_in,ios::out);
 find_and_replace( in,out,Replace[3] ,ReplaceWith[3] );
 in.close();  out.close();

 remove(myfile_out.c_str());

 ZipINAction(folder);


}
