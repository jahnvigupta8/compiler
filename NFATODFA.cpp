#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter the Regular Expression: ";
    string regexp;
    cin>>regexp;
    int i=0;
    char poststack[100];
    char postarr[100];
    int flag=0;
    int top=0;
    int j=0;
    while(regexp[i]!='\0'){
        if(regexp[i]=='+'){
            poststack[top]=regexp[i];
            top++;
            flag=0;
        }
        else{
            postarr[j]=regexp[i];
             j++;
            if(flag==1){
                postarr[j]='*';
                j++;
            }
            flag=1;
        
        }
        i++;
    }
    while(top!=0){
        top--;
        postarr[j]=poststack[top];
        j++;
    }
    postarr[j]='\0';
    i=0;
    while(postarr[i]!='\0'){
    cout<<postarr[i];
    i++;
    }
    cout<<endl;
    int states[100][2];
    i=0;
    j=0;
    int stateNo=0;
    int statestack[100];
    char input[100];
    vector<pair<int,int> > epsilonarr;
    top=0;
    while(postarr[i]!='\0'){
        if(postarr[i]=='*'||postarr[i]=='+'){
            if(postarr[i]=='*'){
                top--;
                states[j][1]=statestack[top];
                top--;
                int m=statestack[top];
                 top--;
                int n=statestack[top];
                top--;
                states[j][0]=statestack[top];
                top++;
                statestack[top]=states[j][0];
                top++;
                statestack[top]=states[j][1];
                top++;
                states[j][1]=m;
                states[j][0]=n;
                input[j]='e';
                epsilonarr.push_back(make_pair(n,m));
                j++;
            }
            else{
                int m=stateNo;
                stateNo++;
               int n=stateNo;
                stateNo++;
                 top--;
                states[j][0]=statestack[top];
                states[j][1]=n;
                input[j]='e';
                j++;
                epsilonarr.push_back(make_pair(statestack[top],n));

                states[j][1]=statestack[top-1];
                states[j][0]=m;
                input[j]='e';
                j++;
                epsilonarr.push_back(make_pair(m,statestack[top-1]));

                states[j][0]=statestack[top-3];
                states[j][1]=n;
                input[j]='e';
                j++;
                epsilonarr.push_back(make_pair(statestack[top-3],n));

                states[j][1]=statestack[top-4];
                states[j][0]=m;
                input[j]='e';
                epsilonarr.push_back(make_pair(m,statestack[top-4]));
                j++;

                top=top-4;
                top++;
                statestack[top]=m;
                top++;
                statestack[top]=n;
                top++;
            
            }
        }
        else{
            states[j][0]=stateNo;
            states[j][1]=stateNo+1;
            stateNo=stateNo+2;  
            statestack[top]=states[j][0];
            top++;
            statestack[top]=stateNo-1;
            top++;
             input[j]=postarr[i];

            j++;
        }
        i++;
    }
    for(int i=0;i<j;i++){
        cout<<states[i][0]<<" to "<<states[i][1]<<" by "<<input[i]<<endl;
    }
    cout<<"Dfa"<<endl;
    for(int i=0;i<j;i++){
        // cout<<states[i][0]<<" to "<<states[i][1]<<" by "<<input[i]<<endl;
        if(input[i]!='e'){
            for(int j=0;j<epsilonarr.size();j++){
                if(states[i][1]==epsilonarr[j].first){
                    states[i][1]=epsilonarr[j].second;
                }
            }
            cout<<states[i][0]<<" to "<<states[i][1]<<" by "<<input[i]<<endl;
        }
    }
    

} 

