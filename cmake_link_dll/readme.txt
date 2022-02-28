该 dll 是用的 mingw-g++ 编译出来的，所以 Qt 中工程也要对应使用 mingw 才可以。


第一步：g++ -c -fPIC mythread.cpp， 生成 mythread.o

第二步：g++ -shared -o libmythread.dll  mythread.o

第三步：g++  a.cpp  -L./  -llibmythread
第三步（cmake）：target_link_libraries(testDll   E:/Desktop/new/libmythread.dll) 


需要注意的是 mingw 和 msvc 在 target_link_libraries() 的时候，msvc 会默认给他追加后缀 .lib，
该项目用的是 mingw，msvc下还没有经过测试，！！！