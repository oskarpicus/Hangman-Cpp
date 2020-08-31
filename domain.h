#pragma once
#include<string>
using namespace std;

class Word {
private:
	string cuvant;
	string formatat; //contine cuvantul, dar doar prima si ultima litera
	bool ales; 

	/*
	Functie pentru determinarea variante formatate a cuvantului
	pre: adevarat
	post: this->formatat se modifica
	*/
	void formatare();

public:

	/*
	Constructor
	pre: cuvant: string
	*/
	Word(string cuvant) :cuvant{ cuvant }, ales{ false }{
		formatare();
	}

	/*
	Getter pentru cuvantul efectiv din entitatea Word
	pre: adevarat
	post: cuvant: string
	*/
	string get_cuvant() const {
		return cuvant;
	}

	/*
	Getter pentru varianta formatata a entitatii
	pre: adevarat
	post: formatat: string
	*/
	string get_formatat() const {
		return formatat;
	}

	/*
	Getter pentru campul ales din entitatea Word
	pre: adevarat
	post: ales: bool
	*/
	bool get_ales() const {
		return ales;
	}

	/*
	Setter pentru indicatorul ales din entitatea Word
	pre: value: bool
	post: Word', Word.ales = value
	*/
	void set_ales(bool value) {
		this->ales = value;
	}

	/*
	Functie pentru modificarea versiunii formatate dupa adaugarea unei litere
	pre: c: char
	post: se completeaza versiunea formatata cu litera c
	*/
	void adauga_litera(char c);
};