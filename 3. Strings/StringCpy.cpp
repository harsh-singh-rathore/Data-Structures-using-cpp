#include<iostream>

using namespace std;

int main()
{
	char str[50], strCp[] = "I study at MIT Maipal";
	int i;
	for(i = 0; strCp[i] != '\0'; i++)
	{
		str[i] = strCp[i];
	}
	str[i] = '\0';
	cout << " Original Str = "<< strCp <<endl;
	cout << "Copied str = "<< str << endl;
	return 0;
}