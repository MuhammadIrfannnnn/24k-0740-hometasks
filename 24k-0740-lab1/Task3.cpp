#include<iostream>
using namespace std;

class Exam{
    int *marks;

    public:
    Exam(int m){
        marks=new int(m);
    }
    void set(int m){
        *marks=m;
    }
    int get(){
        return *marks;
    }
    ~Exam(){
        delete marks;
    }
};

int main(){
    Exam E1(100);
    Exam E2(E1);
    cout<<"Marks1: "<<E1.get()<<endl;
    cout<<"Marks2: "<<E2.get()<<endl;
    E2.set(90);
    cout<<"New Marks 2: "<<E2.get()<<endl;
    cout<<"Marks1 (changed): "<<E1.get()<<endl;
    return 0;
}