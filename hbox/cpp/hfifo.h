/***************************************************************
 * Name:      hfifo.h
 * Purpose:   hfifo
 * Author:    HYH (hyhsystem.cn)
 * Created:   2024-01-28
 * Copyright: HYH (hyhsystem.cn)
 * License:   MIT
 **************************************************************/
#ifndef HFIFO_H
#define HFIFO_H

#ifdef __cplusplus

#include "hcpprt.h"
#include "hringbuf.h"
#include "stdint.h"
#include "stdlib.h"


template<class lock=hlock>
class hfifo
{
    lock &m_lock;
    hringbuf_t *m_ringbuf;
public:
    hfifo(lock &_lock):m_lock(_lock),m_ringbuf(NULL)
    {

    }

    hfifo(hfifo & oths):m_lock(oths.m_lock),m_ringbuf(oths.m_ringbuf)
    {
    }
    hfifo(hfifo && oths):m_lock(oths.m_lock),m_ringbuf(oths.m_ringbuf)
    {
    }

    //不允许赋值操作
    hfifo &operator =(hfifo & oths) =delete;
    hfifo &operator =(hfifo && oths) =delete;

    virtual ~hfifo()
    {

    }

    //重置FIFO
    void reset()
    {
        hlockguard<lock> s_lock(m_lock);
        m_ringbuf=NULL;
    }

    //FIFO是否有效
    bool is_vaild()
    {
        hlockguard<lock> s_lock(m_lock);
        return m_ringbuf!=NULL;
    }

    //设置FIFO缓冲区，flase表示无效
    bool set_buffer(uint8_t *buffer,size_t buffer_length)
    {
        if(is_vaild())
        {
            return false;
        }
        hlockguard<lock> s_lock(m_lock);
        m_ringbuf=hringbuf_get(buffer,buffer_length);
        if(is_vaild())
        {
            hringbuf_set_lock(m_ringbuf,this,[](void *usr)->void
            {
                if(usr!=NULL)
                {
                    hfifo<lock> &obj=*(hfifo<lock> *)usr;
                    obj.m_lock.lock();
                }
            },[](void *usr)->void
            {
                if(usr!=NULL)
                {
                    hfifo<lock> &obj=*(hfifo<lock> *)usr;
                    obj.m_lock.unlock();
                }
            });
        }
        return is_vaild();
    }

    //heventloop接口包装

    size_t get_length()
    {
        if(is_vaild())
        {
            return hringbuf_get_length(m_ringbuf);
        }
        return 0;
    }

    size_t get_max_length()
    {
        if(is_vaild())
        {
            return hringbuf_get_length(m_ringbuf);
        }
        return 0;
    }

    size_t write(const uint8_t *data,size_t data_length)
    {
        if(is_vaild())
        {
            return hringbuf_input(m_ringbuf,data,data_length);
        }
        return 0;
    }

    size_t read(uint8_t *data,size_t data_length,bool clear=true)
    {
        if(is_vaild())
        {
            if(clear)
            {
                return hringbuf_output(m_ringbuf,data,data_length);
            }
            else
            {
                return hringbuf_output_no_clear(m_ringbuf,data,data_length);
            }
        }
        return 0;
    }


};

#endif // __cplusplus

#endif // HFIFO_H
