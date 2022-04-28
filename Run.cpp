#include <iostream>
#include <fstream>

#include "Tests.cpp"

using namespace std;
int tab_val[20];
int tab_val_size = 20;

void Read_from_file(int tab[])
{
    ifstream file("textfile.txt");
    int val = 0;
    int size = 0;
    if(file.is_open())
    {
    file >> size;
    if(file.fail())
    cout << "File error - READ SIZE" << endl;
    else
        for(int i = 0; i < size; i++)
        {
            file >> val;
            if(file.fail())
            {
                cout << "File error - READ DATA" << endl;
                break;
            }else
                tab[i] = val;
        }
     file.close();
    }else
        cout << "File error - OPEN" << endl; 
}

int Get_Value()
{
    int val;
    cout <<"Write number to insert: ";
    cin >> val;

    return val;
}

int Get_Del()
{
    int index;
    cout <<"Write number to delete: ";
    cin >> index;

    return index;
}

int Get_Index()
{
    int index;
    cout <<"Choose one index: ";
    cin >> index;

    return index;
}

int What_to_search()
{
    int value;
    cout <<"Write value you want to search: ";
    cin >> value;

    return value;
}

int Get_Prev()
{
    int val;
    cout <<"After which value you want to insert your number: ";
    cin >> val;

    return val;
}

void Array_Menu()
{
    Array container;
    char input;
    while(true)
    {
         cout<<"\n1.Add value to end of array \n"
            <<"2.Add value to front of array \n"
            <<"3.Add value to special index of array \n"
            <<"4.Delete value from end of array \n"
            <<"5.Delete value from front od array \n"
            <<"6.Delete value from special index of array \n"
            <<"7.Show array \n"
            <<"8.Check if array contains value \n"
            <<"9.Add values from file \n"
            <<"q.Quit \n";
        
        cout<<"\nPick your number: ";
        cin >> input;

        switch(input)
        {
            case '1':
                container.Add_Back(Get_Value());
                break;
            case '2':
                container.Add_Front(Get_Value());
                break;
            case '3':
                container.Add_Spec(Get_Value(), Get_Index());
                break;
            case '4':
                container.Del_Back();
                break;
            case '5':
                container.Del_Front();
                break;
            case '6':
                container.Del_Spec(Get_Index());
                break;
            case '7':
                container.Show_Array();
                break;
            case '8':
                if (container.Find_Elem(What_to_search()))
                    cout<<"\nArray contains this value!\n";
                else cout<<"\nArray doesn't contain this value!\n";
                break;
            case '9':
                Read_from_file(tab_val);
                for(int i = 0 ; i < tab_val_size ; i++)
                {
                    container.Add_Back(tab_val[i]);
                }
                break;
            case 'q':
                return;
                break;
        }
    }
}

void List_Menu()
{

    List container;
    char input;
    while(true)
    {
         cout<<"\n1.Add value to end of list \n"
            <<"2.Add value to front of list \n"
            <<"3.Add value next to the value \n"
            <<"4.Delete value from end of list \n"
            <<"5.Delete value from front of list \n"
            <<"6.Delete special value from list \n"
            <<"7.Show list \n"
            <<"8.Check if list contains value \n"
            <<"9.Add values from file \n"
            <<"q.Quit \n";
        
        cout<<"\nPick your number: ";
        cin >> input;

        switch(input)
        {
            case '1':
                container.Add_Back(Get_Value());
                break;
            case '2':
                container.Add_Front(Get_Value());
                break;
            case '3':
                container.Add_Spec(Get_Value(), Get_Prev());
                break;
            case '4':
                container.Del_Back();
                break;
            case '5':
                container.Del_Front();
                break;
            case '6':
                container.Del_Spec(Get_Del());
                break;
            case '7':
                container.Show_List();
                break;
            case '8':
                if (container.Find_Elem(What_to_search()))
                    cout<<"\nList contains this value!\n";
                else cout<<"\nList doesn't contain this value!\n";
                break;
            case '9':
                Read_from_file(tab_val);
                for(int i = 0 ; i < tab_val_size ; i++)
                {
                    container.Add_Back(tab_val[i]);
                }
                break;
            case 'q':
                return;
                break;
        }
    }
}

void Heap_Menu()
{
    Heap container;
    char input;
    while(true)
    {
         cout<<"\n1.Add value to heap\n"
            <<"2.Delete value from heap \n"
            <<"3.Show heap \n"
            <<"4.Check if heap contains value \n"
            <<"5.Add values from file \n"
            <<"q.Quit \n";
        
        cout<<"\nPick your number: ";
        cin >> input;

        switch(input)
        {
            case '1':
                container.Add(Get_Value());
                break;
            case '2':
                container.Delete(Get_Del());
                break;
            case '3':
                container.Show_Heap();
                break;
            case '4':
                if (container.Find_Value(What_to_search()))
                    cout<<"\nHeap contains this value!\n";
                else cout<<"\nHeap doesn't contain this value!\n";
                break;
            case '5':
                Read_from_file(tab_val);
                for(int i = 0 ; i < tab_val_size ; i++)
                {
                    container.Add(tab_val[i]);
                }
                break;
            case 'q':
                return;
                break;
        }
    }
}

void RBTree_Menu()
{
    RBTree container;
    char input;
    while(true)
    {
         cout<<"\n1.Add value to RB Tree\n"
            <<"2.Delete value from RB Tree \n"
            <<"3.Show RB Tree \n"
            <<"4.Check if RB Tree contains value \n"
            <<"5.Add values from file \n"
            <<"q.Quit \n";
        
        cout<<"\nPick your number: ";
        cin >> input;

        switch(input)
        {
            case '1':
                container.Add(Get_Value());
                break;
            case '2':
                container.Delete(Get_Del());
                break;
            case '3':
                container.Show_Tree();
                break;
            case '4':
                if (container.Find(What_to_search()))
                    cout<<"\nRB Tree contains this value!\n";
                else cout<<"\nRB Tree doesn't contain this value!\n";
                break;
            case '5':
                Read_from_file(tab_val);
                for(int i = 0 ; i < tab_val_size ; i++)
                {
                    container.Add(tab_val[i]);
                }
                break;
            case 'q':
                return;
                break;
        }
    }
}


void Benchmarks()
{
    Tests test;
    test.run();
}

int main()
{
    char variable;
    while(true)
    {
     cout<<"\n1.Array \n"
        <<"2.List \n"
        <<"3.Heap \n"
        <<"4.Red-Black Tree \n"
        <<"5.Benchmarks \n"
        <<"q.End \n";

    cout<<"Pick one numer: ";
    cin >> variable;

    switch(variable)
    { 
        case '1':
            Array_Menu();
            break;
        case '2':
            List_Menu();
            break;
        case '3':
            Heap_Menu();
            break;
        case '4':
            RBTree_Menu();
            break;
        case '5':
            Benchmarks();
            break;
        case 'q':
            return 0;
    }
    }   
}