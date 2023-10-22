#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

//暴力枚举
int BF(string s1,string s2)
{
	int i = 0, j = 0;
	int k = 0;
	while ( i < s1.size() && j < s2.size() )
	{
		k = i;
		if ( s1[i] != s2[j] )
		{
			i = k + 1;
			j = 0;
		}
		while ( i < s1.size() && j < s2.size() && s1[i] == s2[j] )
		{
			i++;
			j++;
		}
	}
	if ( j == s2.size() )
		return i-s2.size();
	else
		return -1;
}

//kmp
int kmp(string s1, string s2)
{
	int* next = new int[s2.size()];
	next[0] = -1;
	if( s2.size() > 1 )
	next[1] = 0;

	int j = 0;
	for ( int i = 2; i < s2.size(); i++ )
	{
		while( j != -1 && s2[i-1] != s2[j] )
		{
			j = next[j];
		}

		if ( j == -1 )
		{
			next[i] = 0;
		}
		else if( s2[i-1] == s2[j] )
		{
			next[i] = next[i-1] + 1;
		}
	}

	int i = 0;
	j = 0;
	while ( i < s1.size() && j < s2.size() )
	{
		if ( s1[i] != s2[j] )
		{
			j = next[j];
		}
		if ( j == -1 )
		{
			j = 0;
			i++;
		}
		while ( i < s1.size() && j < s2.size() && s1[i] == s2[j] )
		{
			i++;
			j++;
		}
	}

	delete[]next;

	if ( j == s2.size() )
		return i - s2.size();
	else
		return -1;
}

int main()
{
	string s1, s2;
	cout << "请输入两个字符串" << endl;
	cin >> s1 >> s2;
	//int ret = BF(s1, s2);
	int ret = kmp(s1, s2);
	cout << ret << endl;
	return 0;
}