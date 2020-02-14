<center><font size=10, color='gray'>第四章 朴素贝叶斯法</font></center>
[TOC]

> 朴素贝叶斯(naive Bayes)法是基于**贝叶斯定理**与**特征条件独立假设**的分类方法。对于给定的训练数据集，首先基于特征条件独立假设学习输入\输出的联合概率分布;然后基于此模型，对给定的输入x，利用贝叶斯定理求出后验概率最大的输出y。

# 基本方法

* 设输入空间${\bf{\chi }}\subseteq {\Re ^n}$，为n维向量的集合，输出空间为类标记集合${\cal{Y }} = \{ {c_1},{c_2}, \cdots ,{c_k}\}$；输入为特征向量$x \in {\bf{\chi }}$，输出为类标记$y \in {\cal{Y }}$
    * $P(X,Y)$是X和Y的联合概率分布，其中X是输入空间$\bf{\chi }$上的随机向量，Y是定义在输出空间$\cal{Y}$上的随机变量
    * 训练数据集$T = \{ ({x_1},{y_1}),({x_2},{y_2}), \cdots ,({x_N},{y_N})\}$由$P(X,Y)$独立同分布产生

* 朴素贝叶斯法通过训练数据集**学习联合概率分布**$P(X,Y)$
    * 先验概率分布$P(Y=c_k),k=1,2,\cdots,K$
    
    * 条件概率分布$P(X = x|Y = {c_k}) = P({X^{(1)}} = {x^{(1)}}, \cdots ,{X^{(n)}} = {x^{(n)}}|Y = c)$

* 条件概率分布$P(X=x|Y=c_k)$有指数级数量的参数，其估计是不可行的，因此对条件概率分布作了**条件独立性的假设**
  $$
  \begin{array}{l}
      P(X = x|Y = {c_k}) &= P({X^{(1)}} = {x^{(1)}}, \cdots ,{X^{(n)}} = {x^{(n)}}|Y = c)\\
       &= \prod\limits_{j = 1}^n {P({X^{(j)}} = {x^{(j)}}|Y = {c_k})} 
      \end{array}
  $$
  
* 朴素贝叶斯法实际上学习到生成数据的机制，所以属于**生成模型**，条件独立假设使朴素贝叶斯法变得简单，但有时会牺牲一定的分类准确率
* 朴素贝叶斯分类时
    * 对给定的输入x，通过学习到的模型计算后验概率分布$P(Y=c_k|X=x)$，将后验概率最大的类作为x的类输出
  $$
  P(Y = {c_k}|X = x) = \frac{P(X = x|Y = {c_k})P(Y = {c_k})}{\sum\nolimits_j {P(X = x|Y = {c_j})P(Y = {c_j})} }
  $$
  
    * 将上式代入得到
      $$
  P(Y = c_k|X = x) = \frac{P(Y = c_k)\prod\nolimits_j P(X^{(j)} = x^{(j)}|Y = c_k) } {\sum\nolimits_j P(Y = c_j)\prod\nolimits_l P(X^{(l)} = x^{(l)}|Y = c_j)}  
      $$
    
    * 于是，朴素贝叶斯分类器可表示为
      $$
      y = f(x) = \mathop {\arg \max }\limits_{c_k} \frac{P(Y = {c_k})\prod\nolimits_j P(X^{(j)} = x^{(j)}|Y = c_k) } {\sum\nolimits_j P(Y = c_j)\prod\nolimits_l P(X^{(l)} = x^{(l)}|Y = {c_j})} 
      $$
    
    * 注意，分母对于所有比较式都是一样的，所以可以简化为
      $$
      y = f(x) = \mathop {\arg \max }\limits_{{c_k}} P(Y = {c_k})\prod\nolimits_j {P({X^{(j)}} = {x^{(j)}}|Y = {c_k})}
      $$

