#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

class Logger {
private:
    std::ofstream logfile;

public:
    // �����������
    Logger();

    // ����������
    ~Logger();

    // ����� ��� ��������� �����������
    void log(const std::string& message);
};

#endif