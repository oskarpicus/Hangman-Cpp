#pragma once
#include "domain.h"

class Validator {
private:

	/*
	Functie pentru validarea cuvantului propriu zis
	pre: w: Word
	post: true, daca w.cuvant nu contine caractere speciale
	false, in caz contrar
	*/
	bool valid_cuvant(const Word& w);

public:
	/*
	Functie pentru validarea unui cuvant
	pre: w: Word
	post:
	@ arunca ValidError daca w nu este valid
	*/
	void valid_word(const Word& w);
};

//clasa de erori de tip validator
class ValidError {
private:
	string mesaj;
public:

	//constructor: pre: mesaj: string
	ValidError(string mesaj) :mesaj{ mesaj } {};

	/*
	Getter pentru mesajul erorii
	pre: adevarat
	post: mesaj: string
	*/
	string get_mesaj() {
		return mesaj;
	}
};