# 后验概率最大化的含义
* 朴素贝叶斯将实例分到**后验概率最大**的类中，**等价于期望风险最小化**

  * 假设选择0-1损失函数
    ${L(Y,f(X))}=\left\{ \begin{aligned} 1,Y \ne f(x)  \\ 0,Y = f(x) \end{aligned} \right.$

  * 期望风险函数为 ${R_{\exp }}(f) = E[L(Y,f(X))]$

  * 期望是对联合分布$P(X,Y)$取的，由此取条件期望${R_{\exp }}(f) = E[L({c_k},f(X))]P({c_k}|X)$

  * 为了使期望风险最小化，只需对$X=x$逐个进行最小化，得到
    $$
    \begin{array}{l}
    f(x) &= \mathop {\arg \min }\limits_{y \in Y} \sum\limits_{k = 1}^K {L({c_k},y)P({c_k}|X = x)} \\
     &= \mathop {\arg \min }\limits_{y \in Y} \sum\limits_{k = 1}^K {P(y \ne {c_k}|X = x)} \\
     &= \mathop {\arg \min }\limits_{y \in Y} (1 - P(y = {c_k}|X = x))\\
     &= \mathop {\arg \max }\limits_{y \in Y} P(y = {c_k}|X = x)
    \end{array}
    $$

# 朴素贝叶斯法的参数估计

## 极大似然估计

* 在朴素贝叶斯法中，学习意味着估计$P(Y=c_k)$和$P({X^{(j)}} = {x^{(j)}}|Y = {c_k})$，可以应用极大似然估计法估计相应的概率

  * 先验概率$P(Y=c_k)$的极大似然估计
    $$
    P(Y = {c_k}) = \frac{\sum\limits_{i = 1}^N I({y_i} = c_k)}{N},k=1,2,\cdots,K
    $$

  * 设第j个特征$x^{(j)}$可能取值为$\{ {a_{j1}},{a_{j2}}, \cdots ,{a_{js}}\} $，条件概率$P({x^{(j)}} = {a_{jl}}|Y = {c_k})$的极大似然估计
    $$
    P(x^{(j)} = a_{jl}|Y = {c_k}) = \frac{\sum\limits_{i = 1}^N I(x_i^{(j)} = a_{jl},{y_i} = {c_k})}{\sum\limits_{i = 1}^N I({y_i} = {c_k})}\\
    j=1,2,\cdots,n;l=1,2,\cdots,S_i;k=1,2,\dots,K
    $$
    式中，${x_i^{(j)}}$是第i个样本的第j个特征；$a_{jl}$是第j个特征可能取的第i个值

## 学习与分类算法

* 相当于实施步骤，前面的总结

  * 前提

    * 输入：训练数据$T={(x_1,y_1),(x_2,y_2),\cdots,(x_N,y_N)}$，其中${x_i} = {(x_i^{(1)},x_i^{(2)}, \cdots ,x_i^{(n)})^T}$，$x_i^{(j)}$是第i个样本的第j个特征，$x_i^{(j)} \in \{a_{j1},a_{j2},\cdots,a_{js_j}\}$，$a_{jl}$是第j个特征可能取的第l个值，$j=1,2,\cdots,n$，$l=1,2,\cdots,S_j$；
    * 输出：实例x的分类

  * 计算先验概率及条件概率
    $$
    P(Y = {c_k}) = \frac{\sum\limits_{i = 1}^N I({y_i} = {c_k})} {N},k=1,2,\cdots,K \\
    P(x^{(j)} = a_{jl}|Y = {c_k}) = \frac{\sum\limits_{i = 1}^N I(x_i^{(j)} = a_{jl},{y_i} = {c_k})} {\sum\limits_{i = 1}^N I({y_i} = {c_k})} \\
    j=1,2,\cdots,n;l=1,2,\cdots,S_i;k=1,2,\dots,K
    $$

  * 对于给定的实例$x=(x^{(1)},x^{(2)},\cdots,x^{(n)})^T$，计算
    $$
    P(Y = {c_k})\prod\nolimits_j {P({X^{(j)}} = {x^{(j)}}|Y = {c_k})}
    $$

  * 确定实例x的类
    $$
    y = \mathop {\arg \max }\limits_{{c_k}} P(Y = {c_k})\prod\nolimits_j {P({X^{(j)}} = {x^{(j)}}|Y = {c_k})}
    $$

## 贝叶斯估计

* 用极大似然估计可能会出现所要估计的概率值为0的情况，这样会影响到后验概率的计算结果，使分类产生偏差——采用贝叶斯估计可以解决这一问题

* 条件概率的贝叶斯估计
  $$
  {P_\lambda }(X^{(j)} = a_{jl}|Y = {c_k}) = \frac{\sum\limits_{i = 1}^N I(x_i^{(j)} = {a_{jl}},{y_i} = {c_k}) + \lambda } {\sum\limits_{i = 1}^N I({y_i} = {c_k}) + {S_j}\lambda }
  $$
  式中$\lambda \ge 0$，等价于在随机变量各个取值的频数上赋予一个整数$\lambda$；

  * 当$\lambda=0$就是极大似然估计

  * 常取$\lambda=1$，这时称为**拉普拉斯平滑**（Laplace smoothing）

  * 对任何$l=1,2,\cdots,S_j$，$k=1,2,\cdots,K$，
    $$
    \begin{array}{l}
    {P_\lambda }(X^{(j)} = a_{jl}|Y = {c_k}) > 0\\
    \sum\limits_{l = 1}^{S_j} P(X^{(j)} = a_{jl}|Y = {c_k}) = 1 
    \end{array}
    $$

* 先验概率的贝叶斯估计
  $$
  {P_\lambda }(Y = {c_k}) = \frac{\sum\limits_{i = 1}^N I({y_i} = {c_k})  + \lambda }{N + K\lambda}
  $$