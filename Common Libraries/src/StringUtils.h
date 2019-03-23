// Author: Matthew Day

#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class StringUtils {

public:

	static string getNumber(const string &data, int start, int &end);

	static int getNextNumber(const string &data, int start, int &end);

	static string getVariable(const string &data, int start, int &end);

	static string getNextVariable(const string &data, int start, int &end);

	static void prepend(string &str, const string &other);

	static void toUpper(string &str);

	static void toLower(string &str);

	static void trimStart(string &str);

	static void trimEnd(string &str);

	static void trim(string &str);

	static void split(const string &delimiter, vector<String> &oTokens);

	static bool startsWith(const string &other);

	static bool endsWith(const string &other);

	static bool isWhiteSpace(char c);
};