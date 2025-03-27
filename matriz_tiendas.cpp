#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

constexpr int t=10;

//Prototipo de las funciones
void escribir_A(int A[t][t], int, int);
void generar_A(int A[t][t], int, int);

void total(int A[t][t], int v[t], int, int);

void mayor(int v[t], int);

int main(){
    int tiendas=0, dep=0;
    int A[t][t]; //Matriz donde se almacenará todos los datos
    int v[t]={0}; //Vector donde se almacenará el total de ventas por cada tienda.

    cout<<"Escriba el numero de departamentos: ";
    cin>>dep;
    cout<<"Escriba el numero de tiendas: ";
    cin>>tiendas;

    generar_A(A, dep, tiendas);
    escribir_A(A, dep, tiendas);
    total(A, v, dep, tiendas);
    mayor(v, tiendas);

    return 0;
}

void generar_A(int A[t][t], int dep, int tiendas){
    srand(time(NULL));
    int c=A[0][0];
    for (int i = 0; i < dep; i++)
    {
        for (int j = 0; j < tiendas; j++)
        {
            c=10+rand()%91;
            A[i][j]=c;
        }
    }
}

void escribir_A(int A[t][t], int dep, int tiendas){
    cout<<"\n";
    for (int i = 0; i < dep; i++)
    {
        for (int j = 0; j < tiendas; j++)
        {
            cout<<" "<<A[i][j];
        }
        cout<<"\n";
    }
}

void total(int A[t][t], int v[t], int dep, int tiendas){
    for (int i = 0; i < dep; i++)
    {
        for (int j = 0; j < tiendas; j++)
        {
            v[j]+=A[i][j];
        }
    }
    cout<<"\nTotal de ventas\n";
    for (int j = 0; j < tiendas; j++)
    {
        cout<<" "<<v[j];
    }
    
}

void mayor(int v[t], int tiendas){
    cout<<"\n";
    int num_mayor=v[0];
    for (int j = 0; j < tiendas; j++)
    {
        if (v[j]>num_mayor)
        {
            num_mayor=v[j];
            cout<<"\nLa tienda que mas ha vendido es t_"<<j+1<<" con un total de: L. "<<num_mayor;
        }
    }
}