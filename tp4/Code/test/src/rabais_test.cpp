
#include "rabais_test.h"

void RabaisTest::setUp()
{
	this->objet_a_tester = new Rabais();
}

void RabaisTest::tearDown()
{
	delete this->objet_a_tester;
}

//d1 = <{ Facture = [total = 0, Client = [25001, “Tremblay”, “Huguette”, 60, “G4S”, 2020] ] , code_client = 25001}, {rabais = 0.15}>
void RabaisTest::test_getRabais_d1()
{
	tm date;
	date.tm_year = 2020;
	objet_a_tester->ajouterClient(new Client(25001, "Tremblay", "Huguette", 60, "G4S", date));
	Facture facture;
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.15, objet_a_tester->getRabais(facture, 25001), 0.01);
}

//d2 = <{Facture = [total = 0, Client = [10000, “Salinas”, “Harold”, 56, “H1C”, 2020] ], code_client = 10000}, {rabais = 0.14}>
void RabaisTest::test_getRabais_d2()
{
	tm date;
	date.tm_year = 2020;
	objet_a_tester->ajouterClient(new Client(10000, "Salinas", "Harold", 56, "H1C", date));
	Facture facture;
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.14, objet_a_tester->getRabais(facture, 10000), 0.01);
}

//d3 = <{Facture = [total = 0, Client = [11000, “Denver”, “John”, 60, “P1D”, 2016] ], code_client = 11000}, {rabais = 0.12}>
void RabaisTest::test_getRabais_d3()
{
	tm date;
	date.tm_year = 2016;
	objet_a_tester->ajouterClient(new Client(11000, "Denver", "John", 60, "P1D", date));
	Facture facture;
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.12, objet_a_tester->getRabais(facture, 11000), 0.01);
}

//d4 = <{Facture = [total = 0, Client = [12000, “Arruda”, “Horacio”, 43, “H3P”, 2020] ], code_client = 12000}, {rabais = 0.03}>
void RabaisTest::test_getRabais_d4()
{
	tm date;
	date.tm_year = 2020;
	objet_a_tester->ajouterClient(new Client(12000, "Arruda", "Horacio", 43, "H3P", date));
	Facture facture;
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.03, objet_a_tester->getRabais(facture, 12000), 0.01);
}

//d5 = <{Facture = [total = 0, Client = [13000, “Santos”, “Baltazar”, 30, “J4O”, 2008] ], code_client = 13000}, {rabais = 0.10}>
void RabaisTest::test_getRabais_d5()
{
	tm date;
	date.tm_year = 2008;
	objet_a_tester->ajouterClient(new Client(13000, "Santos", "Baltazar", 30, "J4O", date));
	Facture facture;
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.10, objet_a_tester->getRabais(facture, 13000), 0.01);
}

//d6 = <{Facture = [total = 0, Client = [14000, “Wayne”, “Bruce”, 14, “S3X”, 2000] ], code_client = 14000}, {rabais = 0.10}>
void RabaisTest::test_getRabais_d6()
{
	tm date;
	date.tm_year = 2000;
	objet_a_tester->ajouterClient(new Client(14000, "Wayne", "Bruce", 14, "S3X", date));
	Facture facture;
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.10, objet_a_tester->getRabais(facture, 14000), 0.01);
}

//d7 = <{Facture = [total = 250, Client = [15000, “Fleck”, “Arthur”, 10, “P0P”, 2020] ], code_client = 15000}, {rabais = 0.02}>
void RabaisTest::test_getRabais_d7()
{
	tm date;
	date.tm_year = 2020;
	objet_a_tester->ajouterClient(new Client(15000, "Fleck", "Arthur", 10, "P0P", date));
	Facture facture;
	facture.ajouterItem(250);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.02, objet_a_tester->getRabais(facture, 15000), 0.01);
}

//d8 = <{Facture = [total = 0, Client = [16000, “Kjelberg”, “Felix”, 9, “T2S”, 2020] ], rabais = 16000}, {code_client = 0.06}>
void RabaisTest::test_getRabais_d8()
{
	tm date;
	date.tm_year = 2020;
	objet_a_tester->ajouterClient(new Client(16000, "Kjelberg", "Felix", 9, "T2S", date));
	Facture facture;
	facture.ajouterItem(1000);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.06, objet_a_tester->getRabais(facture, 16000), 0.01);
}

//d9 = <{Facture = [total = 1000, Client = [17000, “Apple”, “Tim”, 60, “P2Q”, 2020] ], code_client = 17000}, {rabais = 0.16}>
void RabaisTest::test_getRabais_d9()
{
	tm date;
	date.tm_year = 2020;
	objet_a_tester->ajouterClient(new Client(17000, "Apple", "Tim", 60, "P2Q", date));
	Facture facture;
	facture.ajouterItem(1000);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.16, objet_a_tester->getRabais(facture, 17000), 0.01);
}