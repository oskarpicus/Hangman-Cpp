#include "Spanzuratoare.h"
#include <QtWidgets/QApplication>
#include "teste.h"
#include "UI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Teste teste;
    teste.test_all();
    Repository repo("fisier.txt");
    Validator valid;
    Service service(repo, valid);
    UI ui(service);
    ui.show();
    return a.exec();
}
