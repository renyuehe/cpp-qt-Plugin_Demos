#### SimN10 ： 最简单的 N10 框架模拟, 还是直接生成插件的方式

#define ComPluginInterface_IID "org.qt-project.Qt.ComPluginInterface/1.0"
//此宏用于把标识符与类名接口关联起来。这个标识符是唯一的
Q_DECLARE_INTERFACE(ComPluginInterface, ComPluginInterface_IID)
Q_PLUGIN_METADATA(IID ComPluginInterface_IID)
// 将该接口注册到Qt的meta-object system
Q_INTERFACES(ComPluginInterface)