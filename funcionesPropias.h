
#include <cstdlib>
#include <iostream>


using namespace std;

int cadenaEntero(string cadena);
int largoCadena(string cadena);
int caracterEntero(char caracter);
bool validaCadena(string cadena);

int cadenaEntero(string cadena){
	int multiplo = 1;
	int i = largoCadena(cadena)-1;
	int resultado;
	if(validaCadena(cadena)){
		do{
		cout<<resultado;
		if(cadena[i]=='.'){
		
			/*if(largoCadena(cadena)==1){
				resultado = 0;
			return resultado;
				
			}*/
			break;	
		}
		resultado += caracterEntero(cadena[i])*multiplo;
		multiplo *=10;
				
		i -= 1;
		}while(i>=0);
		
	}else{
		
		resultado =  -999999999;	
	}
	
	return resultado;
}

int largoCadena(string cadena){
	int largo = 0;
	
	while(cadena[largo]!= '\0'){
			largo += 1;
	}
	return largo;
}
int caracterEntero(char caracter){
	int numero;
	switch(caracter){
    	case '0' :numero =0;break;case '1' :numero =1;break;
		case '2' :numero =2;break;case '3' :numero =3;break;
		case '4' :numero =4;break;case '5' :numero =5;break;
		case '6' :numero =6;break;case '7' :numero =7;break;
        case '8' :numero =8;break;case '9' :numero =9;break;
	}
	return numero;
}
bool validaCadena(string cadena){
	int j = 0;
	enum estados{q0,q1,q2,qe};
	estados estado;
	estado = q0;
	char caracter = cadena[j];
	
	while(cadena[j]!='\0'){
		switch(estado){
			case q0:
				if(caracter > '0' && caracter<'9' || caracter== '+' || caracter =='-'){
				estado = q1;	
				}else if(caracter == '.'){
					estado = q2;
				}else{ 
					estado = qe;
				}
				break;
			case q1:
				if(caracter > '0' && caracter<'9'){
					break;	
				}else if(caracter == '.'){
					estado = q2;
				}else{
					estado = qe;
				}
				
				break;
			case q2:
				if(caracter > '0' && caracter<'9'){
					break;	
				}else{
					estado = qe;
				}
		}
		j +=1;
	}
	if(estado==q1 || estado == q2){
		return true;
	}
	return false;
}
