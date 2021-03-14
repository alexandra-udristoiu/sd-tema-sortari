#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int n, i, maxquick;
int v[10000005];
ifstream fin("sortare.in");
ofstream fout("sortare.out");
int calcpivot(int st, int dr){
    return st + rand() * 1LL * rand() % (dr - st + 1);
}
void quicksort(int st, int dr){
    if(st >= dr){
        return;
    }
    if(dr - st < maxquick){
        for(int i = st; i < dr; i++){
            for(int j = i + 1; j <= dr; j++){
                if(v[j] < v[i]){
                    swap(v[i], v[j]);
                }
            }
        }
        return;
    }
    int p, u, pivot;
    p = st;
    u = dr;
    pivot = calcpivot(st, dr);
    pivot = v[pivot];
    while(p <= u){
        while(p <= u && v[p] <= pivot){
            p++;
        }
        while(p <= u && v[u] > pivot){
            u--;
        }
        if(p > u){
            break;
        }
        swap(v[p], v[u]);
        p++;
        u--;
    }
    p--;
    for(int i = st; i <= p; i++){
        if(v[i] == pivot){
            swap(v[i], v[p]);
            p--;
            i--;
        }
    }
    quicksort(st, p);
    quicksort(u + 1, dr);
}
int main(){
    maxquick = 15;
    srand(time(0));
    fin>> n;
    for(i = 1; i <= n; i++){
        fin>> v[i];
    }
    quicksort(1, n);
    for(i = 1; i <= n; i++){
        fout<< v[i] <<" ";
    }
}
