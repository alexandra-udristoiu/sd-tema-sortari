#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int n, i;
int v[10000005], w[10000005];
ifstream fin("sortare.in");
ofstream fout("sortare.out");
void mergesort(int st, int dr){
    if(st == dr){
        return;
    }
    else{
        int mid = (st + dr) / 2;
        mergesort(st, mid);
        mergesort(mid + 1, dr);
        int i = st, j = mid + 1, pos = st;
        while(i <= mid && j <= dr){
            if(v[i] <= v[j]){
                w[pos++] = v[i];
                i++;
            }
            else{
                w[pos++] = v[j];
                j++;
            }
        }
        while(i <= mid){
            w[pos++] = v[i];
            i++;
        }
        while(j <= dr){
            w[pos++] = v[j];
            j++;
        }
        for(i = st; i <= dr; i++){
            v[i] = w[i];
        }
    }
}
int main(){
    fin>> n;
    for(i = 1; i <= n; i++){
        fin>> v[i];
    }
    mergesort(1, n);
    for(i = 1; i <= n; i++){
        fout<< v[i] <<" ";
    }
}

