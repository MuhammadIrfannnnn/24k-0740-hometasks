#include <iostream>
using namespace std;

int getMax(int arr[], int n){
    int mx=arr[0];
    for(int i=1;i<n;i++) {
        if(arr[i]>mx){
            mx=arr[i];
        } 
    }
    return mx;
}

void countSort(int arr[], int n, int exp){
    int output[15];
    int count[10]={0};
    for(int i=0;i<n;i++) {
        count[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++) {
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    } 
}

void radixSort(int arr[], int n){
    int m=getMax(arr,n);
    for(int exp=1;m/exp>0;exp*=10){
         countSort(arr,n,exp);
    }
}

int main(){
    int trans[6]={120,450,320,450,120,800};
    int n=6;
    radixSort(trans,n);
    cout<<"Sorted Transaction Amounts:"<<endl;
    for(int i=0;i<n;i++) {
        cout<<trans[i]<<" ";
    }
}
