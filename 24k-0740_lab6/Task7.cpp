#include<iostream>
using namespace std;

class Patron{
    public:
        string name;
        int books;
};

class Queue{
    public:
    Patron*P;
    int front,rear;
    int n;
    Queue(int n):n(n){
        P=new Patron[n];
        front=-1;
        rear=-1;
    }
    bool isfull(){
        return rear==n-1;
    }
    bool isempty(){
        return front==-1 || front>rear;
    }
    void enqueue(string n,int b){
        if(isfull()){
            cout<<"Queue is full"<<endl;
            return;
        }
        if(front==-1){
            front=0;
        }
        rear++;
        P[rear].name=n;
        P[rear].books=b;
        cout<<n<<" has entered in queue with books "<<b<<endl;
    }
    void deque(){
        if(isempty()){
            cout<<"No patroons in queue"<<endl;
            return;
        }
        cout<<P[front].name<<" has completed transaction"<<endl;
        front++;
    }

    void display() {
        if (isempty()) {
            cout << "No patrons are waiting in the queue.\n";
            return;
        }
        cout << "\nCurrent Queue of Patrons:\n";
        for (int i = front; i <= rear; i++) {
            cout << i - front + 1 << ". " << P[i].name
                 << " (" << P[i].books << " book(s))\n";
        }
    }
};

int main() {
    Queue library(3);

    library.enqueue("Irfan", 2);
    library.enqueue("Huzaifa", 3);
    library.enqueue("Bilal", 1);
    library.display();
    library.deque();
    library.deque();
    library.display();

    return 0;
}
