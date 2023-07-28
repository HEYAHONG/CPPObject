#ifndef __HCPPOBJECT_H__
#define __HCPPOBJECT_H_


#ifdef __cplusplus
#include <mutex>
#include <list>
#include <thread>
#include <typeinfo>
#include "stdlib.h"
#include "stdint.h"
class HCPPObject
{
private:
    //对象锁
    std::recursive_mutex *m_lock;
    //父对象指针
    HCPPObject *m_parent;
    //子对象列表
    std::list<HCPPObject *> m_child_list;
    void AddToChildList(HCPPObject * child);
    void RemoveFromChildList(HCPPObject * child);
public:
    HCPPObject(HCPPObject *parent=NULL);
    virtual ~HCPPObject();

    //获取父对象
    HCPPObject *GetParent();

    //设置父对象
    bool SetParent(HCPPObject * parent,bool force_update=false);

    //锁定对象
    void Lock();

    //解锁对象
    void UnLock();

    typedef enum
    {
        HCPPOBJECT_TYPE_BASE=0, /**< HCPPObject基类 */
        HCPPOBJECT_TYPE_SIMPLE /**< HCPPObjectSimple模板类 */
    } Type;

    //重载new
    void *operator new(std::size_t count);
    //重载delete
    void operator delete(void *ptr);

    //是否在heap上，判断是否为栈变量或堆变量
    bool IsInHeap();

    //若为堆上的变量，当前是否在创建它的线程
    bool IsInThread();

    //获取线程ID
    std::thread::id *GetThreadId();

    //获取此类的void指针
    void * GetVoidPtr();

    //获取类型
    virtual Type GetType()
    {
        return HCPPOBJECT_TYPE_BASE;
    }

    //获取typeid
    virtual const std::type_info & GetTypeId()
    {
        return typeid(*this);
    }

protected:
    //必须在子类重载此函数
    virtual void * getthis()=0;

};
#endif // __cplusplus

/*
HCPPObject的子类必须包含以下结构
class A:public HCPPObject
{
    ...//其它声明或定义
    O_HCPPOBJECT
    ...//其它声明或定义(注意：后面的权限变为public)
}
*/
#define O_HCPPOBJECT \
                    protected:\
                    void *getthis() override\
                    {\
                        return static_cast<void *>(this);\
                    }\
                    public:\
                    void *operator new(std::size_t count)\
                    {\
                        return HCPPObject::operator new(count);\
                    }\
                    void operator delete(void *ptr)\
                    {\
                        return HCPPObject::operator delete(ptr);\
                    }\
                    const std::type_info & GetTypeId() override\
                    {\
                        return typeid(*this);\
                    }\

#ifdef __cplusplus
/*
简易的C++对象模板
*/
template<typename T>
class HCPPObjectSimple:public HCPPObject
{
    T data;
    O_HCPPOBJECT
public:
    HCPPObjectSimple(T &_data,HCPPObject *parent=NULL):data(_data),HCPPObject(parent)
    {

    }
    HCPPObjectSimple(T &&_data,HCPPObject *parent=NULL):data(_data),HCPPObject(parent)
    {

    }
    virtual ~HCPPObjectSimple()
    {

    }
    //获取类型
    Type GetType() override
    {
        return HCPPOBJECT_TYPE_SIMPLE;
    }
    //获取数据,失败返回NULL
    template<typename DataType=T>
    DataType *GetDataPtr()
    {
        return dynamic_cast<DataType*>(&data);
    }
};

/*
判断简易的C++对象模板数据类型是否为某类型
*/
template<typename T>
bool IsHCPPObjectSimpleDataType(HCPPObject *obj)
{
    if((obj!=NULL) && (obj->GetType()==HCPPObject::HCPPOBJECT_TYPE_SIMPLE))
    {
        return typeid(HCPPObjectSimple<T>)==obj->GetTypeId();
    }
    return false;
}
#endif // __cplusplus

#endif // __CPPOBJECT__

