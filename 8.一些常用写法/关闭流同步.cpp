
    ios::sync_with_stdio(false);
    int a;
    cin>>a;
    cout<<a;
//   其实默认的时候，cin与stdin总是保持同步的，也就是说这两种方法可以混用，而不必担心文件指针混乱，
//	同时cout和stdout也一样，两者混用不会输出顺序错乱。正因为这个兼容性的特性，导致cin有许多额外的
//	开销，关闭流同步以提高cin、cout速度,这时就不能再用scanf和printf了 

//由于getchar()比scanf()还快一点 
int read()
{
	char ch=getchar();int x=0,f=1;
	while(ch<'0' || ch>'9'){//若ch不是数字字符，则读取到数字字符为止，数据必须要有数字字符 
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

