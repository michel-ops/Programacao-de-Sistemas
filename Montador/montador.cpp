

// Funcoes padrao
#include    <stdio.h>
#include    <iostream>
#include    <sstream>
#include    <string.h>
#include    <fstream> 
#include    <vector>
#include    <map>

// Funcoes personalizadas
#include    "funcoes.h"

using namespace std;

void imprimi_vetor_string(vector<string> vec)
{
    
    cout << "\n" << "INICIO IMPRESSAO! " << endl;
    for (auto i = 0; i < vec.size(); i++)
    {
        cout << i << ": " <<"[" << vec[i] << "]" << endl;
    }
    cout << "FIM IMPRESSAO!" << endl;
}

void imprimi_vetor_inteiros(vector<int> vec)
{
    
    cout << "\n" << "INICIO IMPRESSAO! " << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << i << ": " <<"[" << vec[i] << "]" << endl;
    }
    cout << "\n" << "FIM IMPRESSAO!" << endl;
}

vector<string> split_string(string input)
{
    vector<string> tokens;
    stringstream ss(input);
    char delimite = ' ';
    string token;
    
    while (getline(ss, token, delimite))
    {
        tokens.push_back(token);
    }

    return tokens;
}

vector<string> tabela(vector<string> lista)
{
    vector<string> palavras;

    for (int i=0; i<lista.size(); i++)
    {
        vector<string> p;
        p = split_string(lista[i]);
        for (int o=0; o<p.size(); o++)
        {
             palavras.push_back(p[i]);    
        }
    }

    return palavras;
}

int main()
{
    vector<string> lista_comandos, Tabsim;
    vector<int>    comandos_inteiros;
    string token = " ";

    lista_comandos = ler_linha_do_arquivo();
    imprimi_vetor_string(lista_comandos);

    lista_comandos = tabela(lista_comandos);
    
    imprimi_vetor_string(lista_comandos);

    return 0;
}