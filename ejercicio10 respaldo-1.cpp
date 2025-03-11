#include <iostream>
#include <cmath>

using namespace std;

//Prototipo de las funciones
//Función j.1)
double taylor_exp(double, int);
double rpotencia(double, int);
int rfactorial(int);

//Función principal
int main(){
    double x;
    int n;

    //Lectura y validación de los numeros ingresados por el usuarios
    do
    {
        cout<<"Escriba un valor para x y un valor para n\n";
        cout<<"x= ";
        cin>>x;
        cout<<"n= ";
        cin>>n;
        if (x<=0 || n<0)
        {
            cout<<"Numeros no validos, intentelo de nuevo\n";
            cout<<"\n";
        }
    } while (x<=0 || n<0);
    
    //Llamado a la función taylor_exp()
    double resultado=taylor_exp(x, n);
    cout<<"Serie de taylor para e^x\n";
    cout<<resultado;
    cout<<"\n";
    

    return 0;
}

//Definición de las funciones
double taylor_exp(double x, int n){
    double resultado=1;

    for (int i = 1; i <= n; i++)
    {
        resultado+=(rpotencia(x, i)/rfactorial(i));
    }
    return resultado;
}

//Si x=2, n=5
//Retorna 32
double rpotencia(double x, int n){
    //Casos base
    if (n==0){
        return 1;
    }
    else if (n==1){
        return x;
    } 

    //Caso general
    else {
        return x*rpotencia(x, n-1);
    }
}

//Si n=5
//Retorna 120
int rfactorial (int n){
    int producto;
    if (n==0){
        return 1;
    } else {
        return producto=n*rfactorial(n-1);
    }
}