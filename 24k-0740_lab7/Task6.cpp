#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    int id;
    double salary;
};

void merge(Employee arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    Employee L[12], R[12];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int j=0;j<n2;j++) R[j]=arr[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1&&j<n2) {
        if(L[i].salary >= R[j].salary) arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

void mergeSort(Employee arr[], int l, int r) {
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    Employee e[12] = {
        {"Ali",191,56000},{"Saba",123,12000},{"kinza",323,80000},{"sana",211,63000},
        {"raza",10,84000},{"zahid",345,54000},{"moiz",142,39000},{"saba",121,32000},
        {"laila",990,28000},{"shama",100,24000},{"yasir",156,47000},{"zohaib",477,49000}
    };
    mergeSort(e,0,11);
    cout<<"Top 3 Highest Paid Employees:\n";
    for(int i=0;i<3;i++)
        cout<<e[i].name<<" (ID: "<<e[i].id<<") - Salary: "<<e[i].salary<<endl;
}
