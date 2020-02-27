

# 队列的定义

- 队列（quene）定义：只允许在一端进行插入操作，而在另一端进行删除操作的线性表

  - 队列是一种先进先出（First In First Out）的线性表，简称FIFO

  - 允许插入的一端称为队尾，允许删除的一端称为队头

    <img src="pic/912ef9daf11bac4a02434d5acd85946d.png" style="zoom:38%;" />

# 队列的抽象数据类型

<img src="pic/81f47d10f451cd3e1ad8b04011f4eb15.png" style="zoom: 50%;" />

# 循环队列

- 顺序存储入列：在队尾追加一个元素，不需要移动任何元素，时间复杂度为O(1)

  <img src="pic/766c51a97eaf41b4c1c35877abffb199.png" style="zoom:38%;" />

- 顺序存储出列：队列中的所有元素都得向前移动，时间复杂度为O(n)

  <img src="pic/6dd8a78c9e47acb365996d1f7773ed45.png" style="zoom:38%;" />

- 引入两个指针，front指针指向队头元素，rear指针指向队尾元素的下一位置

  <img src="pic/6bf6873502633c959bf8a6bdf7995a8f.png" style="zoom:38%;" />

- 有一种情况是font在数组3的位置，再插入元素时，rear向后移，溢出了，称为假溢出，因为front前面还有空间

- 循环队列：队列的头尾相接的顺序存储结构

  <img src="pic/522553b101c254e9a5799c8fa793df97.png" style="zoom:38%;" />

- 循环队列的顺序存储结构代码

  <img src="pic/4d11b27afdf916ebdcbaf7298195d809.png" style="zoom:38%;" />

 

# 队列的链式存储结构及实现

- 队列的链式存储结构：其实就是线性表的单链表，只不过它只能尾进头出，简称链队列

  - 队头指针指向链队列的头结点，而队尾指针指向终端结点

    <img src="pic/346bcfe921e36a554f09b046e6ad06fd.png" style="zoom:38%;" />

- 空队列时，front和rear都指向头结点

  <img src="pic/0e83710a0ff3af822da36be81f5ffabf.png" style="zoom:38%;" />

- 链队列的结构

  <img src="pic/0fd6e999daaf4e61bc5a5611a0246383.png" style="zoom:38%;" />

- 入队操作

  <img src="pic/32d581292e0fe573db83d83ad98d674f.png" style="zoom:38%;" />

  <img src="pic/b6134a904b6ebaa549a4bff5941ba4de.png" style="zoom:38%;" />

- 出队操作

  <img src="pic/f344d520abd57e742a92d21f3e7d939d.png" style="zoom: 50%;" />

  <img src="pic/86f97bb4ac0709b7f30caa5e786088a7.png" style="zoom:38%;" />

-   循环队列与链队列的比较

    -   时间上都是O(1)，不过循环队列（顺序结构）是事先申请好空间，使用期间不释放，而对于链队列，每次申请和释放结点

    -   空间上，循环队列必须有一个固定的长度，所以就有了存储元素个数和空间浪费的问题，而链队列不存在这个问题，尽管需要一个指针域，会产生一些空间上的开销

**总结回顾**

- 栈和队列都是特殊的线性表

  -   栈（stack）是限定仅在表尾进行插入和删除操作的线性表

  -   队列（quene）是只允许在一端进行插入操作，而在另一端进行删除操作的线性表

- 对于栈来说，如果是两个相同数据类型的栈，则可以用数组的两端作栈顶的方法来让两个栈共享数据，可以最大化地利用数组的空间

- 对于队列来说，为了避免数组插入和删除时需要移动数据，于是引入了循环队列，使得队头和队尾可以在数组中循环变化：解决了移动数据的时间损耗，使得本来插入和删除时O(n)的时间复杂度变成了O(1)

  <img src="pic/ec0c19f5f06fc7a2cc1480ecff0881b2.png" alt="ec0c19f5f06fc7a2cc1480ecff0881b2" style="zoom:38%;" />
