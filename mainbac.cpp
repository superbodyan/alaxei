//Valevich Alyaxey
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
void reduce(int &N, int **&t, int &I,int &J, int * &m)
{
    --t[I][J];
    if((I-1)>=0)--t[I-1][J];
    if((I+1)<N)--t[I+1][J];
    int M=m[J];
    if((J-1)>=0)--t[I][J-1];
    if((J+1)<M)--t[I][J+1];
}
bool check(int** p, int nn, int* mm)
{
   unsigned long long int summ = 0;

    for (int i = 0; i != nn; i++) {
        for (int j = 0; j != mm[i]; j++) {
            summ += p[i][j];
        }
    }
    if (summ == 0) {
  cout << "GRATULACJE";
        return true;
    }
        
    
    return false;
}
int main()
{
    char input;
    int n, x, y;
    cin >> n;
    int** p = (int**)malloc(n * sizeof(int*));
    int* m = (int*)malloc(n * sizeof(int));

    for (int i = 0; i != n; i++) {
        cin >> m[i];
        p[i] = (int*)malloc(m[i] * sizeof(int));
        for (int j = 0; j != m[i]; j++) {
            cin >> p[i][j];
        }
    }
    cout << "\n";
    for (int i = 0; i != n; i++) {
        for (int j = 0; j != m[i]; j++) {
            cout << p[i][j] << " ";
        }
        cout << "\n";
    }
    cin >> x >> y;
    reduce(n, p, x,y,m);
                  
  
   
    if (!check(p,n,m) )
        while (!check(p,n,m)) {
            cin >> input;

            switch (input) {
            
                
                
                
                
                
                
                
                
                
                case 'D': {  --x;
             
                  reduce(n, p, x,y,m);
              
                cout << "\n";
                break;
            }
            case 'U': {    ++x;
                  reduce(n, p, x,y,m);
                cout << "\n";
                break;
            }
            case 'L': {
                --y;
                 reduce(n, p, x,y,m);
               
                cout << "\n";
                break;
            }
            case 'R': { ++y;
                  reduce(n, p, x,y,m);
               
                cout << "\n";
                break;
            }
            case 'S': {
            //    cout << "\n";
                for (int i = 0; i != n;++i) {
                    for (int j = 0; j != m[i]; ++j) {
                        if (p[i][j] > 0) {
                            cout << p[i][j] << " ";
                        }
                    }
                    cout << "\n";
                }
                break;
            }
           
            case 'P': { // for testing
               cout << x << " " << y; // show position
              cout << "\n";
                break;
            }

            case 'Q': {
                goto L;
            }
            }

          
        }
    
    L:
    for (int i = 0; i != n; i++) {
        free(p[i]);
    }
    free(p);
        free(m);

        return 0;
}
