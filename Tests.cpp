#include <iostream>
#include <random>
#include <windows.h>
#include <iomanip>

#include "Array.cpp"
#include "List.cpp"
#include "Heap.cpp"
#include "RBTree.cpp"

using namespace std;

random_device rd;
default_random_engine generator(rd());
double PCFreq = 0.0;
__int64 CounterStart = 0;

class Tests
{
//array to save random numbers, n to save how many elements we use to test and m to save how many times we launch function
int n = 7000;
int rands[7000];
int m = 1000;


public:
int Rand_Number(int one, int two)
{
    uniform_int_distribution<int> distribution(one, two);

    return distribution(generator);
}

void Generate_Rand()
{
    for(int i = 0 ; i < n ; i++)
    {
        rands[i] = Rand_Number(INT32_MIN, INT32_MAX);
    }
}

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/10000000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

int Heap_Add_Bench()
{
    int sum = 0;
   
    for(int j = 0 ; j<m ; j++)
    {
     Heap container;
     Generate_Rand();
     StartCounter();
     for(int i = 0 ; i<n ; i++)
        {
         container.Add(rands[i]);
        }
     sum += GetCounter();
    }
    return (sum/(m));
}

int Heap_Delete_Bench()
{
    int sum = 0;

    for(int j = 0 ; j<(m) ; j++)
    {
        Heap container;
        Generate_Rand();
        for(int i = 0 ; i<n ; i++)
        {
         container.Add(rands[i]);
        }
        int rand = Rand_Number(0, n - 1);

        StartCounter();

         container.Delete(rands[rand]);

        sum += GetCounter();
    }
    return (sum/(m));
}

int Heap_Find_Bench()
{
    int sum = 0;

    for(int j = 0 ; j<(m) ; j++)
    {
        Heap container;
        Generate_Rand();
        for(int i = 0 ; i<n ; i++)
        {
         container.Add(rands[i]);
        }
        int rand = Rand_Number(0, n - 1);

        StartCounter();

         container.Find_Value(rands[rand]);

        sum += GetCounter();
    }
    return (sum/(m));
}

int Array_Add_Back_Bench()
{
    int sum = 0;
   
    for(int j = 0 ; j<m ; j++)
    {
     Array container;
     Generate_Rand();
     StartCounter();
     for(int i = 0 ; i<n ; i++)
        {
         container.Add_Back(rands[i]);
        }
 
     sum += GetCounter();
    }
    return (sum/(m));
}

int Array_Add_Front_Bench()
{
    int sum = 0;
   
    for(int j = 0 ; j<m ; j++)
    {
     Array container;
     Generate_Rand();
     StartCounter();
     for(int i = 0 ; i<n ; i++)
        {
         container.Add_Front(rands[i]);
        }
 
     sum += GetCounter();
    }
    return (sum/(m));
}

int Array_Add_Spec_Bench()
{
    int sum = 0;
   
    for(int j = 0 ; j<(m) ; j++)
    {
     Array container;
     Generate_Rand();
     int rand = Rand_Number(0, n - 1);
     int place = Rand_Number(0 , n - 1);
     for(int i = 0 ; i<n ; i++)
        {
         container.Add_Back(rands[i]);
        }
    //Generate_Rand();
     StartCounter();
        container.Add_Spec(rands[rand], place);
     sum += GetCounter();
    }
    return (sum/(m));
}

int Array_Del_Back_Bench()
{
      int sum = 0;
   
    for(int j = 0 ; j<(m) ; j++)
    {
     Array container;
     Generate_Rand();
     for(int i = 0 ; i<n ; i++)
        {
         container.Add_Back(rands[i]);
        }

     StartCounter();
     for(int i = 0 ; i<n ; i++)
     {
        container.Del_Back();
     }
     sum += GetCounter();
    }
    return (sum/(m));
}

int Array_Del_Front_Bench()
{
     int sum = 0;
   
    for(int j = 0 ; j<(m) ; j++)
    {
     Array container;
     Generate_Rand();
     for(int i = 0 ; i<n ; i++)
        {
         container.Add_Back(rands[i]);
        }

     StartCounter();
     for(int i = 0 ; i<n ; i++)
     {
        container.Del_Front();
     }
     sum += GetCounter();
    }
    return (sum/(m));
}

int Array_Del_Spec_Bench()
{
     int sum = 0;
   
    for(int j = 0 ; j<(m) ; j++)
    {
    Array container;
    Generate_Rand();
    int rand = Rand_Number(0, n - 1);
    for(int i = 0 ; i<n ; i++)
        {
         container.Add_Back(rands[i]);
        }

     StartCounter();
        container.Del_Spec(rand);
     sum += GetCounter();
    }
    return (sum/(m));
}

int Array_Find_Bench()
{
    int sum = 0;
   
    for(int j = 0 ; j<(m) ; j++)
    {
    Array container;
    Generate_Rand();
    int rand = Rand_Number(INT32_MIN, INT32_MAX);
    for(int i = 0 ; i<n ; i++)
        {
         container.Add_Back(rands[i]);
        }

     StartCounter();
        container.Find_Elem(rand);
     sum += GetCounter();
    }
    return (sum/(m));
}

int List_Add_Back_Bench()
{
     int sum = 0;
   
    for(int j = 0 ; j<m ; j++)
    {
     List container;
     Generate_Rand();
     StartCounter();
     for(int i = 0 ; i<n ; i++)
        {
         container.Add_Back(rands[i]);
        }
 
     sum += GetCounter();
    }
    return (sum/(m));
}

int List_Add_Front_Bench()
{
    int sum = 0;
   
    for(int j = 0 ; j<m ; j++)
    {
     List container;
     Generate_Rand();
     StartCounter();
     for(int i = 0 ; i<n ; i++)
        {
         container.Add_Front(rands[i]);
        }
 
     sum += GetCounter();
    }
    return (sum/(m));
}

int List_Del_Back_Bench()
{
    
      int sum = 0;
   
    for(int j = 0 ; j<(m) ; j++)
    {
     List container;
     Generate_Rand();
     for(int i = 0 ; i<n ; i++)
        {
         container.Add_Back(rands[i]);
        }

     StartCounter();
     for(int i = 0 ; i<n ; i++)
     {
        container.Del_Back();
     }
     sum += GetCounter();
    }
    return (sum/(m));
}

int List_Del_Front_Bench()
{

    int sum = 0;
   
    for(int j = 0 ; j<(m) ; j++)
    {
     List container;
     Generate_Rand();
     for(int i = 0 ; i<n ; i++)
        {
         container.Add_Back(rands[i]);
        }

     StartCounter();
     for(int i = 0 ; i<n ; i++)
     {
        container.Del_Front();
     }
     sum += GetCounter();
    }
    return (sum/(m));
}

int List_Find_Bench()
{
    int sum = 0;
   
    for(int j = 0 ; j<(m) ; j++)
    {
    List container;
    Generate_Rand();
    int rand = Rand_Number(INT32_MIN, INT32_MAX);
    for(int i = 0 ; i<n ; i++)
        {
         container.Add_Back(rands[i]);
        }

     StartCounter();
        container.Find_Elem(rand);
     sum += GetCounter();
    }
    return (sum/(m));
}

int List_Del_Spec_Bench()
{
    int sum = 0;
   
    for(int j = 0 ; j<(m) ; j++)
    {
    List container;
    Generate_Rand();
    int rand = Rand_Number(INT32_MIN, INT32_MAX);
    for(int i = 0 ; i<n ; i++)
        {
         container.Add_Back(rands[i]);
        }

    
     StartCounter();
        container.Del_Spec(rand);
     sum += GetCounter();
    }
    return (sum/(m));
}

int List_Add_Spec_Bench()
{
     int sum = 0;
   
    for(int j = 0 ; j<(m) ; j++)
    {
    List container;
    Generate_Rand();
    int rand = Rand_Number(INT32_MIN, INT32_MAX);
    int prev = Rand_Number(INT32_MIN, INT32_MAX);
    for(int i = 0 ; i<n ; i++)
        {
         container.Add_Back(rands[i]);
        }

    
     StartCounter();
        container.Add_Spec(rand, prev);
     sum += GetCounter();
    }
    return (sum/(m));
}

int RBTree_Delete_Bench()
{
    int sum = 0;

    for(int j = 0 ; j<(m) ; j++)
    { 
        RBTree container;
        Generate_Rand();
        for(int i = 0 ; i<n ; i++)
        {
         container.Add(rands[i]);
        }
        int rand = Rand_Number(0, n-1);

        std::cout<<rand <<"\n";

        StartCounter();

         container.Delete(rands[rand]);

        sum += GetCounter();
    }
    return (sum/(m));
}

int RBTree_Add_Bench()
{
    int sum = 0;
   
    for(int j = 0 ; j<m ; j++)
    {
     RBTree container;
     Generate_Rand();
     StartCounter();
     for(int i = 0 ; i<n ; i++)
        {
         container.Add(rands[i]);
        }
     sum += GetCounter();
    }
    return (sum/(m));
}

int RBTree_Find_Bench()
{
    int sum = 0;

    for(int j = 0 ; j<(m) ; j++)
    {
        RBTree container;
        Generate_Rand();
        for(int i = 0 ; i<n ; i++)
        {
         container.Add(rands[i]);
        }
        int rand = Rand_Number(0, n - 1);
        
        StartCounter();

         container.Find(rands[rand]);

        sum += GetCounter();
    }
    return (sum/(m));
}

void run()
{  
   cout<<"\nElements: " <<n <<"\n";

   cout<<"\nHeap Add: "<<(Heap_Add_Bench()/1000) <<" [ms]";
   cout<<"\nHeap Delete: "<<Heap_Delete_Bench() <<" [ns]";
   cout<<"\nHeap Find Element: "<<Heap_Find_Bench() <<" [ns]\n";

   cout<<"\nArray Add Back: " <<(Array_Add_Back_Bench()/1000) <<" [ms]";
   cout<<"\nArray Add Front: " <<(Array_Add_Front_Bench()/1000) <<" [ms]";
   cout<<"\nArray Add Spec: " <<Array_Add_Spec_Bench() <<" [ns]";

   cout<<"\nArray Delete Back: " <<(Array_Del_Back_Bench()/1000) <<" [ms]";
   cout<<"\nArray Delete Front: " <<(Array_Del_Front_Bench()/1000) <<" [ms]";
   cout<<"\nArray Delete Special Element:" <<Array_Del_Spec_Bench() <<" [ns]";

   cout<<"\nArray Find Element: " <<Array_Find_Bench() <<" [ns]\n";

   cout<<"\nList Add Back: " <<(List_Add_Back_Bench()/1000) <<" [ms]";
   cout<<"\nList Add Front: " <<(List_Add_Front_Bench()/1000) <<" [ms]";
   cout<<"\nList Add Spec: " <<List_Add_Spec_Bench() <<" [ns]";

   cout<<"\nList Delete Back: " <<(List_Del_Back_Bench()/1000) <<" [ms]";
   cout<<"\nList Delete Front: " <<(List_Del_Front_Bench()/1000) <<" [ms]";
   cout<<"\nList Delete Special Element: " <<List_Del_Spec_Bench() <<" [ns]";

   cout<<"\nList Find Element: " <<List_Find_Bench() <<" [ns]\n";

   cout<<"\nRB Tree Add: " <<(RBTree_Add_Bench()/1000) <<" [ns]";
   cout<<"\nRB Tree Find Element: " <<RBTree_Find_Bench() <<" [ns]";

   cout<<"\nRB Tree Delete: " <<RBTree_Delete_Bench() <<" [ns]";


}

};