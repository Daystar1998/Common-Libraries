#include "../stdafx.h"
#include "CppUnitTest.h"

#include "../../Common Libraries/src/StringUtils.h"

#include <string>

using std::string;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUtilsUnitTests {

	TEST_CLASS(StringUtilsTrimTests) {

public:

	TEST_METHOD(TrimNoWhitespace) {

		string s = string("This is an example string");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimOneSpaceAtBeginning) {

		string s = string(" This is an example string");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimFiveSpacesAtBeginning) {

		string s = string("     This is an example string");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimOneTabAtBeginning) {

		string s = string("	This is an example string");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimFiveTabsAtBeginning) {

		string s = string("					This is an example string");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimCarriageReturnAtBeginning) {

		string s = string("\rThis is an example string");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimVerticalTabAtBeginning) {

		string s = string("\vThis is an example string");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimMultipleTypesWhitespaceAtBeginning) {

		string s = string("\v\r\t  This is an example string");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimCharacterBeforeSpaceAtBeginning) {

		string s = string("T his is an example string");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("T his is an example string"));
	}

	TEST_METHOD(TrimOneSpaceAtEnd) {

		string s = string("This is an example string ");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimFiveSpacesAtEnd) {

		string s = string("This is an example string     ");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimOneTabAtEnd) {

		string s = string("This is an example string	");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimFiveTabsAtEnd) {

		string s = string("This is an example string					");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimCarriageReturnAtEnd) {

		string s = string("This is an example string\r");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimVerticalTabAtEnd) {

		string s = string("This is an example string\v");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimMultipleTypesWhitespaceAtEnd) {

		string s = string("This is an example string\v\r\t  ");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimOneSpaceAtBothEnds) {

		string s = string(" This is an example string ");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimFiveSpacesAtBothEnds) {

		string s = string("     This is an example string     ");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimOneTabAtBothEnds) {

		string s = string("	This is an example string	");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimFiveTabsAtBothEnds) {

		string s = string("					This is an example string					");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimMultipleTypesWhitespaceAtBothEnds) {

		string s = string("\v\r\t  This is an example string\v\r\t  ");

		StringUtils::trim(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(StringEmptyTrim) {

		string s = string();

		StringUtils::trim(s);

		Assert::AreEqual(s, string());
	}

	TEST_METHOD(TrimOnlyWhitespace) {

		string s = string("\r\t\v ");

		StringUtils::trim(s);

		Assert::AreEqual(s, string());
	}
	};
}