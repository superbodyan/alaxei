

#include <iostream>
#include <cstdlib>

using namespace std;

// ‘ÛÌÍˆ≥ˇ ˘Ó ‚Ë‚Ó‰ËÚ¸ Ú‡·ÎËˆ˛ Ì‡ ÂÍ‡Ì
void vyvod(int N, int *t[]){
    for (int i=0; i<N; ++i){
        int M = t[i][0];
        for(int j=1; j<=M;++j){
            cout << t[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

//ƒÓÔÓÏ≥ÊÌ‡ ÙÛÌÍˆ≥ˇ ˘Ó ˜ËÒÚËÚ¸ Ó‰ÌÓ‚ËÏ≥ÌËÈ macË‚ ‚≥‰ 0
void vydal01(int* &t){
    int M=t[0];
    int j1 = 1;
    for(int j=1;j<=M;++j){
            if(t[j] == 0){
                    --(*t);
            }
            else{
                t[j1]=t[j];
                j1++;
            }
        }

    int M1 = t[0]+1;
    int *t1 = (int*) malloc(M1*sizeof(int));
    for(int i=0;i<M1;i++)t1[i]=t[i];
    free(t);
    t=t1;
}

//‘ÛÌÍˆ≥ˇ ˘Ó ˜ËÒÚËÚ¸ Ï‡ÒË‚ ‚≥‰ 0
void vydal0(int &N,int **&t){
    int N1=N;
    for(int i=0;i<N;i++){
        vydal01(t[i]);
        if(t[i][0]==0){
            --N1;
        }
    }

    int **t1=(int **)malloc(N1*sizeof(int*));
    int i1=0;
    for(int i=0;i<N;i++){
        if(t[i][0]!=0){
            int M = t[i][0];
            t1[i1] = (int*) malloc(M*sizeof(int));
            t1[i1][0]=M;
            for(int j=1;j<=M;++j){
                t1[i1][j]=t[i][j];
            }
            i1++;
        }
    }

    for(int i=0;i<N;i++)
        free(t[i]);
    free(t);

    N=N1;
    t=t1;
}

//‘ÛÌÍˆ≥ˇ Â‰ÛÍˆ≥ø Ì‡‚ÍÓÎÎË¯Ì≥ı ˜ËÒÂÎ ≥ Ó˜ËÒÚÍ‡ Ú‡·ÎËˆ≥ ‚≥‰ 0
void reduce(int &N, int **&t, int &I,int &J)
{
    --t[I][J];
    if((I-1)>=0)--t[I-1][J];
    if((I+1) <N)--t[I+1][J];
    int M=t[I][0];
    if((J-1)>=1)--t[I][J-1];
    if((J+1)<=M)--t[I][J+1];
    vydal0(N,t);
    if(I>=N)--I;
    if(J>(t[I][0]))J=t[I][0];
}

//ÙÛÌÍˆ≥ˇ ˘Ó ‡ıÛ∫ ÒÛÏÛ ‚Ò≥ı ÂÎÂÏÂÌÚ≥‚ ‚ Ú‡·Ëˆ≥
int suma(int &N,int **&t){
    int s=0;
    for(int i=0;i<N;i++){
        for(int j=1;j<=t[i][0];++j){
            s = s+t[i][j];
        }
    }
    return s;
}
// ‰ÓÔÓÏ≥ÊÌ‡ ÙÛÌÍˆ≥ˇ ˇÍ‡ ‰ÓÍÎÂ˛∫ ‚Ò≥ ÂÎÂÏÂÌÚË Ó‰ÌÓø Ú‡·ÎËˆ≥ ‰Ó ‰Û„Óø
void doklej(int *&t1,int *&t2){
    int M  = t1[0]+t2[0];
    int *t11 = (int*) malloc(M*sizeof(int));
    t11[0]=M;
    for(int i=1;i<=t1[0];++i)
        t11[i]=t1[i];
    for(int i=1;i<=t2[0];++i)
        t11[t1[0]+i]=t2[i];
    free(t1);
    t1 = t11;
}

int main (){

    //ÒÚ‚ÓÂÌÌˇ Ú‡·Ëˆ≥ Á‡ ‚‚Â‰ÂÌËÏË ˜ËÒÎ‡ÏË
    int N;
    cin >> N;
    int **t=(int **)malloc(N*sizeof(int*));
    for(int i=0;i<N;++i){
        int M;
        cin >> M;
        t[i] = (int*) malloc(M*sizeof(int));
        t[i][0] = M;
        for(int j=1; j<=M;++j){
            int m;
            cin >> m;
            t[i][j]=m;
        }
    }

    int I,J;
    cin >> I >> J;
    ++J;
    reduce(N,t,I,J);
    int Sum = suma(N,t); //Ó˜Í≥ ˇÍ≥ Ï‡∫ „‡‚Âˆ¸ Ô≥ÒÎˇ ‰‡ÌÓø ÚÛË
    int q = suma(N,t);         // ÒÛÏ‡ ÂÎÂÏÂÌÚ≥‚ Ú‡·ÎËˆ≥

    while (q>1){
        char C;
        cin >> C;
        switch(C){
    case 'U':
        {
        --I;
        reduce(N,t,I,J);
        q = suma(N,t);
        Sum=Sum+q;
        break;
        }
    case 'D':
        {
        ++I;
        reduce(N,t,I,J);
        q = suma(N,t);
        Sum=Sum+q;
        break;
        }
    case 'L':
        {
        --J;
        reduce(N,t,I,J);
        q = suma(N,t);
        Sum=Sum+q;
        break;
        }
    case 'R':
        {
        ++J;
        reduce(N,t,I,J);
        q = suma(N,t);
        Sum=Sum+q;
        break;
        }
    case 'P':
        {
        cout <<"("<<I<<","<<J-1<<")"<<endl;
        break;
        }
    case 'O':
        {
        cout << Sum <<'\n';
        break;
        }
    case 'S':
        {
        vyvod(N,t);
        break;
        }
    case 'A':
        {
        int q1 = suma(N,t);
        doklej(t[I],t[I+1]);
        q = suma(N,t);
        Sum=Sum+q-q1;
        break;
        }
    case 'Q':
        {
        for(int i=0;i<N;i++){
            free(t[i]);
        }
        free(t);
        return 0;
        }
    }

    }
    if(q==1)cout << "PORAZKA"<<endl;
    if(q==0)cout << "GRATULACJE"<<endl <<Sum;

    for(int i=0;i<N;i++){
        free(t[i]);
    }
    free(t);
}
