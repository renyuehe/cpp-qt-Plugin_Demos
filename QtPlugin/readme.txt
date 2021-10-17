#### QtPlugin ： 界面插件简单示例

QPluginLoader
qobject_cast
TestOneInterface //插件接口,名字随便取
Q_PLUGIN_METADATA(IID "org.qt-project.Qt.TestOneInterface" FILE "test1.json")
Q_INTERFACES(TestOneInterface) // 将该接口注册到Qt的meta-object system