#include<iostream>
#include<string>
using namespace std;
class sort{
    string arr[5]= {"banana", "apple", "cherry", "date", "grape"};
    public:
    sort(){
        for(int i=0;i<5;i++){
            int index=i;  
            for(int j=i+1;j<5;j++){
                if(arr[j][0]<arr[index][0]){
                   index=j;
                }
            }
            if(index!=i){
            string temp=arr[i];
            arr[i]=arr[index];
           arr[index]=temp;}
        }
        for(int i=0;i<5;i++){
            cout<<"\nString"<<i+1<<" = "<<arr[i];
        };
    }
};
int main(){
    sort start;
    return 0;
}