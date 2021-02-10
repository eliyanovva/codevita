#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

// function to find the substring of the
// string
string substring(string s,int a,int b)
{
    string s1="";

    // extract the specified poition of
    // the string
    for(int i = a; i < b; i++)
        s1 = s1 + s[i];

    return s1;
}

// can get palindrome string from a
// given string
vector<string> pal(string s)
{
    vector<string> v ;

    // moving the pivot from starting till
    // end of the string
    for (float pivot = 0; pivot < s.length();
         pivot += .5)
    {

        // set radius to the first nearest
        // element on left and right
        float palindromeRadius = pivot -
                                 (int)pivot;

        // if the position needs to be
        // compared has an element and the
        // characters at left and right
        // matches
        while ((pivot + palindromeRadius)
               < s.length() && (pivot - palindromeRadius)
                               >= 0 && s[((int)(pivot - palindromeRadius))]
                                       == s[((int)(pivot + palindromeRadius))])
        {

            v.push_back(substring(s,(int)(pivot -
                                          palindromeRadius), (int)(pivot
                                                                   + palindromeRadius + 1)));

            // increasing the radius by 1 to point
            // to the next elements in left and right
            palindromeRadius++;
        }
    }

    return v;
}
int main() {

    int len;
    string s;
    cin>>len>>s;
    int n;
    cin>>n;
    int numbers[n];
    int total= 0;

    for(int i=0; i<n; i++)
        cin>>numbers[i];

    vector<string> p = pal(s);

    for(int i=0; i<p.size(); i++) {
        for (int j = 0; j < n; j++) {
            int k = p[i].size();
            if (k== numbers[j]) {
                total ++;
                break;
            }
        }
    }
    cout<<total;
    return 0;
}
