#include<bits/stdc++.h>
using namespace std;

int main(){
    fstream ic,lt,mc,st;
    ic.open("IC.txt",ios::in);
    lt.open("LITTAB.txt",ios::in);
    st.open("SYMTAB.txt",ios::in);
    mc.open("MC.txt",ios::out);
    string line;
    vector<int>symt,lit;
    string sa,la;


    while(getline(st,sa)){
        string temp ="";
        for(int i=sa.size()-1;i>=0;i--){
            if(sa[i] ==' ') break;
            else temp+=sa[i];
        }
        reverse(temp.begin(),temp.end());
        symt.push_back(stoi(temp));
    }

    while(getline(lt,la)){
        string temp ="";
        for(int i=la.size()-1;i>=0;i--){
            if(la[i] ==' ') break;
            else temp+=la[i];
        }
        reverse(temp.begin(),temp.end());
        lit.push_back(stoi(temp));
    }

    // for(int i=0;i<symt.size();i++) cout<<symt[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<lit.size();i++) cout<<lit[i]<<" ";
    while(getline(ic,line)){
        string temp ="";
        string str = "";
        int flag = 0, end = 0;
        for(auto ch:line){
            if(ch=='('){
                temp ="";
                str="";
            }
            else if(ch==','){
                if(temp=="AD"){
                    flag=1;
                    break;
                }
                str = temp;
                temp = "";
                continue;
            }
            else if(ch == ')'){
                if(temp == "00" and str=="IS"){
                    end =1;
                    break;
                }
                else if(str == "L"){
                    mc<<lit[temp[1]-'0'];
                }
                else if(str == "S"){
                    mc<<symt[temp[1]-'0'];
                }
                else if(str == "C"){
                    mc<<"00"<<temp;
                }
                else{
                    if(str=="DL") mc<<"00 00 ";
                    else mc<<temp<<" ";
                }
                str = "";
            }
            else temp+=ch;
        }
        mc<<endl;
        if(flag==1) continue;
       if(end == 1) break;
    }



    ic.close();
    lt.close();
    st.close();
    mc.close();

}