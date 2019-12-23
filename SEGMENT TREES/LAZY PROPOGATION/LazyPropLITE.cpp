#include<bits/stdc++.h>
using namespace std;
mt19937 g;
const int N=102400,gmid=g.max()>>1,p=1e9+7,d6=(p+1)/6;
char o[N];
int a[N],x[N],y[N],n,q;

typedef struct node *tree;
struct node{
    tree c[2];
    unsigned pri,tot,live;
    void update(){tot=c[0]->tot+c[1]->tot+live;}
} nil[N<<1];
tree px[N],py[N],mem=nil;

tree new_node(unsigned p=0){
    ++mem;
    mem->c[0]=mem->c[1]=nil;
    mem->pri=p?p:g();
    mem->live=mem->tot=1;
    return mem;
}
tree init(int l,int r,int p){
    if(l==r)return new_node(p);
    int m=l+r+1>>1;
    tree lc,me;
    lc=init(l,m-1,p-g()/18);
    me=new_node(p);
    me->tot=r-l+1;
    me->live=1;
    me->c[0]=lc;
    me->c[1]=m<r?init(m+1,r,p-g()/18):nil;
    return me;
}
tree to(tree a,int k){
    for(int t;k;){
        t=a->c[0]->tot;
        if(t>=k)a=a->c[0];
        else{
            k-=t+a->live;
            if(!k)return a;
            a=a->c[1];
        }
    }
}
tree lazydel(tree a,int k){
    for(int t;k;){
        --a->tot;
        t=a->c[0]->tot;
        if(t>=k)a=a->c[0];
        else{
            k-=t+a->live;
            if(!k){a->live=0;return a;}
            a=a->c[1];
        }
    }
}
tree insert(tree a,int k){
    static vector<tree> q(256);
    q.clear();
    for(int t;;){
        q.push_back(a);
        ++a->tot;
        t=a->c[0]->tot;
        if(t==k && !a->live){
            a->live=1;
            return a;
        }
        bool r=t<k;
        if(r)k-=t+a->live;
        if(a->c[r]!=nil)a=a->c[r];
        else {
            q.push_back(a=a->c[r]=new_node(g()));
            break;
        }
    }
    for(a=q.back(),q.pop_back();
    q.size() && q.back()->pri < a->pri;){
        tree b=q.back();q.pop_back();
        k=(b->c[1]==a);
        b->c[k]=a->c[!k]; b->update();
        a->c[!k]=b; a->update();
        if(q.size())q.back()->c[q.back()->c[1]==b]=a;
    }
    return a;
}

void dfs(tree u){
    static int k=0;
    if(u==nil)return;
    dfs(u->c[0]);
    u->pri=++k;
    dfs(u->c[1]);
}

typedef long long ll;

struct Tr{
    ll S1,S2,S3;
    int cc;
} T[N<<1];
ll S1,S2,S3;int cc;
void inc(Tr&a){a.S1+=S1;a.S2+=S2;a.S3+=S3;a.cc+=cc;}
void collect(Tr&x){S1+=x.S1;S2+=x.S2;S3+=x.S3;}
int U;
set<pair<int,int>> v={{-p,-p},{p+10,p+10}};
int A[N<<1];
pair<pair<int,int>,int> query[N<<3]; int cnt;
vector<pair<int,int>> pos;
void add(int L,int R){
    query[cnt++]={{L,R},(int)S1};
}
void in(int k,int x){
    assert(x>=1 && x<p);
    S1=A[k]=x;S2=S1*x%p;S3=S2*x%p;cc=1;
    auto it=v.insert({x,k}).first,prev=it,succ=it;
    --prev;++succ;
    if(prev->first==x)add(prev->second,k);
    if(succ->first==x)add(k,succ->second);
    for(;k<=U;k+=k&-k)inc(T[k]);
    S1=-S1;
    if(prev->first==succ->first)add(prev->second,succ->second);
}
void out(int k){
    int x=A[k];A[k]=0;
    assert(x);
    auto it=v.find({x,k}),prev=it,succ=it;
    --prev;++succ;
    S1=-x;S2=S1*x%p;S3=S2*x%p;cc=-1;
    if(succ->first==x)add(k,succ->second);
    if(prev->first==x)add(prev->second,k);
    for(;k<=U;k+=k&-k)inc(T[k]);
    S1=-S1;
    if(succ->first==prev->first)add(prev->second,succ->second);
    v.erase(it);
}

