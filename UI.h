#pragma once
#include "service.h"
#include <qwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qmessagebox.h>
#include <qlayout.h>
#include "Hangman.h"
#include "FereastraCuvinte.h"

class UI : public QWidget {
private:
	Service& service;
	QLineEdit* text_cuvant = new QLineEdit;
	QPushButton* buton_adauga = new QPushButton("Adauga cuvant");
	Hangman* hangman = new Hangman;
	FereastraCuvinte* fereastra_cuvinte;
	QVBoxLayout* ly_butoane = new QVBoxLayout;
	QPushButton* buton_newgame = new QPushButton("New game");
	vector<QPushButton*> lista_butoane_litere;
	QWidget* butoane = new QWidget;

	void conecteaza();
	void initializeaza();
	void adauga_butoane();

public:

	//constructor
	UI(Service& service) :service{ service } {
		initializeaza();
		conecteaza();
		adauga_butoane();
	};
};