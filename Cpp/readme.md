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
    static_cast<>
    dynamic_cast<>
    const_cast<>
    reinterpret_cast<>
    
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
    
    
    
    
    
    
    
    
    
    
    
    









