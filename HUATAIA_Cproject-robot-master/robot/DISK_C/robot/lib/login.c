/*
    login.c

    Initial version: 2020.7.13
    Lastest update: 2020.8.12
    Author: Mengfp
*/
#include "headers.h"

void start_func()
{
    //start_page();//画出开始界面
    login_page(); //画出登录界面
    mouseinit();
    login_func(); //进入登录界面 
}

void login_func()
{
    int flag;

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        if(mouse_press(115,630,235,680)==1) {flag=1; break;}
        if(mouse_press(365,630,485,680)==1) {flag=2; break;}
        if(mouse_press(240,630,360,680)==1) {flag=3; break;}
    }
    clrmous(MouseX, MouseY);
    switch(flag)
    {
        case 1:
        {
            register_page();
            user_register();
        }
        break;
        case 2:
        {
            findback_page();
            user_findback();
        }
        break;
        case 3:
        {
            exit_window();
            exit_pro();
        }
        break;
        default: break;
    }
}

void user_register()
{
    int flag;
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        if(mouse_press(120,625,240,675)==1) {flag=1; break;}
        if(mouse_press(360,625,480,675)==1) {flag=2; break;}
    }
    clrmous(MouseX, MouseY);
    switch(flag)
    {
        case 1:
        {

        }
        break;
        case 2:
        {
            login_page();
            login_func();
        }
        break;//返回登陆界面
        default: break;
    }
}

void user_findback()
{
    int flag;
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        if(mouse_press(120,600,240,650)==1) {flag=1; break;}
        if(mouse_press(360,600,480,650)==1) {flag=2; break;}
    }
    clrmous(MouseX, MouseY);
    switch(flag)
    {
        case 1:
        {

        }
        break;
        case 2:
        {
            login_page();
            login_func();
        }
        break;//返回登陆界面
        default: break;
    }
}

void exit_pro()
{
    int flag;
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        if(mouse_press(300,450,330,480)==1) {flag=1; break;};
        if(mouse_press(470,450,500,480)==1) {flag=2; break;};
    }
    clrmous(MouseX, MouseY);
    switch(flag)
    {
        case 1:
        {
            exit(0);
        }
        break;
        case 2:
        {
            login_page();
            login_func();
        }
        break;//返回登陆界面
        default: break;
    }
}
