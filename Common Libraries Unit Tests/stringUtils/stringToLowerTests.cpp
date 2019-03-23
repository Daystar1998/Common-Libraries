#include "../stdafx.h"
#include "CppUnitTest.h"

#include "../../Common Libraries/src/StringUtils.h"

#include <string>

using std::string;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUtilsUnitTests {

	TEST_CLASS(StringUtilsToLowerTests) {

public:

	TEST_METHOD(ToLowerAllCaps) {

		string s = string("THIS IS AN EXAMPLE STRING");

		StringUtils::toLower(s);

		Assert::AreEqual(s, string("this is an example string"));
	}

	TEST_METHOD(EmptyToLower) {

		string s = string();

		StringUtils::toLower(s);

		Assert::AreEqual(s, string());
	}

	TEST_METHOD(ToLowerWithNumbersOnEnds) {

		string s = string("1THIS IS AN EXAMPLE STRING1");

		StringUtils::toLower(s);

		Assert::AreEqual(s, string("1this is an example string1"));
	}

	TEST_METHOD(ToLowerWithNumberInMiddle) {

		string s = string("THIS IS AN 1EXAMPLE STRING");

		StringUtils::toLower(s);

		Assert::AreEqual(s, string("this is an 1example string"));
	}

	TEST_METHOD(ToLowerWithSymbolsOnEnds) {

		string s = string("!@#$%^&*()THIS IS AN EXAMPLE STRING!@#$%^&*()");

		StringUtils::toLower(s);

		Assert::AreEqual(s, string("!@#$%^&*()this is an example string!@#$%^&*()"));
	}

	TEST_METHOD(ToLowerWithSymbolsInMiddle) {

		string s = string("THIS IS AN !@#$%^&*()EXAMPLE STRING");

		StringUtils::toLower(s);

		Assert::AreEqual(s, string("this is an !@#$%^&*()example string"));
	}

	TEST_METHOD(ToLowerAlreadyLowercase) {

		string s = string("this is an example string");

		StringUtils::toLower(s);

		Assert::AreEqual(s, string("this is an example string"));
	}
	};
}