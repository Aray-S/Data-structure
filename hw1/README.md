# Problem 1
在单链表类中增加一个功能erase(x, y), 删除表中所有值在 [x, y] 之间的结点。假设链表中结点数值类型是整形，要求编程返回删除相应结点后的链表长度和链表元素。
并分析该程序的时间复杂度和空间复杂度。

**输入描述**<br/>
第一行输入链表List的结点元素值，元素之间用空格间隔，且均为int类型；<br/>
第二行输入为x和y，分别表示需要删除结点元素的最小值和最大值。

**输出描述**<br/>
第一行输出删除相应结点后链表的长度；<br/>
第二行输出删除相应结点后链表的所有元素，元素之间用空格间隔。

**输入举例**
10 2 71 8 4 35<br/>
0 5

**输出举例**
4<br/>
10 71 8 35

# Problem 2
假定用带头结点的单链表保存单词，当两个单词有相同的后缀时，则可以共享后缀存储空间。要求编程找出两个单词共同后缀的起始位置，并输出共同后缀的值（两个单词均不为空值）。
并分析该程序的时间复杂度和空间复杂度。

**输入描述**<br/>
第一行输入第一个单词；<br/>
第二行输入第二个单词。

**输出描述**<br/>
第一行输出共同后缀的值（不是共同后缀的长度），若不存在共同后缀请输出空行。<br/>

**输入举例**<br/>
loading<br/>
being

**输出举例**<br/>
ing

# Problem 3
编程实现中缀算术表达式转后缀算术表达式。(注：先要对算术表达式进行符号平衡检查）

**输入描述**<br/>
第一行输入中缀算数表达式，数字均为int类型，运算符只考虑加减乘除四则运算和小括号，不考虑int中的负数。

**输出描述**<br/>
第一行输出后缀算数表达式。

**输入举例**<br/>
5*(7-2*3)+10/4

**输出举例**<br/>
5 7 2 3 * - * 10 4 / +
