#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include<bits/stdc++.h>
using namespace std;

bool encuentra(vector<int> vec, int elem);
int expo(int x, int y, int p) ;
int raizPrimitiva(int n);
vector<int> FactorP(long long n);

int main(void)
{   
    int limite,n;
    cout << "Ingrese un numero primo: ";
    cin >> n;
    cout << "La menor raiz primitiva de " << n << " es: " << raizPrimitiva(n);
    while (expo(raizPrimitiva(n), limite, n) != 2021) limite++;
   cout <<"\nx = "<< limite;
}

int RaizPrimi(int n){
    bool tem;
    int phi = n - 1;
    vector<int> vec = FactorP(phi);
    for (int i = 2; i < n; i++) {
        if (std::__gcd(i, n) == 1) {
            tem = false;
            for (int j = 0; j < vec.size(); j++){
                if (expo(i, (phi/vec[j]), n) == 1){
                    tem = true;
                    break;}}
            if (!tem)
                return i;
        }
    }
    return -1;
}

bool encuentra(vector<int> vec, int elem)
{
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] == elem)
            return 1;}
    return 0;
}

vector<int> FactorP(long long n) {
    vector<int> res;
    long long tem = 2;
    while (tem * tem <= n) {
        if (n % tem == 0)  {
            if (!encuentra(res, tem))
                res.push_back(tem);
            n /= tem;} 
        else 
          tem++; }
    if (n > 1)  {
        if (!encuentra(res, n))
            res.push_back(n);}
    return res;
}

int expo(int x, int y, int p) 
{
    int tem = 1;
    while (y){
        if (y & 1){
            tem = int (tem * 1ll * x % p);
            --y; }
        else {
            x = int (x * 1ll * x % p);y >>= 1; } }  
    return tem;
}
