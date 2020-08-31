#pragma once
#include "repository.h"
#include "valid.h"

class Service {
private:
	Repository& repo;
	Validator& valid;
public:

	//constructor
	Service(Repository& repo, Validator& valid) :repo{ repo }, valid{ valid }{};

	/*
	Functie in vederea adaugarii unui nou cuvant
	pre: cuvant: string, este valid si nu exista deja memorat
	post: repo.lista ' = repo.lista + Word(cuvant)
	*/
	void service_adauga(string cuvant);

	/*
	Functie pentru selectarea unui nou Word
	pre: adevarat
	post: w: Word, w.ales = false
	w' are ales = true
	*/
	Word service_selectare_word();
};