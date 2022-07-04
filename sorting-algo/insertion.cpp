#include<iostream>>
using namespace std;

int main()
{
    /* code */
    //insertion sort
    int a[10];
    int temp;
    for(int i = 0; i < 10; i++){
        cout << "Enter values at index "<< i+1<<endl;
        cin >> a[i];
    }

    for(int i=1; i<10; i++){
        temp = a[i];
        int j = i-1;
        while(j>=0 && a[j]>temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }

    cout << endl<<endl<<"Sorted array\t[";
    for(int i = 0; i < 10; i++){
        std::cout << a[i]<<" ";
    }
    cout <<"]"<<endl;
    return 0;
}
