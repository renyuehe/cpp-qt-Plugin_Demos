#ifndef DLL_H
#define DLL_H

class __declspec(dllimport) Dll
{
public:
    Dll();
    void run();
};

#endif // DLL_H
