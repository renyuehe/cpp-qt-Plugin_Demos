#include <iostream>
#include <Windows.h>
using namespace std;

int main(){
	//LoadLibrary
	//GetProcAddress
	//FreeLibrary
	
	HINSTANCE hand = LoadLibrary("dll.dll");
//	typedef (*p_add)(int, int);//Ϊʲô��д����ֵҲ������ 
	typedef int(*p_add)(int, int); 
	p_add p = (p_add)GetProcAddress(hand,"add");//��ͬ�ĺ���ָ�붼�ǲ�ͬ�ģ��������Ҫǿתһ�� 
	cout<<p(3,6)<<endl;
	
	system("pause");
	
	return 0;
}
