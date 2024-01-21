/***************************************************************
 * Name:      hcpprt.cpp
 * Purpose:   hcpprt实现,实现常用的C++移植。
 * Author:    HYH (hyhsystem.cn)
 * Created:   2024-01-21
 * Copyright: HYH (hyhsystem.cn)
 * License:   MIT
 **************************************************************/
#include "hcpprt.h"
#include "hcompiler.h"
#include "hdefaults.h"

/*
通过此类判断构造函数是否被执行。
*/
static class ctors_state
{
    int state;
    int GetMagicNumber()
    {
        return 0x5A5AAA55;
    }
public:
    ctors_state():state(0)
    {
        state=GetMagicNumber();
    }
    ~ctors_state()
    {

    }
    bool IsOk()
    {
        /*
        当未构造时，内存数据一般不为魔数
        */
        return state==GetMagicNumber();
    }
} g_ctors_state;

extern "C"
{
#ifdef __GNUC__
    //GCC环境
    typedef void(*ctors_func)();
    //由链接脚本提供
    extern ctors_func __init_array_start[];
    //由链接脚本提供
    extern ctors_func __init_array_end[];
#endif // __GNUC__
}

static void ctors_execute()
{
    if(!g_ctors_state.IsOk())
    {

#ifdef __GNUC__
        /*
        GCC环境中，某些SDK不提供C++构造函数支持，需要手动添加构造函数,需要链接脚本提供___init_array_start与___init_array_end符号。
        */
        {
            ctors_func *p=NULL;

            for (p = __init_array_start; p < __init_array_end; p++)
            {
                (*p)();
            }
        }
#endif
    }
}

void hcpprt_init()
{
    /*
    执行构造函数
    */
    ctors_execute();
}


#ifndef HCPPRT_NO_NEW_AND_DELETE_OVERRIDE

//重载全局new与delete,如需进一步移植请参考hdefaults组件
void *operator new(size_t size)
{
    return hdefaults_malloc(size,NULL);
}
void *operator new[](size_t size)
{
    return hdefaults_malloc(size,NULL);
}
void operator delete(void *ptr)
{
    hdefaults_free(ptr,NULL);
}
void operator delete[](void *ptr)
{
    hdefaults_free(ptr,NULL);
}

#endif // HCPPRT_NO_NEW_AND_DELETE_OVERRIDE

