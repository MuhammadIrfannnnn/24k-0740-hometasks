#include <iostream>
using namespace std;

int getMax(int arr[], int n){
    int mx=arr[0];
    for(int i=1;i<n;i++) if(arr[i]>mx) mx=arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp){
    int output[50];
    int count[10]={0};
    for(int i=0;i<n;i++){
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
    for(int exp=1;m/exp>0;exp*=10) {
        countSort(arr,n,exp);
    }
}

int main(){
    int scores[50]={95,45,87,23,65,12,34,88,56,73,90,54,100,67,78,43,32,21,85,60,
                    70,66,89,40,20,10,30,25,35,50,55,62,68,71,74,80,83,84,86,92,
                    93,94,97,98,99,59,58,57,46,15};
    int n=50;
    radixSort(scores,n);
    cout<<"Rank     Score"<<endl;
    for(int i=0;i<n;i++)
        cout<<i+1<<"     "<<scores[i]<<endl;
}
