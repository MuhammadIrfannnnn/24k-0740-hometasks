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
        ~ResearchPaper() {
        delete[] authors;
        delete authors;
    }


    void display() {
        for (int i=0;i<n; i++) {
            cout<<authors[i]<<endl;
        }
    }

};
int main() {
    string s1[] = {"Irfan","Ali"};
    ResearchPaper p1(2, s1);

    cout <<"Original Paper Authors:"<< endl;
    p1.display();

    ResearchPaper p2(p1);
    cout<<endl<<"Copied Paper Authors:"<< endl;
    p2.display();
     string s2[]={"Ahmed","Fahad"};
     ResearchPaper p3(2,s2);
     cout<<endl<<"Paper 3 authors"<<endl;
     p3.display();

     p3=p1;
    cout<<endl<<"Paper 3 after assignment operator"<<endl;
    p3.display();

    return 0;
}