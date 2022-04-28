#include "Heap.h"
#include <iostream>

#define Parent(child) (((child)-1)/2)
#define Left_Child(parent) (((parent)*2)+1)
#define Right_Child(parent) (((parent)*2)+2)

void Heap::Add(int val)
{  
    int pos = tab_size;
   int new_size = tab_size + 1; //nowy rozmiar
   int *new_tab = new int[new_size]; //nowa tablica na elementy

   for(int i = 0 ; i<tab_size ; i++) //przepisanie wartosci do nowej tablicy
   {
       new_tab[i] = tab[i];
   }

   new_tab[pos] = val; //wpisanie wartosci na ostatni element tablicy

    delete[] tab; //usuniecie starej tablicy

    tab = new_tab;
   tab_size = new_size;

   while(pos != 0) //naprawa kopca (aż do korzenia - wartosc 0)
   {
       if(tab[pos] > tab[Parent(pos)]) //jesli wartosc jest wieksza od wartosci jego rodzica to zamieniamy je
        {
            int buf = tab[pos];
            tab[pos] = tab[Parent(pos)];
            tab[Parent(pos)] = buf;
        }
            pos = (Parent(pos)); //sprawdzamy wartosc rodzica
   }

}

void Heap::Show_Heap()
{
    int x = 1;
    int y = 0;

    std::cout<<"\n";
    for(int i = 0 ; i<tab_size; i++)
    {
        std::cout<<tab[i] <<" ";

          if (i == y) {
            x *= 2;
            y += x;
            std::cout <<"\n";
        }
    }
    std::cout<<"\nEnd of heap \n";
}

void Heap::Delete(int val)
{
    if(Find_Value(val) == false) //jesli nie ma wartosci podanej do usuniecia to konczymy program
    {
        std::cout<<"There is no value like this in heap!";
        return;
    }

    int index = 0;

    for(int i = 0 ; i<tab_size ; i++) //wyszukiwanie indeksu dla podanej wartosci
    {
        if(tab[i] == val)
            index = i;
    }
    

    int new_size = tab_size - 1;
    tab[index] = tab[new_size]; // element do usuniecia zostaje zastapiony ostatnim elementem z tablicy
    
    int *new_tab = new int[new_size];

    for(int i = 0 ; i<new_size ; i++) //przepisanie wartosci ze starej tablicy
    {
        new_tab[i] = tab[i];
    }

    delete[] tab;

    tab = new_tab;
    tab_size = new_size;

  while (1) //ewentualna naprawa kopca
   {
        int candidate = index;

        if (Left_Child(index) < tab_size && tab[index] < tab[Left_Child(index)])//jesli istnieje lewe dziecko oraz ostatni element(wpisany w indeks)
            candidate = Left_Child(index);                                      //jest od niego mniejszy to kandydatem do zamiany jest lewe dziecko
 
        if (Right_Child(index) < tab_size && tab[candidate] < tab[Right_Child(index)])//jesli istnieje prawe dziecko to analogicznie moze
            candidate = Right_Child(index);                                           // byc kandydatem do zamiany, przyrownujemy do kandydata (ew zmiana)

        if (candidate != index) //jesli kandydat sie zmienił
        {
            int buf = 0;
            buf = tab[candidate];
            tab[candidate] = tab[index];
            tab[index] = buf;
            index = candidate;
        }else
            break; //jesli wszystko przebieglo bez zmian to konczymy petle
    }
}

bool Heap::Find_Value(int val)
{
    for(int i = 0; i<tab_size ; i++)
    {
        if(tab[i] == val)
            return true;
    }
    return false;
}
