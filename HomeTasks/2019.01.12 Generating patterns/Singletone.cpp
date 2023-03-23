#include <iostream>

using namespace std;

#include <string>
#include <assert.h>

class Logger {
//private:
protected:
    Logger(string login) {
        this->login = login;
    }

    string login;
    static Logger *logger;
public:
    static Logger *getInstance(string logname = "User") {
        if (logger == nullptr)
            logger = new Logger(logname);
        return logger;

    }

    string logName() const { return login; }

    void setLogName(string newLogin) {
        login = newLogin;
    }
};

Logger *Logger::logger = 0;

//class LoggerDer : public Logger
//{
//
//	string password;
//	LoggerDer(string login, string password) : Logger(login), password(password)
//	{}
//public:
//
//};
int main() {
    Logger *l = Logger::getInstance(); // �������� ���������, login = "User"
    cout << l->logName() << endl;;

    Logger *l1 = Logger::getInstance(
            "Admin");// ������ ������ �������� �� ���� ��������� ����� Logger �  login = "Admin"
    cout << l1->logName() << endl; // ������, �� �� ��������, �� ����� ������ login ( "User")

    cout << "\nl : " << l << ",\tl1 : " << l1 << endl;
    _ASSERT(l1 == l); // ������� ��������� �����, ���� ������, �� ���� ������� ����������

    l1->setLogName("Ivanyk"); // ������ ���� ������� ����������
    cout << l1->logName() << endl;
    cout << l->logName() << endl;


}
