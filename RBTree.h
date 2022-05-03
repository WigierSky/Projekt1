#include <string>
class RBTree
{
    struct Node
    {
        int data; //klucz
        Node *parent; //wskaźnik na rodzica
        Node *left_child; //wskaźnik na lewego potomka
        Node *right_child; //wskaźnik na prawego potomka
        int color; // 1 - Czerwony, 0 - Czarny
    };

private:
    Node *root = nullptr;
    Node *Null_Node = nullptr;
   
    void Rotate_Left(Node *node);
    void Rotate_Right(Node *node);
    void Fix_Tree_Add(Node *node);
    void Fix_Tree_Delete(Node *node);
    void print(Node *root, std::string x, bool last);
    void replace(Node *node1, Node *node2);

public:
    RBTree();
    ~RBTree();
    void Add(int val);
    void Delete(int val);
    void Show_Tree();
    bool Find(int val);

};