## [QQBot](https://github.com/RuiPro/QQBot)的插件模板

你可以在src中进行你的插件制作。

1. 包含`headers`目录下的`plugin_build.h`头文件
2. 继承`BasicPlugin`类，设置变量，并实现三个纯虚函数。
3. 记得修改`loadPlugin`函数里的类名
4. 把你的源文件编译为动态库
5. 动态库的后缀统一为`.plg`
6. 拷贝到QQBot可执行文件所在的目录下的`plugins`目录里
7. 重启QQBot



如果使用CMake，你可以参考此[CMakeLists.txt](CMakeLists.txt)模板。

