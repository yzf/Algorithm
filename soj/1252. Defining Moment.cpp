#include <iostream>
#include <string>

using namespace std;

int n;
string str;

string substring(string word, int be, int en)
{
	string sub;
	if (be < 0)	return sub;
	for (int i = be; i < en; i ++)
		sub += word[i];
	return sub;
}

string getPrefix(string word)//前缀
{
	if (substring(word, 0, 4) == "anti")	return "anti";
	else if (substring(word, 0, 4) == "post")	return "post";
	else if (substring(word, 0, 3) == "pre")	return "pre";
	else if (substring(word, 0, 2) == "re")		return "re";
	else if (substring(word, 0, 2) == "un")		return "un";
	else return "";
}

string getSuffix(string word)//后缀
{
	int len = word.length();
	if (substring(word, len-2, len) == "er")	return "er";
	else if (substring(word, len-3, len) == "ing")	return "ing";
	else if (substring(word, len-3, len) == "ize")	return "ize";
	else if (substring(word, len-1, len) == "s")		return "s";
	else if (substring(word, len-4, len) == "tion")		return "tion";
	else return "";
}

string getMiddle(string word)//剩下的
{
	string pre = getPrefix(word);
	string suf = getSuffix(word);
	int be = pre.length();
	int len = word.length() - suf.length();
	return substring(word, be, len);
}

string sufMeaning(string prefix, string middle, string suffix)
{
	if (suffix == "er")
		return "one who " + middle + "s";
	else if (suffix == "ing")
		return "to actively " + middle;
	else if (suffix == "ize")
		return "change into " + middle;
	else if (suffix == "s")
		return "multiple instances of " + middle;
	else if (suffix == "tion")
		return "the process of " + middle + "ing";
	else
		return middle;
}

string preMeaning(string prefix, string middle, string suffix)
{
	if (prefix == "anti")
		return "against " + sufMeaning(prefix, middle, suffix);
	else if (prefix == "post")
		return "after " + sufMeaning(prefix, middle, suffix);
	else if (prefix == "pre")
		return "before " + sufMeaning(prefix, middle, suffix);
	else if (prefix == "re")
		return sufMeaning(prefix, middle, suffix) + " again";
	else if (prefix == "un")
		return "not " + sufMeaning(prefix, middle, suffix);
	else
		return sufMeaning(prefix, middle, suffix);
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
 
	cin >> n;
	while (n --) {
		cin >> str;
		cout << preMeaning(getPrefix(str), getMiddle(str), getSuffix(str)) << endl;
	}

	return 0;
}
