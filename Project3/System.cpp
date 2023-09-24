#include"head.h"

extern users User;

bool System::check_user()
{
    ifstream infile("users.txt", ios::in);
    if (infile.is_open())
    {
        while (getline(infile, line))
        {
            user = line.substr(0, line.find(" ")); 
            if (reg_name == user)
            {
                int first_space = line.find(" ");
                string rest = line.substr(first_space + 1); 
                password = rest.substr(0, rest.find(" ")); 
                if (reg_password == password) 
                {
                    int second_space = rest.find(" ");
                    rest = rest.substr(second_space + 1); 
                    user_type = rest.substr(0, rest.find(" ")); 
                    cout << user_type << "��¼�ɹ�!" << endl;
                    return true;
                }
                else 
                {
                    cout << "�û������������" << endl;
                    return false;
                }
            }
        }
        infile.close();
        cout << "�û������ڣ�" << endl;
        return false;
    }
    else // �ļ���ʧ��
    {
        cout << "�ļ���ʧ��" << endl;
        return false;
    }
}

void System::api_get(string ISBN)
{

    // ����һ��HTTP�ͻ���ʵ����ָ��api��ַ�������Ͷ˿�
    httplib::Client cli("47.99.80.202", 6066);

    // ����һ��HTTP���������ָ��isbn�ź�appKey
    httplib::Params params;
    params.emplace("isbn", ISBN);
    params.emplace("appKey", "ae1718d4587744b0b79f940fbef69e77");

    cli.set_url_encode(true);
    string query = httplib::detail::params_to_query_str(params);

    // ƴ�ӵõ�������url
    string url = "/openApi/getInfoByIsbn" + query;

    auto res = cli.Get("/openApi/getInfoByIsbn", params, httplib::Headers{});

    if (res && res->status == 200)
    {
        // ��ȡ��Ӧ�����ģ�ת��Ϊjson����
        json j = json::parse(res->body);
        if (j.contains("data"))
        {
            json data = j["data"];
            setlocale(LC_ALL, "zh_CN.UTF-8");
            Book b1(std::string(data["isbn"]), std::string(data["bookName"]), std::string(data["author"]), std::string(data["press"]),
                std::to_string(data["price"].get<double>() / 100.0), std::string(data["clcCode"]));
        }
        else
        {
            cerr << "No data field in json response." << endl;
        }
    }
    else
    {
        cerr << "Request failed." << endl;
    }

}