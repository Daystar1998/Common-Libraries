#include "../stdafx.h"
#include "CppUnitTest.h"

#include "../../Common Libraries/src/StringUtils.h"

#include <string>

using std::string;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUtilsUnitTests {

	TEST_CLASS(StringUtilsTrimStartTests) {

public:

	TEST_METHOD(TrimStartNoWhitespace) {

		string s = string("This is an example string");

		StringUtils::trimStart(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimStartOneSpaceAtBeginning) {

		string s = string(" This is an example string");

		StringUtils::trimStart(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimStartFiveSpacesAtBeginning) {

		string s = string("     This is an example string");

		StringUtils::trimStart(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimStartOneTabAtBeginning) {

		string s = string("	This is an example string");

		StringUtils::trimStart(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimStartFiveTabsAtBeginning) {

		string s = string("					This is an example string");

		StringUtils::trimStart(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimStartCarriageReturnAtBeginning) {

		string s = string("\rThis is an example string");

		StringUtils::trimStart(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimStartVerticalTabAtBeginning) {

		string s = string("\vThis is an example string");

		StringUtils::trimStart(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimStartMultipleTypesWhitespaceAtBeginning) {

		string s = string("\v\r\t  This is an example string");

		StringUtils::trimStart(s);

		Assert::AreEqual(s, string("This is an example string"));
	}

	TEST_METHOD(TrimStartCharacterBeforeSpaceAtBeginning) {

		string s = string("T his is an example string");

		StringUtils::trimStart(s);

		Assert::AreEqual(s, string("T his is an example string"));
	}

	TEST_METHOD(TrimStartOneSpaceAtEnd) {

		string s = string("This is an example string ");

		StringUtils::trimStart(s);

		Assert::AreEqual(s, string("This is an example string "));
	}

	TEST_METHOD(TrimStartFiveSpacesAtEnd) {

		string s = string("This is an example string     ");

		StringUtils::trimStart(s);

		Assert::AreEqual(s, string("This is an example string     "));
	}

	TEST_METHOD(TrimStartOneTabAtEnd) {

		string s = string("This is an example string	");

		StringUtils::trimStart(s);

		Assert::AreEqual(s, string("This is an example string	"));
	}

	TEST_METHOD(TrimStartFiveTabsAtEnd) {

		string s = string("This is an example string					");

		StringUtils::trimStart(s);

		Assert::AreEqual(s, string("This is an example string					"));
	}

	TEST_METHOD(TrimStartCarriageReturnAtEnd) {

		string s = string("This is an example string\r");

		StringUtils::trimStart(s);

		Assert::AreEqual(s, string("This is an example string\r"));
	}

	TEST_METHOD(TrimStartVerticalTabAtEnd) {

		string s = string("This is an example string\v");

		StringUtils::trimStart(s);

		Assert::AreEqual(s, string("This is an example string\v"));
	}

	TEST_METHOD(TrimStartMultipleTypesWhitespaceAtEnd) {

		string s = string("This is an example string\v\r\t  ");

		StringUtils::trimStart(s);

		Assert::AreEqual(s, string("This is an example string\v\r\t  "));
	}

	TEST_METHOD(TrimStartEmpty) {

		string s = string();

		StringUtils::trimStart(s);

		Assert::AreEqual(s, string());
	}

	TEST_METHOD(TrimStartOnlyWhitespace) {

		string s = string("\r\t\v ");

		StringUtils::trimStart(s);

		Assert::AreEqual(s, string());
	}
	};
}