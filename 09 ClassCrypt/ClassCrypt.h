#pragma once
#include <iostream> // для функции cout();
#include <stdlib.h> // для функции system();
#include <cstdio> // для функции remove();
#include <cstring> // для функции strcpy_s();

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
        cout << "========= Загрузка программы расшифровки =========" << endl;
        cout << "Пожалуйста, подождите..." << endl;
        string command = path_openssl + " enc -aes-256-cbc -d -in " + secure_db_filename +" -out "+ \
            db_filename +" - pass pass : " + password;
        system(command.c_str());
        if (remove(secure_db_filename.c_str()) != 0) {
            cout << "[!] Ошибка удаления зашифрованной базы данных!" << endl;
        }
    }
    void Crypt()
    {
        string command = path_openssl + " enc -aes-256-cbc -salt -in " + db_filename +" -out " \
            + secure_db_filename +" -pass pass:" + password;
        system(command.c_str());
        if (remove(db_filename.c_str()) != 0)
        {
            cout << "[!] Ошибка удаления НЕзашифрованной базы данных!" << endl;
        }
    }
    ClassCrypt() {
        path_openssl = "c:\\openssl\\bin\\openssl.exe";
        db_filename = "secure_db_filename";
        secure_db_filename = "secure_dataBinary.txt";
        password = "SecretKey!";
    }
};

