/*
    register.h
    
    Initial version: 2020.7.13
    Lastest update: 2020.9.12
    Author: hhw
*/
#ifndef _REGISTER_H_
#define _REGISTER_H_

#include "headers.h"

void random_vc(char *c); //���������֤��
int register_func(char *user,char *code,char *tel,char *vc,char *vc1); //ע����Ϣ����
int findback_func(char *user,char *code,char *tel); //�һ��û���Ϣ
void input_database(char *user,char *code,char *tel); //ע����Ϣ�������ݿ�
void output_database(char *user,char *code,char *tel,int *f); //������ݿ���Ϣ
int check_data(char *user,char *code,char *tel); //����˺ź͵绰�����ݿ���Ϣ�Ƿ�ƥ��

#endif