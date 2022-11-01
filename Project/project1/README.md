# Lexical Analysis & Syntax Analysis

小组成员姓名学号：@[Leo-Adventure](https://github.com/Leo-Adventure)、@[yolk-pie-L](https://github.com/yolk-pie-L)

## How To Run It

1. 通过 `make clean`指令清理环境

2. 在根目录下使用 `make` 
3. 使用 `sh github_test.sh` 或者 `sh student_test.sh` 跑老师以及学生的相应测试，测试的结果会生成在 `myOutput` 文件夹当中

## FLEX部分

我们检测了正确格式的token和错误格式的token。正确的token可以帮助bison部分做语法分析，错误的token也可以帮助bison做错误恢复，将整个程序分析完。我们通过一个int类型的共享变量has_error作为判断词法分析部分是否出错。如果出错则将`has_error` 变量置为1，最后将不会输出语法分析树。

## BISON部分

在这一部分我们通过构建符合 `spl` 的语法规则，并且在相应的规约上面加上错误处理。

不管token是终结符还是非终结符，我们认定它的类型都是`Node*`。

```c++
%union{
    Node* node_ptr;
}
```

对于各种运算符，按照优先级从低到高，依此从上定义到下。通过`%prec`指定优先级以消除部分二义性。

对于每一条生产式，我们调用`Node`构造器，构建起一层一层的语法分析树。当递归到Program时，判断词法分析和语法分析是否中途存在错误。如果中途不存在错误，则输出语法分析树。

## MAKEFILE部分

由于在语法分析树部分使用了queue，所以我们的程序需要使用g++编译。

我们使用`extern "C" int yylex()`来解决链接问题。

## 构建语法分析树

我们设计了枚举类`NodeType`，来表示语法分析树上不同节点的类型。根据不同的节点类型，在输出的时候采用不同的策略。

```C++
typedef enum NodeType{
    Type,
    Int,
    Char,
    Float,
    Id,
    TERMINAL,
    NONTERMINAL
} NodeType;
```

我们设计了类`Node`，来表示语法分析树上的每个节点。通过Node中`nodetype`来标志节点类型，`name`表示该节点的名字，`nodes_num`表示该节点子节点的个数，`int_value`，`char_value`，`float_value`相应节点类型的值，`line_num`表示该节点所对应的行数。我们设计了五种构造器用于不同的节点类型。

通过`explicit Node(NodeType nodetype, string name, int nodes_num, int line_num, ...)`将生产式右边的的子节点作为可变参数传入构造器函数。在构造器中，我们将子节点push进入队列nodes_queue。

```c++
class Node{
public:
    NodeType nodetype;
    string name;
    union{
        int line_num;
        int int_value;
        char* char_value;
        float float_value;
    };
    int nodes_num = 0;
    queue<Node*> nodes_queue;

    // 用于 bison
    explicit Node(NodeType nodetype, string name, int nodes_num, int line_num, ...);

    // 用于 lex
    // 用于 TERMINAL 
    explicit Node(string name);

    // 用于 CHAR, Id
    explicit Node(NodeType nodetype, char* char_value);

    // 用于INT
    explicit Node(NodeType nodetype, string name, int int_value);

    // 用于 FLOAT
    explicit Node(NodeType nodetype, string name, float float_value);        
};
```

我们通过以下两个函数完成对语法分析树的输出

```c++
void printTree(Node* root, int space=0);

void print(Node* node, int space);
```

`printTree`和`print`结合不断递归地输出整棵语法分析树。如果判断该节点是NONTERMINAL，则调用`printTree`继续往下递归；如果是TERMINAL，则调用`print`，停止递归。

## BONUS部分

对于bonus部分，我们做了单行注释和多行注释以及比较完全的错误检测。测试用例分别对应`test-ex/comment_1.spl`和`test-ex/comment_.spl`。

实现的代码如下：

通过`COMMENT "//".*$`匹配单行注释

通过`MULTIPLE_COMMENT "/*"((("*"[^/])?)|[^*])*"*/" `匹配多行注释
