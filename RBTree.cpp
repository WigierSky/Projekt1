#include "RBTree.h"
#include <iostream>

RBTree::RBTree()
{
    Null_Node = new Node; //przypisanie parametrów do zerowego elementu
    Null_Node->color = 0; //Czarny
    Null_Node->left_child = nullptr;
    Null_Node->right_child = nullptr;
    root = Null_Node;

}

void RBTree::Rotate_Left(Node *node) //rotacja w lewo wzgledem podanego elemetu (node)
{
    Node *new_node = node->right_child; //tymczasowy element, przypisujemy do niego parametry prawego dziecka node'a
    node->right_child = new_node->left_child; //do prawego dziecka node'a przypisujemy parametry lewego dziecka wczesniej utworzonego tymczasowgo elementu

    if(new_node->left_child != Null_Node) //jesli tymczasowy element posiada lewe dziecko to przypisujemy mu jako ojca node'a
    {
        new_node->left_child->parent = node;
    }

    new_node->parent = node->parent;

    if (node->parent == nullptr) //jesli ojciec node'a nie istnieje to jest on korzeniem
    {
		root = new_node; //root
	} else if (node == node->parent->left_child) //jesli istnieje to sprawdzamy czy byl on lewym dzieckiem
            {
			    node->parent->left_child = new_node; // jesli tak to przypisujemy do wartosci lewego dziecka ojca wartosc tymczasowgo elementu
		    } else 
                {
			        node->parent->right_child = new_node; //jesli byl prawym to analogicznie
		        }
	new_node->left_child = node; //lewym dzieckiem od naszego nowego elementu bedzie node (był od niego mniejszy)
	node->parent = new_node;
}

void RBTree::Rotate_Right(Node *node) //rotacja w prawo wzgledem podanego elemetu (node)
{
    Node *new_node = node->left_child; //tymczasowy element, przypisujemy do niego parametry lewego dziecka node'a
    node->left_child = new_node->right_child; //do lewego dziecka node'a przypisujemy parametry prawego dziecka wczesniej utworzonego tymczasowgo elementu

    if(new_node->right_child != Null_Node) //jesli nowy element posiada prawe dziecko to przypisujemy mu jako ojca node
    {
        new_node->right_child->parent = node;
    }

    new_node->parent = node->parent;

    if(node->parent == nullptr)  //jesli ojciec node'a nie istnieje to jest on korzeniem
    {
        root = new_node; //root
    }else if (node == node->parent->right_child) //jesli istnieje to sprawdzamy czy byl on prawym dzieckiem
            {
                node->parent->right_child = new_node; // jesli tak to przypisujemy do wartosci prawego dziecka ojca wartosc tymczasowgo elementu
            }else
                {
                    node->parent->left_child = new_node; //jesli byl lewym to analogicznie
                }
    
    new_node->right_child = node; //lewym dzieckiem od naszego tymczasowgo elementu bedzie node (był od niego wiekszy)
    node->parent = new_node;
}


void RBTree::Add(int val) 
{
    Node *node = new Node; //nowy element
    node->parent = nullptr;
    node->data = val;
    node->left_child = Null_Node;
    node ->right_child = Null_Node;
    node->color = 1; //nowy element musi być czerwony

    Node *y = nullptr; //dwa elementy tymczasowe, jeden ma przypisana wartosc korzenia
    Node *x = root;

    while (x != Null_Node) //jesli korzen istnieje
    {
        y = x;
			if (node->data < x->data) //jesli wartosc nowego elementu jest mniejsza od wartosci korzenia
            {
				x = x->left_child; //to do x wpisujemy wartosc jego lewego dziecka
			} else {
				x = x->right_child; //jesli nie to wpisujemy wartosc prawego dziecka
			}
    }

    // y jest ojcem x
		node->parent = y; //jako ojca nowej wartosci ustawiamy korzen
		if (y == nullptr) { //jesli korzen nie istnieje
			root = node; //to nasz nowy element nim zostaje
		} else if (node->data < y->data) //jesli istnieje i jego wartosc jest wieksza od naszego elementu to element zostaje jego lewym dzieckiem
            {
		    	y->left_child = node;
	    	} else 
            {
			y->right_child = node; //jesli jest mniejszy to element zostaje jego prawym dzieckiem
		    }

		//jesli nowy element jest korzeniem to koniec
		if (node->parent == nullptr){
			node->color = 0; //czarny
			return;
		}

		//jesli dziadek naszego elementu nie istnieje to rowniez koniec
		if (node->parent->parent == nullptr) {
			return;
		}

        //naprawa drzewa
       Fix_Tree_Add(node);

}

