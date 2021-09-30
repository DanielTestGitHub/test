#include<iomanip>
#include<vector>
#include<fstream>

#include"Usuario.h"

using namespace std;

void modoUsuario();
void modoSupervisor();
vector<string> readVentas();
vector<string> readPlanes();
vector<string> readUsuarios();
vector<string> readSes();
void registerSesion(string user);
void registerVenta(string venta);

void registerUser(Usuario usuario){
	
	ofstream archivo;
	archivo.open("usuarios.txt",ios::out|ios::app);
	
	archivo<<usuario.id<<","<<usuario.nombre<<","<<usuario.contrasenia<<","<<usuario.plan.fechaInit<<","<<usuario.plan.fechaF<<",\n";
	registerVenta(usuario.plan.precio);		
	archivo.close();
	
}

void registerVenta(string venta){
	
	ofstream archivo;
	archivo.open("ventas.txt",ios::out|ios::app);
	
	archivo<<venta<<",\n";
			
	archivo.close();
	
}

void registerSesion(string user){
	
	ofstream archivo;
	archivo.open("sesiones.txt",ios::out|ios::app);
	
	archivo<<user<<",\n";
			
	archivo.close();
	
}



bool setPassword(string password){
	if(password == "admin"){
		return true;
	}else{
		return false;
	}
}


void selectModo(){
	
	int modo;
	
	cout<<setw(30)<< "\n\n\t( L ) ( O ) ( G ) ( I ) ( N )"<<"\n";
	
	cout<<"\n\t1) Supervisor \n"<<
	  "\t2) Usuario\n\n"<<
	  "\t>>--> ";
	  cin>>modo;
	
	if(modo == 1){
		
		string pass = "";
		
		do{
			system("cls");
			cout<<"Password: ";
			cin>>pass;
			
		}while(setPassword(pass)==false);
		
		system("cls");
		modoSupervisor();
		
	
	}else if (modo == 2){
		
		system("cls");
		modoUsuario();

	}else{
		
		system("cls");
		selectModo();

	}	
	
}

vector<string> readPlanes(){
	string cadena="";
	vector<Plan> planes;

	ifstream datos("planes.txt",ios::out|ios::app);

		vector<string> plan;
	
	while (!datos.eof()) {

//		cout<<"-------------------"<<endl;
		getline(datos,cadena); 
		
		string aux = "";
		
		for(int i = 0; i<cadena.size();i++){
			if(cadena[i]!=','){
				aux+=cadena[i];
			}else{
				plan.push_back(aux);	
				aux = "";
			}
		}
			
	}
	return plan;
	datos.close();

}

vector<string> readVentas(){
	string cadena="";

	ifstream datos("ventas.txt",ios::out|ios::app);

		vector<string> ventas;
	
	while (!datos.eof()) {


		getline(datos,cadena); 
		
		string aux = "";
		
		for(int i = 0; i<cadena.size();i++){
			if(cadena[i]!=','){
				aux+=cadena[i];
			}else{
				cout<<"\t$ "<<aux<<endl;
				ventas.push_back(aux);	
				aux = "";
			}
		}
			
	}
	return ventas;
	datos.close();

}

vector<string> readUsuarios(){
	
	string cadena="";

	ifstream datos("usuarios.txt",ios::out|ios::app);

		vector<string> usuarios;
	
		while (!datos.eof()) {
			
			getline(datos,cadena); 
			usuarios.push_back(cadena);
				
		}
	
	return usuarios;
	datos.close();

}

vector<string> readSes(){
	
	string cadena="";

	ifstream datos("sesiones.txt",ios::out|ios::app);

		vector<string> sesiones;
	
		while (!datos.eof()) {
			
			getline(datos,cadena); 
			sesiones.push_back(cadena);
				
		}
	
	return sesiones;
	datos.close();

}

