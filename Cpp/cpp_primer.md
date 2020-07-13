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