void RBTree::replace(Node *node1, Node *node2) 
{
    if(node1 == root) //jesli pierwszy element jest korzeniem
    {
        root = node2; //to zostaje nim drugi (lewe/prawe dziecko)
    }else if(node1 == node1->parent->left_child) //jesli pierwszy element jest lewym dzieckiem swojego ojca
      {
          node1->parent->left_child = node2; //to zostaje nim drugi
      }else //jesli nie to drugi zostaje prawym dzieckiem ojca pierwszego
      {
          node1->parent->right_child = node2;
      }

      node2->parent = node1->parent; // ojciec drugiego zostaje ojcem pierwszego elementu
}


void RBTree::Delete(int val)
{
   
    Node *z = Null_Node; //elementy tymczasowe
    Node *x;
    Node *y;
    Node *node = root;

    while(node != Null_Node) //szukanie ktory węzeł zawiera podana wartosc
    {
        if(node->data == val) 
        {
            z = node;
        }

        if(node->data <= val) //jesli wartosc jest mniejsza niz ta do usuniecia to idziemy w prawo, jesli wieksza to w lewo
        {
            node = node->right_child;
        }else node = node->left_child;
    }

    if(z == Null_Node) //jesli z nadal jest zerowe to nie ma elementu
    {
        std::cout<<"\nCan't find value!\n";
        return;
    }
    
    int y_color; //pozniej przechowamy kolor danego elementu
    
    if(z->left_child == Null_Node) //jesli lewe dziecko kandydata do usuniecia nie istnieje
    {
        x = z->right_child; //to do x wpisujemy wartosc prawego dziecka kandydata i zamieniamy miejscami kandydata i jego prawe dziecko
        replace(z, z->right_child);

    }else if(z->right_child == Null_Node) //jesli prawe dziecko nie istnieje to analogicznie wykonujemy operacje dla lewego dziecka
       {
           x = z->left_child;
           replace(z, z->left_child);
       }else 
       {
            y = z->right_child; //szukamy najmniejszego elementu z prawej strony kandydata
           while(y->left_child != Null_Node)
           {
               y = y->left_child;
           }
           y_color = y->color; //zapisujemy wartosc najmniejszego elementu
           x = y->right_child; //do x wpisujemy wartosc prawego dziecka najmniejszego elementu

           if(y->parent == z)
           {
               x->parent = y; 
           }else //jesli ojcem y nie jest kandydat do usuniecia
           {
               replace(y, y->right_child); //to zamieniamy go z prawym dzieckiem
               y->right_child = z->right_child; 
               y->right_child->parent = y;
           }
            replace(z, y); //na koniec zmieniamy kandydata do usuniecia z finalnym y
            y->left_child = z->left_child;
            y->left_child->parent = y;
            y->color = z->color;
       }

    delete z; //usuwamy z 

    if(y_color == 0) //jesli jest czarny to naprawiamy
    {
        Fix_Tree_Delete(x);
    }
}
    
void RBTree::Fix_Tree_Add(Node *node)
{
    Node *new_node;
    while (node->parent->color == 1) //jeśli ojciec jest czerwony
    {
        if(node->parent == node->parent->parent->right_child) //oraz jest on prawym dzieckiem swojego ojca
        {
            new_node = node->parent->parent->left_child; //tymczasowy element zostaje wujkiem (lewym)
            if(new_node->color == 1) //jeśli wujek jest czerwony
            {
                new_node->color = 0; //zmiana koloru wujka na czarny
                node->parent->color = 0; //zmiana koloru ojca na czarny
                node->parent->parent->color = 1; //zmiana koloru dziadka na czerwony
                node = node->parent->parent; //do node przypisujemy dziadka
            } else
             {
                 if(node == node->parent->left_child)//jesli wujek byl czarny i node jest lewym dzieckiem
                 {
                     node = node->parent;//to do node przypisujemy ojca i robimy rotacje w prawo wzgledem node
                     Rotate_Right(node);
                 }

                node->parent->color = 0; //ustawienie koloru ojca na czarny
                node->parent->parent->color = 1; //ustawienie koloru dziadka na czerwony
                Rotate_Left(node->parent->parent); //rotacja w lewo względem dziadka
             }
        }else //jesli byl ojciec byl lewym dzieckiem swojego ojca
        {
            new_node = node->parent->parent->right_child; //wujek (prawy)
            if(new_node->color == 1)//jeśli wujek jest czerwony
            {
                new_node->color = 0; //zmiana koloru wujka na czarny
                node->parent->color = 0; //zmiana koloru ojca na czarny
                node->parent->parent->color = 1; //zmiana koloru dziadka na czerwony
                node = node->parent->parent; //przypisujemy do node dziadka
            }else 
            {
                if(node == node->parent->right_child) //jesli wujek byl czarny i node jest prawym dzieckiem
                {
                    node = node->parent; //to przypisujemy node wartosc jego ojca i robimy rotacje w lewo wzgledem node
                    Rotate_Left(node);
                }

                node->parent->color = 0; //ustawienie koloru ojca na czarny
                node->parent->parent->color = 1; //ustawienie koloru dziadka na czerwony
                Rotate_Right(node->parent->parent); //rotacja w prawo względem dziadka
            }
        }
        if(node == root) //jesli node jest korzeniem to koniec
        {
            break;
        }
    }
    root->color = 0; //ustawienie koloru korzenia na czarny
}

