#include "teste.h"
#include <assert.h>
#define SIZE_INITIAL 4

void Teste::test_formatat() {
	Word c("ana");
	assert(c.get_formatat() == "a a");
	Word c2("aerul");
	assert(c2.get_formatat() == "a   l");
	Word c3("integritate");
	assert(c3.get_formatat() == "i  e  i   e");
}

void Teste::test_adauga_litera() {
	Word c("aerul");
	assert(c.get_formatat() == "a   l");
	c.adauga_litera('s');
	assert(c.get_formatat() == "a   l");
	c.adauga_litera('r');
	assert(c.get_formatat() == "a r l");
	Word cc("kahgaual");
	cc.adauga_litera('a');
	assert(cc.get_formatat() == "ka  a al");
	Word ccc("laaaan");
	ccc.adauga_litera('a');
	assert(ccc.get_cuvant() == ccc.get_formatat());
}

void Teste::test_get_cuvant() {
	Word c("cuvant");
	assert(c.get_cuvant() == "cuvant");
	Word c2("actualitate");
	assert(c2.get_cuvant() == "actualitate");
}

void Teste::test_get_ales() {
	Word c("aaaa");
	assert(c.get_ales() == false);
}

void Teste::test_set_ales() {
	Word c("askgks");
	assert(!c.get_ales());
	c.set_ales(true);
	assert(c.get_ales());
	c.set_ales(false);
	assert(!c.get_ales());
}

void Teste::test_repo_fisier() {
	Repository repo("fisier_test.txt");
	assert(repo.repo_get_all().size() == SIZE_INITIAL);
	auto lista = repo.repo_get_all();
	auto it = find_if(lista.begin(), lista.end(), [](const Word& w) {
		return w.get_cuvant() == "prosperitate";
		});
	assert(it != lista.end());
	it = find_if(lista.begin(), lista.end(), [](const Word& w) {
		return w.get_cuvant() == "abracadabra";
		});
	assert(it == lista.end());
}

void Teste::test_repo_adauga() {
	Repository repo("fisier_test.txt");
	try {
		repo.repo_adauga(Word("camila"));
		assert(false);
	}
	catch (RepoError& e) {
		assert(e.get_mesaj()=="Cuvant deja adaugat");
	}
	repo.repo_adauga(Word("anarhism"));
	assert(repo.repo_get_all().size() == 1 + SIZE_INITIAL);
	auto lista = repo.repo_get_all();
	auto it = find_if(lista.begin(), lista.end(), [](const Word& w) {
		return w.get_cuvant() == "anarhism";
		});
	assert(it != lista.end());
	repo.repo_sterge(Word("anarhism"));
	assert(repo.repo_get_all().size() == SIZE_INITIAL);
}

void Teste::test_repo_sterge() {
	Repository repo("fisier_test.txt");
	try {
		repo.repo_sterge(Word("caine"));
		assert(false);
	}
	catch (RepoError& e) {
		assert(e.get_mesaj() == "Cuvantul nu exista");
	}
	repo.repo_sterge(Word("prosperitate"));
	assert(repo.repo_get_all().size() == SIZE_INITIAL - 1);
	auto lista = repo.repo_get_all();
	auto it = find_if(lista.begin(), lista.end(), [](const Word& w) {
		return w.get_cuvant() == "prosperitate";
		});
	assert(it == lista.end());
	repo.repo_adauga(Word("prosperitate"));
}

void Teste::test_valid_word() {
	Validator valid;
	valid.valid_word(Word("cuvantul"));
	try {
		valid.valid_word(Word("floarea soarelui"));
		assert(false);
	}
	catch (ValidError& e) {
		assert(e.get_mesaj() == "Cuvantul nu poate contine caractere speciale\n");
	}
	try {
		valid.valid_word(Word("floarea-soarelui"));
		assert(false);
	}
	catch (ValidError& e) {
		assert(e.get_mesaj() == "Cuvantul nu poate contine caractere speciale\n");
	}
	try {
		valid.valid_word(Word("5225!!!!"));
		assert(false);
	}
	catch (ValidError& e) {
		assert(e.get_mesaj() == "Cuvantul nu poate contine caractere speciale\n");
	}
}

void Teste::test_service_adauga() {
	Repository repo("fisier_test.txt");
	Validator valid;
	Service service(repo, valid);
	try {
		service.service_adauga("camila");
		assert(false);
	}
	catch (RepoError& e) {
		assert(e.get_mesaj() == "Cuvant deja adaugat");
	}
	try {
		service.service_adauga("camila cu 2 cocoase");
		assert(false);
	}catch(ValidError& e){
		assert(e.get_mesaj() == "Cuvantul nu poate contine caractere speciale\n");
	}
	service.service_adauga("anaconda");
	assert(repo.repo_get_all().size() == SIZE_INITIAL + 1);
	repo.repo_sterge(Word("anaconda"));
}

void Teste::test_service_selectare_word() {
	Repository repo("fisier_test.txt");
	Validator valid;
	Service service(repo, valid);
	auto cuv=service.service_selectare_word();
	assert(cuv.get_cuvant() == "camila" || cuv.get_cuvant() == "inteligenta" || cuv.get_cuvant() =="aer" || cuv.get_cuvant() =="prosperitate");
}

void Teste::test_all() {
	test_formatat();
	test_adauga_litera();
	test_get_cuvant();
	test_get_ales();
	test_set_ales();
	test_repo_fisier();
	test_repo_sterge();
	test_repo_adauga();
	test_valid_word();
	test_service_adauga();
	test_service_selectare_word();
}