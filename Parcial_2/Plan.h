#include<string>
#include<time.h>
#include<iostream>
#include<iomanip>

using namespace std;

class Plan{
	
	public:
		string id;
		string nombre;
		string precio;
		string duracion;
		int dias;
		string fechaInit;
		string fechaF;
		
   	public:
	    string fechaInicio();
		string fechaFin();
		diasRestantes();
		string toString();
		Plan();
		~Plan();
		Plan(string idp,string nombrep,string duracionp,string preciop){
			id = idp;
			nombre = nombrep;
			precio = preciop;
			duracion = duracionp;
		}
};

Plan::Plan(){
	fechaInicio();
	fechaFin();
	int len = fechaInit.size();
	fechaInit[len-1]='\0';
	int len2 = fechaF.size();
	fechaF[len2-1]='\0';
}
Plan::~Plan(){
		
}
string Plan::fechaInicio(){
	time_t tSac = time(NULL);
	struct tm* tmP = localtime(&tSac);
	fechaInit = asctime(tmP);
	return asctime(tmP);
}
string Plan::fechaFin(){
	time_t tSac = time(NULL);
	struct tm* tmP = localtime(&tSac);
	struct tm* newyear;
	double seconds;

	newyear = localtime(&tSac);
  	newyear->tm_mon = newyear->tm_mon+1;  

  	seconds = difftime(mktime(newyear),tSac);

	dias = seconds/86400;
	fechaF = asctime(newyear);
	
  	return asctime(newyear);
  	
}
int Plan::diasRestantes(){
	return dias;
}

string Plan::toString(){
	
	cout<<setw(15)<<"\nPlan No. "<<id<<"\n"
		<<setw(15)<<"Nombre: "<<nombre<<"\n"
		<<setw(15)<<"Duracion en Meses: "<<duracion<<"\n"
		<<setw(15)<<"Precio: $"<<precio<<"\n\n";

}

