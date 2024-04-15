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
    cout << "\nInterio: " << memoria[memoria[index]];
}

void RW(int memoria[MAXMEM], int index)
{
    cout << "\nDigite um inteiro: ";
    cin >> memoria[memoria[index]];
}

void STOP(bool *stop)
{
    *stop = true;
}

void ler_arquivo_objeto(int memoria[], int *inicio)
{
    FILE *f;
    int x, y, i;
    bool erro=true;
    char nomeArq[30];
    
    printf("digite o nome do arquivo\n") ;
    scanf("%s", nomeArq) ;
    f = fopen (nomeArq, "r");

    fscanf (f, "%d", &x);
    *inicio = x;
    i = x;

    while (!feof(f) && erro) 
    {
        fscanf (f, "%d%d", &x, &y) ;
        if(i > MAXMEM)
        { 
            erro = false;
        }
        else
        {
            memoria[i] = x;
            i++;  
            memoria[i] = y;
            i++; 
        }
    }

}

int main()
{
    int Memoria[MAXMEM];

    int PC=0, Ac=0;
    bool stop = false;

    ler_arquivo_objeto(Memoria, &PC);
    
    
    while ( !stop && PC<MAXMEM)
    {
        //printf("\nPc: %d, Memoria: %d", PC, Memoria[PC]);
    
        switch ( Memoria[PC] )
        {
            case 0:
                PC++;
                LA(Memoria, &Ac, Memoria[PC]);
                PC++;
                break;

            case 1:
                PC++;
                SA(Memoria, Memoria[PC], &Ac);
                PC++;
                break;

            case 2:
                PC++;
                AA(Memoria, &Ac, PC);
                PC++;
                break;

            case 3:
                PC++;
                MUL(Memoria, &Ac, PC);
                PC++;
                break; 

            case 4:
                PC++;
                DIV(Memoria, &Ac, PC);
                PC++;
                break; 

            case 5:
                PC++;
                SUB(Memoria, &Ac, PC);
                PC++;
                break; 
            
            case 6:
                PC++;
                JMP(&PC, Memoria[PC]);
                PC++;
                break; 

            case 7:
                PC++;
                JEQ(&PC, Memoria[PC], Ac);
                PC++;
                break; 

            case 8:
                PC++;
                JGT(&PC, Memoria[PC], Ac);
                PC++;
                break; 

            case 9:
                PC++;
                JLT(&PC, Memoria[PC], Ac);
                PC++;
                break; 

            case 10:
                PC++;
                PW(Memoria, PC);
                PC++;
                break; 

            case 11:
                PC++;
                RW(Memoria, PC);
                PC++;
                break; 

            case 12:
                PC++;
                STOP(&stop);
                PC++;
                break;    

            default:
                PC++;
                STOP(&stop);
                PC++;
                break;
        }
    }
    

    
    std::cout << "\n\n\n" << "      MEMORIA SALVA       " << "\n";
    //std::cout << "Inicio: " << inicio << endl;
    for(int i=0; i<128; i++)
    {
        if( (i+1)%10 == 0) printf("\n");  
        std::cout << Memoria[i] << ", ";
    }
    

    return 0;
}


