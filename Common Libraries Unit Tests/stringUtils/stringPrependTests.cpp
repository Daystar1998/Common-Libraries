#include "../stdafx.h"
#include "CppUnitTest.h"

#include "../../Common Libraries/src/StringUtils.h"

#include <string>

using std::string;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUtilsUnitTests {

	TEST_CLASS(StringUtilsPrependTests) {

public:

	TEST_METHOD(PrependStringToEmpty) {

		string s = string();

		StringUtils::prepend(s, string("Test"));

		Assert::AreEqual(s, string("Test"));
	}

	TEST_METHOD(StringPrependCharPointerToEmpty) {

		string s = string();

		StringUtils::prepend(s, "Test");

		Assert::AreEqual(s, string("Test"));
	}

	TEST_METHOD(StringPrependEmptyToEmpty) {

		string s = string();

		StringUtils::prepend(s, string());

		Assert::AreEqual(s, string());
	}

	TEST_METHOD(StringPrependStringToString) {

		string s = string("Original");

		StringUtils::prepend(s, string("Test"));

		Assert::AreEqual(s, string("TestOriginal"));
	}

	TEST_METHOD(StringPrependCharPointerToString) {

		string s = string("Original");

		StringUtils::prepend(s, "Test");

		Assert::AreEqual(s, string("TestOriginal"));
	}

	TEST_METHOD(StringPrependEmptyToString) {

		string s = string("Original");

		StringUtils::prepend(s, string());

		Assert::AreEqual(s, string("Original"));
	}

	TEST_METHOD(StringPrependThis) {

		string s = string("Original");

		StringUtils::prepend(s, s);

		Assert::AreEqual(s, string("OriginalOriginal"));
	}
	};
}