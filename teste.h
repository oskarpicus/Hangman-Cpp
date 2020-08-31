#pragma once
#include "domain.h"
#include "repository.h"
#include "service.h"

class Teste {
private:

	void test_formatat();
	void test_adauga_litera();
	void test_get_cuvant();
	void test_get_ales();
	void test_set_ales();
	void test_repo_fisier();
	void test_repo_adauga();
	void test_repo_sterge();
	void test_valid_word();
	void test_service_adauga();
	void test_service_selectare_word();

public:
	void test_all();
};