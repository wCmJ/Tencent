vector删除元素导致迭代器失效，解决办法：
    for(auto it = v.begin();it != v.end();){
        if(*it == 0){
            it = v.erase(it);
        }
        else{
            ++it;
        }    
    }

map删除元素导致迭代器失效，解决办法：
    for(auto it = m.begin(); it != m.end();){
        if(*it % 2 == 0){
            m.erase(it++);
        }
        else{
            ++it;
        }        
    }

四种转型：少用转型
    static_cast<>:基本类型转换，增加const属性，
    dynamic_cast<>:父子类型转换
    const_cast<>:去除const属性
    reinterpret_cast<>:重新解释字节的意义，一般使用类型指针的转换。使用者需要确保类型的正确性。
    
    在转换指针的时候，static_cast<>和reinterpret_cast基本一致，父子类型指针转换除外。
    static_cast会对指针进行修正，保证其结果正确指向父对象或子对象，但reinterpret_cast不会。
    Cp:public Ap, public Bp;
    Cp cc;// Ap | Bp
	Bp* pb = &cc;// to Bp
	Ap* pa = &cc;// to Ap
	Cp* c1 = static_cast<Cp*>(pb);// to Ap
	Cp* c2 = reinterpret_cast<Cp*>(pb);// to Bp
    
使用RAII防止资源泄漏
    
构造函数里，对象没有完全构建好，此时调用虚函数不一定能正确绑定，析构亦如此

lambda/右值引用/move语义/多线程库

OOP设计原则：
    单一职责原则
    里氏替换原则
    依赖倒置原则
    接口隔离原则
    迪米特法则
    开闭原则
    
CPU 100%时，利用perf进行分析：
    perf:
        Linux下的系统性能调优工具，用来进行软件性能分析。
        可以被配置以中断或氢气方式获取时间实例数来手机代码的运行信息。
        perf top -p PID
        查看CPU占比较高的调用
    Vtune:
        用于分析和优化程序性能
    原理：
        对被监测对象进行采样，根据tick中断进行采样，在采样点里判断程序当时的上下文
    
    
    
    
    
    
    
    
    
    
    
    









