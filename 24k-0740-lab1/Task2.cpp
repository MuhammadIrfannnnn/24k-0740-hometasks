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

    void setvol(int v){
        *vol=v;
    }
    int getvol(){
        return *vol;
    }
};

int main(){
    Box b1;
    cout<<"Box 1 vol: "<<b1.getvol()<<endl;
    Box b2(10);
    cout<<"Box 2 vol: "<<b2.getvol()<<endl;
    Box b3(b2);
    cout<<"Box 3 vol: "<<b3.getvol()<<endl;
    b3.setvol(100);
    cout<<"Box 3 new vol: "<<b3.getvol()<<endl;
    cout<<"Box 2 unchanged vol: "<<b2.getvol()<<endl;
    return 0;
}