class Array
{
private:
    int array_size = 0;
    int *array = nullptr;
    //tworzy nowa tablice, kopiuje elementy i usuwa stara tablice
    void resize(int size);  

public:
    Array();
    void Show_Array();

    void Add_Back(int val);
    void Add_Front(int val);
    void Add_Spec(int val, int index);

    void Del_Back();
    void Del_Front();
    void Del_Spec(int index);

    bool Find_Elem(int val);
};

 