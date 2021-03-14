#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<cstring>
using namespace std;
int n, i, k;
int v[10000005], fr[300], w[10000005];
ifstream fin("sortare.in");
ofstream fout("sortare.out");
void radixsort(){
    int i, maxim, biti, pt, k = 0;
    biti = 8;
    pt = (1 << biti) - 1;
    for(i = 1; i <= n; i++){
        maxim = max(maxim, v[i]);
    }
    while(maxim > 0){
        memset(fr, 0, sizeof(fr));
        for(i = 1; i <= n; i++){
            fr[ (v[i] >> k) & pt ]++;
        }
        for(i = 1; i <= pt; i++){
            fr[i] += fr[i - 1];
        }
        for(i = n; i >= 1; i--){
            w[ fr[ v[i] ] -- ] = v[i];
        }
        for(i = 1; i <= n; i++){
            v[i] = w[i];
        }
        maxim >>= biti;
        k += biti;
    }
}
int main(){
    fin>> n;
    for(i = 1; i <= n; i++){
        fin>> v[i];
    }
    radixsort();
    for(i = 1; i <= n; i++){
        fout<< v[i] <<" ";
    }
}
