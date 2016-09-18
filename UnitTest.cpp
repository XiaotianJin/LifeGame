#include<iostream>

#include"LIFEGAME_H.hpp"
#include"UNITTEST_H.hpp"


	void LIFEGAMETEST::setUp()
	{
		lifegame.GameInit(50, 50);
	}

	void LIFEGAMETEST::testConstructor()
	{
		CPPUNIT_API(lifegame.FinishCondition() == true);
		CPPUNIT_API(lifegame.OnGameStart() == true);
		CPPUNIT_API(lifegame.RunGame() == true);
	}


void UnitTestMain()
{
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestSuite *suite = new CppUnit::TestSuite();

	suite->addTest(new CppUnit::TestCaller<LIFEGAMETEST>("testConstructor", &LIFEGAMETEST::testConstructor));

	runner.addTest(suite);

	runner.run("", true);
}