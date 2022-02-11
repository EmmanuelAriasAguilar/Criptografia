#include <fstream>
#include <iostream>
using namespace std;

// Prototipos de funciones
string encriptar(string frase, string clave);
string desencriptar(string frase, string clave);

int main()
{

    // ofstream ArchivoNuevoo;
    string nombreArchivo, ArchivoActual, ArchivoNuevo, ArchivoAnterior, clave;
    cout << "Introduzca el nombre del archivo con su extension, ejemplo Prueba.cpp\n";
    cin >> nombreArchivo;
    string direccionArchivo = "C:\\Users\\manea\\Documents\\Prog_Log\\Clases\\Lenguajes\\Criptografia3\\" + nombreArchivo;
    ifstream archivo(direccionArchivo.c_str());
    string linea;
    // Obtener línea de archivo, y almacenar contenido en "linea"
    while (getline(archivo, linea))
    {
        // Lo vamos imprimiendo
        ArchivoActual = ArchivoActual + linea + "\n";
    }

    cout << ArchivoActual;
    cout << "\nQue clave utilizaras para encriptarlo\n";
    cin >> clave;

    ArchivoNuevo = encriptar(ArchivoActual, clave);
    cout << "\n\nArchivo encriptado:\n\n";
    cout << ArchivoNuevo;

    ArchivoAnterior = desencriptar(ArchivoNuevo, clave);
    cout << "\n\nArchivo desencriptado:\n\n";
    cout << ArchivoAnterior;

    return 0;
}

string encriptar(string frase, string clave)
{
    string res;
    int a, b, c;
    int i, j;
    res = frase;
    // Recorro la cadena para obtener la frase encriptada
    for (i = 0; i < frase.length(); i++)
    {
        a = int(frase[i]);
        // Calculo el indice de la clave
        j = i % clave.length();
        b = int(clave[j]);
        // Operación xor
        c = a ^ b;
        // Guardo el caracter encriptado
        res[i] = char(c);
    }
    return res;
}

string desencriptar(string frase, string clave)
{
    string res;
    int a, b, c;
    int i, j;
    res = frase;
    // Recorro la cadena para obtener la frase encriptada
    for (i = 0; i < frase.length(); i++)
    {
        a = int(frase[i]);
        // Calculo el indice de la clave
        j = i % clave.length();
        b = int(clave[j]);
        // Operación xor
        c = b ^ a;
        // Guardo el caracter encriptado
        res[i] = char(c);
    }
    return res;
}