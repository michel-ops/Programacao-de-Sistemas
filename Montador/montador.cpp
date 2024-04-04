

// Funcoes padrao
#include    <stdio.h>
#include    <iostream>
#include    <string.h>
#include    <fstream> 
#include    <vector>

// Funcoes personalizadas
#include    "funcoes.h"

using namespace std;

void imprimi_vetor_string(vector<string> vec)
{
    
    cout << "\n" << "INICIO IMPRESSAO! " << endl;
    for (int i = 0; i < vec.size(); i++)
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

vector<string> separa_comandos(vector<string> linhas)
{
    vector<string> resultado, palavras_separadas;
    string token = " ";

    for (int i = 0; i < linhas.size(); i++)
    {
        palavras_separadas = separa_palavras(linhas[i].data(), token.data());

        for (int o=0; o<palavras_separadas.size(); o++)
        {
            resultado.push_back(palavras_separadas[o]);
        }
    }

    return resultado;
}

void gera_codigo_binario(vector<string>& comandos)
{
    //vector<int> lista_codigo;

    for (int i=0; i<comandos.size() ; i++)
    {
        int comando = codifica_comando(comandos[i]);

        if (comando != -1)
        {
            comandos[i] = to_string(comando);
        }
        
    }
    
    //return lista_codigo;
}

vector<string> insere_Tabsim(vector<string> comandos)
{
    vector<string> tabela;

    for (int i=0; i < comandos.size(); i++)
    {
        if ( !contem_na_tabela(tabela, comandos[i]) )
        {
            tabela = inseri_na_tabela(tabela, comandos[i]);
        }
    }

    return tabela;
}

int main()
{
    vector<string> lista_comandos, Tabsim;
    vector<int>    comandos_inteiros;
    string token = " ";

    lista_comandos = ler_linha_do_arquivo();
    lista_comandos =  separa_comandos(lista_comandos);

    //gera_codigo_binario(lista_comandos);

    imprimi_vetor_string(lista_comandos);

    cout << "\n INICIO DA TABELA TABSIM DO ARQUIVO ";
    Tabsim = insere_Tabsim(lista_comandos);
    imprimi_vetor_string(Tabsim);
    
    /*
    comandos_inteiros = gera_codigo_binario(linhas_do_arquivo);

    imprimi_vetor_inteiros(comandos_inteiros);


    cout << "\n INICIO DO CODIGO OBJETO";
    for (int i = 0; i < comandos_inteiros.size(); i++)
    {
        cout << comandos_inteiros[i] << endl;
    }
    cout << "\n" << "FIM DO CODIGO OBJETO" << endl;
    */
   
    return 0;
}