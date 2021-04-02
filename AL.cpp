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
        cout<<texto<<endl;
    }

    archivo.close();
}
