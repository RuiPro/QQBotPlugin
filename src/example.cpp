#include "plugin_build.h"
#include <iostream>
using namespace std;

class MyPlugin : public BasicPlugin {
public:
	// 构造函数
	// 你应该在此做的：对插件的成员变量进行初始化
	// 你不该在此做的：对插件配置进行初始化，因为此时程序主体还不知道插件的信息，
	MyPlugin(const string& app_path) : BasicPlugin(app_path){
		
		this->m_author = "xxx";
		this->m_name = "MyPlugin";
		this->m_version = "0.1.1.alpha";
		this->m_other_info = "xxx@xxx.xxx";
	}
	// 加载插件时执行
	// 你应该在此做的：对插件配置进行初始化，比如读取插件配置文件
	void loading() {
		m_plugin_home_path += "plugins/" + m_name + "/";
		loger.pluginInfo(this) << "欢迎使用xxx的插件：MyPlugin";
		loger.pluginInfo(this) << "联系方式：" << this->m_other_info;
	}
	// 插件主体，每个Tick执行一次
	void pluginMain() {
		// 无参版：每个Tick都会调用一次
	}
	void pluginMain(const string& msg) {
		// 有参版：只有消息队列有消息时，才会调用
		// 下面的逻辑是：当有人给Bot发送"呀咩咯"时，Bot进行回复
		json QQevent = json::parse(msg, NULL, false);
		if (QQevent["post_type"] == "message") {
			if (QQevent["message_type"] == "private" && QQevent["message"] == "呀咩咯") {
				unsigned int sender = QQevent["sender"]["user_id"];
				QQMessage msg;
				msg << "呀咩咯!";
				msg.addImageURLForPrivate(QQBot.getQQHeaderImageURL(sender));
				QQBot.applySendPrivateMsg(sender, msg);
			}
			else if (QQevent["message_type"] == "group" && QQevent["message"] == "呀咩咯") {
				unsigned int sender_group = QQevent["group_id"];
				unsigned int sender_member = QQevent["user_id"];
				QQGroupMember m(sender_member);
				QQMessage msg;
				msg.addAt(sender_member);
				msg << "呀咩咯!";
				msg.addImageURLForGroup(QQBot.getQQHeaderImageURL(sender_member));
				QQBot.applySendGroupMsg(sender_group, msg);
			}
		}
	}
};

// 下面是必须存在的两个函数，你需要把MyPlugin改成你自己继承的类名
// 一定要带extern "C"，不然g++会给函数添加唯一标识符前后缀以实现重载，到时候加载插件就找不到了
// 比如loadPlugin()会变成_Z10loadPluginv()
// 可以使用"nm 库文件 | grep 函数名"看看你的C函数被g++命名为了什么
extern "C" BasicPlugin* loadPlugin(const string& app_path) {
    return new MyPlugin(app_path);
}
extern "C" void destroyPlugin(MyPlugin * plugin) {
    delete plugin;
}
