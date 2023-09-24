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
				cout << "以下是书本的信息:" << endl;
				cout << line << endl;
				break;
			}
		}
	}
	else
	{
		while (getline(infile, line))
		{
			isbn_in_file = line.substr(0, line.find(" ")); // 截取第一个单词
			
			if (isbn_in_file == ISBN)
			{
				find_flag = true;
				cout << "以下是书本的信息:" << endl;
				cout << isbn_in_file << " ";
				size_t pos = line.find(" "); // 找到第一个空格的位置
				
				while (pos != string::npos) // 如果没有到达字符串的末尾
				{
					pos++; // 移动到下一个字符
					if (isdigit(line[pos])) // 如果是数字
					{
						pos = line.find(" ", pos); // 跳过直到下一个空格
					}
					else // 如果不是数字
					{
						size_t next_pos = line.find(" ", pos); // 找到下一个空格的位置
						if (next_pos == string::npos) // 如果没有找到
						{
							cout << line.substr(pos) << endl; // 输出剩余的字符串
							break;
						}
						else // 如果找到了
						{
							cout << line.substr(pos, next_pos - pos) << " "; // 输出当前空格和下一个空格之间的字符串
							pos = next_pos; // 更新位置
						}
					}
				}
				break;
			}
		}
	}
	if (!find_flag)
	{
		cout << "图书未找到" << endl;
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
				cout << "以下是书本的信息:" << endl;
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
				cout << "以下是书本的信息:" << endl;
				cout << line.substr(0, line.find(" ")) << " ";
				size_t pos = line.find(" "); // 找到第一个空格的位置
				while (pos != string::npos) // 如果没有到达字符串的末尾
				{
					pos++; // 移动到下一个字符
					if (isdigit(line[pos])) // 如果是数字
					{
						pos = line.find(" ", pos); // 跳过直到下一个空格
					}
					else // 如果不是数字
					{
						size_t next_pos = line.find(" ", pos); // 找到下一个空格的位置
						if (next_pos == string::npos) // 如果没有找到
						{
							cout << line.substr(pos) << endl; // 输出剩余的字符串
							break;
						}
						else // 如果找到了
						{
							cout << line.substr(pos, next_pos - pos) << " "; // 输出当前空格和下一个空格之间的字符串
							pos = next_pos; // 更新位置
						}
					}
				}
				break;
			}
		}
	}
	if (!find_flag)
	{
		cout << "图书未找到" << endl;
	}
	infile.close();
	std::system("pause");

}

void users::print_allbook(String user_type)
{
	string line;
	ifstream infile("books.txt", ios::in);
	cout << "***************************" << endl;
	cout << "以下是图书库内所有图书信息" << endl;
	if (!infile) 
	{
		cout << "无法打开文件" << endl;
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
			size_t pos = line.find(" "); // 找到第一个空格的位置
			cout << line.substr(0, line.find(" ")) << " ";
			while (pos != string::npos) // 如果没有到达字符串的末尾
			{
				pos++; // 移动到下一个字符
				if (isdigit(line[pos])) // 如果是数字
				{
					pos = line.find(" ", pos); // 跳过直到下一个空格
				}
				else // 如果不是数字
				{
					size_t next_pos = line.find(" ", pos); // 找到下一个空格的位置
					if (next_pos == string::npos) // 如果没有找到
					{
						cout << line.substr(pos) << endl; // 输出剩余的字符串
						break;
					}
					else // 如果找到了
					{
						cout << line.substr(pos, next_pos - pos) << " "; // 输出当前空格和下一个空格之间的字符串
						pos = next_pos; // 更新位置
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
	cout << "以下是图书库内所有图书信息" << endl;
	while (getline(infile, line))
	{
		cout <<line_num<<"、 " << line << endl; 
		line_num++;
	}
	infile.close();
	cout << "***************************" << endl;
	cout << "请输入需要删除行数的数字" << endl;
	int del_num;
	cin >> del_num;
	fstream in("books.txt", ios::in); 
	if (!in) 
	{
		cout << "文件打开失败" << endl;
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
		cout << "文件打开失败" << endl;
		return ;
	}
	out << data; 
	cout << "删除文件成功" << endl;
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
	cout << "以下是图书库内所有图书信息" << endl;
	while (getline(infile, line)) // 读取每一行数据
	{
		cout << line_num << "、 " << line << endl; // 输出这一行数据
		line_num++;
	}
	infile.close(); //关闭文件
	cout << "***************************" << endl;
	cout << "请输入需要修改行数的数字" << endl;
	int del_num;
	cin >> del_num;
	ifstream in("books.txt", ios::in); //以读模式打开文件
	if (!in) //判断文件是否存在
	{
		cout << "文件打开失败" << endl;
		std::system("pause");
		return;
	}
	char data[256]; //用于存储新的内容
	cin.ignore(); //清空输入缓冲区
	cout << "请输入新的内容" << endl;
	cin.getline(data, 256); //读取一行字符数组
	
	string newdata = GBToUTF8(data); //转换为字符串
	ofstream temp("temp.txt", ios::out); //创建一个临时文件
	temp.imbue(std::locale(temp.getloc(), new std::codecvt_utf8<wchar_t>)); //设置字符编码为UTF-8
	int count = 0; //用于记录行数
	while (getline(in, line)) //逐行读取文件
	{
		count++; //更新行数
		if (count == del_num) //如果是要修改的行号，替换为新的内容
			temp << newdata << "\n";
		else //否则，保持原来的内容，并换行
			temp << line << "\n";
	}
	in.close(); //关闭文件
	temp.close(); //关闭临时文件
	remove("books.txt"); //删除原文件
	rename("temp.txt", "books.txt"); //重命名临时文件为原文件名
	cout << "修改文件成功" << endl;

	ifstream in2("books_find.txt", ios::in); //以读模式打开另一个文件
	if (!in2) //判断文件是否存在
	{
		cout << "另一个文件打开失败" << endl;
		std::system("pause");
		return;
	}
	ofstream temp2("temp2.txt", ios::out); //创建一个临时文件
	count = 0; //重置行数
	while (getline(in2, line)) //逐行读取另一个文件
	{
		count++; //更新行数
		if (count == del_num) //如果是要修改的行号，替换为新的内容（不需要转换编码）
			temp2 << data << "\n";
		else //否则，保持原来的内容，并换行
			temp2 << line << "\n";
	}
	in2.close(); //关闭另一个文件
	temp2.close(); //关闭临时文件
	remove("books_find.txt"); //删除原文件
	rename("temp2.txt", "books_find.txt"); //重命名临时文件为原文件名

	cout << "修改两个文件成功" << endl;
	std::system("pause");
}

string GBToUTF8(const char* str)
{
	string result;
	WCHAR* strSrc;
	LPSTR szRes;

	//获得临时变量的大小
	int i = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_ACP, 0, str, -1, strSrc, i);

	//获得临时变量的大小
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

	//获得临时变量的大小
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//获得临时变量的大小
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}