void RBTree::Fix_Tree_Delete(Node *node)
{
    Node *new_node;
    while(node != root && node->color == 0) //jesli node jest czarny i nie jest korzeniem
    {
        if(node == node->parent->left_child) //jesli node jest lewym dzieckiem
        {
            new_node = node->parent->right_child; // to do tymczasowego elementu przypisujemy wartosc prawego dziecka
            if(new_node->color == 1) //jesli prawe dziecko jest czerwone
            {
                new_node->color = 0; // to zmieniamy kolor na czarny
                node->parent->color = 1; // kolor ojca node zmieniamy na czerwony
                Rotate_Left(node->parent); //rotacja w lewo wzgledem ojca node
                new_node = node->parent->right_child; // do tymczasowego elementu wpisujemy prawe dziecko ojca node
            }

            if(new_node->left_child->color == 0 && new_node->right_child->color == 0) //jesli oboje dzieci new_node sa czarne
            {
                new_node->color = 1; //to zmienamy kolor na czerwony i ustawiamy node na jego ojca
                node = node->parent;
            }else
            {
                 if(new_node->right_child->color == 0)//jesli tylko prawe dziecko jest czarne
                 {
                     new_node->left_child->color = 0;//to zmieniamy kolor lewego dziecka na czarne
                     new_node->color = 1;//kolor new_node na czerwony
                     Rotate_Right(new_node);//rotacja w prawo wzgledem new_node
                     new_node = node->parent->right_child; //przypisujemy do new_node prawe dziecko ojca node
                 }

            new_node->color = node->parent->color; //zmiana koloru new_node na kolor ojca node
            node->parent->color = 0; //zmiana koloru ojca node na czarny
            new_node->right_child->color = 0; //zmiana prawego dziecka new_node na czarny
            Rotate_Left(node->parent);//rotacja w lewo wzgledem ojca node
            node = root; //node zostaje korzeniem
            }
        }else// jesli node nie jest lewym dzieckiem
        {
            new_node = node->parent->left_child; //do new_node przypisujemy lewe dziecko ojca node 
            if(new_node->color == 1) //jesli jest ono czerwone
            {
                new_node->color = 0; //to zmienamy mu kolor na czarny
                node->parent->color = 1; //a ojca node na czerwony
                Rotate_Right(node->parent);//rotacja w prawo wzgledem ojca node
                new_node = node->parent->left_child;//do new_node przypisujemy lewe dziecko ojca node 
            }

            if(new_node->right_child->color == 0 && new_node->left_child->color == 0) //jesli dzieci new_node sa czarne
            {
                new_node->color = 1;//to zmienamy kolor na czerwony i ustawiamy node na jego ojca
                node = node->parent;
            }else
            {
                if(new_node->left_child->color == 0) //jesli tylko lewe dziecko jest czarne
                {
                    new_node->right_child->color = 0; // to zmienamy kolor lewego dziecka na czarne a new_node na czerwony
                    new_node->color = 1;
                    Rotate_Left(new_node); //rotacja w lewo wzgledem new_node
                    new_node = node->parent->left_child; //przypisujemy do new_node lewe dziecko ojca node
                }

                new_node->color = node->parent->color; //zmiana koloru new_node na kolor ojca node
                node->parent->color = 0; //zmiana koloru ojca node na czarny
                new_node->left_child->color = 0; //zmiana koloru lewego dziecka new_node na czarny
                Rotate_Right(node->parent); //rotacja w prawo wzgledem ojca node
                node = root; //node zostaje korzeniem
            }
        }
    }

    node->color = 0; //kolor node na czarny
}

bool RBTree::Find(int val)
{
    Node *node = root; //tymczasowy element z wartoscia korzenia

    while(node && node->data != val) //jesli korzen istnieje i nie jest wartoscia ktorej szukamy
    {
        if(node->data > val) // jesli wartosc korzenia jest wieksza od wartosci ktorej szukamy to idziemy w lewo, jesli nie to w prawo
            node = node->left_child;
        else node = node->right_child;
    }

    if(node && node->data == val)
        return true;

    return false;
}

void RBTree::print(Node *root, std::string x, bool last)
{
    std::string color_root;
   if(root != Null_Node)
   {
       std::cout<<x;
       if(last)
       {
           std::cout<<"R--";
            x += "   ";
       }else
       {
           std::cout<<"L--";
          x += "|  ";
       }

       if(root->color == 1) //jeśli kolor jest czerwony
       {
           color_root = "Red";
       }else color_root = "Black";

       std::cout<<root->data <<"(" <<color_root <<")" <<"\n";

       print(root->left_child,x, false);
       print(root->right_child,x , true);
   }
}

void RBTree::Show_Tree()
{
    if(root)
    { 
        print(root,"", true); 
    }
}

