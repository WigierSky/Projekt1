#include "List.h"
#include <iostream>


List::List()
{
    Elem_List *elem = head;

    while(elem)
    {
        Elem_List *next = elem->next;
        
        delete elem;
        elem = next;
    }
}

void List::Add_Front(int val)
{
    Elem_List* swap = head; //nowy element do którego przypisujemy pierwszy element listy (head)

    head = new Elem_List(); //nowy element, do którego przypiszemy naszą wartość
    head->data = val;
    head->next = swap; //ustawienie starego heada jako element kolejny po nowym elemencie

    if(swap) //jeśli wcześniej istniał pierwszy element to jego poprzednik zostaje headem
        swap->prev = head;
    else tail = head;//jeśli wpisany element jest jedyny to jest równiez tailem (ogonem)
}

void List::Show_List()
{
    Elem_List *elem = head; //nowy element do którego przypisujemy pierwszy element listy (head)
    while(elem) //jeśli pierwszy element istnieje to wyświetlamy po kolei wartosci elementów
    {
        std::cout<< elem->data << " ";

        elem = elem->next;
    }

    std::cout<<"\n";
}

void List::Add_Back(int val)
{
    Elem_List *elem = new Elem_List(); //nowy element
    elem->data = val; //przypisanie podanej wartosci
    elem->prev = tail; //ustawienie poprzedniego elementu jako poprzednika nowego elementu

    if(tail) //jeśli poprzednio istniał ogon to przypisujemy nowy element jako nastepny element ogona
        tail->next = elem; 
    else    head = elem; // jeśli nie to nowy element jest równiez headem

    tail = elem; //ustawienie nowego elementu jako ogon
}

void List :: Add_Spec(int val, int prev_elem)
{
    if(!Find_Elem(prev_elem)) //jesli element podany jako poprzednik tego który chcemy dodać nie istnieje to kończymy dodawanie
        return;

    Elem_List *place = new Elem_List();
    Elem_List *elem = new Elem_List();
    Elem_List *elem_head = head; //nowe elementy, do ostatniego przypisujemy wartosc heada

     while(elem_head) //wyszukanie elementu poprzedzajacego, jesli head istnieje
    {
        if(elem_head->data == prev_elem) // oraz jesli jego wartosc to wartosc poprzedniego elementu to wpisujemy go do place
            place = elem_head;

        elem_head = elem_head->next;
    }
    

    elem->data = val; //wpisujemy wartosc do wpisania do elementu
    elem->next = place->next; //ustawiamy element w odpowiednie miejsce
    place->next->prev = elem;
    elem->prev = place;
    place->next = elem;
    
    if(!place->prev) //jesli nie ma elementu przed tym wpisanym przez nas to jest on headem
        place = head;
}

void List::Del_Back()
{
    if(!tail) //jesli ogon nie istnieje to konczymy usuwanie
        return;
    
    if(!tail->prev) //jesli ogon nie ma poprzednika to usuwamy go i ustawiamy tail i head jako nullptr
    {
        delete tail;

        tail = nullptr;
        head = nullptr;
        return;
    }

    Elem_List *tmp = tail; //nowy element, przypisujemy do niego wartosc ogona
    tail = tail->prev; //ustawiamy ogon jako przedostatni element
    tail->next=nullptr; //ustawiamy ostatni element jako nullptr

    delete tmp; //usuwamy ostatni element (nullptr)
}

void List::Del_Front()
{
    if (!head) //jeśli head nie istnieje to kończymy usuwanie
        return;

    if(!head->next) //jeśli head nie ma kolejnego elemenu to usuwamy go i ustawiamy tail i head na nullptr
    {
        delete head;

        tail=nullptr;
        head=nullptr;
        return;
    }

    Elem_List *tmp = head; //nowy element, przypisujemy do niego wartosc heada
    head = head->next; //ustawiamy head jako drugi element
    head->prev = nullptr; //pierwszy element ustawiamy jako nullptr

    delete tmp; //usuwamy pierwszy element(nullptr)
}

void List::Del_Spec(int val)
{
    if(!Find_Elem(val)) //jesli element do usuniecia nie istnieje to konczymy usuwanie
        return;
    
    Elem_List *elem = head; //nowe elementy, do jednego wpisujemy wartosc head
    Elem_List *candidate = new Elem_List();

    while(elem) //szukamy elementu do usuniecia
    {
        if(elem->data == val)  
            candidate = elem;

        elem = elem->next;
    }

 if(candidate->prev)
        candidate->prev->next = candidate->next;
    else
        if(candidate->next) // jesli kandydat jest headem to headem zostaje kolejny element (jesli istnieje)
            head = candidate->next;
        else head = nullptr;

    if(candidate->next)
        candidate->next->prev = candidate->prev;
    else
        if(candidate->prev) //jesli kandydat jest ogonem to ogonem zostaje jego poprzednik
            tail = candidate->prev;
        else tail = nullptr;

    delete candidate;
    candidate = nullptr;

    delete elem;
    elem = nullptr;

    return;

}

bool List::Find_Elem(int val)
{
    Elem_List *elem = head; //nowy element, przypisujemy do niego wartosc head

    while(elem)
    {
        if(elem->data == val)
            return true;
        
        elem = elem->next;
    }
    return false;
}