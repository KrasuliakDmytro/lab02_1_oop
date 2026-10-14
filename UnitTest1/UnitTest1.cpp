#include "pch.h"
#include "CppUnitTest.h"
#include "../lr2_1/Progression.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestDefaultConstructor)
        {
            Progression p;

            Assert::AreEqual(1.0, p.getFirst());
            Assert::AreEqual(2.0, p.getSecond());
        }

        // Тест гетерів і сетерів
        TEST_METHOD(TestGettersAndSetters)
        {
            Progression p(2, 3);

            Assert::IsTrue(p.setFirst(5));
            Assert::IsTrue(p.setSecond(4));

            Assert::AreEqual(5.0, p.getFirst());
            Assert::AreEqual(4.0, p.getSecond());
        }


        // Тест обчислення елементів прогресії
        TEST_METHOD(TestElementJ)
        {
            Progression p(2, 3);

            Assert::AreEqual(2.0, p.elementJ(0), 0.0001);
            Assert::AreEqual(6.0, p.elementJ(1), 0.0001);
            Assert::AreEqual(54.0, p.elementJ(3), 0.0001);
        }


        // Тест унарних операторів
        TEST_METHOD(TestUnaryOperators)
        {
            Progression p(2, 3);

            Progression positive = +p;
            Progression negative = -p;

            Assert::AreEqual(2.0, positive.getFirst());
            Assert::AreEqual(3.0, positive.getSecond());

            Assert::AreEqual(-2.0, negative.getFirst());
            Assert::AreEqual(-3.0, negative.getSecond());

            Progression zero(0, 0);
            Assert::IsTrue(!zero);
            Assert::IsFalse(!p);
        }

        // Тест префіксного інкременту
        TEST_METHOD(TestPrefixIncrement)
        {
            Progression p(2, 3);

            ++p;

            Assert::AreEqual(3.0, p.getFirst());
            Assert::AreEqual(3.0, p.getSecond());
        }

        // Тест постфіксного інкременту
        TEST_METHOD(TestPostfixIncrement)
        {
            Progression p(2, 3);

            Progression old = p++;

            Assert::AreEqual(2.0, old.getFirst());
            Assert::AreEqual(3.0, old.getSecond());

            Assert::AreEqual(2.0, p.getFirst());
            Assert::AreEqual(4.0, p.getSecond());
        }

        // Тест префіксного декременту
        TEST_METHOD(TestPrefixDecrement)
        {
            Progression p(2, 3);

            --p;

            Assert::AreEqual(1.0, p.getFirst());
            Assert::AreEqual(3.0, p.getSecond());
        }

        // Тест постфіксного декременту
        TEST_METHOD(TestPostfixDecrement)
        {
            Progression p(2, 3);

            Progression old = p--;

            Assert::AreEqual(2.0, old.getFirst());
            Assert::AreEqual(3.0, old.getSecond());

            Assert::AreEqual(2.0, p.getFirst());
            Assert::AreEqual(2.0, p.getSecond());
        }

        // Тест бінарних операцій
        TEST_METHOD(TestBinaryOperators)
        {
            Progression a(8, 4);
            Progression b(2, 2);

            Progression sum = a + b;
            Assert::AreEqual(10.0, sum.getFirst());
            Assert::AreEqual(6.0, sum.getSecond());

            Progression difference = a - b;
            Assert::AreEqual(6.0, difference.getFirst());
            Assert::AreEqual(2.0, difference.getSecond());

            Progression product = a * b;
            Assert::AreEqual(16.0, product.getFirst());
            Assert::AreEqual(8.0, product.getSecond());

            Progression quotient = a / b;
            Assert::AreEqual(4.0, quotient.getFirst());
            Assert::AreEqual(2.0, quotient.getSecond());
        }

        // Тест складених операцій присвоєння
        TEST_METHOD(TestCompoundOperators)
        {
            Progression a(8, 4);
            Progression b(2, 2);

            a += b;
            Assert::AreEqual(10.0, a.getFirst());
            Assert::AreEqual(6.0, a.getSecond());

            a -= b;
            Assert::AreEqual(8.0, a.getFirst());
            Assert::AreEqual(4.0, a.getSecond());

            a *= b;
            Assert::AreEqual(16.0, a.getFirst());
            Assert::AreEqual(8.0, a.getSecond());

            a /= b;
            Assert::AreEqual(8.0, a.getFirst());
            Assert::AreEqual(4.0, a.getSecond());
        }

        // Тест оператора присвоєння
        TEST_METHOD(TestAssignment)
        {
            Progression a(8, 4);
            Progression b;

            b = a;

            Assert::AreEqual(a.getFirst(), b.getFirst());
            Assert::AreEqual(a.getSecond(), b.getSecond());
        }

        // Тест порівняння
        TEST_METHOD(TestComparison)
        {
            Progression a(2, 3);
            Progression b(2, 3);
            Progression c(4, 5);

            Assert::IsTrue(a == b);
            Assert::IsTrue(a != c);
        }

	};
}
