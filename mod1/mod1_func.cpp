//
// Created by Administrator on 2019/11/05.
//
#include <stdio.h>
#include "mod1.h"
#include "mod1_func.h"
#include "mod2/mod2.h" //新增

void mod1_func()
{
    mod2_func();//新增
    printf( "mod1: %d \n", GLOBAL_MOD1_VAR );
}