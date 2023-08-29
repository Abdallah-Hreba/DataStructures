#include<bits/stdc++.h>
using namespace std;
template <class T>
class Node
{
private:
    T info;
    Node* next;
public:
    Node(T d=0,Node* n = nullptr){info = d; next = n;}
    Node* getnext(){return next;}
    void setnext(Node* x){next = x;}
    T getinfo(){return info;}
    void setinfo(T d){info = d;}
};
template<class T>
class SLL
{
private:
    Node<T> *head,*tail;
public:
    SLL(){head=tail=NULL;}
    Node<T>* gethead(){return head;}
    Node<T>* gettail(){return tail;}
    bool isEmpty() {//function to make sure the SLL is empty or not
        if (head == NULL && tail == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //function to insert a node at the front of the SLL
    void addtohead(T value) {
        Node<T> *newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    //function to insert a node at the back of the SLL
    void addtotail(T value) {
        Node<T> *newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->setnext(newNode);
            tail = newNode;
        }
    }
    //function to remove the first element in the SLL
    T removefromhead() {
        if (isEmpty()) {
            cout<<"List is empty\n";
        }
        T value = head->getinfo();
        Node<T> *temp = head;

        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->getnext();
        }

        delete temp;
        return value;
    }
    //function to remove the last elemnt in the SLL
    T removefromtail() {
        if (isEmpty()) {
            cout<<"List is empty\n";
        }

        T value = tail->getinfo();
        Node<T> *temp = tail;

        if (head == tail) {
            head = tail = NULL;
        } else {
            Node<T> *current = head;
            while (current->next != tail) {
                current = current->next;
            }
            current->next = NULL;
            tail = current;
        }
        delete temp;
        return value;
    }
    //function to get the info of the head node
    T getvalueathead() {
        if (isEmpty()) {
            cout<<"List is empty\n";
        }
        return head->info;
    }
    //function to clear and empty ou SLL
    void clear() {
        while (!isEmpty()) {
            removefromhead();
        }
    }
    //function to print our SLL
    void print()
    {
        Node<T> *cu = gethead();
        while (cu != NULL)
        {
            cout<<cu->getinfo()<<" ";
            cu = cu->getnext(); 
        }
        cout<<"\n";
    }
    //function to swipe elements in the SLL pairwise
    void pairwiseSwap()
    {
        if (isEmpty() || head->getnext() == nullptr) {
            return;
        }
        Node<T>* prev = head;
        Node<T>* current = head->getnext();
        head = current;
        while (true) {
            Node<T>* nextNode = current->getnext();
            current->setnext(prev);

            if (nextNode == nullptr || nextNode->getnext() == nullptr) {
                prev->setnext(nextNode);
                break;
            }

            prev->setnext(nextNode->getnext());
            prev = nextNode;
            current = prev->getnext();
        }
        tail = prev;
    }
//remove duplicates function regarding of their position
    void removeDuplicates()
    {
        if (isEmpty() || head->getnext() == nullptr) {
            return;
        }

        unordered_set<T> uniqueElements;
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        while (current != nullptr) {
            if (uniqueElements.count(current->getinfo()) > 0) {
            // Duplicate element found, remove the node
                prev->setnext(current->getnext());
                Node<T>* temp = current;
                current = current->getnext();
                delete temp;
            } 
            else 
            {
            // Unique element, add it to the set
                uniqueElements.insert(current->getinfo());
                prev = current;
                current = current->getnext();
            }
    }
    tail = prev;
    }
};

int main()
{
    SLL<int> linkedList;//initializing our SLL of type integer
    //adding items(nodes) to our SLL
    linkedList.addtotail(1);
    linkedList.addtotail(2);
    linkedList.addtotail(3);
    linkedList.addtotail(4);
    linkedList.addtotail(5);
    linkedList.addtotail(6);
    //printing our SLL
    cout << "Original List: ";
    linkedList.print();
    //swapping the items in our SLL pairwise
    linkedList.pairwiseSwap();
    cout << "Pairwise Swapped List: ";
    linkedList.print();
    //clearing and reseting our SLL
    linkedList.clear();
    linkedList.addtotail(1);
    linkedList.addtotail(2);
    linkedList.addtotail(3);
    linkedList.addtotail(4);
    linkedList.addtotail(5);
    linkedList.addtotail(3);
    cout << "Original List: ";
    linkedList.print();
    //removing duplicate values from our SLL
    linkedList.removeDuplicates();
    cout << "List with Duplicates Removed: ";
    linkedList.print();
    return 0;
}