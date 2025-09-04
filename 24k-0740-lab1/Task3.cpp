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

}