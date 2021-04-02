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
    ifstream archivo;
    string texto;

    archivo.open("instrucciones.txt", ios::in); //Abre el archivo de texto

    if (archivo.fail()){
        cout<< "Archivo de texto no encontrado";
        exit(1);
    }

    while (!archivo.eof()){

    getline(archivo,texto);

    string palabrasReservadas[6]= {"girarRuedas", "girarBrazo", "mover", "extiendeBrazo", "rotaBrazo", "tomarFoto"};

    enum TEstado{q0,q1,qe};

    TEstado Estado;
    int Simbolo;

    int i;
    int longitud;

    i= longitud=0;
    Estado= q0;

    longitud=texto.size();

    while (longitud>i and Estado!=qe){
        Simbolo= texto[i];

        switch(Estado){

        case q0:
            if (Simbolo>='a' && Simbolo<='z' || Simbolo>='A' && Simbolo<='Z'){
                Estado = q1;
            }
            break;

        case q1:
            if (Simbolo>='a' && Simbolo<='z' || Simbolo>='A' && Simbolo<='Z'){
                Estado = q1;
            //}else if (Simbolo == '='){
                //Estado q2;
            }else{
                Estado = q0;
            }
            break;

        /*case q2:
            if (Simbolo>='0' && Simbolo<='9'){
                Estado=q3;
            }else{
                Estado qe;
            }
            break;

        case q3:
            if (Simbolo>='0' && Simbolo<='9'){
                Estado=q3;
            }else{
                Estado qe;
            }
            break;*/
        }
        i++;
}

if (Estado== q1){
    int j;
    int TamanioArreglo= sizeof palabrasReservadas / sizeof palabrasReservadas[0];
    for (j=0;j<TamanioArreglo;j++){
        if (texto.compare(palabrasReservadas[j])==0){
            cout<< texto << " es un comando valido"<< endl;
            break;
        }else{
        cout<<texto<< " No es un comando valido"<< endl;
        break;
    }
    }
}
    }

    archivo.close();
}

