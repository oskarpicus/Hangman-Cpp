#pragma once
#include <qwidget.h>
#include "service.h"
#include <qlabel.h>
#include <qlayout.h>
#include <qmessagebox.h>

class FereastraCuvinte : public QWidget {
private:
	Word curent;
	vector<QLabel*> lista;
	QHBoxLayout* ly = new QHBoxLayout;

	void actualizeaza_labels();

public:
	
	//Constructor
	FereastraCuvinte(Word w) :curent{ w } {
		this->setLayout(ly);
		actualizeaza_labels();
	};

	/*
	Functie pentru adaugarea unei litere in spatiu destinat
	pre: c: char
	post: true, daca c este in word-ul curent, false, altfel
	*/
	bool adauga_litera(char c);


	//Getter pentru cuvantul curent
	Word get_curent() const {
		return curent;
	}

	//Setter pentru cuvantul curent
	void set_curent(Word w) {
		curent = w;
		actualizeaza_labels();
	}
};