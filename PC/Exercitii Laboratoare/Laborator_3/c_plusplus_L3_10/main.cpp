#include <iostream>
#include <fstream>

//COMPLETA

using namespace std;

struct cangur
{
  unsigned short int greutate; //2^16 , 65.000 - 10.000
  int x, y, salt;
}lista[100000];

unsigned short int celule[100000];

int main()
{
    //cout<<sizeof(int)*3+sizeof(short int);
    //vs
    //cout<<sizeof(cangur);
    ifstream d("date.in");
    int N, M;
    d>>N>>M;

    for(int i=1;i<=M;i++)
    {
        d>>lista[i].x>>lista[i].y>>lista[i].salt>>lista[i].greutate;

        //solutia banala si lenta.
        int f=(lista[i].y-lista[i].x)/lista[i].salt;

        for(int j=0;j<=f;j++)
        celule[lista[i].x+j*lista[i].salt]+=lista[i].greutate;
    }

    for(int i=1;i<=N;i++)
        cout<<celule[i]<<" ";
    //cout<<sizeof(lista)+sizeof(celule)+sizeof(N)+sizeof(M)<<"/"<<"100.000.000 Bytes";

    d.close();
    return 0;
}
