#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int n, i, k;
int v[10000005], hp[10000005];
ifstream fin("sortare.in");
ofstream fout("sortare.out");
void addheap(int x){
    hp[++k] = x;
    int c = k, p = c / 2;
    while(p > 0 && hp[p] > hp[c]){
        swap(hp[p], hp[c]);
        c = p;
        p = c / 2;
    }
}
void removeheap(){
    int p = 1, c = 2;
    while(c <= k){
        if(c + 1 <= k && hp[c + 1] < hp[c]){
            c++;
        }
        if(hp[c] < hp[p]){
            swap(hp[p], hp[c]);
            p = c;
            c *= 2;
        }
        else{
            break;
        }
    }
}
void heapsort(){
    for(int i = 1; i <= n; i++){
        addheap(v[i]);
    }
    for(i = 1; i <= n; i++){
        v[i] = hp[1];
        swap(hp[1], hp[k]);
        k--;
        removeheap();
    }
}
int main(){
    fin>> n;
    for(i = 1; i <= n; i++){
        fin>> v[i];
    }
    heapsort();
    for(i = 1; i <= n; i++){
        fout<< v[i] <<" ";
    }
}
