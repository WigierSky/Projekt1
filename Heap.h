class Heap
{
private:
    int tab_size = 0;
    int *tab = nullptr;
    void resize(int size);
    
public:
    void Add(int val);
    void Delete(int val);
    bool Find_Value(int val);

    void Show_Heap();
};