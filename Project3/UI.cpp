#include"head.h"

extern users User;
wstring_convert<codecvt_utf8<wchar_t>> converter;

String wstring_to_String(wstring ws) 
{
	// ����ת������to_bytes��������wstringת��Ϊstring
	string s = converter.to_bytes(ws);
	// ����һ��String���󣬴���string��Ϊ����
	String S(s);
	// ����ת�����String����
	return S;
}

bool System::original_UI()
{
	cout << "**************************************" << endl;
	cout << "��ӭʹ��ͼ����Ϣ����ϵͳ" << endl;
	cout << "1����¼" << endl;
	cout << "2���˳�" << endl;
	cout << "�����·������Ӧ���������ֲ��һس�ȷ��" << endl;
	cin >> operate_numberl;
	while (cin.fail()) // ��������Ƿ���Ч
	{
		cin.clear(); // ��������־
		cin.ignore(100, '\n'); // ����������еĴ�������
		cout << "��ֻ���������֣����������룺" << endl; // ��ʾ�û���������
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
		cout << "�������û����Ӧ�Ĳ���������������" << endl;
		Sleep(1000);
		std::system("cls");
	}
	return true;
}

void System::regisiter_UI()
{
	cout << "**************************************" << endl;
	cout << "��ӭʹ��ͼ����Ϣ����ϵͳ" << endl;
	cout << "�������û���" << endl;
	cin >> reg_name;
	cout << "����������" << endl;
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
	cout << "��ӭʹ��ͼ����Ϣ����ϵͳ" << endl;
	if (user_type == Administrator)
	{
		cout << "���Ĺ���Ա" << reg_name << "��ӭ��" << endl;
	}
	if (user_type == Reader)
	{
		cout << "�װ��Ķ���" << reg_name << "��ӭ��" << endl;
	}
	cout << "1����ѯͼ����Ϣ" << endl;//���
	cout << "2�����ͼ���������ͼ����Ϣ" << endl;//���
	cout << "3��¼��ͼ����Ϣ(����Ա)" << endl;//���
	cout << "4��ɾ��ͼ����Ϣ(����Ա)" << endl;//���
	cout << "5���޸�ͼ����Ϣ(����Ա)" << endl;//���
	cout << "�������Ӧ��ŵ����ֽ����Ӧ����" << endl;
	cin >> operate_numberl;
	while (cin.fail()) // ��������Ƿ���Ч
	{
		cin.clear(); // ��������־
		cin.ignore(100, '\n'); // ����������еĴ�������
		cout << "��ֻ���������֣����������룺" << endl; // ��ʾ�û���������
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
			cout << "�Բ�������Ȩ�޲���" << endl;
			Sleep(1000);
		}
	}
	else if (operate_numberl == 4)
	{
		if (user_type == Reader)
		{
			cout << "�Բ�������Ȩ�޲���" << endl;
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
			cout << "�Բ�������Ȩ�޲���" << endl;
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
	cout << "��ѡ����ҵ�����" << endl;
	cout << "1��ISBN����" << endl;
	cout << "2���ؼ��ֲ���(���������ߡ�������)" << endl;
	cin >> operate_numberl;
	std::system("cls");
	cin.get();
	if (operate_numberl == 1)
	{
		String isbn;
		cout << "��������Ҫ���ҵ�ISBN��" << endl;
		cin >> isbn;
		User.find_book_ISBN(isbn,user_type);
	}
	if (operate_numberl == 2)
	{
		string keyword;
		cout << "��������Ҫ���ҵ�ͼ��ؼ���" << endl;
		getline(cin, keyword); 
		User.find_book_keyword(keyword, user_type);
	}
}