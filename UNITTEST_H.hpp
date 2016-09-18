#pragma once
#ifndef UNITTEST_H
#define UNITTEST_H

#include<iostream>

#include"LIFEGAME_H.hpp"

#include "cppunit/TestFixture.h"
#include "cppunit/ui/text/TestRunner.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestSuite.h"

using namespace std;

class LIFEGAMETEST : public CppUnit::TestFixture
{
protected:
	LIFEGAME lifegame;

public:
	void setUp();

	void testConstructor();
};

void UnitTestMain();

#endif // !UNITTEST_H