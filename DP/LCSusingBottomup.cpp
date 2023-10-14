#include<bits/stdc++.h>
using namespace std;
class LCS
{
    public:
    int n;
    int m;
    string user_string1,user_string2,lcs_string="";
    int lcs_size;
    vector<vector<int>>dp_legit;
    LCS(string s1,string s2)
    {
        n=s1.size();
        m=s2.size();
        user_string1=s1;
        user_string2=s2;
    }
    int LCS_lenght(string s1,string s2)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=0;
        }
        for(int j=0;j<m;j++)
        {
            dp[0][j]=0;
        }
        for(int index1=1;index1<=n;index1++)
        {
            for(int index2=1;index2<=m;index2++)
            {
                if(s1[index1-1]==s2[index2-1])
                {
                   dp[index1][index2]=1+dp[index1-1][index2-1];     
                }
                else
                {
                    dp[index1][index2]=max(dp[index1-1][index2],dp[index1][index2-1]);
                }
            }
        }
        dp_legit=dp;
        lcs_size=dp[n][m];
        return lcs_size;
    }
    string get_LCS_String()
    {
        int index=lcs_size;
        int i=n;
        int j=m;
        while(i>0 && j>0)
        {
            if(user_string1[i-1]==user_string2[j-1])
            {
                lcs_string+=user_string1[i-1];
                index--;
                i--;
                j--;
            }
            else if(dp_legit[i-1][j]>dp_legit[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
        reverse(lcs_string.begin(),lcs_string.end());
        return lcs_string;
    }
    
    ~LCS()
    {

    }
};
int main()
{
    clock_t start,end;
    start=clock();
    string s1,s2;
    cout<<"Enter text = ";
    cin>>s1;
    cout<<"Enter pattern = ";
    cin>>s2;
    LCS l(s1,s2);
    cout<<"LCS size = "<<l.LCS_lenght(s1,s2)<<"\n";
    cout<<"LCS = "<<l.get_LCS_String()<<"\n";
    cout<<l.lcs_size<<"\n";
    end=clock();
    cout<<"\n\n\tProgramme finished = "<<(double)(end-start)/(double)CLOCKS_PER_SEC<<" second \n";
}