#pragma once
#include "domain.h"
#include <vector>

//clasa de erori de tip repository
class RepoError {
private:
	string mesaj;
public:
	//constructor: pre: mesaj: string
	RepoError(string m) :mesaj{ m } {};

	/*
	Getter pentru mesajul unei erori
	pre: adevarat
	post: mesaj: string
	*/
	string get_mesaj() const {
		return mesaj;
	}
};

class Repository {
private:
	string fisier;
	vector<Word> lista;

	//functie pentru incarcarea datelor din fisier
	void load_from_file();

	//functie pentru incarcarea datelor in fisier
	void update_file();
public:

	//Constructor: pre: f: string, un nume de fisier
	Repository(string f) :fisier{ f } {
		load_from_file();
	}

	/*
	Functie pentru adaugarea unui nou cuvant
	pre: w: Word
	post: lista' = lista + w
	@ arunca RepoError daca w se afla deja in lista
	*/
	void repo_adauga(Word& w);

	/*
	Functie pentru stergerea unui cuvant
	pre: w: Word
	post: lista' = lista - w
	@ arunca RepoError daca w nu se afla in lista
	*/
	void repo_sterge(Word& w);

	/*
	Functie pentru obtinerea tuturor cuvintelor memorate
	pre: adevarat
	post: lista: vector<Word>
	*/
	vector<Word>& repo_get_all()  {
		return this->lista;
	}

	/*
	Functie pentru modificarea atributului de ales al unui element
	pre: indice: int, pozitie valida din lista
	post: lista[indice]' are ales = true
	*/
	void repo_set_ales(int indice);
};