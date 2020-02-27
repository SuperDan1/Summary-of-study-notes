<center><font size=10 color='gray'>第五章 支持向量机</fontfont></center>
[TOC]

# 线性可分支持向量机与硬间隔最大化
> 支持向量机(support vector machines, SVM)是一种二类分类模型。基本模型是定义在特征空间上的间隔最大的线性分类器；还包括核技巧，这使它成为实质上的非线性分类器。
>
> 支持向量机的学习策略就是间隔最大化，可形式化为一个求解凸二次规划(convex quadratic programming)的问题，也等价于正则化的合页损失函数的最小化问题。

## 线性可分支持向量机

* 考虑一个二类分类问题，假设输入空间与特征空间为两个不同的空间。输入空间为欧式空间或离散集合，特征空间为欧式空间或希尔伯特空间

  * 线性可分支持向量机、线性支持向量机假设这两个空间的元素一一对应，并将输入空间中的输入映射为特征空间中的特征向量
  * 非线性支持向量机利用一个从输入空间到特征空间的非线性映射将输入映射为特征向量

  **结论**：输入都由输入空间转换到特征空间，支持向量机的学习是在特征空间进行的。

* **TODO**：欧式空间和希尔伯特空间

* 当训练数据集线性可分时，存在无穷个分离超平面可将两类数据正确分开

  * 感知机利用误分类最小的策略，求得分离超平面，不过这时的解有无穷多个
  * 线性可分支持向量机利用间隔最大化求最优分离超平面，这时解是唯一的

* 函数间隔（functional margin）：对于给定的训练数据集$T$和超平面$(\omega,b)$，定义超平面$(\omega,b)$关于样本点$(x_i,y_i)$的函数间隔为
    $$
    \mathop \gamma \limits^ \wedge   = {y_i}(\omega  \cdot {x_i} + b)
    $$
    定义超平面$(\omega,b)$关于训练数据集$T$的函数间隔为超平面$(\omega,b)$关于$T$中所有样本点$(x_i,y_i)$的函数间隔之最小值，$\mathop \gamma \limits^ \wedge   = \mathop {\min }\limits_{i = 1, \cdots ,N} \mathop {\gamma_i}\limits^ \wedge$

    * 一般来说，一个点距离分离超平面的远近可以表示分类预测的确信程度：在超平面$\omega  \cdot x + b = 0$确定的情况下，$\left| {\omega  \cdot x + b} \right|$能够相对地表示点$x$距离超平面的远近
    * $\omega  \cdot x + b$的符号与类标记$y$的的符号是否一致能够表示分类是否正确。所以可以用$y(\omega  \cdot x + b)$表示分类的正确性及确信度

* 几何间隔（geometric margin）：对于给定的训练数据集$T$和超平面$(\omega,b)$，定义超平面$(\omega,b)$关于样本点$(x_i,y_i)$的几何间隔为$\mathop \gamma= {y_i}(\frac{\omega}{\left\| \omega  \right\|}  \cdot {x_i} + \frac{b}{\left\| \omega  \right\|})$，定义超平面$(\omega,b)$关于训练数据集$T$的几何间隔为超平面$(\omega,b)$关于$T$中所有样本点$(x_i,y_i)$的几何间隔之最小值
    $$
    \mathop \gamma= \mathop {\min }\limits_{i = 1, \cdots ,N} \mathop {\gamma_i}=\frac{\mathop \gamma \limits^ \wedge}{\left\| \omega  \right\|}
    $$

    * 函数间隔可以表示分类预测的正确性及确信度，但是选择超平面时，只要成比例地改变$\omega$和$b$，超平面并没有改变，但函数间隔却成比例改变
    * 所以对分离超平面的法向量$\omega$加某些约束——规范化使得$\left\| \omega  \right\|=1$，使得间隔是确定的
    * 超平面$(\omega,b)$关于样本点$(x_i,y_i)$的几何间隔是实例点到超平面的带符号的距离，当样本点被超平面正确分类时就是实例点到超平面的距离
    ![d5927dbc75d7198e04a4b10226020191.png](pic/Image.png)

