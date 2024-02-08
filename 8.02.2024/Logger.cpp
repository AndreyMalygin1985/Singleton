#include "Logger.h"

Logger* Logger::GetInstance()
{
    if (!pObj) {
        pObj = new Logger();
    }
    return pObj;
}

Logger* Logger::pObj = NULL;

void Logger::PutMessage(string msg)
{
    auto start = chrono::system_clock::now();
    auto legacyStart = chrono::system_clock::to_time_t(start);
    ofstream fObj("logfile.txt", ios::app);
    if (!fObj)
    {
        cout << "Файл не создан" << endl;
        exit(EXIT_FAILURE);
    }
    fObj << msg.c_str() << "\t" << ctime(&legacyStart) << endl;
}
