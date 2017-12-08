#include <iostream>
using namespace std;

// General list node
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

// General list class
class List {
    public:
        List() { mHead = NULL; mCount = 0; }
        ~List() {}
        Node* head() { return mHead; }
        void setHead(Node* head) { mHead = head; }

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
                cout << ptr->data() << " ";
                ptr = ptr->next();
            }
            cout << endl;
        }

        bool isPalindrome(Node*& n1, Node* n2) {
            if ( ! n2 )
                return true;

            if ( ! isPalindrome(n1, n2->next()) )
                return false;

            bool flag = ( n1->data() == n2->data() );

            n1 = n1->next();

            return flag;
        }

    private:
        Node* mHead;
        int mCount;
};

int main() {
    List* l = new List();
    l->append(100);
    l->append(200);
    l->append(300);
    l->append(400);
    l->append(300);
    l->append(200);
    l->append(100);
    l->print();

    Node* n1 = l->head();
    bool stat = l->isPalindrome(n1, n1);
    if ( stat ) {
        cout << "Linked list is palindrome" << endl;
    }
    else {
        cout << "Linked list is not a palindrome" << endl;
    }

    delete l;
}
