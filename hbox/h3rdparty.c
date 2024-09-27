/***************************************************************
 * Name:      h3rdparty.c
 * Purpose:   引入第三方源代码文件
 * Author:    HYH (hyhsystem.cn)
 * Created:   2024-09-27
 * Copyright: HYH (hyhsystem.cn)
 * License:   MIT
 **************************************************************/
#include "h3rdparty.h"
#include "hdefaults.h"

#ifndef  H3RDPARTY_USING_SYSTEM_CJSON
#include "3rdparty/cJSON/cJSON.c"
#endif // H3RDPARTY_USING_SYSTEM_CJSON


static void *h3rdparty_malloc(size_t len)
{
    return hdefaults_malloc(len,NULL);
}

static void h3rdparty_free(void *ptr)
{
    hdefaults_free(ptr,NULL);
}

void h3rdparty_init(void)
{
    {
        //初始化cJSON
        cJSON_Hooks hook= {h3rdparty_malloc,h3rdparty_free};
        cJSON_InitHooks(&hook);
    }
}

