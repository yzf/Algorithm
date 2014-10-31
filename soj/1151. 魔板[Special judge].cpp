#include <cstdio>
#include <iostream>

using namespace std;

char  hash[ 1 << 24 ]; // hash[i]=�õ�״̬i���õĲ���

inline  int  A( int  n) 
{ 
    return  (n & 4095 ) << 12 | n >> 12 ;
} // 4095=2^12-1

inline  int  B( int  n) 
{ 
    return  (( 7 << 9 | 7 << 21 ) & n) >> 9   |  ( ~ ( 7 << 9 | 7 << 21 ) & n) << 3 ;
}

inline  int  C( int  n) 
{ 
    return  ( 7 | 7 << 9 | 7 << 12 | 7 << 21 ) & n  |  (( 7 << 3 ) & n) << 3   |  (( 7 << 6 ) & n) << 12   |  (( 7 << 18 ) & n) >> 3   |  (( 7 << 15 ) & n) >> 12 ;
}

inline  int  zip( int  a[]) 
{ // ���ڽ�8����ѹ��Ϊ1��С��2^24(Լ1670��)������
    int  s = 0 ;
    for ( int  i = 0 ;i < 8 ; ++ i) s |= (a[i] - 1 ) << ( 3 * i);
    return  s;
}

int  a[] = { 1 , 2 , 3 , 4 , 8 , 7 , 6 , 5 } ; // ��ʼ״̬
const   int  QLen = 10000 ; // ���г���
int  q[QLen],b = 0 ,e = 0 ; // ѭ�����м��ס�βָ��
inline  void  inc( int &  p){ if(++ p ==QLen) p=0;} //�����ƶ�������βָ��

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
    int i,j,n,bgn=zip(a);//bgn�ǳ�ʼ״̬��ѹ����
    hash[bgn]='E';
    q[b]=bgn; inc(b);
    while(b!=e)
    {
        i=q[e]; inc(e);//ȡ����
        j=A(i);
        if(!hash[j]) hash[j]='A', q[b]=j, inc(b);
        j=B(i);
        if(!hash[j]) hash[j]='B', q[b]=j, inc(b);
        j=C(i);
        if(!hash[j]) hash[j]='C', q[b]=j, inc(b);
    }
    char s[1000];//s[]���ڱ������ɵĲ�������
    while(scanf("%d",&n),n!=-1)
    {
        for(i=0; i<8; ++i) scanf("%d",&a[i]);
        for(i=zip(a),j=0; i!=bgn; ++j)
        {
           s[j]=hash[i];
           switch(s[j])
           {
               case 'A': i=A(i);        break;
               case 'B': i=B(B(B(i)));    break;
               case 'C': i=C(C(C(i)));    break;
           }
        }
        if(j>n) 
            printf("-1\n");
        else
        {
            printf("%d ",j);
            while(j--) putchar(s[j]);
            putchar('\n');
        }
    }   
    return 0;
}