void modoUsuario(){
	int opc;
	
	cout<<setw(30)<< "\n\n\t( M ) ( O ) ( D ) ( O )"<<"\n";
	cout<<setw(30)<< "\t( U ) ( S ) ( U ) ( A ) ( R ) ( I ) ( O )"<<"\n";
	
	cout<<"\n\t1) Consulta de planes de afiliacion \n"<<
	  "\t2) Apartar sesion de entrenamiento \n"<<
	  "\t3) Cancelar sesion de entrenamiento\n"<<
	  "\t4) Consulta de perfil de afiliacion\n\n"<<
	  "\t>>--> ";
	  cin>>opc;
	  
	  if(opc == 1){
	  	
	  	vector<string> planes;
	  	
	  	planes = readPlanes();
	  	
	  	cout<<"\t-------------------"<<endl;
		cout<<"\t----- PLANES ------"<<endl;
		
		for(int i = 0;i<planes.size();i+=4){
			cout<<"\t-------------------"<<endl;
			cout<<setw(15)<<"\n\tPlan No. "<<planes.at(i)<<"\n"
				<<setw(15)<<"\tNombre: "<<planes.at(i+1)<<"\n"
				<<setw(15)<<"\tDuracion en Meses: "<<planes.at(i+2)<<"\n"
				<<setw(15)<<"\tPrecio: $"<<planes.at(i+3)<<"\n\n";			
		}
		
		modoUsuario();
	  	
	  }else if(opc == 2){
	  	
	  	int user;
		vector<string> usuarios;
		usuarios = readSes();
		
		string cod = "";
		cout<<"\n\tDigite su codigo: ";cin>>cod;
		cout<<endl;
		int cont = 0;
		
		for (int i = 0;i < usuarios.size();i++){
			
			if((cod+",")== usuarios.at(i)){
				cont++;
			}
		}
		
		if(cont==0){
			registerSesion(cod);
			cout<<"\n\t----------------------"<<endl;
			cout<<"\t-- SESION REGISTRADA--"<<endl;
			cout<<"\t----------------------"<<endl;
		}else{
			cout<<"\n\t----------------------------------------"<<endl;
			cout<<"\t--USTED YA TIENE UNA SESION REGISTRADA--"<<endl;
			cout<<"\t----------------------------------------"<<endl;
		}
		
		modoUsuario();
	  
	  }else if(opc == 3){
	  	
	  	int user;
		vector<string> usuarios;
		usuarios = readSes();
		
		string cod = "";
		cout<<"\n\tDigite su codigo: ";cin>>cod;
		cout<<endl;
		int cont = 0;
		
		for (int i = 0;i < usuarios.size();i++){
			
			if((cod+",") == usuarios.at(i)){
				cont = i;
			}
		}
		
		if(cont!=0){
			
			ofstream archivo;
			archivo.open("sesiones.txt",ios::out|ios::trunc);

			for (int i = 0;i < usuarios.size();i++){
				if(i != cont){
					archivo<<usuarios.at(i)<<"\n";
				}
			}
			
			
			cout<<"\n\t----------------------"<<endl;
			cout<<"\t-- SESION CANCELADA --"<<endl;
			cout<<"\t----------------------"<<endl;
				
			archivo.close();
			
			
		}else{
			cout<<"\n\t----------------------------------------"<<endl;
			cout<<"\t--USTED NO TIENE UNA SESION REGISTRADA--"<<endl;
			cout<<"\t----------------------------------------"<<endl;
		}
		
		modoUsuario();
	  
	  }else if(opc == 4){
	  
	  
	  }else if(opc == 0){
	  	system("cls");
	  	selectModo();
	  }
	  	
	
}

