#include "headers.h"

/*汉字输入法*/

int hz_input(int x1,int y1,int x2,int y2,char *s,int len, int backcolor); //返回本次键入字符串长度
int input_method(int x,int y,char *str,int value,char *py); //汉字输入法调入函数
char *addnum(int a,char *s); //数字标号输出 
void pyFrm(int x1,int y1,int x2,int y2); //输入法小框 