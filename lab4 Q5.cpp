#include<iostream>
using namespace std;
class sort{
    int arr[6]={2022, 2023, 2024, 2022, 2023, 2024};
    public:
    sort(){
        for(int i=0;i<6;i++){
            int index=i;  
            for(int j=i+1;j<6;j++){
                if(arr[j]<arr[index]){
                    index=j;
                };
            }
            int temp=arr[i];
            arr[i]=arr[index];
           arr[index]=temp;
        }
        for(int i=0;i<6;i++){
            cout<<"\nValue"<<i+1<<"= "<<arr[i];
        };
    }
};
int main(){
    sort start;
    return 0;
}