int q1[N],q2[N],q3[N];
vector<pair<int,int>> qq;

void bf(){
    map<pair<int,int>,int> z;
    int j=0;
    for(auto pr:qq){
        for(;j<pr.second;++j){
            auto& t=query[j];
            if(t.second>0)z.insert(t);
            else z.erase(t.first);
        }
        int i=pr.first;
        auto it=z.lower_bound({x[i],x[i]}),
            et=z.upper_bound({y[i],y[i]});
        if(o[i]=='5'){
            int res=q1[i];
            for(;it!=et;++it)if(it->first.second<=y[i])--res;
            printf("%d\n",res);
        }else{
            S1=q1[i];S2=q2[i];S3=q3[i];
            for(;it!=et;++it)if(it->first.second<=y[i]){
                ll t=it->second,s=t*t%p;
                S1-=t;S2-=s;S3-=s*t%p;
            }
            S1%=p;
            printf("%d\n",(int)(((S3*2+(S1*S1-S2*3)%p*S1)%p*d6%p+p)%p));
        }
    }
}

Tr Mt[1<<22];
int Mz[1<<22];int mc=0;
struct zz{
    Tr* s;int *rs;int sz=0;
    void reg(){s=Mt+mc-1;rs=Mz+mc-1;}
    void push(int x){Mz[mc++]=x;sz++;}
} X[1<<19];
int V;
void build3(int k,int l,int r){
    static size_t i =0;
    zz& O=X[k];
    if(l+1==r){
        O.reg();
        for(;i<pos.size() && pos[i].first==l;)
            O.push(pos[i++].second);
        sort(O.rs+1,O.rs+1+O.sz);
        return;
    }
    int m=l+r>>1;
    build3(k<<1,l,m);
    build3(k<<1|1,m,r);
    O.reg();
    int *li=X[k<<1].rs+1,*ri=X[k<<1|1].rs+1,
        *le=li+X[k<<1].sz,*re=ri+X[k<<1|1].sz;
    for(int t;li!=le && ri!=re;){
        t=min(*li,*ri);
        O.push(t);
        for(;li!=le && t==*li;)li++;
        for(;ri!=re && t==*ri;)ri++;
    }
    for(;li!=le;)O.push(*li++);
    for(;ri!=re;)O.push(*ri++);
}
void add2(int L,int R,int x){
    S1=x;cc=x>0?1:-1;
    x=abs(x);S2=S1*x%p;S3=S2*x%p;
    for(int k=1,l=0,r=V;;){
        auto& z=X[k];
        int i=lower_bound(z.rs+1,z.rs+z.sz+1,R)-z.rs;
        for(;i<=z.sz;i+=i&-i)inc(z.s[i]);
        if(l+1==r)break;
        int m=l+r>>1;
        k<<=1;
        if(L<m)r=m;else{l=m;k|=1;}
    }
}
int L,R;
void ask1(int k,int l,int r){
    if(l>=L && r<=R+1){
        auto& z=X[k];
        int i=upper_bound(z.rs+1,z.rs+z.sz+1,R)-z.rs-1;
        for(;i;i^=i&-i)collect(z.s[i]);
        return;
    }
    int m=l+r>>1;
    if(m>L)ask1(k<<1,l,m);
    if(m<=R)ask1(k<<1|1,m,r);
}
void ask5(int k,int l,int r){
    if(l>=L && r<=R+1){
        auto& z=X[k];
        int i=upper_bound(z.rs+1,z.rs+z.sz+1,R)-z.rs-1;
        for(;i;i^=i&-i)cc+=z.s[i].cc;
        return;
    }
    int m=l+r>>1;
    if(m>L)ask5(k<<1,l,m);
    if(m<=R)ask5(k<<1|1,m,r);
}
vector<int> dis;
void diss(int&x){
    x=lower_bound(dis.begin(),dis.end(),x)-dis.begin();
}
void gao(){
    if(!dis.size())return;
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    V=dis.size()+1;
    cnt=qq.back().second;
    for(int j=0;j<cnt;++j){
        diss(query[j].first.first);
        diss(query[j].first.second);
        if(query[j].second>0)pos.push_back(query[j].first);
    }
    sort(pos.begin(),pos.end());
    pos.erase(unique(pos.begin(),pos.end()),pos.end());
    build3(1,0,V);
    int j=0;
    for(auto pr:qq){
        for(;j<pr.second;++j)
            add2(query[j].first.first,query[j].first.second,query[j].second);
        int i=pr.first;
        L=x[i];R=y[i];
        diss(L);diss(R);
        if(o[i]=='5'){
            cc=0;
            ask5(1,0,V);
            //printf("!5 %d\n",cc);
            printf("%d\n",q1[i]-cc);
        }else{
            S1=0;S2=0;S3=0;
            ask1(1,0,V);
            //printf("!1 %d %d %d\n",S1,S2,S3);
            S1=(q1[i]-S1)%p;
            S2=q2[i]-S2;
            S3=q3[i]-S3;
            printf("%d\n",(int)(((S3*2+(S1*S1-S2*3)%p*S1)%p*d6%p+p)%p));
        }
    }
}

