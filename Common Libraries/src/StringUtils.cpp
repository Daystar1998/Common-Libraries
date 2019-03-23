// Author: Matthew Day

#include "stringUtils.h"

#include <cctype>
#include <stack>
#include <vector>

using std::isdigit;
using std::isalnum;
using std::stack;

string StringUtils::getNumber(const string &data, int start, int &end) {

	string result = "";
	int position = start;

	if (data[start] == '-') {

		result.push_back('-');
		position++;
	}

	for (int i = position; i < data.length(); i++) {

		if (isdigit(data[i])) {

			result.push_back(data[i]);
		} else {

			break;
		}

		end = i;
	}

	return result;
}

int StringUtils::getNextNumber(const string &data, int start, int &end) {

	int result = 0;

	for (int i = start; i < data.length(); i++) {

		if (isdigit(data[i]) || data[i] == '-') {

			result = stoi(getNumber(data, i, end));
			break;
		}
	}

	return result;
}

string StringUtils::getVariable(const string &data, int start, int &end) {

	string result = "";
	int position = start;

	for (int i = position; i < data.length(); i++) {

		if (isalnum(data[i]) || data[i] == '_') {

			result.push_back(data[i]);
		} else {

			break;
		}

		end = i;
	}

	return result;
}

string StringUtils::getNextVariable(const string &data, int start, int &end) {

	string result = "";

	for (int i = start; i < data.length(); i++) {

		if (isalpha(data[i])) {

			result = getVariable(data, i, end);
			break;
		}
	}

	return result;
}

void StringUtils::prepend(string &str, const string &other) {

	string result(other);

	result.append(str);

	str.assign(result);
}

void StringUtils::toUpper(string &str) {

	if (!str.empty()) {

		size_t length = str.length();
		char *result = new char[length + 1];

		for (size_t i = 0; i < length; i++) {

			if (str.at(i) >= 97 && str.at(i) <= 122) {

				result[i] = str.at(i) - 32;
			} else {

				result[i] = str.at(i);
			}
		}

		result[length] = '\0';

		str.assign(result);

		delete[] result;
	}
}

void StringUtils::toLower(string &str) {

	if (!str.empty()) {

		size_t length = str.length();
		char *result = new char[length + 1];

		for (size_t i = 0; i < length; i++) {

			if (str.at(i) >= 65 && str.at(i) <= 90) {

				result[i] = str.at(i) + 32;
			} else {

				result[i] = str.at(i);
			}
		}

		result[length] = '\0';

		str.assign(result);

		delete[] result;
	}
}

void StringUtils::trimStart(string &str) {

	if (!str.empty()) {

		int start;

		for (start = 0; start < str.length(); start++) {

			if (!isWhiteSpace(str.at(start))) {

				break;
			}
		}

		str.assign(str.substr(start, str.length() - start));
	}
}

void StringUtils::trimEnd(string &str) {

	if (!str.empty()) {

		int end;

		for (end = (int)str.length() - 1; end >= 0; end--) {

			if (!isWhiteSpace(str.at(end))) {

				break;
			}
		}

		str.assign(str.substr(0, end + 1));
	}
}

void StringUtils::trim() {

	this->trimStart();
	this->trimEnd();
}

void StringUtils::split(const string &delimiter, vector<String> &oTokens) {

	size_t start = 0;
	size_t end = 0;

	start = this->find_first_not_of(delimiter, end);

	while (start != -1) {

		end = this->find(delimiter, start);
		oTokens.push_back(this->substr(start, end - start));

		start = this->find_first_not_of(delimiter, end);
	}
}

bool StringUtils::startsWith(const string &other) {

	bool result = false;

	if (this->length() >= other.length()) {

		size_t j = 0;

		bool matching = false;

		for (int i = 0; i < other.length(); i++) {

			if (other[i] == this->at(j)) {

				matching = true;
			} else {

				matching = false;
				break;
			}

			j++;
		}

		if (matching) {

			result = true;
		}
	}

	return result;
}

bool StringUtils::endsWith(const string &other) {

	bool result = false;

	if (this->length() >= other.length()) {

		size_t j = this->length() - 1;

		bool matching = false;

		for (int i = (int)other.length() - 1; i >= 0; i--) {

			if (other[i] == this->at(j)) {

				matching = true;
			} else {

				matching = false;
				break;
			}

			j--;
		}

		if (matching) {

			result = true;
		}
	}

	return result;
}

bool StringUtils::isWhiteSpace(char c) {

	bool result = false;

	switch (c) {

		case ' ':
		case '\n':
		case '\r':
		case '\t':
		case '\v':

			result = true;
			break;
	}

	return result;
}