#include<iostream>
using namespace std;
class sort{
    public:
    sort(){}
    void arrange(int arr[], int n){
        for(int i=0;i<n;i++){
            int index=i;  
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[index]){
                    index=j;
                };
            }
            int temp=arr[i];
            arr[i]=arr[index];
           arr[index]=temp;
        }
        for(int i=0;i<n;i++){
            cout<<"\nValue"<<i+1<<"= "<<arr[i];
        };
    }
};
int main(){
    sort start;
    int a;
    cout<<"Enter how many numbers you want to check= ";
    cin>>a;
    int arr[a];
    for(int i=0;i<a;i++){
        cout<<"Enter Number"<<i+1<<"=";
        cin>>arr[i];
    }
    start.arrange(arr,a);
    return 0;
}