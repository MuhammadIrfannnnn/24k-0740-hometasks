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
void insertfront(string n,double p){
    Node*newnode=new Node(n,p);
    if(head==NULL){
        head=tail=newnode;
    }
    newnode->next=head;
    head=newnode;
}
void insertend(string n,double p){
    Node*newnode=new Node(n,p);
    if(head==NULL){
        head=tail=newnode;
    }
    tail->next=newnode;
    tail=newnode;
}
void insert(string na,string n,double p){
    Node*newnode=new Node(n,p);
        if(head==NULL){
        head=tail=newnode;
    }
    Node*temp=head;
    while (temp->name!=na)
    {
        temp=temp->next;
    }
    Node*t2=temp->next;
    temp->next=newnode;
    newnode->next=t2;
    
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
    L.insertfront("laptop",1000);
    L.insertend("Phone",700);
    L.insertend("Tablet",400);
    L.insertend("Headphone",150);
    cout<<"Initial list: "<<endl;
    L.display();
    cout<<"Insert at front: "<<endl;
    L.insertfront("Smartwastch",200);
    L.display();
    cout<<"Insert at end: "<<endl;
    L.insertend("Keyboard",80);
    L.display();
    cout<<"Insert after phone: "<<endl;
    L.insert("Phone","Monitor",300);
    L.display();
    cout<<"Search for tablet"<<endl;
    L.search("Tablet");
    cout<<"Final list"<<endl;
    L.display();
}