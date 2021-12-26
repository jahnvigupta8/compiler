#include <bits/stdc++.h>
using namespace std;
int main()
{

    cout<<"Production Rules: "<<endl;
    for(int i=0;i<1;i++)
	{
        string st;
        cin>>st;
        cout<<endl<<"OUTPUT"<<endl;
        char ch=st[0];
        if(st[0]==st[3])
		{
            for(int j=3;j<st.length();j++)
			{
                if(st[j]=='|')
				{
                    cout<<st[0]<<st[1]<<st[2];
                    for(int k=j+1;k<st.length();k++)
					{
                        cout<<st[k];
                    }
                    cout<<"X\nX->";
                     for(int k=4;k<st.length();k++)
					 {
                         if(st[k]=='|')
						 {
                             break;
                         }
                         cout<<st[k];
                    }
                    cout<<"X|e\n";
                    break;
                }
             }
        }
        else
		{
            cout<<st;
        }   
    }

}
