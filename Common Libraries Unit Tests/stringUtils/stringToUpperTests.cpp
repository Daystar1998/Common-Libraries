#include "../stdafx.h"
#include "CppUnitTest.h"

#include "../../Common Libraries/src/StringUtils.h"

#include <string>

using std::string;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUtilsUnitTests {

	TEST_CLASS(StringUtilsToUpperTests) {

public:

	TEST_METHOD(ToUpperAllLower) {

		string s = string("This is an example string");

		StringUtils::toUpper(s);

		Assert::AreEqual(s, string("THIS IS AN EXAMPLE STRING"));
	}

	TEST_METHOD(EmptyToUpper) {

		string s = string();

		StringUtils::toUpper(s);

		Assert::AreEqual(s, string());
	}

	TEST_METHOD(ToUpperWithNumbersOnEnds) {

		string s = string("1This is an example string1");

		StringUtils::toUpper(s);

		Assert::AreEqual(s, string("1THIS IS AN EXAMPLE STRING1"));
	}

	TEST_METHOD(ToUpperWithNumberInMiddle) {

		string s = string("This is an 1example string");

		StringUtils::toUpper(s);

		Assert::AreEqual(s, string("THIS IS AN 1EXAMPLE STRING"));
	}

	TEST_METHOD(ToUpperWithSymbolsOnEnds) {

		string s = string("!@#$%^&*()This is an example string!@#$%^&*()");

		StringUtils::toUpper(s);

		Assert::AreEqual(s, string("!@#$%^&*()THIS IS AN EXAMPLE STRING!@#$%^&*()"));
	}

	TEST_METHOD(ToUpperWithSymbolsInMiddle) {

		string s = string("This is an !@#$%^&*()example string");

		StringUtils::toUpper(s);

		Assert::AreEqual(s, string("THIS IS AN !@#$%^&*()EXAMPLE STRING"));
	}

	TEST_METHOD(ToUpperAlreadyUppercase) {

		string s = string("THIS IS AN EXAMPLE STRING");

		StringUtils::toUpper(s);

		Assert::AreEqual(s, string("THIS IS AN EXAMPLE STRING"));
	}
	};
}