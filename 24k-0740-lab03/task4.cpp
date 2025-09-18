#include<iostream>
using namespace std;

class Node{
    public:
    int id;
    string name;
    string ride;
    Node* next;

    Node(int i,string n,string r):id(i),name(n),ride(r){
        next=NULL;
    }
};

class List{
public:
Node*head;
Node*tail;

List(){
    head=tail=NULL;
}

void bookticket(int i,string n,string r){
    Node*newnode=new Node(i,n,r);
    if(head==NULL){
        head=tail=newnode;
        tail->next=newnode;
    }
    tail->next=newnode;
    tail=newnode;
    tail->next=head;
}

void bookVIPticket(int i,string n,string r){
    Node*newnode=new Node(i,n,r);
    if(head==NULL){
        head=tail=newnode;
        tail->next=newnode;
    }
    newnode->next=head;
    head=newnode;
    tail->next=head;
}

void cancelFirstTicket(){
    Node*temp=head;
    if(head==NULL){
        return;
    }
    if (head==tail) { 
        delete head;
        head=tail=NULL;
        return;
    }
    head=head->next;
    tail->next=head;
    temp->next=NULL;
    delete temp;
    cout<<"First Ticket Cancelled"<<endl;
}

void cancelTicket(int i){
    Node*temp=head;
    if(temp->id==i){
        cancelFirstTicket();
        return;
    }
    temp=temp->next;
    Node* prev=head;
        while (temp!=head) {
            if (temp->id==i) {
                if (temp==tail) { 
                    tail=prev;
                }
                prev->next=temp->next;
                delete temp;
                cout<<"Ticket "<<i<<" cancelled."<<endl;
                return;
            }
            prev =temp;
            temp=temp->next;
        }
        cout << "Ticket ID " << i << " not found"<<endl;
}

    void searchTicket(int i) {
        if (head == NULL) {
            return;
        }
        Node* temp = head;
        do {
            if (temp->id == i) {
                cout << "Ticket Found:"<<endl
                
                ;
                cout << "ID: " << temp->id << ", Customer: " << temp->name << ", Ride: " << temp->ride << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Ticket ID " << i << " not found"<<endl;
    }

    void displayTickets() {
        if (head==NULL) {
            return;
        }
        Node* temp=head;
        cout << "All Tickets:"<<endl;
        do {
            cout << "ID: " << temp->id << ", Customer: " << temp->name << ", Ride: " << temp->ride << endl;
            temp = temp->next;
        } while (temp != head);
    }

     void countTickets() {
        if (head==NULL) {
            return;
        }
        int n=0;
        Node* temp=head;
        do{
            n++;
            temp=temp->next;
        }while(temp!=head);
        cout << "Total Tickets: "<<n<<endl;
    }

    void findNextTicket(int i) {
        if (head==NULL) {
            return;
        }
        Node* temp=head;
        do {
            if (temp->id==i) {
                cout<<"Next Ticket:";
                cout<<"ID: "<<temp->next->id<<", Customer: "<<temp->next->name<< ", Ride: " << temp->next->ride << endl;
                return;
            }
            temp = temp->next;
        } while (temp!=head);
        cout << "Ticket ID " << i << " not found"<<endl;
    }

};
int main(){

List L;

    L.bookticket(1,"Irfan","Roller Coaster");
    L.bookticket(2,"Ahmed","Ferris Wheel");
    L.bookVIPticket(3,"Ali","Haunted House");

    L.displayTickets();
    L.countTickets();

    L.searchTicket(2);
    L.findNextTicket(2);

    L.cancelTicket(1);
    L.displayTickets();

    L.cancelFirstTicket();
    L.displayTickets();

    return 0;
}