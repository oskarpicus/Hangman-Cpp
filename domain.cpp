#include "domain.h"

void Word::formatare() {
	if (cuvant.size() == 0)
		return;
	this->formatat.resize(this->cuvant.size());
	char prima = this->cuvant[0], ultima = this->cuvant[this->cuvant.size() - 1];
	int contor = 0;
	for (const auto& litera : this->cuvant) {
		if (litera == prima || litera == ultima)
			formatat[contor] = litera;
		else
			formatat[contor] = ' ';
		contor++;
	}
}

void Word::adauga_litera(char c) {
	for (int i = 0; i < this->cuvant.size(); i++)
		if (cuvant[i] == c)
			formatat[i] = c;
}