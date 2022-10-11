#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() 
{	string s1="",s2,s3="Bye";
	s1.append("Good morning");				//s1="Good morning"
	s2=s1;									//s2="Good morning"
	int i=s2.find("morning");				//i=5
	s2.replace(i,s2.length()-i,s3);			//相当于s2.replace(5,7,s3)
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	string s4=s1;
	reverse(s4.begin(),s4.begin()+4);		//逆置s4的前面4个字符 
	cout << "s4: " << s4 << endl;
	return 0;
}

