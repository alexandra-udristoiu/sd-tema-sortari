#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int n, i, k;
int v[10000005], hp[10000005];
ifstream fin("sortare.in");
ofstream fout("sortare.out");
struct treapnode{
    int val, vp, num;
    treapnode *st, *dr;
    treapnode(int val, int vp, int num, treapnode *st, treapnode *dr){
        this->val = val;
        this->vp = vp;
        this->num = num;
        this->st = st;
        this->dr = dr;
    }
};
treapnode *root, *nil;
void updtreap(treapnode *r){
    r->num = r->st->num + r->dr->num + 1;
}
void rotst(treapnode* &r){
    treapnode *aux = r->st;
    r->st = aux->dr;
    aux->dr = r;
    r = aux;
    updtreap(r->dr);
    updtreap(r);
}
void rotdr(treapnode* &r){
    treapnode *aux = r->dr;
    r->dr = aux->st;
    aux->st = r;
    r = aux;
    updtreap(r->st);
    updtreap(r);
}
void rottreap(treapnode* &r){
    if(r->st->vp > r->vp){
        rotst(r);
    }
    else{
        if(r->dr->vp > r->vp){
            rotdr(r);
        }
    }
}
void addtreap(treapnode* &r, int x){
    if(r == nil){
        r = new treapnode(x, rand() + 1, 1, nil, nil);
    }
    else{
        if(r->val > x){
            addtreap(r->st, x);
        }
        else{
            addtreap(r->dr, x);
        }
        rottreap(r);
        updtreap(r);
    }
}
void solve(treapnode *r, int prev){
    if(r != nil){
        v[prev + r->st->num + 1] = r->val;
        solve(r->st, prev);
        solve(r->dr, prev + r->st->num + 1);
    }
}
void treapsort(){
    srand( time(0) );
    root = nil = new treapnode(0, 0, 0, NULL, NULL);
    for(int i = 1; i <= n; i++){
        addtreap(root, v[i]);
    }
    solve(root, 0);
}
int main(){
    fin>> n;
    for(i = 1; i <= n; i++){
        fin>> v[i];
    }
    treapsort();
    for(i = 1; i <= n; i++){
        fout<< v[i] <<" ";
    }
}
