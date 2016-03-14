
using namespace std;

class MyString
{
private:
	wchar_t *str = nullptr;

public:

	MyString()
	{
		str = new wchar_t[1];
		str[0] = '\0';
	}

	MyString(wchar_t *str)
	{
		this->str = new wchar_t[wcslen(str)+1];
		wcscpy(this->str, str);
	}
	
	MyString(MyString &s)
	{

		str = new wchar_t[wcslen(s.str) + 1];
		wcscpy(str, s.str);
	}


	MyString& operator=(MyString &s)
	{
		if (str != nullptr)
			delete[] str;

		str = new wchar_t[wcslen(s.str) + 1];

		wcscpy(str, s.str);

		return *this;


	}


	wchar_t operator[](int index)
	{
		return str[index];
	}

	~MyString()
	{
		delete[] str;
	}

	friend MyString operator+(MyString &s1, MyString &s2);

	friend wostream &operator<<(wostream &out, MyString &s);
	friend wistream &operator>>(wistream &in, MyString &s);
};

MyString operator+(MyString &s1, MyString &s2)
{
	wchar_t *res = new wchar_t[wcslen(s1.str) + wcslen(s2.str) + 1];

	wcscpy(res, s1.str);
	wcscat(res, s2.str);

	MyString r(res);

	return r;
}

wostream &operator<<(wostream &out, MyString &s)
{
	out << s.str;
	return out;
}

wistream &operator>>(wistream &in, MyString &s)
{
	wchar_t buf[1000];
	in >> buf;

	if (s.str != nullptr)
		delete[] s.str;
	
	s.str = new wchar_t[wcslen(buf) + 1];
	wcscpy(s.str, buf);

	return in;
}
