//快读，读取一个数，可以是负数，返回int型 
inline int read(){
    char chr=getchar(); int f=1,ans=0;
    while(!isdigit(chr)) {if(chr=='-') f=-1;chr=getchar();}
    while(isdigit(chr))  {ans=ans*10;ans+=chr-'0';chr=getchar();}
    return ans*f;
}

ll read()
{
    char c=getchar();ll s=0,f=1;
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())s=s*10+c-48;
    return s*f;
}
