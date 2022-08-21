#include "pch.h"
#include <iostream>
#include <conio.h>
#include <locale.h>

using namespace System;
using namespace std;

//FUNCIONES DE LA HOJA 2 
//NO  ENTENDI BIEN PERO LO INTENTE

template <class tipo>
void generar_Arreglo(int * arr, tipo n) {
    Random r;
    for (int i = 0; i < n; i++)
    {
        arr[i] = r.Next(0, 10);
    }
}

template <class tipo2>
void mostrar_Arreglo(int * arr, tipo2 n) {

    for (int i = 0; i < n; i++)
    {
        cout << arr[i]; cout << endl;
    }
}

template <class tipo3>
void numero_Mayor(int* arr, tipo3 n) {
    int mayor = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mayor) {
            mayor = arr[i];
        }
    }
    cout << "El numero mayor es: " << mayor << endl;
}

template <class tipo4>
void menor_Mayor(int* arr, tipo4 n) {
    int menor = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < menor) {
            menor = arr[i];
        }
    }
    cout << "El numero mayor es: " << menor << endl;
}

template <class tipo5>
void suma_numeros(int* arr, tipo5 n) {
    int suma = 0; 
    for (int i = 0; i < n; i++)
    {
        suma = +arr[i]; 
    }
    cout << "La suma de los arreglos es: " << suma << endl; 
}

template <class tipo6>
void moda_num(int* arr, tipo6 n) {
    int moda;
    int cont1 = 0, cont2 = 0; 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j] && i != j)cont1++; 
        }
        if (cont1 > cont2) {
            cont2 = cont1; 
            moda = arr[i]; 
        }
        cont1 = 0; 
    }
    cout << "El valor de la moda es: " << moda << endl; 
}

template <class tipo7>
void ordenamiento(int* arr, tipo7 n) {

    int aux = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1]) {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }

}

template <class tipo8>
void eliminar_posicion(int*& arr, tipo8& n, tipo8& pos) {

    if (pos >= n)return;
    int* aux = new int[n - 1];
    int i = 0;
    for (; i < pos; i++)
    {
        aux[i] = arr[i];
    }
    for (; i < n - 1; i++)
    {
        aux[i] = arr[i + 1];
    }
    delete[]arr;
    arr = aux;
    aux = nullptr;
    delete[]aux;
    n--;
}

template <class tipo9>
void buscar_posicion(int* arr, tipo9 n) {
    int num;
    bool ban;
    cout << "Numero a buscar: "; cin >> num; cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (num == arr[i]) {
            ban = true;
        }
        else ban = false;
    }
    if (ban == true) {
        cout << "Si se encuentra el numero" << endl;
    }
    else if (ban == false) {
        cout << "No se encuentra el numero" << endl;
    }
}

template <class tipo10>
void existe_numero(int* arr, tipo10 n) {
    int num;
    bool ban;
    cout << "Numero a buscar: "; cin >> num; cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (num == arr[i]) {
            ban = true;
        }
        else ban = false;
    }
    if (ban == true) {
        cout << "El numero si existe" << endl;
    }
    else if (ban == false) {
        cout << "El numero No existe" << endl;
    }
}

template <class tipo11>
void RepiteNumero(int* arr, tipo11 numeroRepetido, tipo11 n) {
    int contRepe = 0;
    for (int i = 0; i < n; i++)
    {
        if (numeroRepetido == arr[i]) {
            contRepe++;
        }
    }
    cout << "El elemento " << numeroRepetido << " se repite " << contRepe << " veces.";
}

int main()
{
    setlocale(LC_ALL, "");
    int n, hacer; 
    cout << "Ingrese el numero del arreglo:"; cin >> n;
    int* arr = new int[n];
    int pos;
    int numeRepe1; 
    generar_Arreglo(arr, n);
    mostrar_Arreglo(arr, n);
    cout << endl;  

    cout <<"1. Encontrar el elemento mayor en un arreglo.                     "<<endl; 
    cout <<"2. Encontrar el elemento menor en un arreglo.                     "<<endl; 
    cout <<"3. Sumar todos los elementos de un arreglo.                       "<<endl; 
    cout <<"4. Encontrar la moda de los elementos de un arreglo.              "<<endl; 
    cout <<"5. Ordenar un arreglo.                                            "<<endl; 
    cout <<"6. Eliminar el elemento en una posición de un arreglo.            "<<endl; 
    cout <<"7. Buscar un elemento en un arreglo.                              "<<endl; 
    cout <<"8. Determinar si un elemento existe en un arreglo.                "<<endl; 
    cout <<"9. Calcular cuántas veces se repite un elemento X en un arreglo.  "<<endl; 
    
    cout << "Opcion:";  cin >> hacer; cout << endl;
    switch (hacer)
    {
    case 1: numero_Mayor(arr, n);  break;
    case 2: menor_Mayor(arr, n);  break;
    case 3: suma_numeros(arr, n);  break;
    case 4: moda_num(arr, n);  break;
    case 5: ordenamiento(arr, n); break; 
    case 6:  cout << "Que posicion desea eliminar: "; cin >> pos; cout << endl;
        eliminar_posicion(arr, n, pos);
        mostrar_Arreglo(arr, n); break; 
    case 7: buscar_posicion(arr, n);  break;
    case 8:existe_numero(arr, n); break;
    case 9:
        cout << "Que numero desea ver si se repite: "; cin >> numeRepe1; cout << endl; 
        RepiteNumero(arr, numeRepe1, n);  break;
    }

    getch(); 
    return 0; 
    
}
