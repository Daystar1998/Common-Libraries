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

	TEST_METHOD(StringPrependCharToEmpty) {

		string s = string();

		StringUtils::prepend(s, 't');

		Assert::AreEqual(s, string("t"));
	}

	TEST_METHOD(StringPrependIntToEmpty) {

		string s = string();

		StringUtils::prepend(s, 100);

		Assert::AreEqual(s, string("100"));
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

	TEST_METHOD(StringPrependCharToString) {

		string s = string("Original");

		StringUtils::prepend(s, 't');

		Assert::AreEqual(s, string("tOriginal"));
	}

	TEST_METHOD(StringPrependIntToString) {

		string s = string("Original");

		StringUtils::prepend(s, 100);

		Assert::AreEqual(s, string("100Original"));
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

	TEST_METHOD(StringPrependNull) {

		string s = string("Original");

		StringUtils::prepend(s, nullptr);

		Assert::AreEqual(s, string("Original"));
	}

	TEST_METHOD(StringPrependNullPointer) {

		string s1 = string("Original");

		string *s2 = nullptr;

#pragma warning(suppress: 6011)
		StringUtils::prepend(s1, *s2);

		Assert::AreEqual(s1, string("Original"));
	}
	};
}