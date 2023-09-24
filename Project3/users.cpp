#include"head.h"

void users::find_book_ISBN(String ISBN,String user_type)
{
	string line;
	string isbn_in_file;
	bool find_flag = false;
	ifstream infile("books.txt", ios::in);
	if (user_type == Administrator)
	{
		while (getline(infile, line))
		{
			isbn_in_file = line.substr(0, line.find(" ")); 
			if (isbn_in_file == ISBN)
			{
				find_flag = true;
				cout << "�������鱾����Ϣ:" << endl;
				cout << line << endl;
				break;
			}
		}
	}
	else
	{
		while (getline(infile, line))
		{
			isbn_in_file = line.substr(0, line.find(" ")); // ��ȡ��һ������
			
			if (isbn_in_file == ISBN)
			{
				find_flag = true;
				cout << "�������鱾����Ϣ:" << endl;
				cout << isbn_in_file << " ";
				size_t pos = line.find(" "); // �ҵ���һ���ո��λ��
				
				while (pos != string::npos) // ���û�е����ַ�����ĩβ
				{
					pos++; // �ƶ�����һ���ַ�
					if (isdigit(line[pos])) // ���������
					{
						pos = line.find(" ", pos); // ����ֱ����һ���ո�
					}
					else // �����������
					{
						size_t next_pos = line.find(" ", pos); // �ҵ���һ���ո��λ��
						if (next_pos == string::npos) // ���û���ҵ�
						{
							cout << line.substr(pos) << endl; // ���ʣ����ַ���
							break;
						}
						else // ����ҵ���
						{
							cout << line.substr(pos, next_pos - pos) << " "; // �����ǰ�ո����һ���ո�֮����ַ���
							pos = next_pos; // ����λ��
						}
					}
				}
				break;
			}
		}
	}
	if (!find_flag)
	{
		cout << "ͼ��δ�ҵ�" << endl;
	}
	infile.close();
	std::system("pause");
}

int users::find_line(String keyword)
{
	string line;
	ifstream infile("books_find.txt", ios::in);
	int find_line = 0;
	while (getline(infile, line)) 
	{
		find_line++;
		if (line.find(keyword) != string::npos) 
		{
			return find_line;
		}
	}
	infile.close();
	return 0;
}

void users::find_book_keyword(String keyword,String user_type)
{
	string line;
	ifstream infile("books.txt", ios::in);
	bool find_flag = false;
	int line_num = 0;
	int return_line = find_line(keyword);
	if (user_type == Administrator)
	{
		while (getline(infile, line)) 
		{
			line_num++;
			if (line_num==return_line) 
			{
				find_flag = true;
				cout << "�������鱾����Ϣ:" << endl;
				cout << line << endl;
			}
		}
	}
	if (user_type == Reader)
	{
		while (getline(infile, line)) 
		{
			line_num++;
			if (line_num == return_line) 
			{
				find_flag = true;
				cout << "�������鱾����Ϣ:" << endl;
				cout << line.substr(0, line.find(" ")) << " ";
				size_t pos = line.find(" "); // �ҵ���һ���ո��λ��
				while (pos != string::npos) // ���û�е����ַ�����ĩβ
				{
					pos++; // �ƶ�����һ���ַ�
					if (isdigit(line[pos])) // ���������
					{
						pos = line.find(" ", pos); // ����ֱ����һ���ո�
					}
					else // �����������
					{
						size_t next_pos = line.find(" ", pos); // �ҵ���һ���ո��λ��
						if (next_pos == string::npos) // ���û���ҵ�
						{
							cout << line.substr(pos) << endl; // ���ʣ����ַ���
							break;
						}
						else // ����ҵ���
						{
							cout << line.substr(pos, next_pos - pos) << " "; // �����ǰ�ո����һ���ո�֮����ַ���
							pos = next_pos; // ����λ��
						}
					}
				}
				break;
			}
		}
	}
	if (!find_flag)
	{
		cout << "ͼ��δ�ҵ�" << endl;
	}
	infile.close();
	std::system("pause");

}

void users::print_allbook(String user_type)
{
	string line;
	ifstream infile("books.txt", ios::in);
	cout << "***************************" << endl;
	cout << "������ͼ���������ͼ����Ϣ" << endl;
	if (!infile) 
	{
		cout << "�޷����ļ�" << endl;
		return;
	}
	if (user_type == Administrator)
	{
		while (getline(infile, line))
		{
			cout << line << endl; 
		}
	}
	if (user_type == Reader)
	{
		String isbn_in_file;
		while (getline(infile, line))
		{
			isbn_in_file = line.substr(0, line.find(" "));
			size_t pos = line.find(" "); // �ҵ���һ���ո��λ��
			cout << line.substr(0, line.find(" ")) << " ";
			while (pos != string::npos) // ���û�е����ַ�����ĩβ
			{
				pos++; // �ƶ�����һ���ַ�
				if (isdigit(line[pos])) // ���������
				{
					pos = line.find(" ", pos); // ����ֱ����һ���ո�
				}
				else // �����������
				{
					size_t next_pos = line.find(" ", pos); // �ҵ���һ���ո��λ��
					if (next_pos == string::npos) // ���û���ҵ�
					{
						cout << line.substr(pos) << endl; // ���ʣ����ַ���
						break;
					}
					else // ����ҵ���
					{
						cout << line.substr(pos, next_pos - pos) << " "; // �����ǰ�ո����һ���ո�֮����ַ���
						pos = next_pos; // ����λ��
					}
				}
			}
			
		}
	}
	std::system("pause");
}

