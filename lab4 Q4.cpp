#include<iostream>
#include<string>
using namespace std;
bool check(int arr[],int a){
    for(int i=0;i<a;i++){
        for(int j=i+1;j<a;j++){
            if(arr[i]==arr[j]){
                return true;
            }
            
    } 
    }
    cout<<"No duplicates found";
    return false;
}
int main(){
    int array[5];
    for(int i=0;i<5;i++){
      cout<<"input value= ";  
        cin>>array[i];
    }
    if(check(array,5)==true){
        cout<<"It has duplicates";
    }
    return 0;
}