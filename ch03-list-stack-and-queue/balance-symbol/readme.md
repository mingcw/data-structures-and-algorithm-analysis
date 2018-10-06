# 栈的应用：平衡符号

编译器经常对源代码里的「括号」做配对检查。例如`([{}])`是一个合法闭合的字符串，而`([)]`没有严格闭合。

利用栈可以轻松地实现此算法。

## 算法思路

做一个空栈。依次读入字符直到文件尾。当遇到一个开放符号时，将其压入栈里。当遇到一个闭合符号时，如果栈空则报错；否则，将栈元素弹出。如果弹出的符号不是对应的开放符号，则报错。当读到文件尾时，如果栈非空则报错。

>运行时间：O(N)