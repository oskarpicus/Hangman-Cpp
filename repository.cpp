#include "repository.h"
#include <fstream>
#include<algorithm>

void Repository::load_from_file() {
	ifstream in(this->fisier);
	string cuv;
	while (in >> cuv) {
		if (cuv == "")
			break;
		this->lista.push_back(Word(cuv));
	}
	in.close();
}

void Repository::update_file() {
	ofstream out(fisier);
	for (const auto& el : lista) {
		out << el.get_cuvant() << endl;
	}
	out.close();
}

void Repository::repo_adauga(Word& w) {
	auto it = find_if(lista.begin(), lista.end(), [w](const Word& w2) {
		return w.get_cuvant()==w2.get_cuvant();
		});
	if (it == lista.end()) //nu a mai fost adaugat
	{
		lista.push_back(w);
		update_file();
	}
	else
		throw RepoError("Cuvant deja adaugat");
}

void Repository::repo_sterge(Word& w) {
	auto it = find_if(lista.begin(), lista.end(), [w](const Word& w2) {
		return w.get_cuvant() == w2.get_cuvant();
		});
	if (it == lista.end()) //nu exista
		throw RepoError("Cuvantul nu exista");
	lista.erase(it);
	update_file();
}

void Repository::repo_set_ales(int indice) {

	if (indice < 0 || indice >= lista.size())
		throw RepoError("Cuvantul nu exista");

	this->lista[indice].set_ales(true);
}