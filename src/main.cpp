#include <util/Util.h>
#include "MainWindow.h"
#include <DApplication>
#include <DLog>
DWIDGET_USE_NAMESPACE
#ifdef DUTIL_USE_NAMESPACE
DUTIL_USE_NAMESPACE
#else
DCORE_USE_NAMESPACE
#endif
int main(int argc, char *argv[]) {
    DApplication::loadDXcbPlugin();
    DApplication app(argc, argv);
    if (app.setSingleInstance(Util::APPLICATION_NAME)) {
        qRegisterMetaTypeStreamOperators<SQProfile>("SQProfile");
        app.setOrganizationName(Util::ORGANIZATION_NAME);
        app.setApplicationName(Util::APPLICATION_NAME);
        app.setApplicationVersion(Util::VERSION);

        app.setProductIcon(QIcon(":/icons/Resources/shadowsocks-client.png"));
        app.setProductName("Shadowsocks Client");
        app.setApplicationDescription("If you want to keep a secret, you must also hide it from yourself.");
        app.setApplicationAcknowledgementPage("https://github.com/PikachuHy/shadowsocks-client");

        app.setTheme("light");
        app.loadTranslator();
        app.setQuitOnLastWindowClosed(false);
        DLogManager::registerConsoleAppender();
        DLogManager::registerFileAppender();

        MainWindow mainWindow;
//        mainWindow.show();
        return QApplication::exec();
    }
    return 0;
}
