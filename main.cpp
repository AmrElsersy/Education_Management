#include <QtCore/QCoreApplication>
#include "system_flow.h"
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString dummy_data_path = "/home/amrelsersy/Desktop/Education/DymmyData.txt";
    System_Flow Get_Startded(dummy_data_path);
    return a.exec();
}
