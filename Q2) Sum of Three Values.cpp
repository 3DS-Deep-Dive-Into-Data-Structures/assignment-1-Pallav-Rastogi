#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    
    if (n<3)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    
    
    vector <int> v;
    
    for (int vinpidx = 0; vinpidx < n; vinpidx++){
        int tempinp;
        cin >> tempinp;
        v.push_back(tempinp);
    }
    
    vector <int> v2(v);
    sort(v.begin(), v.end());
        
    for (auto i = v.begin(); i != v.end()-2; i++)
    {
        int sum = x - (*i);
        
        auto strt = i+1;
        auto end = v.end()-1;
        
        while (strt < end)
        {
            if (sum == *strt + *end)
            {   
                int a = find(v2.begin(), v2.end(), *i) - v2.begin() + 1;
                *(find(v2.begin(), v2.end(), *i)) = -1;
                
                int b = find(v2.begin(), v2.end(), *strt) - v2.begin()+1;
                *find(v2.begin(), v2.end(), *strt) = -1;
                
                cout<<a<<" "<<b<<" "<<find(v2.begin(), v2.end(), *end) - v2.begin()+1<<" "<<endl;
                return 0;
            }
            
            if (sum < *strt + *end) 
            {
                end--;
            }
            
            else{
                strt++;
            }
            
        }
        
    }
    
    cout<<"IMPOSSIBLE"<<endl;
    
    return 0;
}
