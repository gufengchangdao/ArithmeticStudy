广搜常用于找单一的最短路线，步数未知，或者是规模小的路径搜索，它的特点是"搜到就是最优解"， 
	常用于搜索最短路径 
深搜用于找多个解或者是"步数已知（好比3步就必需达到前提）"的标题，它的空间效率高，然则找到的不必
	定是最优解，必需记实并完成全数搜索，故一般情况下，深搜需要很是高效的剪枝（优化）.
分歧： 
深搜的实现近似于栈，每次选择栈顶元素往下搜索，
广搜则是用了队列，先搜索到的结点先存入并先拿出，故只要找到就是最短。

深搜就是优先搜索一棵子树，然后是另一棵，它和广搜对比，有着内存需要相对较少的所长，八皇后标题就是
	典范楷模的操作，这类标题很显著是不能用广搜往解决的。或者像图论里面的找圈的算法，数的前序中序后序
	遍历等，都是深搜	

搜索树的形态：深搜层数良多，广搜则是很宽。
深搜合适找出所有方案，广搜则用来找出最佳方案	
深搜并不能保证第一次碰着方针点就是最短路径，是以要搜索所有可能的路径，是以要回溯，
	标记了只后回溯的时候还要打消标记，是以统一个点可能被访问良多次。
而广搜因为它的由近及远的结点搜索，结点老是以最短路径被访谒。一个结点假如第一次次被访谒，第二次访
问只会获得更差的解。标记后就不会取消。每访谒一个结点，与它相连的边就被搜检一次。	
