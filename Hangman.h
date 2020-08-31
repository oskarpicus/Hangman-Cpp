#pragma once
#include <qwidget.h>
#include <qpainter.h>
#include <qdebug.h>
#define START_X 200
#define START_Y 5
#define END_SUPPORT_Y 200
#define DIF_SUPPORT_Y 25
#define DIF_SUPORT_X 75
#define END_HANG_X 450
#define END_SMALL_LINE_Y 40
#define RAZA 20
#define END_NECK_Y 100
#define DIF_BODY 25
#define TORSO_LENGTH 50

class HangmanError {
private:
	string mesaj;
public:
	HangmanError(string m) :mesaj{ m } {};

	string get_mesaj() const {
		return mesaj;
	}
};

class Hangman : public QWidget {
private:
	int nr_greseli = 0;
public:

	//Constructor
	Hangman() {
		repaint();
	}

	//Functie pentru desenarea hangman-ului
	void paintEvent(QPaintEvent* event) override {
		QPainter p{ this };

		p.setPen(QPen(Qt::black, 4));

		p.drawLine(START_X, START_Y, START_X, END_SUPPORT_Y); //linia verticala
		p.drawLine(START_X, END_SUPPORT_Y, START_X - DIF_SUPORT_X, END_SUPPORT_Y + DIF_SUPPORT_Y); //suport 1 spanzuratoare
		p.drawLine(START_X, END_SUPPORT_Y, START_X + DIF_SUPORT_X, END_SUPPORT_Y + DIF_SUPPORT_Y); //suport 2 spanzuratoare
		p.drawLine(START_X, START_Y,END_HANG_X, START_Y); //linie orizontala
		p.drawLine(END_HANG_X, START_Y, END_HANG_X, END_SMALL_LINE_Y); //linie verticala mica

		if(nr_greseli>=1)
			p.drawEllipse(QPoint(END_HANG_X, END_SMALL_LINE_Y + RAZA), RAZA, RAZA); //cap
		if(nr_greseli >=2)
			p.drawLine(END_HANG_X, END_SMALL_LINE_Y + 2 * RAZA, END_HANG_X, END_NECK_Y); //gat

		//maini
		if(nr_greseli>=3)
			p.drawLine(END_HANG_X, END_NECK_Y,END_HANG_X - DIF_BODY, END_NECK_Y + DIF_BODY);
		if (nr_greseli >= 4)
			p.drawLine(END_HANG_X, END_NECK_Y, END_HANG_X + DIF_BODY, END_NECK_Y + DIF_BODY);

		if (nr_greseli >= 5)
			p.drawLine(END_HANG_X, END_NECK_Y, END_HANG_X, END_NECK_Y + TORSO_LENGTH); //trunchi

		//picioare
		if (nr_greseli >= 6)
			p.drawLine(END_HANG_X, END_NECK_Y + TORSO_LENGTH, END_HANG_X - DIF_BODY, END_NECK_Y + TORSO_LENGTH + DIF_BODY);
		if (nr_greseli >= 7)
			p.drawLine(END_HANG_X, END_NECK_Y + TORSO_LENGTH, END_HANG_X + DIF_BODY, END_NECK_Y + TORSO_LENGTH + DIF_BODY);
		qDebug() << "aici";
	}

	/*
	Functie pentru resetarea hangman-ului
	pre: adevarat
	post: nr_greseli=0
	*/
	void reset() {
		nr_greseli = 0;
		this->repaint();
	}

	/*
	Functie pentru incrementarea numarului de greseli efectuate
	pre: adevarat
	post: nr_greseli' = nr_greseli + 1
	*/
	void adauga_greseala() {
		nr_greseli++;
		this->repaint();
		if (this->nr_greseli >= 7)
			throw HangmanError("Ati pierdut");
	}
};
