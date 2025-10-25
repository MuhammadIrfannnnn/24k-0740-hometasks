#include<iostream>
using namespace std;

struct call{
   string name;
   string number;
   string duration;
};

class Stack{
public:
    int top;
    call*history;
    int n;

    Stack(int n):n(n){
        history=new call[n];
        top=-1;
    }
    void push(call c){
        if(top==n-1){
            cout<<"Stack is overflow!"<<endl;
            return;
        }
        history[++top]=c;
        cout<<"Call added successfully"<<endl;
    }
    void pop(){
        if(top==-1){
            cout<<"Stack is underflow!"<<endl;
            return;
        }
        cout<<"Removed call: "<<history[top].name;
        top--;
    }
    call peek(){
          if(top==-1){
            cout<<"Stack is underflow!"<<endl;
            return {"", "", ""};
        }
        return history[top];
    }
    bool empty(){
        return top==-1;
    }

    void display(){
             if (empty()) {
            cout<<"No call history"<< endl;
            return;
        }
        cout<<endl<<"Call History"<<endl;
        for (int i=top;i>=0;i--) {
            cout << i + 1 << ". Name: "<< history[i].name<<", Number: "<< history[i].number<<", Duration: " << history[i].duration << endl;
        }
        cout <<endl;
    }
    
      ~Stack() {
        delete[] history;
    }
};

int main(){
     Stack s(5);

    call calls[5] ={
        {"Irfan", "03211234567", "2:30"},
        {"Huzaifa", "03310987654", "5:15"},
        {"Imran", "03121111111", "1:45"},
        {"Ayan", "03347878780", "3:10"},
        {"Hasan", "03343333333", "4:05"}
    };
    for (int i = 0; i < 5; i++) {
        s.push(calls[i]);
    }

    s.display();

    call last = s.peek();
    cout <<endl<< " Last Call-- Name: " << last.name<< ", Number: " << last.number<< ", Duration: " << last.duration << endl;
    s.pop();

    s.display();

    return 0;
}