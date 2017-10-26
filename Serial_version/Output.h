#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>
#include<vector>
#include<fstream>
#include <windows.h>


using namespace std;

void CreateArrayProc();
char* stopwatch(clock_t stop_t,clock_t start_t);
string currentDatetime();
string computeDistance(string word);
void time();
void OpenDialog(string Total);
void result(clock_t stop_t);
void cutAlphabet(string alphabet,string& alpha,string& alpha2);
void hackPassword();
bool fexists(string filename);
boolean WriteFile(string dest,string bufferResult);

string printTitle();
void QuerySpecs(string pathFolder);
void find_and_replace(ifstream &in,ofstream &out,string find, string replace );
void AdjustFile(string pathFolder);
