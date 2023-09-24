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
			isbn_in_file = line.substr(0, line.find(" ")); // ��ȡ��һ������
			if (isbn_in_file == ISBN) 
			{
				cout << "�Ȿ���Ѿ���ͼ�������!" << endl;
				need_write = false;
				break;
			}
		}
		infile.close(); 
	}

	if (need_write) 
	{
		ofstream outfile("books.txt", ios::out | ios::app); // ���ļ���׷������
		if (outfile.is_open())
		{
			outfile << ISBN << " " << Book_Name << " " << Author << " " << Press << " " << Price << " " << CLC_Code << endl;
			outfile.close();

			cout << "¼��ͼ����Ϣ�ɹ�!" << endl;
			cout << "ISBN��: " << ISBN << endl;
			cout << "��  ��: " << Book_Name << endl;
			cout << "��  ��: " << Author << endl;
			cout << "������: " << Press << endl;
			cout << "��  ��: " << Price << endl;
			cout << "�����: " << CLC_Code << endl;

			num_books++; 
		}
		else
		{
			cout << "���ļ�ʧ��!" << endl;
		}
		ofstream outfile2("books_find.txt", ios::out | ios::app); // ����һ���ļ���׷������
		if (outfile2.is_open())
		{
			string data = ISBN + " " + Book_Name + " " + Author + " " + Press + " " + Price + " " + CLC_Code; // ƴ���ַ���
			data = UTF8ToGB(data.c_str());
			char* data2 = new char[data.length() + 1]; // ����һ���ַ�����
			strcpy(data2, data.c_str()); // ���ַ������Ƶ��ַ�������
			outfile2.write(data2, strlen(data2)); // д���ַ����鵽�ļ���
			outfile2.put('\n'); // д�뻻�з�
			outfile2.close(); // �ر��ļ�

			delete[] data2; // �ͷ��ڴ�

			cout << "¼����һ��ͼ����Ϣ�ɹ�!" << endl;
		}
		else
		{
			cout << "����һ���ļ�ʧ��!" << endl;
		}
	}
}

Book::~Book()
{

}