#include<iostream>
using namespace std;

class ResearchPaper{
    string *authors;
    int n;

    public:
        ResearchPaper(int n, string s[]):n(n){
        authors = new string[n];
        for (int i=0;i<n;i++) {
            authors[i]=s[i];
        }
    }
    ResearchPaper(const ResearchPaper& other) {
        n=other.n;
        authors=new string[n];
        for (int i=0;i<n;i++) {
            authors[i]=other.authors[i];
        }
    }
      ResearchPaper& operator=(const ResearchPaper& other) {
        if (this != &other) {
            delete[] authors; 
            n=other.n;
            authors = new string[n];
            for (int i=0;i<n;i++) {
                authors[i] = other.authors[i];
            }
        }
        return *this;
    }
};