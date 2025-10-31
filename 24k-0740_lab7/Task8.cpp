#include <iostream>
#include <string>
using namespace std;

struct Order {
    int orderID;
    string customerName;
    double totalPrice;
};

int partition(Order arr[], int low, int high){
    double pivot=arr[high].totalPrice;
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j].totalPrice<=pivot){
            i++;
            Order t=arr[i]; arr[i]=arr[j]; arr[j]=t;
        }
    }
    Order t=arr[i+1]; arr[i+1]=arr[high]; arr[high]=t;
    return i+1;
}

void quickSort(Order arr[], int low, int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    Order o[3]={
        {1001,"Fariha",8900},{1455,"Zainab",9190},{2201,"Kinza",9100}
    };
    quickSort(o,0,2);
    cout<<"Sorted Orders"<<endl;
    for(int i=0;i<3;i++)
        cout<<o[i].orderID<<" "<<o[i].customerName<<" "<<o[i].totalPrice<<endl;
}
