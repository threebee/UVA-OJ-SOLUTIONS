#include<cstdio>
#include<stack>
#include<queue>
#include<iostream>
using namespace std;

int main()
{
    stack <int> s;
    queue <int> q;
    priority_queue <int> pq;

    int sc,qc,pqc,flag,x,n,counter;

    while(scanf("%d",&n))
    {
        sc=qc=pqc=counter=0;

        while (!s.empty())         s.pop();
        while (!q.empty())         q.pop();
        while (!pq.empty())        pq.pop();

        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&flag,&x);
            if(flag==1)
            {
                s.push(x);
                q.push(x);
                pq.push(x);
            }
            else
            {
                counter++;
                if(x==s.top())
                sc++;
                if(x==q.front())
                qc++;
                if(x==pq.top())
                pqc++;
                s.pop();
                q.pop();
                pq.pop();
            }
        }

        if(sc==0 && qc==0 && pqc==0)
            printf("impossible\n");
        if(sc==counter && qc!=counter && pqc!=counter)
            printf("stack\n");
        if(sc!=counter && qc==counter && pqc!=counter)
            printf("queue\n");
        if(sc!=counter && qc!=counter && pqc==counter)
            printf("priority queue\n");
        if((sc==counter && qc==counter && pqc!=counter) || (sc==counter && qc!=counter && pqc==counter) || (sc!=counter && qc==counter && pqc==counter) || (sc==counter && qc==counter && pqc==counter))
            printf("not sure\n");

    }

   return 0;
}
