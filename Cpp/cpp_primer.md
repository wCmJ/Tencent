c++11新增：
    1.允许将变量声明为constexpr类型以便由编译器来验证变量的值是否是一个常量表达式
    2.引入auto类型说明符，让编译器替我们去分析表达式所属的类型，通过初始值来推算变量的类型，所以auto定义的变量必须有初始值
    3.希望从表达式的类型推断出变量的类型，但不想用表达式的值去初始化变量。引入decltype：选择并返回操作数的数据类型。编译器分析表达式并得到它的类型，却不实际计算表达式的值
        decltype(f()) sum = x;
    4.可以为类内数据成员提供一个类内初始值，创建对象时，类内初始值用于初始化成员，没有初始值的成员将被默认初始化
    5.列表初始化vector
    6.引入begin和end函数，非成员函数
        int ia[] = {1,2,3,4,5};
        int *beg = begin(ia);
        int *end = end(ia);
    7.规定商一律向0取整




6-29:
character 2:

    typedef/using/const/&/*/auto/decltype/#ifndef/

    1.short/int/long/
    2.无符号数和有符号数
    3.\x后跟一个或多个16进制数
    4.\后跟一个/二个/三个8进制数
    5.引用/指针:引用对象必须初始化，指针不强制。引用是绑定的，指针不是；引用不占用空间，指针占用
    6.函数外定义的内置类型，未初始化时值为0。函数内定义的内置类型，未初始化时值未定义
    7.const对象必须初始化，默认状态下，const对象仅在文件内有效，因为编译器会用值替换该变量
    8.为了使const对象在各个文件中和非常量一样，无论是定义还是声明都增加extern关键字。
    9.顶层const表示对象本身是个const，底层const表示指针所指对象是一个常量
    10.常量表达式是指在编译过程就能得到计算结果的表达式
    11.类型别名：typedef/using
        typedef char* pstring;//指向char的指针
        const pstring cstr = 0;//const pstring指向char的常量指针
        const pstring *ps;
    12.auto会忽略顶层const，保留底层const
    13.decltype会保留顶层const，执行解引用操作，得到引用类型
        int i;
        decltype((i)) d;//d是int&，必须初始化
        decltype(i) e;//e是int
    14.类通常定义在头文件中，预处理器

character 3: string/vector/array

    using/string/

    1.using namespace::name;
    2.#include<string>  using std::string;
    3.string对象初始化：
        string s1;
        string s2(s1);
        string s3 = s1;
        string s4("string");
        string s5 = "string";
        string s6(10,'c');
    4.is>>s;    os<<s;  getline(is,s);  
    5.strign::size()返回无符号数，切勿混用有符号数和无符号数
    6.两个字面值不能直接相加
    7.模板：类模板/函数模板。编译器根据模板创建类或函数的过程成为实例化。
        vector是模板，vector<int>是类型
        引用不是对象，所以不存在包含引用的vector
    8.容器迭代器允许的操作(iterator/const_iterator)：
        *item
        item->
        ++item
        --item
        item1 == item2
        item1 != item2
    9.容器为空时，s.begin() == s.end()。尾后指针不能执行递增和解引用操作   
    10.for循环中向容器中添加元素，会导致迭代器失效
    11.数组定义：
        int arr[10];
        int* arr[10];
        int (*arr)[10] = &base;
        int (&arr)[10] = base;
    12.指针与数组
        数组特性：在很多用到数组名字的地方，编译器会自动将其替换为指向数组首元素的指针。
        int arr[] = {1,2,3,4,5,6,7,8,9,10};
        auto ia(arr);//此处arr是int*，
        decltype(arr) ia2;//此处arr是10个数字构成的数组
    13.两个指针指向同一个数组，才能使用关系运算符进行比较
    14.C风格字符串：
        以空字符结束
        strlen/strcat/strcpy/strcmp必须传入C风格字符串。
    15.多维数组
        int ia[3][4] = {1,2,3,4,5,6,7,8,9,10};
        for(auto row:ia){//此处必须引用，否则ia会被自动转为int*，指向首元素。
            for(auto col:row){

            }
        }   
    16.重载运算符时，运算对象的类型和返回值的类型，都是由该运算符定义的。但是运算对象的个数、运算符的优先级和结合律都是无法改变的
    17.左值和右值：
        当一个对象被用作右值的时候，用的是对象的值（内容）
        当对象被当作左值的时候，用的是对象的身份（在内存中的位置）
        重要原则：
            在需要右值的地方可以用左值来代替，但是不能把右值当作左值。
            当一个左值被当成右值使用时，实际使用的是它的内容（值）
    18.只有四个运算符规定了顺序：
        &&
        ||
        ?:
        ,
    19.商/求余
        (-m)/n m/(-n) == -(m/n)
        m % (-n) == m % n
        (-m) % n == -(m % n)
    20.赋值运算符满足右结合律

character 4:
    1.static_cast:
        任何具有明确定义的类型转换，只要不包含底层const，都可以使用static_cast
    2.const_cast:
        只能改变对象的底层const
            const char* pc = &c;
            char *p = const_cast<char*>(pc);        

character 6:
    1.函数参数的顶层const被忽略
    2.数组形参
        void print(const int*);
        void print(const int[]);
        void print(const int[10]);
        上述三个函数声明等价
    

cin/cout/cerr/endl/ends/flush/unitbuf/nounitbuf/    
程序崩溃时，输出数据很可能停留在缓冲区，没有被刷新
cin.tie(&cout);//将输入关联到输出上，读取cin时，会刷新cout

ifstream:从一个给定文件读取数据
ofstream:向一个给定文件写入数据



resize: 增大或缩小容器
    如果当前大小大于新大小，尾部元素会被删除
    如果当前大小小于新大小，新元素被添加到尾部
reverse(n):分配至少能保存n个元素的空间
size:目前已经保存了多少个元素
capacity:不分配新内存空间的前提下最多可以保存多少个元素
shrink_to_fit():请将capacity()减少至与size()相同大小

vector的erase函数会返回下一个有效的迭代器
顺序容器适配器：
    stack
    queue
    priority_queue

泛型算法：
    find(begin, end, val)
    accumulate(begin, end, sum)
    equal(r1.cbegin(), r1.cend(), r2.cbegin())//r2中的元素数目至少与r1一样多
    fill(begin, end, val)//赋值操作
    fill_n(iterator, size, val)//安全操作
    back_iterator(vec);//vector<int> vec,尾后迭代器
    copy(begin, end, a2)//将begin和end的内容拷贝至a2
    replace(begin, end, val, target)
    replace_copy(begin, end, iterator, val, target)
    unique(begin, end)

lambda表达式：
    [capture list](parameters) -> return type {function body;}
    必须包含捕获列表和函数体，参数列表和返回类型可以省略
    capture list:lambda所在函数中定义的局部变量的列表
    auto f = []{return 42;}
    std::cout<<f()<<std::endl;
    值捕获：lambda创建时拷贝值，随后修改不会影响lambda内对应的值。若要修改该值，需加mutable
        auto f = [v1]()mutable{return ++v1;}
    引用捕获
    函数体可以直接使用lambda所在函数外定义的对象
    函数体中包含return之外的语句时，未指明return类型，返回void

关联容器：
    map: 红黑树
    set：红黑树
    multimap：红黑树
    multiset：.红黑树

    unordered_map：哈希表
    unordered_set：哈希表
    unordered_multimap：哈希表
    unordered_multiset：哈希表

bool comp(int a, int b){
    return a > b;
}
std::multiset<int, decltype(comp)*> nums(comp);


动态内存：
    静态内存：所有函数外的变量/函数内部static变量/类内static变量，由编译器负责创建/销毁
    栈内存：函数内部非static变量，由编译器负责创建/销毁
    动态内存：new/malloc，由程序创建/销毁

    智能指针行为类型普通指针，自动释放所指的对象
    #include<memory>//类模板
    shared_ptr:允许多个指针指向同一个对象
    unique_ptr:独占所指向的对象
    weak_ptr:弱引用，指向shared_ptr所管理的对象

    shared_ptr:
        shared_ptr p = make_shared<T> (arg);
        shared_ptr<T> p(q);
        p = q;//递减p所指对象的计数器，如果为0，则释放所指对象；递增q所指对象
        
move:
    move告诉编译器：我们有一个左值，但是希望像一个右值一样处理它
    右值引用：绑定到右值的引用，只能绑定一个将要销毁的对象

移动构造函数 & 移动赋值运算符
    从给定对象窃取资源，而不是拷贝资源
    移动构造函数：
        第一个参数是右值引用，其它所有参数必须由默认实参
        一旦移动完成，源对象处于销毁状态
        strvec::strvec(strvec && s) noexcept{//noexcept在声明和定义时，均需带上

        }
        编写一个不抛出异常的移动操作时，应该将此事通知标准库

    移动赋值运算符：
        必须处理自赋值
        
面向对象程序设计：
    基于三个基本概念：数据抽象、继承、动态绑定
    数据抽象：将类的接口和实现分离
    继承：定义相似类型并对相似关系建模
    动态绑定：一定程度上忽略相似类型的区别，以统一的方式使用它们

    对于某些函数，派生类定义自己的版本，采用虚函数。
    C++中，使用基类的引用或指针调用虚函数时将发生动态绑定
    final override
    不能将基类直接转换为派生类
        如果基类中含有虚函数，可以使用dynamic_cast请求一个类型转换，将在运行时执行安全检查。
    如果我们已知某个基类向派生类的转换是安全的，则可以使用static_cast来强制覆盖掉编译器的检查工作

    含有纯虚函数的类是抽象基类，不能创建抽象基类的对象
    class默认是private继承，struct默认是public继承
    


类与类之间有委托关系：
    class A{
        vector<B*> m_views;
    public:
        void attach(B* b){
            m_views.push_back(b);
        }
        void nofity(){
            for(auto p: m_views){
                p->update();
            }
        }
    };
    class B{
    public:
        virtual void update() = 0;
    };
    观察者模式↑

    模板方法模式：
        定义操作框架，将这些步骤延迟加载到子类中

    原型模式：
        基类：能够存储未来定义的类指针
        子类：构建静态对象，构造函数中将该对象加入基类中。



虚拟继承：
    decltype：产生的是在编译时即可确定的声明类型
    typeid：根据对象的类型来确定，即可编译时确定，也可运行时确定

    现代的C++编译器都采用了表格驱动的对象模型，所有虚函数都以一个表格的方式存放在一起。
    每个函数的偏移量在基类型和导出类型中均相同，这使得虚函数相对于表格首地址的偏移量可以在编译时确定
    虚函数表格的首地址存放在每一个对象中，称为虚指针，始终位于对象的起始地址。

    对于多态类型，除了要在运行时确定虚函数地之外，还需要提供运行时类型信息RTTI
    一个解决方案是，将类型信息的地址放入到虚表中，为了避免虚函数表长度对其位置的影响，g++将它放在虚函数表的前面

    单链继承中，每一个派生类型都包含了其基类型的数据以及虚函数，这些虚函数可以按照继承顺序，一次排列在同一张虚表之中，因此只需要一个虚指针即可。

    多继承内存模型：
        struct A{
            int ax;
            virtual void f0(){}
        };

        struct B{
            int bx;
            virtual void f1(){}
        };

        struct C: public A, public B{
            int cx;
            virtual void f0(){} override;
            virtual void f1(){} override;            
        };

        0   -   struct A
        0   -   vptr_A
        8   -   int ax
        16  -   struct B
        16  -   vptr_B
        24  -   int bx
        28  -   int cx
        sizeof :32  align: 8    



