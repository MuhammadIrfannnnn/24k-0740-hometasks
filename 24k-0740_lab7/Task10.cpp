#include <iostream>
using namespace std;

int getMax(int arr[], int n){
    int mx=arr[0];
    for(int i=1;i<n;i++){
         if(arr[i]>mx){
             mx=arr[i];
         }
    }
    return mx;
}

void countSort(int arr[], int n, int exp){
    int output[20];
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
    for(int i=0;i<n;i++) {
        arr[i]=output[i];
    }
}

void radixSort(int arr[], int n){
    int m=getMax(arr,n);
    for(int exp=1;m/exp>0;exp*=10) {
        countSort(arr,n,exp);
    }
}

int main(){
    int ids[20]={12345,54321,23451,15243,43512,25134,31245,21435,13425,34512,51234,43125,12543,32415,21354,24153,45321,13524,32145,14253};
    int n=20;
    cout<<"Before Sorting:"<<endl;
    for(int i=0;i<n;i++) cout<<ids[i]<<" ";
    cout<<endl<<"After Sorting:"<<endl;
    radixSort(ids,n);
    for(int i=0;i<n;i++) {
        cout<<ids[i]<<" ";
    }
}