int main(){
    nil->c[0]=nil->c[1]=nil;
    nil->pri=nil->tot=nil->live=0;
	string x;
	cin>>x;
    tree root=init(1,n,g.max());
    for(int i=1;i<=x.length();++i)a[i]=x[i]-'a';
	cin>>q;
    for(int i=0;i<q;++i)
	{
        scanf(" %c%d",o[i],x[i]);
        if(o[i]!='3')scanf("%d",y+i);
        switch (o[i]) {
            case '1':
            case '5':
                py[i]=to(root,y[i]);
            case '2':
                px[i]=to(root,x[i]);
                break;
            case '3':
                px[i]=lazydel(root,x[i]);
                break;
            case '4':
                px[i]=insert(root,x[i]);
        }
    }
    dfs(root);
    for(int i=0;i<q;++i)switch (o[i]) {
        case '1':case '5':
            y[i]=py[i]->pri;
        case '3':case '2':case '4':
            x[i]=px[i]->pri;
    }
    U=mem-nil;
    for(int i=1;i<=n;++i)in(nil[i].pri,a[i]);
    for(int i=0;i<q;++i)
    switch (o[i]) {
        case '1':{
            S1=S2=S3=0;
            for(int k=x[i]-1;k;k^=k&-k)collect(T[k]);
            S1=-S1;S2=-S2;S3=-S3;
            for(int k=y[i];k;k^= k&-k)collect(T[k]);
            q1[i]=S1%p;q2[i]=S2%p;q3[i]=S3%p;
            qq.push_back({i,cnt});
            dis.push_back(x[i]-1);
            dis.push_back(y[i]);
            break;
        }
        case '2':
            out(x[i]);
            in(x[i],y[i]);
            break;
        case '3':
            out(x[i]);
            break;
        case '4':{
            in(x[i],y[i]);
            break;
        }
        case '5':{
            cc=0;
            for(int k=y[i];k;k^= k&-k)cc+=T[k].cc;
            for(int k=x[i]-1;k;k^=k&-k)cc-=T[k].cc;
            q1[i]=cc;
            qq.push_back({i,cnt});
            dis.push_back(x[i]-1);
            dis.push_back(y[i]);
        }
    }
    gao();
}
