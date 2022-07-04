#include <iostream>
using namespace std;

int main(){
    int a[10];
    // int a[10] = {4,5,3,1,5,13,7,8,2,10};
    int temp;

    for(int i = 0; i < 10; i++){
        cout << "Enter values at index "<< i+1<<endl;
        cin >> a[i];
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(a[i] < a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    cout << endl<<endl<<"Sorted array\t[";

    for(int i = 0; i < 10; i++){
        std::cout << a[i]<<" ";
    }
    cout <<"]"<<endl;

    return 0;
}
