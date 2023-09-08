/***************************************************************
 * Name:      hdefaults.h
 * Purpose:   实现一些一些默认函数
 * Author:    HYH (hyhsystem.cn)
 * Created:   2023-07-14
 * Copyright: HYH (hyhsystem.cn)
 * License:   MIT
 **************************************************************/

#include "hcompiler.h"
#include "hdefaults.h"
#ifdef __RTTHREAD__
#include "rtthread.h"
#endif // __RTTHREAD__
#ifdef WIN32
#include "windows.h"
static CRITICAL_SECTION g_mutex_lock;
static bool g_is_mutex_lock_init=false;
void check_mutex_lock()
{
    if(!g_is_mutex_lock_init)
    {
        InitializeCriticalSection(&g_mutex_lock);
        g_is_mutex_lock_init=true;
    }
}
#endif // WIN32
#ifdef __unix__
#include "pthread.h"
static pthread_mutex_t g_mutex_lock;
static pthread_mutexattr_t g_mutex_lock_attr;
static bool g_is_mutex_lock_init=false;
void check_mutex_lock()
{
    if(!g_is_mutex_lock_init)
    {
        pthread_mutexattr_init(&g_mutex_lock_attr);
        pthread_mutexattr_settype(&g_mutex_lock_attr,PTHREAD_MUTEX_RECURSIVE);
        pthread_mutex_init(&g_mutex_lock,&g_mutex_lock_attr);
        g_is_mutex_lock_init=true;
    }
}
#endif // __unix__


void * hdefaults_malloc(size_t nBytes,void *usr)
{

#ifdef __RTTHREAD__
    return rt_malloc(nBytes);
#else
    return malloc(nBytes);
#endif
}

void hdefaults_free(void *ptr,void *usr)
{
#ifdef __RTTHREAD__
    rt_free(ptr);
#else
    free(ptr);
#endif

}

void  hdefaults_mutex_lock(void *usr)
{
#ifdef  __RTTHREAD__
    rt_enter_critical();
#elif defined(WIN32)
    check_mutex_lock();
    EnterCriticalSection(&g_mutex_lock);
#elif defined(__unix__)
    check_mutex_lock();
    pthread_mutex_lock(&g_mutex_lock);
#else
#warning "hdefaults_mutex_lock is  invalid!"
#endif
}

void  hdefaults_mutex_unlock(void *usr)
{
#ifdef  __RTTHREAD__
    rt_exit_critical();
#elif defined(WIN32)
    check_mutex_lock();
    LeaveCriticalSection(&g_mutex_lock);
#elif defined(__unix__)
    check_mutex_lock();
    pthread_mutex_unlock(&g_mutex_lock);
#else
#warning "hdefaults_mutex_unlock is  invalid!"
#endif
}
