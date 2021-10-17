直接调用dll有两种方式

第一种：LoadLibrary方式，需要 include <windows.h>，但是qt里失败了，虽然vs成功了
第二种：QLibrary方式，成功了

第三种：