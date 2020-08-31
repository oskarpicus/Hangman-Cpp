#include "valid.h"

void Validator::valid_word(const Word& w) {
	string mesaj = "";

	if (w.get_cuvant() == "")
		mesaj += "Cuvant vid\n";

	if (!valid_cuvant(w)) //cuvantul are spatii
		mesaj += "Cuvantul nu poate contine caractere speciale\n";

	if (mesaj != "")
		throw ValidError(mesaj);
}

bool Validator::valid_cuvant(const Word& w) {
	bool v = true;

	for (int i = 0; i < w.get_cuvant().size() && v; i++) {
		if (w.get_cuvant()[i] < 'a' || w.get_cuvant()[i]>'z')
			v = false;
	}
	return v;
}