<center><font size=10 color='gray'>第六章 逻辑斯蒂回归与最大熵模型</fontfont></center>
[TOC]
# 逻辑斯蒂回归与最大熵模型

## 逻辑斯蒂回归模型

- 逻辑斯蒂分布：设$\bf{X}$是连续随机变量，$\bf{X}$具有下列分布函数和密度函数：
  $$
  F(x) = P(\bf{X} \le x) = \frac{1}{1 + e^{ - (x - \mu )/\gamma }}
  $$

  $$
  f(x) = F'(x) = \frac{e^{ - (x - \mu )/\gamma }} {\gamma (1 + {e^{ - (x - \mu )/\gamma }})^2}
  =F(x)(1-F(x))
  $$
  

式中，$\mu$为位置参数，$\gamma>0$为形状参数，将z值转化为一个接近0或1的y值，并且在z=0附近变化很陡

![](pic\logistic.png)

- 二项逻辑斯蒂回归模型（binomial logistic regression model）

  - 分类模型，由条件概率分布$P(\bf{Y}|\bf{X})$表示，优点：直接对分类可能性进行建模，**无需事先假设数据分布**（避免了假设分布不准确所带来的问题）；且可得到近似概率预测；**sigmod函数是任意阶可导的凸函数**；

  - 随机变量$\bf{X}$取值为实数，随机变量$\bf{Y}$取值为$\{0,1\}$

  - 形式如下
    $$
    P(Y = 1|x) = \frac{1}{1 + e^{- (\omega  \cdot x + b)}}
    $$
  
    $$
    P(Y = 0|x) = \frac{e^{- (\omega  \cdot x + b)}} {1 + e^{- (\omega  \cdot x + b)}}
    $$
  
  - 输入$x \in {\Re ^n}$，输出$Y\in\{0,1\}$，权值向量$\omega\in {\Re ^n}$，偏置$b\in \Re $
  
  - 对于给定的输入实例$x$，按照上式可以求得$P(Y = 1|x)$和$P(Y = 0|x)$，比较两个条件概率值的大小，将实例分到概率值较大的一类
- 事件的几率（odds）：该事件发生的概率与该事件不发生的概率的比值，即$\frac{p}{1 - p}$

  - 对数几率（log odds）：${\rm{logit}}(p) = \log \frac{p}{1 - p}$，
  
  - logistic function（**逻辑斯蒂函数**）**连续且可微**
    $$
    y = \frac{1}{1 + e^{ -z}}
    $$
  
  - 其中，将y视为样本x作为正例的可能性，则1-y是其反例的可能性，输出$Y=1$的对数几率是输入x的线性函数
    $$
    y = \frac{1}{1 + e^{ - ({\omega ^T}x + b)}} \Leftrightarrow \ln \frac{y}{1 - y} = {\bf{\omega }}^T \bf{x} + b
    $$

