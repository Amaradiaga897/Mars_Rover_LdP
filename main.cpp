#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>

using namespace std;

void lectura();

int main(){

    lectura();

    system("pause");
    return 0;
}

void lectura(){
	ofstream imp("Instrucciones aceptadas.txt");//crea un archivo de texto con las palabras reservadas
    ifstream archivo;
    archivo.open("instrucciones.txt", ios::in); //Abre el archivo de texto con las instrucciones del usuario
    if (archivo.fail()){
        cout<< "Archivo de texto no encontrado"; // Error en caso de no encontrarse el archivo de texto
        exit(1);
    }
    string texto;
    string comando;
    string parametro;
    string palabrasReservadas[6]= {"girarRuedas", "girarBrazo", "mover", "extiendeBrazo", "inclinaCamara", "tomarFoto"};
    enum TEstado{q0,q1,q2,q3,q4,q5,qe};
    TEstado Estado;
    int Simbolo;
	int i;
	int longitud;
	int linea= 0;



	// mientras no sea el final del archivo de texto
    while (!archivo.eof()){
    	//inicializa variables
    	linea +=1;
    	i= longitud=0;
	    Estado= q0;
	    comando = "";
	    parametro = "";
	    getline(archivo,texto);
	    longitud=texto.size();

	    // asigna a texto la linea actual de instrucciones.txt

		// ciclo que recorrecada caracter de  la linea seleccionada del texto
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
	            if (Simbolo>='0' && Simbolo<='9' || Simbolo=='+' || Simbolo=='-'){
	            	parametro += texto[i];
	            	//cout<< "si paso 3-----";
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
	            		//cout<<i+1<<longitud;
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
				//cout<< "si paso 5-----";
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

		if (Estado == q5 || Estado == q3 || Estado == q1 && comando=="tomarFoto"){
		    int j;
		    /* calcula el tamanio
			del arreglo en bites y lo divide entre el tamanio en bytes del elemento 0 */
		    int tamanioArreglo= sizeof palabrasReservadas/sizeof palabrasReservadas[0];

		    //cout<<comando<<Estado;
		    for (j=0;j<tamanioArreglo;j++){


		    	if(palabrasReservadas[j].compare(comando)==0){

		    		cout<<"linea:" <<linea<<" "<<  comando<<" "<< parametro<<endl;// imprime en pantalla


		            if (comando=="girarRuedas" && std::stof(parametro)>= -70 && std::stof(parametro)<=70){ //Aqui se manda a imprimir las instucciones aceptadas al archivo de texto creado
                        imp<<"El Rover girara sus ruedas delanteras "<<parametro<< " grados"<<endl;
		            }
		            else if (comando=="girarBrazo" && std::stof(parametro)>= 0 && std::stof(parametro)<=360){
                        imp<<"El Rover girara su brazo extendible "<<parametro<< " grados"<<endl;
		            }
		            else if (comando=="mover" && std::stof(parametro)!= 0){
                        imp<<"El Rover avanzara "<<parametro<< " metros"<<endl;
		            }
		            else if (comando=="extiendeBrazo"&& std::stof(parametro)>= 0 && std::stof(parametro)<=100){
                        imp<<"El Rover extendera su brazo "<<parametro<< " centimetros"<<endl;
		            }
		            else if (comando=="inclinaCamara"&& std::stof(parametro)>= -45 && std::stof(parametro)<=45){
                        imp<<"El Rover inclinara su camara "<<parametro<< " grados"<<endl;
		            }
		            else if (comando=="tomarFoto"){
                        imp<<"El Rover tomara una foto"<<endl;
		            }
		            else{
                        imp<<"El Rover no pudo completar la accion "<< "("<<comando<<")"<< " ya que el parametro ingresado "<< "("<<parametro<<")"<< " estaba fuera de limites"<<endl;
		            }
		            break;
				}else{
					if(j+1==tamanioArreglo){
					cout<<"linea:" <<linea<<" Error de sintaxis en la linea."<< endl;
					}
				}
			}
		}else{
		    cout<<"linea:" <<linea<<" Error de sintaxis en la linea "<< endl;
		}
	}
	archivo.close();
}

