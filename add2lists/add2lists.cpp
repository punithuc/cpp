#include <iostream>
#include <cmath>
using namespace std;

class Node {
    public:
        Node() { mData = -1; mNext = NULL; }
        ~Node() {}
        int data() { return mData; }
        void setData(int data) { mData = data; }
        Node* next() { return mNext; }
        void setNext(Node* next) { mNext = next; }
    private:
        int mData;
        Node* mNext;
};

class List {
    public:
        List() { mHead = NULL; }

        ~List() {}

        Node* head() { return mHead; }

        void append(int data) {
            Node* tmp = new Node();
            tmp->setData(data);
            if ( mHead == NULL )
                    mHead = tmp;
            else {
                Node* ptr = mHead;
                while ( ptr->next() != NULL ) {
                        ptr = ptr->next();
                }
                ptr->setNext(tmp);
            }
        }

        void prepend(int data) {
            Node* tmp = new Node();
            tmp->setData(data);
            tmp->setNext(mHead);
            mHead = tmp;
        }

        void print() {
            Node* ptr = mHead;
            while ( ptr != NULL ) {
                cout << ptr->data() << " -- ";
                ptr = ptr->next();
            }
            cout << "NULL" << endl;
        }

        int size() {
            Node* ptr = mHead;
            int count = 0;
            while ( ptr != NULL ) {
                count++;
                ptr = ptr->next();
            }
            return count;
        }

    private:
        Node* mHead;
};

int addlists1(Node* node1, Node* node2, List* l3) {
    if ( node1 == NULL ) return 0;
    int carry = addlists1(node1->next(), node2->next(), l3);
    int val = carry + node1->data() + node2->data();
    int carry1 = val / 10;
    int nodeval = val % 10;

    l3->prepend(nodeval);

    return carry1;
}

void addlists(List* l1, List* l2, List* l3) {
    int size1 = l1->size();
    int size2 = l2->size();
    int diff = size1 - size2;
    if ( size1 > size2 ) {
        while ( diff > 0 ) {
            l2->prepend(0);
            diff--;
        }
    }
    else if ( size2 > size1 ) {
        while ( diff > 0 ) {
            l1->prepend(0);
            diff--;
        }
    }

    cout << "After prepending zeros." << endl;
    l1->print();
    l2->print();

    int carry = addlists1(l1->head(), l2->head(), l3);
    if ( carry ) {
       l3->prepend(carry);
    }
}

int main() {
    List* l1 = new List();
    l1->append(1);
    l1->append(7);
    l1->append(5);
    l1->append(6);

    List* l2 = new List();
    l2->append(9);
    l2->append(9);
    l2->append(9);

    cout << "Initial lists." << endl;
    l1->print();
    l2->print();

    List* l3 = new List();
    addlists(l1, l2, l3);

    cout << "Summed up list." << endl;
    l3->print();

    delete l1;
    delete l2;
}
