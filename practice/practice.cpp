#include <iostream>
#include<string>
using namespace std;

void printEncoding(string str, string asf){
    if(str.length() == 0){
        cout<<asf<<endl;
        return;
    }

    if(str[0] == '0') return;
    int num = str[0]-'0';
    char ch = 'a'+num-1;
    printEncoding(str.substr(1), asf+ch);

    if(str.length() >= 2 and str.substr(0, 2) <= "26"){
        int sum = stoi(str.substr(0,2));
        char ch = 'a'+sum-1;
        printEncoding(str.substr(2), asf+ch);
    }
}

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");
    
}