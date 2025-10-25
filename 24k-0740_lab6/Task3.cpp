#include<iostream>
using namespace std;

class Node{
    public:
        string website;
        Node*next;
    Node(string website):website(website){
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
    void insert(string website){
        Node*temp=new Node(website);
        if(head==NULL){
            head=tail=temp;
            return;
        }
        temp->next=head;
        head=temp;
    }
    void remove(){
        if(head==NULL){
            return;
        }
        Node*temp=head;
        head=head->next;
        delete temp;
    }

    void display(){
        Node*temp=head;
        while (temp)
        {
            cout<<temp->website<<"-->";
            temp=temp->next;
        }
        cout<<endl;
        
    }

};

class Stack{
    public:
        List L;
        Node*top;

    Stack(){
        top=NULL;
    }
    void push(string website){
        L.insert(website);
        top=L.head;
    }
    void pop(){
        L.remove();
        L.remove();
        top=L.head;
    }
    string peek(){
        if (L.head)
        {
            return L.head->website;
        }
        
        return "empty";
    }
    bool empty(){
        return L.head==NULL;
    }
    void display(){
        L.display();
    }
};
int main(){
    Stack history;
    string sites[] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};
    for (int i = 0; i < 5; i++) {
        history.push(sites[i]);
        cout << "Visited: " << sites[i] << endl;
    }
    
    cout <<endl<<"Browsing History (most recent first):"<<endl;
    history.display();
    cout <<endl<< "User presses BACK twice"<<endl;
    history.pop();
    history.pop();

    cout <<endl<<"Current Page: " << history.peek() << endl;

    cout <<endl<<"Updated Browsing History:"<<endl;
    history.display();

    return 0;
}
