#ifndef _CSTRING_H_
#define _CSTRING_H_

#include <stdio.h>

namespace iotek{


class String{
public:
	String(const char * = NULL);
	~String();

	String(const String&);

	//String a; a = b;
	String& operator=(const String &);
	//String a; a = "hello";
	String& operator=(const char*);


	String& operator+=(const String&);
	String operator+(const String&) const;
	
	String& operator+=(const char *);
	String operator+(const char *) const;
	bool operator==(const String& other);
	inline const char* data() const
	{
		return m_data;	
	}

private:
	char *m_data;
	
};

}

#endif
