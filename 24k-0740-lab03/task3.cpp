#include<iostream>
using namespace std;

class Node{
public:
int id;
string name;
double price;
Node*next;
Node*prev;

Node(int i,string n,double p):id(i),name(n),price(p){
    next=NULL;
    prev=NULL;
}
};

class List{
public:
Node*head;
Node*tail;

List(){
    head=NULL;
    tail=NULL;
}

void insertfront(int i,string n,double p){
    Node*newnode=new Node(i,n,p);
    if(head==NULL){
        head=tail=newnode;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}

void insertend(int i,string n,double p){
    Node*newnode=new Node(i,n,p);
    if(head==NULL){
        head=tail=newnode;
    }
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
}

void deletefront(){
    if(head==NULL){
        return;
    }
    Node*temp=head;
    head=head->next;
    head->prev=NULL;
    temp->next=NULL;
}

void deleteend(){
    if(head==NULL){
        return;
    }
    Node*temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    temp->prev=NULL;
}

void search(int i){
    Node*temp=head;
    while(temp!=NULL){
        if(temp->id==i){
            cout<<temp->id<<" "<<temp->name<<": "<<temp->price<<endl;
            return;
        }
        temp=temp->next;
    }
}

void updateprice(int i,double newprice){
    Node*temp=head;
    while(temp!=NULL){
        if(temp->id==i){
            temp->price=newprice;
            cout<<temp->id<<" "<<temp->name<<": "<<temp->price<<endl;
            return;
        }
        temp=temp->next;
    }
}

void display(){
    Node*temp=head;
    while (temp!=NULL)
    {
        cout<<temp->id<<" "<<temp->name<<": "<<temp->price<<endl;
        temp=temp->next;
    }
    
}

void displayRev(){
    Node*temp=tail;
    while (temp!=NULL)
    {
        cout<<temp->id<<" "<<temp->name<<": "<<temp->price<<endl;
        temp=temp->prev;
    }
    
}

void Count(){
    Node*temp=head;
    int n=0;
    while (temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    cout<<"Total Item in the cart are: "<<n<<endl;
}

void expensive(){
    if(head==NULL){
        return;
    }
    int max=-1;
    Node*temp=head;
    Node*expensive=head;
    while(temp!=NULL){
        if(temp->price>max){
            max=temp->price;
            expensive=temp;
        }
        temp=temp->next;
    }
    cout<<"Most expensive item is: "<<expensive->id<<" "<<expensive->name<<": "<<expensive->price<<endl;
}

};

int main(){
    List L1;
    cout<<"Insert Item at front and end"<<endl;
    L1.insertfront(103,"Shirt",500);
    L1.insertfront(102,"Jacket",800);
    L1.insertfront(101,"Trouser",900);
    L1.insertend(104,"Shorts",450);
    L1.insertend(105,"Cargo",1000);
    L1.insertend(106,"Shoes",700);
    L1.display();
    cout<<"Remove item from front and end"<<endl;
    L1.deletefront();
    L1.deleteend();
    L1.display();
    cout<<"Search for an item by ID"<<endl;
    L1.search(104);
    cout<<"Update Price by ID"<<endl;
    L1.updateprice(102,1200);
    cout<<"Display from front to end"<<endl;
    L1.display();
    cout<<"Display from end to front"<<endl;
    L1.displayRev();
    cout<<"Count Total Items"<<endl;
    L1.Count();
    cout<<"Search for most expensive item"<<endl;
    L1.expensive();

}