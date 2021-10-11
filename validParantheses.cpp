//Program to check whether the given string form a valid parentheses or not
//Stack will be used here

#include <bits/stdc++.h>
using namespace std;

bool valP(string &A)
{
    stack<char> s;
    int n = A.size();
    if(n%2==1) return false;
    
    for(int i = 0; i<n; i++)
    {
        if(A[i]=='(') s.push(A[i]);
        else
        {
            if(s.size()==0) return false;
            else s.pop();
        }
    }
    
    if(s.size()==0) return true;
    return false;
}

int main()
{
    string s;
    cout<<"Enter the string consisting of only '(' or ')': ";
    cin>>s;
    if(valP(s)) cout<<"Valid Parantheses!\n";
    else cout<<"Invalid Parantheses!\n";
    return 0;
}
