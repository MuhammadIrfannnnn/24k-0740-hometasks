#include<iostream>
using namespace std;

class Box{
    int * vol;

public:
    Box(){
        vol=new int(0);
    }
    Box(int v){
        vol=new int(v);
    }
    Box(const Box &other){
        vol=new int(*other.vol);
    }
    ~Box(){
        delete vol;
    }
};

int main(){

}