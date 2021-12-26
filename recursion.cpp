#include <bits/stdc++.h>
using namespace std;
int E(int );
int  T(int);

string st;
int matcha(int i){
if(st[i]=='a'){
   i++;
   return i;
}
return -1;
}
int matchstar(int i){
if(st[i]=='*'){
   i++;
   return i;
}
return -1;
}
int matchopen(int i){
if(st[i]=='('){
   i++;
   return i;
}
return -1;
}
int matchplus(int i){
if(st[i]=='+'){
   i++;
   return i;
}
return -1;
}
int matchclose(int i){
if(st[i]==')'){
   i++;
   return i;
}
return -1;
}
int T(int i){
  
   if(matcha(i)!=-1){
       int x=matcha(i);
       if(x!=-1){
          x=matchstar(x);
          if(x!=-1){
              x=T(x);
              if(x!=-1){
                  return x;
              }
             
          }
          return matcha(i);
       }
       else if(matchopen(i)!=-1){
               int y=matchopen(i);
               if(y!=-1){
                   y=E(y);
                   if(y!=-1){
                       y=matchclose(y);
                       if(y!=-1){
                           return y;
                       }
                      
                   }
               }
          
           return -1;
       }
       else{
           return -1;
       }
   }
   else if(matchopen(i)!=-1){
       int y=matchopen(i);
               if(y!=-1){
                   y=E(y);
                   if(y!=-1){
                       y=matchclose(y);
                       if(y!=-1){
                           return y;
                       }
                      
                   }
               }
     
       return -1;
   }
   else{
       return -1;
   }
}
int E(int i){
    if(T(i)!=-1){
           int y=T(i);
           if(y!=-1){
               y=matchplus(y);
               if(y!=-1){
                   y=E(y);
                   if(y!=-1){
                       return y;
                   }
               }
           }
       return T(i);
   }
   else{
       return -1;
   }
  
}
int main(){
   cout<<"Production Rules: \n";
   cout<<"E->T/T+E \n";
   cout<<"T->a/a*T/(E) \n";
   cin>>st;
   int i=0;
   int l=st.length();
   if(E(i)==l){
       cout<<" Accepted"<<endl;
   }
   else{
       cout<<" Not Accepted"<<endl;
   }
}