void users::delet_book()
{
	string line;
	ifstream infile("books.txt", ios::in);
	int line_num = 1;
	cout << "***************************" << endl;
	cout << "������ͼ���������ͼ����Ϣ" << endl;
	while (getline(infile, line))
	{
		cout <<line_num<<"�� " << line << endl; 
		line_num++;
	}
	infile.close();
	cout << "***************************" << endl;
	cout << "��������Ҫɾ������������" << endl;
	int del_num;
	cin >> del_num;
	fstream in("books.txt", ios::in); 
	if (!in) 
	{
		cout << "�ļ���ʧ��" << endl;
		std::system("pause");
		return ;
	}
	string data = ""; 
	int count = 0; 
	while (getline(in, line)) 
	{
		count++; 
		if (count == del_num) 
			continue;
		data += (line + "\n"); 
	}
	in.close(); 
	fstream out("books.txt", ios::out); 
	if (!out) 
	{
		cout << "�ļ���ʧ��" << endl;
		return ;
	}
	out << data; 
	cout << "ɾ���ļ��ɹ�" << endl;
	out.close(); 
	std::system("pause");
}

void users::change_book()
{
	setlocale(LC_ALL, "zh_CN.UTF-8");
	string line;
	ifstream infile("books.txt", ios::in);
	int line_num = 1;
	cout << "***************************" << endl;
	cout << "������ͼ���������ͼ����Ϣ" << endl;
	while (getline(infile, line)) // ��ȡÿһ������
	{
		cout << line_num << "�� " << line << endl; // �����һ������
		line_num++;
	}
	infile.close(); //�ر��ļ�
	cout << "***************************" << endl;
	cout << "��������Ҫ�޸�����������" << endl;
	int del_num;
	cin >> del_num;
	ifstream in("books.txt", ios::in); //�Զ�ģʽ���ļ�
	if (!in) //�ж��ļ��Ƿ����
	{
		cout << "�ļ���ʧ��" << endl;
		std::system("pause");
		return;
	}
	char data[256]; //���ڴ洢�µ�����
	cin.ignore(); //������뻺����
	cout << "�������µ�����" << endl;
	cin.getline(data, 256); //��ȡһ���ַ�����
	
	string newdata = GBToUTF8(data); //ת��Ϊ�ַ���
	ofstream temp("temp.txt", ios::out); //����һ����ʱ�ļ�
	temp.imbue(std::locale(temp.getloc(), new std::codecvt_utf8<wchar_t>)); //�����ַ�����ΪUTF-8
	int count = 0; //���ڼ�¼����
	while (getline(in, line)) //���ж�ȡ�ļ�
	{
		count++; //��������
		if (count == del_num) //�����Ҫ�޸ĵ��кţ��滻Ϊ�µ�����
			temp << newdata << "\n";
		else //���򣬱���ԭ�������ݣ�������
			temp << line << "\n";
	}
	in.close(); //�ر��ļ�
	temp.close(); //�ر���ʱ�ļ�
	remove("books.txt"); //ɾ��ԭ�ļ�
	rename("temp.txt", "books.txt"); //��������ʱ�ļ�Ϊԭ�ļ���
	cout << "�޸��ļ��ɹ�" << endl;

	ifstream in2("books_find.txt", ios::in); //�Զ�ģʽ����һ���ļ�
	if (!in2) //�ж��ļ��Ƿ����
	{
		cout << "��һ���ļ���ʧ��" << endl;
		std::system("pause");
		return;
	}
	ofstream temp2("temp2.txt", ios::out); //����һ����ʱ�ļ�
	count = 0; //��������
	while (getline(in2, line)) //���ж�ȡ��һ���ļ�
	{
		count++; //��������
		if (count == del_num) //�����Ҫ�޸ĵ��кţ��滻Ϊ�µ����ݣ�����Ҫת�����룩
			temp2 << data << "\n";
		else //���򣬱���ԭ�������ݣ�������
			temp2 << line << "\n";
	}
	in2.close(); //�ر���һ���ļ�
	temp2.close(); //�ر���ʱ�ļ�
	remove("books_find.txt"); //ɾ��ԭ�ļ�
	rename("temp2.txt", "books_find.txt"); //��������ʱ�ļ�Ϊԭ�ļ���

	cout << "�޸������ļ��ɹ�" << endl;
	std::system("pause");
}

string GBToUTF8(const char* str)
{
	string result;
	WCHAR* strSrc;
	LPSTR szRes;

	//�����ʱ�����Ĵ�С
	int i = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_ACP, 0, str, -1, strSrc, i);

	//�����ʱ�����Ĵ�С
	i = WideCharToMultiByte(CP_UTF8, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_UTF8, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}

string UTF8ToGB(const char* str)
{
	string result;
	WCHAR* strSrc;
	LPSTR szRes;

	//�����ʱ�����Ĵ�С
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//�����ʱ�����Ĵ�С
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}
