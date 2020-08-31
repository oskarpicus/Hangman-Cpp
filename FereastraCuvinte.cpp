#include "FereastraCuvinte.h"

bool FereastraCuvinte::adauga_litera(char c) {
	auto vechi = this->curent.get_formatat();
	curent.adauga_litera(c);
	if (vechi == curent.get_formatat()) //deci litera nu exista
		return false;
	actualizeaza_labels();
	return true;
}

void FereastraCuvinte::actualizeaza_labels() {
	//stergem vechile labels
	for (const auto& e : lista)
		delete e;
	lista.clear();
	auto cuvant_formatat = curent.get_formatat();
	for (const auto& litera : cuvant_formatat) {
		auto label = new QLabel(((litera == ' ') ? "_" : QString(QChar::fromLatin1(litera-32))));
		label->setStyleSheet("font-weight: bold");
		ly->addWidget(label);
		lista.push_back(label);
	}

	if (cuvant_formatat == curent.get_cuvant())
		QMessageBox::information(this, "Bravo", "Felicitari ! Ai castigat\nApasa pe ""New Game"" pentru a te mai juca odata!");

}