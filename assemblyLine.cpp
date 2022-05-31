#include<bits/stdc++.h>
using namespace std;

int assembly(vector<vector<int> > a,vector<vector<int> > t,vector<int> e,vector<int> x){

    vector<vector<int> > ans(2,vector<int>(a[0].size(),0));
    ans[0][0]=e[0]+a[0][0];
    ans[1][0]=e[1]+a[1][0];

    
    vector<vector<int> > path(2,vector<int>(a.size()));
    path[0][0]=0;
    path[1][0]=1;
    for (int i = 1; i < ans[0].size(); i++)
    {
        
        if ((ans[0][i-1]+a[0][i])<(ans[1][i-1]+t[1][i-1]+a[0][i]))
        {
             ans[0][i]=(ans[0][i-1]+a[0][i]);
            path[0][i]=0;

        }
        else
        {
            ans[0][i]=(ans[1][i-1]+t[1][i-1]+a[0][i]);
            path[0][i]=1;

        }


        if ((ans[1][i-1]+a[1][i])<(ans[0][i-1]+t[0][i-1]+a[1][i]))
        {
            ans[1][i]=(ans[1][i-1]+a[1][i]);
            path[1][i]=1;
          
        }
        else
        {
            ans[1][i]=(ans[0][i-1]+t[0][i-1]+a[1][i]);
            path[1][i]=0;
        
        }
        

    }
    // int currp=-1;
    // if(ans[0][ans[0].size()-1]+x[0]<ans[1][ans[0].size()-1]+x[1]){
    //     currp=0;
    // }
    // else
    // {
    //     currp=1;
    // }
    // cout<<"station "<<a[0].size()<<" line "<<currp<<endl;
    // currp=path[currp][path[0].size()-1];
//     for (int i = path.size(); i >=0 ; i--)
//     {
        
//         cout<<"station "<<i+1<<" line "<<currp<<endl;
//         currp=path[currp][i];
       
//     }
    
//    cout<<"min cost possible is ";

    return min(ans[0][ans[0].size()-1]+x[0],ans[1][ans[0].size()-1]+x[1]);


}

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < 10; i++){

    int n;
    // cout<<"no of stations : ";
    cin>>n;

    vector<vector<int> > a(2,vector<int>(n));
    
    // cout<<"values of stations on both lines : \n";
    for (int i = 0; i < n; i++)
    {
        cin>>a[0][i];
     
    }
    for (int i = 0; i < n; i++)
    {
        cin>>a[1][i];
    
    }


    

    vector<vector<int> > t(2,vector<int>(n-1));
    // cout<<"transation time b/w stations : \n";
    for (int i = 0; i < n-1; i++)
    {
        cin>>t[0][i];
 
    }
    
    for (int i = 0; i < n-1; i++)
    {
        cin>>t[1][i];
        
    }
    
    

    vector<int> e(2),x(2);
    // cout<<"entry time of both stations : ";
    cin>>e[0]>>e[1];
    // cout<<"exit time of both stations : ";
    cin>>x[0]>>x[1];

    
    auto start = chrono::steady_clock::now();

	assembly(a,t,e,x);
	auto end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "," << '\n';
   
    
	}
}

