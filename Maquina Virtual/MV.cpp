#include    <stdio.h>
#include    <iostream>
#include    <string.h>
#include    <fstream> 
#include    <vector>


#define MAXMEM 128

using namespace std;

void LA(int memoria[MAXMEM], int *acumulador, int index)
{
    *acumulador = memoria[index];
}

void SA(int memoria[MAXMEM], int index, int *acumulador)
{
    memoria[index] = *acumulador;
}

void AA(int memoria[MAXMEM], int *acumulador, int index)
{
    *acumulador = *acumulador + memoria[ memoria[index] ]; 
}

void MUL(int memoria[MAXMEM], int *acumulador, int index)
{
    *acumulador = *acumulador * memoria[memoria[index]]; 
}

void DIV(int memoria[MAXMEM], int *acumulador, int index)
{
    *acumulador = *acumulador / memoria[memoria[index]]; 
}

void SUB(int memoria[MAXMEM], int *acumulador, int index)
{
    *acumulador = *acumulador - memoria[memoria[index]]; 
}

void JMP(int *pc, int index)
{
    *pc = index;
}

void JEQ(int *pc, int index, int A)
{
    if ( A == 0)
    {
        *pc = index;
    }
}

void JGT(int *pc, int index, int A)
{
    if ( A > 0)
    {
        *pc = index;
    }
}

void JLT(int *pc, int index, int A)
{
    if ( A < 0)
    {
        *pc = index;
    }
}

void PW(int memoria[MAXMEM], int index)
{
    cout << "\n" << memoria[memoria[index]];
}

void RW(int memoria[MAXMEM], int index)
{
    cin >> memoria[memoria[index]];
}

void STOP(bool *stop)
{
    *stop = true;
}

void ler_arquivo_objeto()
{
    vector<int> mem;

    FILE  *f;
    int    x, y;
    char *nomeArq;

    printf("\ndigite o nome do arquivo: ");
    scanf("%s", nomeArq);


    f = fopen (nomeArq, "r");
    while (!feof(f)) 
    {
        fscanf (f, "%d %d", &x, &y) ;
        mem.push_back(x);
        mem.push_back(y);
    }    

    for (int i=0; i < mem.size(); i++)
    {
        cout << "memori[" << i << "]: " << mem[i] << endl;
    }
}

int main(int argc, char *argv[])
{
    int Memoria[MAXMEM]; 
    int PC=0, Ac=0, Reg[2];
    bool stop = false;

    PC = 5;

    while ( !stop && PC < MAXMEM)
    {
        
        PC++;

        std::cout << "\n--------------------------------------------" << endl;
        std::cout << "PC: " << PC  <<  endl;
        std::cout << "Memoria["<< PC <<"]: " << Memoria[PC]  <<  endl;
        std::cout << "Acumulador: " << Ac  <<  endl;
        std::cout << "stop: " << stop  <<  endl;
        
        switch ( Memoria[PC] )
        {
            case 0:
                PC++;
                LA(Memoria, &Ac, Memoria[PC]);
                break;

            case 1:
                PC++;
                SA(Memoria, Memoria[PC], &Ac);
                break;

            case 2:
                PC++;
                AA(Memoria, &Ac, PC);
                break;

            case 3:
                PC++;
                MUL(Memoria, &Ac, PC);
                break; 

            case 4:
                PC++;
                DIV(Memoria, &Ac, PC);
                break; 

            case 5:
                PC++;
                SUB(Memoria, &Ac, PC);
                break; 
            
            case 6:
                PC++;
                JMP(&PC, Memoria[PC]);
                break; 

            case 7:
                PC++;
                JEQ(&PC, Memoria[PC], Ac);
                break; 

            case 8:
                PC++;
                JGT(&PC, Memoria[PC], Ac);
                break; 

            case 9:
                PC++;
                JLT(&PC, Memoria[PC], Ac);
                break; 

            case 10:
                PC++;
                PW(Memoria, PC);
                break; 

            case 11:
                PC++;
                RW(Memoria, PC);
                break; 

            case 12:
                STOP(&stop);
                break;    

            default:
                STOP(&stop);
                break;
        }
    }

    std::cout << "\n" << "Memoria salva" << "\n";
    for (int i = 0; i < 128; i++)
    {
        std::cout << Memoria[i] <<  endl;
    }
    
    
    return 0;
}


