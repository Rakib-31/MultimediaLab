#include <bits/stdc++.h>
using namespace std;

map<char, int> freq;
map<char, pair<float, float>> proba_range; ///probability distribution


float value_of(string str) ///find value of a binary string
{
    float sum = 0;
    int len = str.size();
    for(int i = 0; i < len; i++)
        sum += (str[i] - '0')*pow(2, -1*i);
    return sum;
}

string arith(string str)
{
    for(auto ch: str) ///count frequency of each character
        freq[ch]++;

    float high, range, low = 0.0;
    for(auto it: freq) ///Iterate through the map freq
    {
        float proba = 1.00*it.second / str.size(); ///it.first is a character and proba is probability of that character
        proba_range[it.first].first = low;     ///range low
        low += proba;
        proba_range[it.first].second = low;    ///range high
    }

    low = 0.0;
    high = range = 1.0;
    for(auto ch: str) ///Iterate through the str
    {
        float temp = low;
        low += range*proba_range[ch].first;
        high = temp + range*proba_range[ch].second;
        range = high - low;
    }

    string code = "";
    while(value_of(code) < low) ///find binary code
    {
        code += "1";
        if(value_of(code) > high)
            code[code.size()-1] = '0';
    }

    //cout << low << " " << high << endl;
    //cout << value_of(code) << endl;
    return code;
}


int main()
{
    freopen("input.txt", "r", stdin);
    string str;
    getline(cin, str);
    str += "$";
    string encrypted =  arith(str);
    cout << "Encrypted code: " << encrypted << endl;
    return 0;
}
