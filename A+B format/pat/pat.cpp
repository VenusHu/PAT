// pat.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int intlen(int a) {
	int n = 0;
	while (a > 0) {
		n++;
		a /= 10;
	}
	return n;
}

int main()
{
	long a, b, c;
	cin >> a >> b;
	c = a + b;
	bool isMinus = false;
	if (c < 0) {
		isMinus = true;
		c = -c;
	}
	else if (c == 0) {
		printf("0");
		return 0;
	}
	int len = intlen(c);
	int group = (len - 1)/ 3;
	char *s = new char[len + group + 1];
	char *ss;

	sprintf(s, "%d", c);

	int i, j, in;

	s[len + group] = 0;

	//the following groups
	for (i = 0; i < group; i++) {   //i control the groups
		in = len + group - i*3 - 1;
		for (j = in; j > in - 3; j--) {
			s[j - i] = s[j - i - group + i];
			s[j - i - 1] = 44;
		}
	}

	if (isMinus) {
		ss = new char[len + group + 2];
		for (i = 0; i < len + group + 1; i++) {
			ss[i + 1] = s[i];
		}
		ss[0] = '-';
		printf("%s", ss);
	}
	else
		printf("%s", s);

    return 0;
}

