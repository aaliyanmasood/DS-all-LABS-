#include<iostream>
using namespace std;
class sort{
    int arr[9]={ 20, 12, 15, 2, 10, 1, 13, 9, 5};
    public:
    sort(){
        cout<<"\n\nSorted 4 items:\n";
        for(int i=1;i<9;i++){
            int key=arr[i];
            int j=i-1;  
            while(j>=0 && arr[j]>key){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
        for(int i=0;i<9;i++){
            cout<<"\nValue"<<i+1<<"= "<<arr[i];
        };
        cout<<"\n";
        arr[4]=arr[8]+arr[4];
        arr[8]=arr[4]-arr[8];
        arr[4]=arr[4]-arr[8];
        for(int i=0;i<9;i++){
            cout<<"\nValue"<<i+1<<"= "<<arr[i];
        };
    }
};
int main(){
    sort start;
    return 0;
}