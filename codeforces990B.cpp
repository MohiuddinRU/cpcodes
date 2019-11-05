#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    int n,K;

    cin>>n>>K;

    int array[n];
    bool vanished[n] = {false};
    int remaining = n;

    for(int i = 0; i<n; i++){
        cin>>array[i];
    }
    sort(array, array + n);

    for(int j = 0; j<n-2; j++){
        for(int i = j; i<n-1; i++){
            if(!vanished[i] && !vanished[i+1]){
                if(array[i]<array[i+1]){
                    if((array[i]+K) >= array[i+1]){
                        vanished[i] = true;
                        remaining--;
                        break;
                    }
                }
            }
        }
    }
    cout<<remaining<<endl;
    return 0;
}
