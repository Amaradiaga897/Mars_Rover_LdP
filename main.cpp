#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>

using namespace std;

void lectura();
bool comparaCadena(string palabra1, string palabra2);

int main(){
	

    lectura();

    system("pause");
    return 0;
}
//funcion propia para comparar dos strings
bool comparaCadena(string palabra1, string palabra2){
	
	for(int i=0;i<sizeof palabra1;i++){
		if((sizeof palabra1!=sizeof palabra2) ||  palabra1[i]!=palabra2[i]){
			return false;
		}
	}	
	return true;
}
//funcion que recorre cada linea leida 
void lectura(){
	ofstream imp("Instrucciones aceptadas.txt");//crea un archivo de texto con las palabras reservadas	
    ifstream archivo;
    archivo.open("instrucciones.txt", ios::in); //Abre el archivo de texto
    if (archivo.fail()){
        cout<< "Archivo de texto no encontrado";
        exit(1);
    }
    string texto;
    string comando;
    string parametro;
    string palabrasReservadas[6]= {"girarRuedas", "girarBrazo", "mover", "extiendeBrazo", "rotaBrazo", "tomarFoto"};
    enum TEstado{q0,q1,q2,q3,q4,q5,qe};
    TEstado Estado;
    int Simbolo;
	int i;
	int longitud;
	int linea= 0;
    

    
	// ciclo que recorre cada linea
    while (!archivo.eof()){
    	//inicializa variables
    	linea +=1;
    	i= longitud=0;
	    Estado= q0;
	    comando = "";
	    parametro = "";
	    // asigna a texto la linea actual de instrucciones.txt
	    getline(archivo,texto);
	    longitud=texto.size();
		// ciclo que recorre cada caracter de  la linea seleccionada del texto
	    while (longitud>i and Estado!=qe){
	    	
	        Simbolo= texto[i];
	
	        switch(Estado){
	
	        case q0:
	            if (Simbolo>='a' && Simbolo<='z' || Simbolo>='A' && Simbolo<='Z'){
	            	comando += texto[i];
	                Estado = q1;
	            }else{
	                Estado = qe;
	            }
	            break;
	        case q1:
	            if (Simbolo>='a' && Simbolo<='z' || Simbolo>='A' && Simbolo<='Z'){
	                comando += texto[i];
	            
	            }else{
	            	
	            	if(Simbolo == ' '){
	            		//cout<< "si paso 2----";
	                Estado = q2;
					}
					else{
						Estado = qe;
					}
	            }
	            break;
	
	        case q2:
	            if (Simbolo>='0' && Simbolo<='9' || Simbolo=='+' && Simbolo=='-'){
	            	parametro += texto[i];
	                Estado=q3;
	            }else{
	                Estado = qe;
	            }
	            break;
	        case q3:
	        	if(longitud==i+1){
	        		Estado = q5;
				}
	            if (Simbolo>='0' && Simbolo<='9'){
	            	parametro += texto[i];
	            }else{
	            	if(Simbolo == '.' ){
	                Estado = q4;
	                parametro += texto[i];
					}
					else{
						Estado = qe;
					}
	            }
	            break;
	        case q4:
	        	Estado = q5;
	            if (Simbolo>='0' && Simbolo<='9'){
	            	parametro += texto[i];
	            	
	            }else{
	            
						Estado = qe;
					}
	            break;
	        case q5:
	            if (Simbolo>='0' && Simbolo<='9'){
	            	parametro += texto[i];
	            	Estado = q5;
	            }else{
	            	if(longitud<=i+1){
	                Estado = q5;
					}
					else{
						Estado = qe;
					}
	            }
	            break;    
	        }
	        i++;
	    }	
		if (Estado == q5){
		    int j;
		    /* calcula el tamanio 
			del arreglo en bites y lo divide entre el tamanio en bytes del elemento 0 */
		    int tamanioArreglo= sizeof palabrasReservadas/sizeof palabrasReservadas[0];
		    for (j=0;j<tamanioArreglo;j++){
		    	
		    	if(comparaCadena(comando,palabrasReservadas[j])==1){
		    		cout<<"linea:" <<linea<<" "<<  comando<<" "<< parametro<<endl;// imprime en pantalla
		            imp<<"Robert " <<comando<<" "<<parametro<<endl;// imprime en el texto
		            break;
				}else{
					if(j+1==tamanioArreglo){
					cout<<"linea:" <<linea<<" "<<" Error de sintaxis  en la linea "<< endl;
					}
				}		
		         
			}
		}else{
		    cout<<"linea:" <<linea<<" "<<" Error de sintaxis  en la linea "<< endl;
		    
		}
	}
	archivo.close();
}

