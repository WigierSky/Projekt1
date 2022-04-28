#include "Array.h"
#include <iostream>

Array::Array()
{
   
}

void Array::resize(int size)
{
    int *new_array = new int[size]; //nowa tablica

    for(int i = 0 ; i<array_size ; i++) //przypisanie elementów
    {
        new_array[i] = array[i];
    }

    delete[] array;
    array = new_array;

    array_size = size;
}

void Array::Add_Back(int val)
{
   resize(array_size + 1);
   array[array_size - 1] = val; //przypisanie elementu na koniec
}

void Array::Show_Array()
{
    if(array_size != 0)
    {
        std::cout<<"\n";
        for(int i = 0 ; i<array_size ; i++)
        {
            std::cout<<array[i] <<"\n";
        }
        std::cout<<"End of array" <<"\n";
    }else
        std::cout<<"\nArray is empty!\n";
}

void Array::Add_Front(int val)
{
    int new_size = array_size + 1; //zwiekszenie rozmiaru
    int *new_array = new int[new_size]; //nowa tablica

    new_array[0] = val; //wpisanie wartości na początek

    for(int i = 0 ; i < array_size ; i++) //przepisanie reszty elementów
    {
        new_array[i+1] = array[i];
    }

    delete[] array;
    array = new_array;

    array_size = new_size;

}

void Array::Add_Spec(int val, int index)
{
    if (index >= array_size)
        throw std::out_of_range("Inserting element outside of array!"); //sprawdzenie czy miejsce do którego dodajemy element istnieje w tablicy
    
    int new_size = array_size + 1; //zwiekszenie rozmiaru
    int *new_array = new int[new_size]; //nowa tablica

    for(int i = 0 ; i < index ; i++) //przepisanie wartości które wystapia przed wybranym miejscem
    {
        new_array[i] = array[i];
    }

    new_array[index] = val; //wpisanie wartości w wybrane miejsce

    for(int i = index ; i < array_size ; i++) //przepisanie wartości które wystapia po wybranym miejscu
    {
        new_array[i+1] = array[i];
    }

    delete[] array;
    array = new_array;

    array_size = new_size;
}

void Array::Del_Back()
{
    int size = array_size - 1; //nowy rozmiar
    int *new_array = new int[size]; //nowa tablica

    for(int i = 0 ; i<size ; i++) //przepisanie elementow, bez ostatniego
    {
        new_array[i] = array[i];
    }

    delete[] array;
    array = new_array;

    array_size = size;
}

void Array::Del_Front()
{
    int new_size = array_size - 1; //nowy rozmiar
    int *new_array = new int[new_size]; //nowa tablica

    for(int i = 0 ; i < new_size ; i++) //przepisanie elementow, bez pierwszego
    {
        new_array[i] = array[i + 1];
    }

    delete[] array;
    array = new_array;

    array_size = new_size;
}

void Array::Del_Spec(int index)
{
    if (index >= array_size)
        throw std::out_of_range("Deleting element outside of array!"); //sprawdzenie czy miejsce z którego usuwamy element istnieje w tablicy
    
    int new_size = array_size - 1; //nowy rozmiar
    int *new_array = new int[new_size]; //nowa tablica

    for(int i = 0 ; i < index ; i++) //przepisanie elementów występujących przed wybranym indeksem
    {
        new_array[i] = array[i];
    }

    for(int i = index ; i < new_size ; i++) //przepisanie elementów występujących po wybranym indeksie
    {
        new_array[i] = array[i + 1];
    }

    delete[] array;
    array = new_array;

    array_size = new_size;
}

bool Array::Find_Elem(int val)
{
    bool t = false;
    for(int i = 0 ; i < array_size ; i++)// wyszukanie elementu
    {
        if(array[i] == val)
            return true;
    }
    return false;      
}