## 推导
推导：[参考文章](https://zhuanlan.zhihu.com/p/44591359)

  - 线性回归表达式：$f(\bf{x}) = {\bf{\omega }}^T\bf{x} + b$；

    - 对于给定的输入$\bf{x}$，输出一个数值$y$，是一个解决回归问题的算法
    - 为了公式的简洁美观，消除掉公式的$b$：令$x' = {[1\;x]^T}$，$\omega ' = {[b\;\omega ]^T}$，方程简化为$f(x') = \omega {'^T}x'$

  - 逻辑回归模型：实质是分类，得到标签为A的概率

    - 通过sigmod函数$\sigma (x) = \frac{1}{1 + e^{ - x}}$将线性回归的输出$( - \infty , + \infty )$映射到$[0,1]$，得到逻辑回归表达式
      $$
      y = \sigma (f(x)) = \frac{1}{1 + e^{ - {\omega ^T}x}}
      $$

    - 假设只有两个标签0和1，把采集到的任何一组样本看做一个事件的话，那么设事件发生的概率为$p$，$P_{y = 1} = \frac{1}{1 + e^{ - {\omega ^T}x}} = p$，因为标签不是1就是0，${P_{y = 0}} = 1-p$

      可以写成

    $$
    P(y|x) = \left\{ {\begin{array}{*{20}{c}}
    {p,y = 1}\\
    {1 - p,y = 0}
    \end{array}} \right.
    $$

    - 若有$N$个数据，合在一起的合事件的总概率为
      $$
      \begin{array}{l}
          P_{all} = P({y_1}|{x_1})P({y_2}|{x_2}) \cdots P({y_N}|{x_N})\\
           = \prod\limits_{n = 1}^N p^{y_n}{(1 - p)}^{1 - y_n} 
          \end{array}
      $$

    ​       上述函数不方便计算，可以简化为$P({y_i}|{x_i}) = {p^{{y_i}}}{(1 - p)^{1 - {y_i}}}$   
    ​        注意$P_{all}$是一个函数，未知量只有$\omega$            

    - 由于连乘很复杂，通过两边取对数变成连加的形式
      $$
      \begin{array}{l}
              F(\omega ) = \ln (P_{all}) = \ln (\prod\limits_{n = 1}^N p^{y_n}{(1 - p)}^{1 - y_n} )\\
               = \sum\limits_{n = 1}^N {\ln (p^{y_n}{(1 - p)}^{1 - y_n}}) \\
               = \sum\limits_{n = 1}^N {({y_n}\ln (p) + (1 - {y_n})\ln (1 - p))} 
              \end{array}
      $$

    - 最大似然估计MLE求解参数：找到参数$\omega^*$使得概率P最大，也就是$F(\omega)$
      $$
      {\omega ^*} = \mathop {\arg \max }\limits_\omega  F(\omega ) =  - \mathop {\arg \min }\limits_\omega  F(\omega )
      $$

    - 求$F(\omega)$的梯度$\nabla F(\omega )$

      - 关于向量求导公式：$\frac{\partial (Ax)}{\partial x} = {A^T},\frac{\partial ({x^T}A)}{\partial x} = A$

    - 对$p$求导，$p$是一个关于变量$\omega$的函数
      $$
      \begin{array}{l}
      p' = f'(\omega ) = (\frac{1}{1 + e^{ - {\omega ^T}x}})'\\
       =  - \frac{1}{ {(1 + e^{ - {\omega ^T}x})}^2}(1 + e^{ - {\omega ^T}x})'\\
       =  - \frac{1}{ {(1 + e^{ - {\omega ^T}x})}^2} \cdot {e^{ - {\omega ^T}x}} \cdot ( - x)\\
           = \frac{xe^{ - {\omega ^T}x}} {(1 + e^{ - {\omega ^T}x})^2}\\
           = p(1 - p)x
      \end{array}
      $$

    - 正式对$F(\omega)$求导：变量只有$\omega$，$y_n,x_n$都是已知的
      $$
      \begin{array}{l}
      \nabla F(\omega ) = \nabla (\sum\limits_{n = 1}^N {({y_n}\ln (p) + (1 - {y_n})\ln (1 - p))} )\\
           = \sum\limits_{n = 1}^N {({y_n}{\mathop{\rm l}\nolimits} n'(p) + (1 - {y_n}){\mathop{\rm l}\nolimits} n'(1 - p))} \\
           = \sum\limits_{n = 1}^N {({y_n}\frac{1}{p}p' + (1 - {y_n})\frac{1}{{1 - p}}( - p'))} \\
           = \sum\limits_{n = 1}^N {({y_n} - p){x_n}} 
          \end{array}
      $$
      可以看出，是每个数据的（真实标签-预测概率）x特征的和

    - 求解目标函数：梯度下降法和拟牛顿法

      - 梯度下降法（GD）与随机梯度下降法（SGD）
        逻辑回归的损失函数是一个连续的凸函数，只有一个全局最优的点，不存在局部最优

  - 逻辑回归的可解释性

    - 可解释性很强：模型训练完成之后，我们获得了一组n维的权重向量$\omega$跟偏差b；对于权重向量，每一个维度的值代表了这个维度的特征对于最终分类结果的贡献大小，正数说明这个特征对于结果有正向的贡献，值越大说明这个特征对于分类为正起到的作用越重要
    - 对于偏差b，一定程度上代表了正负两个类别的判别的容易程度；如果b＞0，说明它更容易被分为正类

## 多项逻辑斯蒂回归

* 逻辑斯蒂回归模型是二项分类模型，用于二类分类，可以将其推广为多项逻辑斯蒂回归模型(multi-nominal logistic regression model)，用于多类分类

* 假设离散型随机变量$Y$的取值集合是${1,2,\cdots,K}$，那么多项逻辑斯蒂回归模型是
  $$
  \begin{array}{l}
  P(Y = k|x) = \frac{e^{ - ({\omega _k} \cdot x)}}{1 + \sum\limits_{k = 1}^{K - 1} e^{ - ({\omega _k} \cdot x)}},\;\;\;\;\;k = 1,2, \cdots ,K - 1\\
  P(Y = K|x) = \frac{1}{1 + \sum\limits_{k = 1}^{K - 1} e^{ - ({\omega _k} \cdot x)}}
  \end{array}
  $$

# 最大熵模型

## 最大熵原理

* 最大熵原理：学习概率模型时，在所有可能的概率模型（分布）中，熵最大的模型时最好的模型——在满足约束条件的模型集合中选取熵最大的模型
* 