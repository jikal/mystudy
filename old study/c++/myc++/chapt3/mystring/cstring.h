#ifndef _CSTRING_H_
#define _CSTRING_H_


namespace iotek{
class String{
public:
	//构造函数，析构函数，拷贝构造函数
	String();//构造
	String(char);
	String(const char *);
	String(int);
	String(bool);
	String(double);
	String(const String& other);
	~String();

	//添加一个字符
	void append(char);
	void append(const char *);
	void append(const String& other);

	bool chomp(char &);//移除最后一个字符

	int length();

	char charAtIndex(int index);

	int toInt();//"25" 25
	double toDouble();//"3.14"->3.14
	bool toBool();//"true" true,"false" false ,false
	int compare(const char*) const;
	int compare(const String& str) const;
	void display();

private:
	char *m_data;
	int m_len;
	
};

}
#endif
