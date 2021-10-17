头文件
extern "C" __declspec(dllexport) int add(int a, int b);


源文件
#include <iostream>
#include <Windows.h>
int main() {
	//LoadLibrary
	//GetProcAddress
	//FreeLibrary

	HINSTANCE hDLL = LoadLibrary("Dll4.dll");
	typedef int(*p_add)(int a, int b);
	p_add addFunction = (p_add)GetProcAddress(hDLL, "add");
	std::cout << addFunction(2, 4);

	return 0;
}