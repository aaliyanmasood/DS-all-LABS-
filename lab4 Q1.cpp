#include<iostream>
using namespace std;
class sort{
    int arr[10];
    public:
    sort(){
        cout<<"Enter 10 Values beneath for the list.\n";
        for(int i=0;i<10;i++){
            cout<<"Enter Value= ";
            cin>>arr[i];
        };
        cout<<"\n\nSorted 4 items:\n";
        for(int i=0;i<9;i++){
            int index=i;  
            for(int j=i+1;j<10;j++){
                if(arr[j]<arr[index]){
                    index=j;
                };
            }
            int temp=arr[i];
            arr[i]=arr[index];
           arr[index]=temp;
        }
        for(int i=0;i<4;i++){
            cout<<"\nValue"<<i+1<<"= "<<arr[i];
        };
    }
};
int main(){
    sort start;
    return 0;
}