#pragma once
#include <zbar.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include<nlohmann/json.hpp>
#include "httplib.h"
#include<string>
#include<stdlib.h>
#include <locale>
#include <codecvt>
#pragma execution_character_set( "utf-8" )
#define Administrator "Administrator"
#define Reader "Reader"

using namespace nlohmann;
using namespace zbar;
using namespace cv;
using namespace std;

string GBToUTF8(const char* str);
string UTF8ToGB(const char* str);

class System
{
public:
	bool original_UI();//��ʼ����
	void regisiter_UI();//��¼����
	void Function_UI();//���ܽ���
	void find_book_UI();//ͼ����ҽ���
	bool check_user();//��¼�û���������֤
	void api_get(string ISBN);//ͨ��ISBN����api������Ϣ
	int scan();//ʶ��������

public:

	String line;
	String user;
	String password;
	String user_type;

	String reg_name;
	String reg_password;
	int operate_numberl;
	bool flag;
	String ISBN;
	bool scan_flag;

};

class Book
{
public:
	Book(String isbn, String book_name, String author, String press, String price, String clc_code);
	~Book();

public:
	String ISBN;
	String Book_Name;
	String Author;
	String Press;
	String Price;
	String CLC_Code;
	static int num_books;
};

class users
{
public:
	void find_book_ISBN(String ISBN,String);
	void find_book_keyword(String keyword,String);
	void print_allbook(String);
	void delet_book();
	void change_book();
	int find_line(String);
	String user_type;

private:
	String user_name;
};

