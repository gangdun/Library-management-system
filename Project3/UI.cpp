#include"head.h"

extern users User;
wstring_convert<codecvt_utf8<wchar_t>> converter;

String wstring_to_String(wstring ws) 
{
	// 调用转换器的to_bytes方法，把wstring转换为string
	string s = converter.to_bytes(ws);
	// 构造一个String对象，传入string作为参数
	String S(s);
	// 返回转换后的String对象
	return S;
}

bool System::original_UI()
{
	cout << "**************************************" << endl;
	cout << "欢迎使用图书信息管理系统" << endl;
	cout << "1、登录" << endl;
	cout << "2、退出" << endl;
	cout << "请在下方输入对应操作的数字并且回车确定" << endl;
	cin >> operate_numberl;
	while (cin.fail()) // 检查输入是否有效
	{
		cin.clear(); // 清除错误标志
		cin.ignore(100, '\n'); // 清除缓冲区中的错误输入
		cout << "你只能输入数字，请重新输入：" << endl; // 提示用户重新输入
		cin >> operate_numberl;
	}
	std::system("cls");
	if (operate_numberl == 1)
	{
		while (1)
		{
			regisiter_UI();

		}
	}
	else if (operate_numberl == 2)
	{
		return false;
	}
	else
	{
		cout << "输入错误，没有相应的操作，请重新输入" << endl;
		Sleep(1000);
		std::system("cls");
	}
	return true;
}

void System::regisiter_UI()
{
	cout << "**************************************" << endl;
	cout << "欢迎使用图书信息管理系统" << endl;
	cout << "请输入用户名" << endl;
	cin >> reg_name;
	cout << "请输入密码" << endl;
	cin >> reg_password;
	std::system("cls");
	if (check_user())
	{
		while (1)
		{
			Function_UI();
		}
	}
	else
	{
		Sleep(3000);
		std::system("cls");
	}
}

void System::Function_UI()
{
	cout << "**************************************" << endl;
	cout << "欢迎使用图书信息管理系统" << endl;
	if (user_type == Administrator)
	{
		cout << "尊贵的管理员" << reg_name << "欢迎您" << endl;
	}
	if (user_type == Reader)
	{
		cout << "亲爱的读者" << reg_name << "欢迎您" << endl;
	}
	cout << "1、查询图书信息" << endl;//完成
	cout << "2、浏览图书库内所有图书信息" << endl;//完成
	cout << "3、录入图书信息(管理员)" << endl;//完成
	cout << "4、删除图书信息(管理员)" << endl;//完成
	cout << "5、修改图书信息(管理员)" << endl;//完成
	cout << "请输入对应序号的数字进入对应操作" << endl;
	cin >> operate_numberl;
	while (cin.fail()) // 检查输入是否有效
	{
		cin.clear(); // 清除错误标志
		cin.ignore(100, '\n'); // 清除缓冲区中的错误输入
		cout << "你只能输入数字，请重新输入：" << endl; // 提示用户重新输入
		cin >> operate_numberl;
	}
	std::system("cls");
	User.user_type == user_type;
	if (operate_numberl == 1)
	{
		find_book_UI();
	}
	else if (operate_numberl == 2)
	{
		User.print_allbook(user_type);
	}
	else if (operate_numberl == 3)
	{
		if (user_type == Administrator)
		{
			scan_flag = true;
			while (scan_flag)
			{
				scan();
				Sleep(1000);
			}
		}
		else
		{
			cout << "对不起，您的权限不足" << endl;
			Sleep(1000);
		}
	}
	else if (operate_numberl == 4)
	{
		if (user_type == Reader)
		{
			cout << "对不起，您的权限不足" << endl;
			Sleep(1000);
		}
		else
		{
			User.delet_book();
		}
	}
	else if (operate_numberl == 5)
	{
		if (user_type == Reader)
		{
			cout << "对不起，您的权限不足" << endl;
			Sleep(1000);
		}
		else
		{
			User.change_book();
		}
	}
	
	std::system("cls");
}

void System::find_book_UI()
{
	cout << "**************************************" << endl;
	cout << "请选择查找的类型" << endl;
	cout << "1、ISBN查找" << endl;
	cout << "2、关键字查找(书名、作者、出版社)" << endl;
	cin >> operate_numberl;
	std::system("cls");
	cin.get();
	if (operate_numberl == 1)
	{
		String isbn;
		cout << "请输入想要查找的ISBN号" << endl;
		cin >> isbn;
		User.find_book_ISBN(isbn,user_type);
	}
	if (operate_numberl == 2)
	{
		string keyword;
		cout << "请输入想要查找的图书关键字" << endl;
		getline(cin, keyword); 
		User.find_book_keyword(keyword, user_type);
	}
}