## 间隔最大化
* 支持向量机学习的基本思想是求解能够正确划分训练集并且**几何间隔最大**的分离超平面
    * 对线性可分的训练数据集而言，线性可分分离超平面有无穷多个（**等价于感知机**）
    * 但是几何间隔最大（硬间隔最大）的分离超平面是**唯一**的
    * 间隔最大化：对训练数据集找到几何间隔最大的超平面意味着以**充分大的确信度**对训练数据进行分类
        * 将正负实例点分开
        * 对最难分的实例点（离超平面最近的点）也有足够大的确信度将它们分开
        * 这样的超平面对未知的新实例有很好的分类预测能力

* 最大间隔分离超平面：求得一个几何间隔最大的分离超平面——最大间隔分离超平面
    * 可以表示为如下的**约束最优化**问题
$\begin{array}{l}
\mathop {\max }\limits_{\omega ,b} \gamma \\
s.t.{y_i}(\frac{\omega }{\left\| w \right\|} \cdot {x_i} + \frac{b}{\left\| w \right\|}) \ge \gamma ,i = 1,2, \cdots ,N
\end{array}$
    * 考虑几何间隔和函数间隔的关系，上式可以改写为
    $\begin{array}{l}
\mathop {\max }\limits_{\omega ,b} \frac{\mathop \gamma \limits^ \wedge  }{\left\| w \right\|}\\
s.t.{y_i}(\omega  \cdot {x_i} + b) \ge \mathop \gamma \limits^ \wedge  ,i = 1,2, \cdots ,N
\end{array}$
    * 函数间隔${\mathop \gamma \limits^ \wedge}$的取值并不影响最优化问题的解，所以取${\mathop \gamma \limits^ \wedge}=1$，同时**注意**最大化$\frac{1}{\left\| w \right\|}$和最小化$\frac{1}{2}{\left\| w \right\|^2}$是等价的，所以上式可以改写为**凸二次规划**（convex quadratic programming）
    $\begin{array}{l}
\mathop {\min }\limits_{\omega ,b} \frac{1}{2}{\left\| w \right\|^2}\\
s.t.&{y_i}(\omega  \cdot {x_i} + b) - 1 \ge 0 ,i = 1,2, \cdots ,N
\end{array}$
    * 求得最优解${\omega ^*},{b^*}$，得到最大间隔分离超平面${\omega ^*} \cdot x + {b^*} = 0$及分类决策函数$f(x) = sign({\omega ^*} \cdot x + {b^*})$
    
* **凸优化问题**是指约束最优化问题
$\begin{array}{l}
\mathop {\min }\limits_\omega  f(\omega )\\
s.t.&{g_i}(\omega ) \le 0,i = 1,2, \cdots ,k\\
&{h_i}(\omega ) = 0,i = 1,2, \cdots ,l
\end{array}$
    * 目标函数$f(\omega)$和约束函数$g_i(\omega)$都是${\Re ^n}$上的**连续可微**的凸函数，约束函数$h_i(\omega)$是${\Re ^n}$上的仿射函数
    * 当目标函数$f(\omega)$是二次函数且约束函数$g_i(\omega)$是仿射函数时，上述凸优化问题成为凸二次规划问题
  
* 最大间隔分离超平面的存在唯一性：TODO

* 支持向量和间隔边界
    * 在线性可分情况下，训练数据集的样本点中与分离超平面距离最近的样本点的实例称为支持向量（support vector）——${y_i}(\omega  \cdot {x_i} + b) - 1 = 0$
    * 对$y_i=+1$的正例点，支持向量在超平面${H_1}:\omega  \cdot x + b = 1$上
    * 对$y_i=-1$的负例点，支持向量在超平面${H_1}:\omega  \cdot x + b = -1$上
        * 在$H_1$和$H_2$之间形成一条长带，分离超平面与它们平行且位于它们中央
        * 长带的宽度：$H_1$和$H_2$之间的距离称为间隔（margin），大小等于$\frac{2}{\left\| \omega  \right\|}$
    * 在决定分离超平面时只有支持向量起作用，而其他实例点并不起作用；如果移动支持向量将改变所求的解；但是如果在间隔边界以外移动其他实例点，甚至去掉这些点，则解是不会改变的

## 学习的对偶算法

​        

# 线性支持向量机与软间隔最大化
TODO
# 非线性支持向量机与核函数

# 序列最小最优化算法