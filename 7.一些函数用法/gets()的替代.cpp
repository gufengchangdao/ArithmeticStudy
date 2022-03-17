
cin.getline(a, num, c);
cin.getline(a,num); 
使用 iostream 库中的cin.getline函数代替gets
  读入一行（可含空格），直到换行符结束
  将其前num-1个字符存入数组a中并以字符c结尾 
1、也可以不传入第三个参数c，则默认 '\0' 结尾
2、若num大于所读入的字符数，则直接存入整行字符串，再在末尾加入字符c结尾
