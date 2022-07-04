#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter value at index " << i+1 << endl;
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    //displaying vector
    cout << endl << endl << "Vector\t[";
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "]" << endl;

    for(auto i=v.begin(); i!=v.end(); i++){
        cout << *i << " ";
    }

    return 0;
}

