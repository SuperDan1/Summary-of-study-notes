[TOC]

# 构建基本脚本

##  创建shell脚本文件

* 第一行指定要使用的shell

  ```shell
  #!/bin/bash
  ```

* 运行shell脚本

  * shell会通过`PATH`环境变量来查找命令——将shell脚本文件所处的目录添加到`PATH`环境变量中

  * 在提示符中用绝对或相对文件路径来引用shell脚本文件

    ```shell
    ./shell_script.sh
    ```

  * 修改shell文件权限

    > 创建脚本文件时，umask的值决定了新文件的默认权限设置；在Ubuntu中umask被设置成了022——系统创建的文件只有文件属主和属组才有读/写权限

    ```shell
    # 赋予文件属主执行文件的权限
    chmod u+x shell_script.sh
    ```

## shell基本命令及特性

### 显示消息`echo`

```shell
# 默认情况下，不需要使用引号将要显示的文本字符串划定出来
echo This is a shell.
# 文件中出现引号
echo "This's a shell."
# 如果想文本字符串和命令输出显示在同一行中，使用-n参数
# 同时保证要显示的字符串尾部有一个空格
echo -n "The time and data are: " 
data
```

### 使用变量

* 环境变量

  * `set`显示完整的当前环境变量列表

  * 在脚本中，可以在环境变量名称前加上`$`来使用环境变量

    ```shell
    # 显示环境变量
    echo $UID
    echo $HOME
    ```

  * 在双引号中，shell依然能够将`$UID`识别为变量，但是当真正想用到美元符号时，需要加反斜线`\$`

* 用户变量：shell脚本可以在脚本中定义和使用自己的变量

  * 定义用户变量

    * 用户变量区分大小写
    * 使用等号将值赋给用户变量——**在变量、等号和值之间不能出现空格**
    * shell脚本会自动决定变量值的数据类型

    ```shell
    var=10
    ```

  * 使用用户变量：与系统变量一样，通过`$`引用

### 命令替换

> 从命令输出中提取信息，并将其赋给变量

* 有两种方法将命令输出赋给变量

  * 反引号字符：\`date\`
  * $()格式：\$(date)

* 示例

  ```shell
  #!/bin/bash
  today=$(date +%y-%m-%d)
  # 将目录信息存储到log文件中
  ls /usr/bin -al > log.$today
  ```

  * `date +%y-%m-%d`是`+%y-%m-%d`格式告诉`date`命令显示格式，注意二者之间有**空格**
  * 脚本将日期赋给变量后，将其作为文件名的一部分
  * 文件自身含有目录列表的重定向输出

### 重定向输入和输出

> bash shell提供了几个操作符，可以将命令的输出重定向到另一个位置(文件)；重定向可以用于输入，也可以用于输出，可以将文件重定向到命令输入

* 输出重定向：将命令的输出发送到一个文件中

  * 若文件已存在，重定向操作符会用新的文件数据覆盖已有文件

    ```shell
    command > outputfile
    ```

  * 将命令的输出追加到已有文件中

    ```shell
    command >> outputfile
    ```

* 输入重定向：将文件的内容重定向到命令

  * 将文本文件重定向到命令的符号`<`

    ```shell
    command < inputfile
    ```

    > wc命令可以对数据中的文本进行计数输出
    >
    > * 文本的行数
    > * 文本的词数
    > * 文本的字节数

    ```shell
    # 示例
    wc < test
    ```

  * 内联输入重定向(inine input redirection)：在命令行中指定用于输入重定向的数据，符号是`<<`

    ```shell
    # 除了重定向符号>>,还需要指定一个文本标记来划分输入数据的开始和结尾
    command << marker
    data
    marker
    ```

### 管道

> 将一个命令的输出作为另一个命令的输入

* 管道被放在命令之间，将一个命令的输出重定向到另一个命令中

  ```shell
  command1 | command2
  ```

* 可以在一条命令中使用任意多条管道——目前管道最流行的用法之一是将命令产生的大量输出通过管道传送到文本分页(`more`或者`less`)命令

  ```shell
  ls -al | sort | more
  ```

### 执行数学运算(TODO)

### 退出脚本(TODO)

# 使用结构化命令

## if-then-elif-else-fi语句

> 运行if后面的那个命令，如果该命令的退出状态码是0(该命令成功运行)，位于then部分的命令就会被执行；
>
> 如果该命令的退出状态码是其他值，then部分的命令就不会被执行，bash shell会继续执行脚本中的下一个命令
>
> fi语句用来表示if-then语句到此结束

```shell
if command1
then
	commands
elif command2
then
	more commands
else
	commands
fi
```

## test(TODO)

### 数值比较

> eq：equal相等
>
> ge：greater equal 大于等于
>
> gt：greater than 大于
>
> le：less equal 小于等于
>
> lt：less than 小于
>
> ne：not equal 不等于

| 比较 | 描述 |
| :-: | :-: |
| n1 -eq n2 | 检查n1是否与n2相等 |
| n1 -ge n2 | 检查n1是否大于或等于n2 |
| n1 -gt n2 | 检查n1是否大于n2 |
| n1 -le n2 | 检查n1是否小于或等于n2 |
| n1 -lt n2 | 检查n1是否小于n2 |
| n1 -ne n2 | 检查n1是否不等于n2 |

* 示例

  ```shell
  #!/bin/bash
  # Using numeric test evaluations
  value1=10
  if [ $value1 -gt 5 ]
  then
  	echo "The test value $value1 is greater than 5"
  fi
  ```

* **注意**：bash shell只能处理整数，不能在`test`命令中使用浮点数

### 字符串比较

|     比较      |          描述          |
| :-----------: | :--------------------: |
|  str1 = str2  | 检查str1是否和str2相同 |
| str1 ！= str2 | 检查str1是否和str2不同 |
|  str1 < str2  |  检查str1是否比str2小  |
|  str1 > str2  |  检查str1是否比str2大  |
|    -n str1    | 检查str1的长度是否非0  |
|    -z str1    | 检查str1的长度是否为0  |

* 大于号和小于号必须转义`\>`和`\<`，否则shell会把它们当做重定向符号，把字符串当做文件名

* 大于和小于顺序和sort命令所采用的不同

  * 在`test`命令中，大写字母被认为是小于小写字母的
  * 在`sort`命令中，大写字母被认为是大于大写字母的
  
* 空的和未初始化的变量会对shell脚本测试造成灾难性的影响，如果不是很确定一个变量的内容，最好在将其用于数值或字符串比较之前先通过`-n`或`-z`来测试一下是否含有值

### 文件比较

|      比较       |                   描述                   |
| :-------------: | :--------------------------------------: |
|     -d file     |       检查file是否存在并是一个目录       |
|     -e file     |             检查file是否存在             |
|     -f file     |       检查file是否存在并是一个文件       |
|     -r file     |          检查file是否存在并可读          |
|     -s file     |          检查file是否存在并非空          |
|     -w file     |          检查file是否存在并可写          |
|     -x file     |         检查file是否存在并可执行         |
|     -O file     |     检查file是否存在并属当前用户所有     |
|     -G file     | 检查file是否存在并且默认组与当前用户相同 |
| file1 -nt file2 |          检查file1是否比file2新          |
| file1 -ot file2 |          检查file1是否比file2旧          |

### 复合条件测试

* `if-then`语句允许你使用布尔逻辑来组合测试
  * [ condition1 ] && [condition2] 
  * [ condition1 ] || [condition2] 

