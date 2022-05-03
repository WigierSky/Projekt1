class List
{

    struct Elem_List
    {
        int data;
        Elem_List *next;
        Elem_List *prev;
    };

public:
    List();
    ~List();
    void Add_Front(int val);
    void Add_Back(int val);
    void Add_Spec(int val, int prev_elem);

    void Del_Back();
    void Del_Front();
    void Del_Spec(int val);
    void Show_List();

    bool Find_Elem(int val);


private:
    Elem_List *head = nullptr;
    Elem_List *tail = nullptr;
};