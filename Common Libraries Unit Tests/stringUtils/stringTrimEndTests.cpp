#include "../stdafx.h"
#include "CppUnitTest.h"

#include "../../Common Libraries/src/StringUtils.h"

#include <string>

using std::string;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUtilsUnitTests {

	TEST_CLASS(StringUtilsTrimEndTests) {

public:

	TEST_METHOD(TrimEndNoWhitespace) {

		string s = string("This is an example string");

		StringUtils::trimEnd(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimEndOneSpaceAtBeginning) {

		string s = string(" This is an example string");

		StringUtils::trimEnd(s);

		Assert::AreEqual(s, string(" This is an example string"));
	}

	TEST_METHOD(TrimEndFiveSpacesAtBeginning) {

		string s = string("     This is an example string");

		StringUtils::trimEnd(s);

		Assert::AreEqual(s, string("     This is an example string"));
	}

	TEST_METHOD(TrimEndOneTabAtBeginning) {

		string s = string("	This is an example string");

		StringUtils::trimEnd(s);

		Assert::AreEqual(s, string("	This is an example string"));
	}

	TEST_METHOD(TrimEndFiveTabsAtBeginning) {

		string s = string("					This is an example string");

		StringUtils::trimEnd(s);

		Assert::AreEqual(s, string("					This is an example string"));
	}

	TEST_METHOD(TrimEndCarriageReturnAtBeginning) {

		string s = string("\rThis is an example string");

		StringUtils::trimEnd(s);

		Assert::AreEqual(s, string("\rThis is an example string"));
	}

	TEST_METHOD(TrimEndVerticalTabAtBeginning) {

		string s = string("\vThis is an example string\v");

		StringUtils::trimEnd(s);

		Assert::AreEqual(s, string("\vThis is an example string"));
	}

	TEST_METHOD(TrimEndMultipleTypesWhitespaceAtBeginning) {

		string s = string("\v\r\t  This is an example string");

		StringUtils::trimEnd(s);

		Assert::AreEqual(s, string("\v\r\t  This is an example string"));
	}

	TEST_METHOD(TrimEndCharacterAfterSpaceAtEnd) {

		string s = string("This is an example strin g");

		StringUtils::trimEnd(s);

		Assert::AreEqual(s, string("This is an example strin g"));
	}

	TEST_METHOD(TrimEndOneSpaceAtEnd) {

		string s = string("This is an example string ");

		StringUtils::trimEnd(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimEndFiveSpacesAtEnd) {

		string s = string("This is an example string     ");

		StringUtils::trimEnd(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimEndOneTabAtEnd) {

		string s = string("This is an example string	");

		StringUtils::trimEnd(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimEndFiveTabsAtEnd) {

		string s = string("This is an example string					");

		StringUtils::trimEnd(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimEndCarriageReturnAtEnd) {

		string s = string("This is an example string\r");

		StringUtils::trimEnd(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimEndVerticalTabAtEnd) {

		string s = string("This is an example string\v");

		StringUtils::trimEnd(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimEndMultipleTypesWhitespaceAtEnd) {

		string s = string("This is an example string\v\r\t  ");

		StringUtils::trimEnd(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimEndEmpty) {

		string s = string();

		StringUtils::trimEnd(s);

		Assert::AreEqual(s, string());
	}

	TEST_METHOD(TrimEndOnlyWhitespace) {

		string s = string("\r\t\v ");

		StringUtils::trimEnd(s);

		Assert::AreEqual(s, string());
	}
	};
}