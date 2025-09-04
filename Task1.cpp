#include<iostream>
using namespace std;

class ResearchPaper{
    string *authors;
    int n;
    public:
    ResearchPaper(){

    }
    ResearchPaper(int n,string s[]):n(n){
          authors=new string[n];
        for (int i=0;i<n;i++) {
            authors[i]=s[i];
        }
    }
};