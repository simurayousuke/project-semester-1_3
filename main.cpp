#include "stdafx.h"
#include "window/loginwindow.h"
#include "commonelements.h"
#include "helper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CommonElements *ce = CommonElements::getInstance();

    ce->setApplication(&a);

    LoginWindow *lw = new LoginWindow;
    ce->setLoginWindow(lw);
    lw->show();
    lw->getLoginGroupBox()->getUsernameEdit()->setFocus();

    ce->getTrayIcon()->show();

    int r = a.exec();

    delete CommonElements::getInstance();

    delete Helper::getInstance();

    return r;

}
