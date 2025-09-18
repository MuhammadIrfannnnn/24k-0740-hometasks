#include<iostream>
using namespace std;

class Node{
    public:
        string  name;
        double price;
        Node * next;

    Node(string n,double p): price(p),name(n){
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
void insertend(string n,double p){
    Node*newnode=new Node(n,p);
    if(head==NULL){
        head=tail=newnode;
    }
    tail->next=newnode;
    tail=newnode;
}

void deletefront(){
    if(head==NULL){
        return;
    }
    Node*temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
}
void search(string n){
    Node*temp=head;
    while(temp!=NULL){
        if(temp->name==n){
            cout<<temp->name<<": "<<temp->price<<endl;
            return;
        }
        temp=temp->next;
    }
}

void searchpos(int pos){
    Node*temp=head;
    int idx=0;
    while(temp!=NULL){
        if(idx==pos){
            cout<<temp->name<<": "<<temp->price<<endl;
            return;
        }
        temp=temp->next;
        idx++;
    }
}

void display(){
    Node*temp=head;
    while (temp!=NULL)
    {
        cout<<temp->name<<": "<<temp->price<<endl;
        temp=temp->next;
    }
    
}
};

int main(){
    List L;

    L.insertend("laptop",1000);
    L.insertend("Phone",700);
    L.insertend("Tablet",400);
    L.insertend("Headphone",150);
    cout<<"Initial list: "<<endl;
    L.display();
    cout<<"Insert item at tail: "<<endl;
    L.insertend("Keyboard",80);
    L.display();
    cout<<"Delete from front: "<<endl;
    L.deletefront();
    L.display();
    cout<<"Search by item name"<<endl;
    L.search("Headphone");
    cout<<"Search by pos"<<endl;
    L.searchpos(1);
    cout<<"Final list"<<endl;
    L.display();
}