#include"head.h"
#pragma warning(disable:4996)
int Book::num_books = 0; 

Book::Book(String isbn, String book_name, String author, String press, String price, String clc_code)
{
	
	ISBN = isbn;
	Book_Name = book_name;
	Author = author;
	Press = press;
	Price = price; 
	CLC_Code = clc_code;

	bool need_write = true; 
	string line; 
	string isbn_in_file;

	ifstream infile("books.txt", ios::in); 
	if (infile.is_open())
	{
		while (getline(infile, line)) 
		{
			isbn_in_file = line.substr(0, line.find(" ")); // 截取第一个单词
			if (isbn_in_file == ISBN) 
			{
				cout << "这本书已经在图书库里了!" << endl;
				need_write = false;
				break;
			}
		}
		infile.close(); 
	}

	if (need_write) 
	{
		ofstream outfile("books.txt", ios::out | ios::app); // 打开文件并追加数据
		if (outfile.is_open())
		{
			outfile << ISBN << " " << Book_Name << " " << Author << " " << Press << " " << Price << " " << CLC_Code << endl;
			outfile.close();

			cout << "录入图书信息成功!" << endl;
			cout << "ISBN号: " << ISBN << endl;
			cout << "书  名: " << Book_Name << endl;
			cout << "作  者: " << Author << endl;
			cout << "出版社: " << Press << endl;
			cout << "价  格: " << Price << endl;
			cout << "分类号: " << CLC_Code << endl;

			num_books++; 
		}
		else
		{
			cout << "打开文件失败!" << endl;
		}
		ofstream outfile2("books_find.txt", ios::out | ios::app); // 打开另一个文件并追加数据
		if (outfile2.is_open())
		{
			string data = ISBN + " " + Book_Name + " " + Author + " " + Press + " " + Price + " " + CLC_Code; // 拼接字符串
			data = UTF8ToGB(data.c_str());
			char* data2 = new char[data.length() + 1]; // 创建一个字符数组
			strcpy(data2, data.c_str()); // 将字符串复制到字符数组中
			outfile2.write(data2, strlen(data2)); // 写入字符数组到文件中
			outfile2.put('\n'); // 写入换行符
			outfile2.close(); // 关闭文件

			delete[] data2; // 释放内存

			cout << "录入另一个图书信息成功!" << endl;
		}
		else
		{
			cout << "打开另一个文件失败!" << endl;
		}
	}
}

Book::~Book()
{

}