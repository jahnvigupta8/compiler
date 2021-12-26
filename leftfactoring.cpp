#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    string str[7];
    int no;
    cin>>no;
    for(int i=0;i<no;i++)
        cin>>str[i];
    for(int j=0;j<no;j++)
    {
        string parts[3];
        for(int i=0;i<3;i++)
            parts[i] = "";
        int len=str[j].length(), partNumber=0;
        char ch=str[j][0];
        string temp = str[j];
        for(int x=3;x<len;x++)
        {
            if(temp[x]=='|')
            {
                partNumber++;
            }
            else
            {
                parts[partNumber] += temp[x];
            }
        }
        string temp1=""; int cnt=0;
        while(parts[0][cnt] == parts[1][cnt])
        {
            temp1 += parts[0][cnt];
            cnt++;
        }
        string x1="",x2="";
        for(int y=cnt;y<parts[0].length();y++)
        {
            x1 += parts[0][y];
        }
        for(int y=cnt;y<parts[1].length();y++)
        {
            x2 += parts[1][y];
        }
        
        cout<<endl<<"The productions after left factoring:-"<<endl;
        cout<<ch<<"->"<<temp1<<ch<<"`|"<<parts[2];
        cout<<endl<<ch<<"`->"<<x1<<"|"<<x2<<endl;
    }

}

