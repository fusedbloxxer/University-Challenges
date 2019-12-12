#pragma once
#include "Vector.h"

namespace TestUtil {
	// Utilities
	class TesterClass;
	void clearScreen();
	void intOperations();
	void vecOperations();

	// Test Design
	void testManual();
	void testAutomat();
	
	// Tests Plan
	void testVector();
	void testLinkedList();
	void testBigInteger();

	// Test Strategy
	void testMax();
	void testScalar();
	void testAddition();
	void testSubtraction();
	void testMultiplication();
	void testAbsoluteMaximum();

	// Test Cases
	// BigInteger
	BigInteger shouldAdd(BigInteger a, BigInteger b);
	BigInteger shouldSubtract(BigInteger a, BigInteger b);
	BigInteger shouldMultiply(BigInteger a, BigInteger b);
	BigInteger shouldReturnMax(BigInteger a, BigInteger b);

	// Vector
	BigInteger shouldCalculateScalar(Vector a, Vector b);
	BigInteger shouldCalculateMaxAbs(Vector a);
}