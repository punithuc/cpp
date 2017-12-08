#include <iostream>
#include <sstream>
using namespace std;

// List nodeclass
class Node {
public:
    int data;
    Node* next;
};

// Linked list class
class List {
public:
    List() { dummyhead.data = 0; dummyhead.next = NULL; head = &dummyhead; }
    ~List() {}
    void addNode(int val);
    void reverse();
    void print();

private:
    Node dummyhead;
    Node* head;
};

// Function to add a node to the list
void List::addNode(int val)
{
    Node* temp = new Node();
    temp->data = val;
    temp->next = NULL;

    Node* temp1 = head;
    while ( temp1->next != NULL )
        temp1 = temp1->next;
    temp1->next = temp;
}

// Iterative function to reverse a list
void List::reverse()
{
    Node* n1 = head->next;
    Node* n2 = NULL;
    Node* n3 = NULL;
    while ( n1 != NULL )
    {
        head->next = n1;
        n2 = n1->next;
        n1->next = n3;
        n3 = n1;
        n1 = n2;
    }
}

void List::print()
{
    Node* temp = head->next;
    while ( temp != NULL ) {
        cout << temp->data << " ";         
        temp = temp->next;
    }
    cout << endl; 
} 

// Test program 
int main(int argc, char** argv) {    
    List* list = new List();     
    if (argc == 1)
    {
        cout << "Input : " << argc << endl;
        list->addNode(100);
        list->addNode(200);
        list->addNode(300);
        list->addNode(400);
        list->addNode(500);
    }
    else
    {
        cout << "Input : " << argc << endl;
        cout << "Nodes : "<< argv[1] << endl;
        stringstream input(argv[1]);
        int nodes;
        input >> nodes;
        cout << "Value Nodes " << nodes << endl;
        for(int i = 0 ; i < nodes; i++)
            list->addNode(i);
    }
    //list->print();
    list->reverse();
    //list->print();
    delete list;
}
