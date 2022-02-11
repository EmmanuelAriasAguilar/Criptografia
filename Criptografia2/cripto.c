#include <ctype.h>
#include <stdio.h>
#include <string.h>

void encriptar(FILE *fuente, FILE *encriptado, const char *clave)
{
    size_t longitud = strlen(clave);
    size_t index = 0;
    char leido = 'a';
    char encr = 'a';

    char clav[longitud];
    strncpy(clav, clave, longitud);

    for (size_t i = 0; i < longitud; ++i)
        clav[i] = toupper(clav[i]);

    while (fread(&leido, sizeof(char), 1, fuente) == 1)
    {

        encr = leido ^ clav[index % longitud];
        fprintf(encriptado, "%c", encr);
        index++;
    }
}

int main(int argc, char const *argv[])
{
    // Compilar: gcc cripto.c -o cripto.exe
    // Ejecutar: ./cripto.exe [nombre archivo] [clave de encriptación]
    FILE *fuente = fopen(argv[1], "r");
    FILE *encriptado = fopen("encriptado.txt", "w");

    encriptar(fuente, encriptado, argv[2]);

    fclose(fuente);
    fclose(encriptado);

    return 0;
}