void modoSupervisor(){
	
	int opc;
	
	cout<<setw(30)<< "\n\n\t( M ) ( O ) ( D ) ( O )"<<"\n";
	cout<<setw(30)<< "\t( S ) ( U ) ( P ) ( E ) ( R ) ( V ) ( I ) ( S ) ( O ) ( R )"<<"\n";
	
	cout<<"\n\t1) Registrar usuario \n"<<
	  "\t2) Actualizar usuario\n"<<
	  "\t3) Registro de ventas\n\n"<<
	  "\t>>--> ";
	  cin>>opc;
	
	if(opc == 1){
		
		Usuario user;
		vector<string> planes;
		int planE;
		
		cout<<left<<setw(30)<<"\n*********REGITRO DE USUARIO*********\n\n";
		cout<<setw(40)<<"Digite numero de cedula: ";cin>>user.id;
		cout<<setw(40)<<"Digite nombre: ";getline(cin>>ws,user.nombre);
		cout<<setw(40)<<"Digite constrasenia: ";cin>>user.contrasenia;
		planes = readPlanes();
		
		cout<<"-------------------"<<endl;
		cout<<"----- PLANES ------"<<endl;
		
		for(int i = 0;i<planes.size();i+=4){
			cout<<"-------------------"<<endl;
			cout<<setw(15)<<"\nPlan No. "<<planes.at(i)<<"\n"
				<<setw(15)<<"Nombre: "<<planes.at(i+1)<<"\n"
				<<setw(15)<<"Duracion en Meses: "<<planes.at(i+2)<<"\n"
				<<setw(15)<<"Precio: $"<<planes.at(i+3)<<"\n\n";			
		}
		
		cout<<setw(30)<<"Digite numero de plan: ";cin>>planE;
		
		int i = 4*(planE-1);
		
		
		cout<<setw(15)<<"\nPlan No. "<<planes.at(i)<<"\n"
			<<setw(15)<<"Nombre: "<<planes.at(i+1)<<"\n"
			<<setw(15)<<"Duracion en Meses: "<<planes.at(i+2)<<"\n"
			<<setw(15)<<"Precio: $"<<planes.at(i+3)<<"\n\n";
			
		Plan p;
		
		p.id = planes.at(i);
		p.nombre = planes.at(i+1);
		p.duracion = planes.at(i+2);
		p.precio = planes.at(i+3);
		
		user.plan = p;

		cout<<"Plan seleccionado: "<<user.plan.nombre<<endl;
		
		registerUser(user);
		
		cout<<"----------------------"<<endl;
		cout<<"--USUARIO REGISTRADO--"<<endl;
		cout<<"----------------------"<<endl;
		
		modoSupervisor();
		
	}else if (opc == 2){
		
		int user;
		vector<string> usuarios;
		usuarios = readUsuarios();
		cout<<endl;
		
		for (int i = 0;i < usuarios.size()-1;i++){
			cout<<"\t"<<i<<"). "<<usuarios.at(i)<<endl;
		}
		
		cout<<"\n\n\tCual usuario desea actualizar?: ";cin>>user;
		cout<<endl;
		
		if(user < 0 || user >= usuarios.size()-1){
			system("cls");
			modoSupervisor();
		}
		
		string aux = "";
		vector<string> usu;
		
		for(int i = 0; i<usuarios.at(user).size();i++){
			if(usuarios.at(user)[i]!=','){
				aux+=usuarios.at(user)[i];
			}else{
				cout<<"\t"<<aux;
				usu.push_back(aux);	
				aux = "";
			}
		}
		
		cout<<endl;
		
		for(int i = 0;i<usu.size()-2;i++){
			
			char val;
			cout<<"\n\tDesea modificar: "<<usu.at(i)<<" ? (s/n)";cin>>val;
			if(val == 's'){
				cout<<"\n\tNuevo valor para: "<<usu.at(i)<<" -> "; cin>>usu.at(i);
			}else if(val == 'n'){
				cout<<"\n\tSe dejo igual"<<endl;				
			}else{
				system("cls");
				modoSupervisor();
			}
			
		}
		
		cout<<"\n\tUsuario actualizado"<<endl;
		string usr = "";
		for(int i = 0; i<usu.size();i++){
			cout<<"\t"<<usu.at(i);
			usr+=usu.at(i)+",";	
		}
		
		usuarios.at(user) = usr;
		cout<<endl;
		
		ofstream archivo;
		archivo.open("usuarios.txt",ios::out|ios::trunc);
	
		for(int i = 0; i< usuarios.size();i++){
			if(usuarios.at(i).size()>1){
				archivo<<usuarios.at(i)+"\n";
			}
		}
		
		archivo.close();
		
		cout<<"\n\n\t-----------------------"<<endl;
		cout<<"\t--USUARIO ACTUALIZADO--"<<endl;
		cout<<"\t-----------------------"<<endl;
		
		modoSupervisor();
			
	}else if (opc == 3){
		
		vector<string> ventas;
		
		cout<<"----------------------"<<endl;
		cout<<"- REGISTRO DE VENTAS -"<<endl;
		cout<<"----------------------"<<endl;
		
		ventas =  readVentas();
		
		cout<<"----------------------"<<endl;
		cout<<"--  VENTAS TOTALES  --"<<endl;
		cout<<"----------------------"<<endl;
		cout<<"\t"<<ventas.size()<<endl;
		cout<<"----------------------"<<endl;
		
		cout<<"----------------------"<<endl;
		cout<<"- TOTALES DE VENTAS  -"<<endl;
		cout<<"----------------------"<<endl;
		double suma = 0;
		
		for(int i = 0;i<ventas.size();i++){
			suma += stod(ventas.at(i)); 
		}
		
		cout<<"\t$ "<<suma<<endl;
		cout<<"----------------------"<<endl;
		
		
	}else if(opc == 0){
		system("cls");
		selectModo();
	}else {
		system("cls");
		modoSupervisor();
	}

	
	
}
