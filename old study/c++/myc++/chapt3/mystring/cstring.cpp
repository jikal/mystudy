#include "cstring.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

namespace iotek{

#define MAX_STR_LEN 1024

String::String()
{
	m_data = new char[1];
	*m_data = '\0';
	m_len = 0;
}

String::String(char c)
{
	m_data = new char[2];
	memset(m_data,0,2);
	*m_data = c;
	m_len = 1;
}

String::String(const char* str)
{
	if(str != NULL){
		m_len = strlen(str);
		m_data = new char[m_len+1];
		memset(m_data,0,m_len + 1);
		strcpy(m_data,str);
	}else{
		m_data = new char[1];
		*m_data = '\0';
		m_len = 0;
	}
}

String::String(bool b)
{
	if(b){
		m_data = new char[5];
		memset(m_data,0,5);
		m_len = 4;
		strcpy(m_data,"true");
	}else{
		m_data = new char[6];
		memset(m_data,0,6);
		m_len = 5;
		strcpy(m_data,"false");
	}
}
	
String::String(int val)
{
	char str[MAX_STR_LEN] = {0};
	snprintf(str,MAX_STR_LEN,"%d",val);
	m_len = strlen(str);
	m_data = new char[m_len+1];
	memset(m_data,0,m_len+1);
	strcpy(m_data,str);
}

String::String(double val)
{
	char str[MAX_STR_LEN] = {0};
	snprintf(str,MAX_STR_LEN,"%lf",val);
	m_len = strlen(str);
	m_data = new char[m_len+1];
	memset(m_data,0,m_len+1);
	strcpy(m_data,str);
}

String::~String()
{
	delete[] m_data;
}

String::String(const String& other)
{
	m_len = other.m_len;
	m_data = new char[m_len + 1];
	memset(m_data,0,m_len + 1);
	strcpy(m_data,other.m_data);
}

int String::length()
{
	return m_len;
}

void String::display()
{
	cout << "str:" <<  m_data << endl;
}


void String::append(char c)
{
	m_len +=1;
	char *p = new char[m_len + 1];
	memset(p,0,m_len+1);
	strcpy(p,m_data);
	*(p + m_len - 1) = c;
	delete []m_data;
	m_data = p;
}

void String::append(const char* str)
{
	if(str == NULL)
		return;
	
	m_len += strlen(str);
	char *p = new char[m_len + 1];
	memset(p,0,m_len + 1);
	strcpy(p,m_data);
	strcat(p,str);
	delete[] m_data;
	m_data = p;
}

void String::append(const String& str)
{
#if 0
	m_len += str.m_len;
	char *p = new char[m_len+1];
	memset(p,0,m_len+1);
	strcpy(p,m_data);
	strcat(p,str.m_data);
	delete[] m_data;
	m_data = p;
#endif
	append(str.m_data);
}

bool String::chomp(char &c)
{
	bool ret = false;
	if(m_len > 0){
		c = m_data[m_len - 1];
		*(m_data + m_len -1) = '\0';
		--m_len;
		ret = true;
	}

	return ret;
}

char String::charAtIndex(int index)
{
	char c = 0;
	if(index < m_len)
	{
		c = *(m_data + index);
	}

	return c;
}


int String::toInt()
{
	return atoi(m_data);
}

double String::toDouble()
{
	return atof(m_data);
}

bool String::toBool()
{
	if(strcmp(m_data,"true") == 0){
		return true;
	}
	return false;
}

int String::compare(const char*str) const
{
	return strcmp(m_data,str);
}

int String::compare(const String& str) const
{
	compare(str.m_data);
}

}
