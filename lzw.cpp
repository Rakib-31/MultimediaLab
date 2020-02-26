#include<bits/stdc++.h>
using namespace std;

int arr[100],l=0;
string store="";

void decode(){
    string str,input,dict[100]="",entry,ans="";
    map <int , string> mp;
    int k = 0, m =0,n=1;

    for(int i = 0; i < store.size(); i++){
        dict[k] += store[i];
        mp[n++] = dict[k++];
    }
    string s="";

    for(int i = 0; i < l; i++){
        entry = mp[arr[i]];
        ans += entry;
        if(!s.empty()){
            s += entry[0];
            dict[k] += s;

            mp[n++] = dict[k++];
        }
        s = entry;
    }
    cout<<"Decode: "<<ans<<endl;
}

void encode(){
    string s,c,str,input,dict[100]="";
    map <string , int> mp;

    int k = 0, m =0,n=1;
    getline(cin,input);

    str = input;

    sort(str.begin(),str.end());

    store += str[0];

    for(int i = 1; i < str.size(); i++){
        if(store[m] != str[i]){
            store += str[i];
            m++;
        }
    }
    for(int i = 0; i < store.size(); i++){
        dict[k] += store[i];
        mp[dict[k++]] = n++;
    }

    s = input[0];

    for(int i = 1; i < input.size(); i++){
        c = input[i];
        bool check = false;
        for(int j = 0; j < k; j++){
            if(s+c == dict[j]){
                check = true;
                break;
            }
        }
        if(check) s = s+c;
        else{
            arr[l++] = mp[s];
            dict[k++] = s+c;


            mp[dict[k-1]] = n++;
            s = c;
        }
    }
    arr[l++] = mp[s];
    cout<<"Encode: ";
    for(int i = 0; i < l; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    encode();
    decode();

    return 0;
}
