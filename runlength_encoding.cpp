#include<bits/stdc++.h>
using namespace std;

int arr[100],m=0;


void makeBits(int character, int counter){
    short int comp = 0;
    comp = comp|character; /// add the character into the lower byte
    counter = counter<<8;  /// shift 8 bit and add then upper byte in variable
    comp= comp | counter;
    cout<<comp<<" ";
    arr[m++] = comp;
}

void makeData(int value){
    short int comp = 256;
    comp &= value;
    short int tmp = comp;
    comp = comp >> 8;
    tmp = tmp << 8;
    cout<<"("<<comp<<","<<tmp<<")"<<endl;
}

void RunLength(string input){

    int i,coun=1,n = input.length();
    //for(int i=0; i<n; i++){
        /*int cou = 1;
        while(i<n-1 && input[i] == input[i+1]){
            cou++;
            i++;
        }
        int value = input[i];
        cout<<"("<<cou<<","<<input[i]<<")"<<" "; /// here data are write in to the run_length_data.txt file*/

        for(i = 1; i < n; i++){
            if(input[i-1] == input[i]){
                coun++;
            }
            else{
                cout<<"("<<coun<<","<<input[i-1]<<")"<<" ";
                int val = input[i-1];
                makeBits(val,coun);
                coun = 1;
            }
        }
        cout<<"("<<coun<<","<<input[i-1]<<")"<<" ";
        int val = input[i-1];
        makeBits(val,coun);
    //}
    cout<<endl;

}

void decrypt(){
    cout<<"decryption"<<endl;
    for(int i = 0; i < m; i++){
        cout<<arr[i]<<endl;
        makeData(arr[i]);
    }
}

int main(){

    string input;
    getline(cin,input);
    RunLength(input);
    decrypt();


    return 0;

}
