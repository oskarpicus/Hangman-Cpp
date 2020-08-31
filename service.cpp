#include "service.h"
#include <stdlib.h>
#include<time.h>

void Service::service_adauga(string cuvant) {
	auto w = Word(cuvant);
	this->valid.valid_word(w);
	this->repo.repo_adauga(w);
}

Word Service::service_selectare_word() {
	srand(time(NULL));
	auto lista = this->repo.repo_get_all();
	auto size = lista.size();
	int i;

	//verificam daca mai avem cuvinte disponibile
	for (i = 0; i < size && lista[i].get_ales(); i++);

	if(i==size)
		throw RepoError("Nu mai exista cuvinte memorate neselectate");

	while(1) { //stim ca avem cuvinte neselectate, incercam pana il gasim
		auto indice = rand() % size;
		if (lista[indice].get_ales() == false)
		{
			this->repo.repo_set_ales(indice);
			return lista[indice];
		}
	}
}