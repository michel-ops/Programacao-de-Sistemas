
#include    <stdio.h>
#include    <iostream>
#include    <string.h>
#include    <fstream> 
#include    <vector>

using namespace std;

bool contem_na_tabela(vector<string> Tabsim, string palavra)
{
    for (int i = 0; i < Tabsim.size(); i++)
    {
        if(palavra == Tabsim[i]) return true;
    }
    
    return false;
}

vector<string> inseri_na_tabela(vector<string> Tabsim, string palavra)
{
    Tabsim.push_back(palavra);
    return Tabsim;
}

vector<string> separa_palavras(char *frase, char *token)
{
    vector<string> palavras;
    char *palavra;
    
    palavra = strtok(frase, token);

    while(palavra != NULL)
    {
        palavras.push_back(palavra);
        palavra = strtok(NULL, token);
    }

    return palavras;
}

vector<string> ler_linha_do_arquivo()
{
    string nome_Arq;
    char linha[50];
    vector<string> lista_palavras;

    cout << "\n" << "Digite o nome do arquivo: ";
    getline(cin, nome_Arq);

    
    ifstream arquivo;

    arquivo.open(nome_Arq);

    if(!arquivo.is_open( ))
    {
        cout <<  "\nNao foi possivel abrir arquivo! Programa sera terminado!";
        arquivo.clear( );
        arquivo.close(); 
    } 
    else
    {
        while (arquivo.getline(linha, 50))
        {
            lista_palavras.push_back(linha);
        }

        arquivo.close(); 
    }

    return lista_palavras;
}

int codifica_comando(string assembly)
{
    vector<string> comandos = {"LA", "SA", "AA", "MUL", "DIV", "SUB", "JMP", "JEQ", "JGT", "JLT", "PW", "RW", "STOP"};

    for (int i = 0; i < comandos.size(); i++)
    {
        if(comandos[i] == assembly) return i;
    }
    
    return -1;
}
