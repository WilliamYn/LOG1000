
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../../src/rabais.h"
#include "../../src/facture.h"
#include "../../src/client.h"


class RabaisTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(RabaisTest);
	CPPUNIT_TEST(test_getRabais_d1);
	CPPUNIT_TEST(test_getRabais_d2);
	CPPUNIT_TEST(test_getRabais_d3);
	CPPUNIT_TEST(test_getRabais_d4);
	CPPUNIT_TEST(test_getRabais_d5);
	CPPUNIT_TEST(test_getRabais_d6);
	CPPUNIT_TEST(test_getRabais_d7);
	CPPUNIT_TEST(test_getRabais_d8);
	CPPUNIT_TEST(test_getRabais_d9);
	CPPUNIT_TEST_SUITE_END();

private: 
	Rabais* objet_a_tester;

public:
	void setUp();
	void test_getRabais_d1();
	void test_getRabais_d2();
	void test_getRabais_d3();
	void test_getRabais_d4();
	void test_getRabais_d5();
	void test_getRabais_d6();
	void test_getRabais_d7();
	void test_getRabais_d8();
	void test_getRabais_d9();
	void tearDown();
};



