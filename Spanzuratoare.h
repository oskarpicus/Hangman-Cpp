#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Spanzuratoare.h"

class Spanzuratoare : public QMainWindow
{
    Q_OBJECT

public:
    Spanzuratoare(QWidget *parent = Q_NULLPTR);

private:
    Ui::SpanzuratoareClass ui;
};
