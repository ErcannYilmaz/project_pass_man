#include "sign_in.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sign_in w;
    w.show();
    return a.exec();
}
