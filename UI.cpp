#include "UI.h"

void UI::conecteaza() {

	QObject::connect(buton_adauga, &QPushButton::clicked, this, [this]() {
		try {
			auto cuvant = this->text_cuvant->text().toStdString();
			this->service.service_adauga(cuvant);
			QMessageBox::information(this, "Anunt", "Cuvant adaugat cu succes");
		}
		catch (RepoError& e) {
			QMessageBox::critical(this, "Eroare", QString::fromStdString(e.get_mesaj()));
		}
		catch (ValidError& e) {
			QMessageBox::critical(this, "Eroare", QString::fromStdString(e.get_mesaj()));
		}
		});

	QObject::connect(buton_newgame, &QPushButton::clicked, this, [this]() {
		try {
			auto word = this->service.service_selectare_word();
			qDebug() << QString::fromStdString(word.get_cuvant());
			this->fereastra_cuvinte->set_curent(word);
			this->hangman->reset();
			adauga_butoane();
		}
		catch (RepoError& e) {
			QMessageBox::warning(this, "Eroare", QString::fromStdString(e.get_mesaj()));
			this->close();
		}
		});


}

void UI::initializeaza() {

	QVBoxLayout* ly_vrt_principal = new QVBoxLayout;
	fereastra_cuvinte = new FereastraCuvinte(this->service.service_selectare_word());

	this->setLayout(ly_vrt_principal);

	auto ly_or = new QHBoxLayout;
	auto layout_vert = new QVBoxLayout;
	ly_vrt_principal->addLayout(ly_or);
	ly_or->addWidget(fereastra_cuvinte);

	auto widget_dreapta = new QWidget;
	widget_dreapta->setLayout(layout_vert);
	layout_vert->addWidget(hangman);
	layout_vert->addWidget(text_cuvant);
	layout_vert->addWidget(buton_adauga);
	layout_vert->addWidget(buton_newgame);

	ly_or->addWidget(widget_dreapta);
	ly_vrt_principal->addWidget(butoane);
	butoane->setLayout(ly_butoane);

}

void UI::adauga_butoane() {

	//stergem butoanele vechi
	for (int i = 0; i < lista_butoane_litere.size(); i++)
		delete lista_butoane_litere[i];
	lista_butoane_litere.clear();
	auto ly_butoane_sec = new QHBoxLayout;
	ly_butoane->addLayout(ly_butoane_sec);

	for (char litera = 'a'; litera <= 'z'; litera++) {

		if (litera % 10 == 0)
		{
			ly_butoane_sec = new QHBoxLayout;
			ly_butoane->addLayout(ly_butoane_sec);
		}

		if (litera == this->fereastra_cuvinte->get_curent().get_cuvant()[0] || litera == this->fereastra_cuvinte->get_curent().get_cuvant()[this->fereastra_cuvinte->get_curent().get_cuvant().size() - 1]) //ignoram literele puse implicit
			continue;

		auto buton = new QPushButton(QString(QChar::fromLatin1(litera-32)));
		lista_butoane_litere.push_back(buton);
		ly_butoane_sec->addWidget(buton);

		QObject::connect(buton, &QPushButton::clicked, this, [this, litera,buton] {
			
			if (!this->fereastra_cuvinte->adauga_litera(litera))
			{
				try {
					this->hangman->adauga_greseala();
				}
				catch (HangmanError& e) {
					QMessageBox::critical(this, "Game Over", QString::fromStdString(e.get_mesaj()));
					this->buton_newgame->click();
					return;
				}
			}

			delete buton;
			auto it = find_if(lista_butoane_litere.begin(), lista_butoane_litere.end(), [buton](QPushButton* b) {
				return buton == b;
				});
			lista_butoane_litere.erase(it);
			});
	}

}