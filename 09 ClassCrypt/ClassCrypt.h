#pragma once
#include <iostream> // ��� ������� cout();
#include <stdlib.h> // ��� ������� system();
#include <cstdio> // ��� ������� remove();
#include <cstring> // ��� ������� strcpy_s();

using namespace std;

class ClassCrypt
{
public:
    string  path_openssl;
    string db_filename;
    string secure_db_filename;
    string password;
    void Decrypt()
    {
        cout << "========= �������� ��������� ����������� =========" << endl;
        cout << "����������, ���������..." << endl;
        string command = path_openssl + " enc -aes-256-cbc -d -in " + secure_db_filename +" -out "+ \
            db_filename +" - pass pass : " + password;
        system(command.c_str());
        if (remove(secure_db_filename.c_str()) != 0) {
            cout << "[!] ������ �������� ������������� ���� ������!" << endl;
        }
    }
    void Crypt()
    {
        string command = path_openssl + " enc -aes-256-cbc -salt -in " + db_filename +" -out " \
            + secure_db_filename +" -pass pass:" + password;
        system(command.c_str());
        if (remove(db_filename.c_str()) != 0)
        {
            cout << "[!] ������ �������� ��������������� ���� ������!" << endl;
        }
    }
    ClassCrypt() {
        path_openssl = "c:\\openssl\\bin\\openssl.exe";
        db_filename = "secure_db_filename";
        secure_db_filename = "secure_dataBinary.txt";
        password = "SecretKey!";
    }
};

