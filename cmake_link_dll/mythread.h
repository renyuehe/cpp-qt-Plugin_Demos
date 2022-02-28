#include <iostream>
using namespace std;

class __declspec(dllexport) Thread{
public:
	Thread(){}
	~Thread(){}
	
    void run();
};
