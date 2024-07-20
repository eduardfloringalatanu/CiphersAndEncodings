#include "Trithemius.h"

namespace Trithemius {
	ReturnCode Encrypt(const char* const input, char* const output, const unsigned long n) {
		if (input == nullptr)
			return NULL_INPUT;

		if (output == nullptr)
			return NULL_OUTPUT;

		unsigned long i = 0;
		unsigned long k = 0;

		for (const char* c = input; *c != '\0' && k < n; ++c, ++k) {
			if (*c >= 65 && *c <= 90) {
				output[k] = (*c - 65 + (char)(i % 26)) % 26 + 65;

				++i;
			} else if (*c >= 97 && *c <= 122) {
				output[k] = (*c - 97 + (char)(i % 26)) % 26 + 97;

				++i;
			} else
				output[k] = *c;
		}

		if (k < n)
			output[k] = '\0';

		return SUCCESS;
	}

	ReturnCode Decrypt(const char* const input, char* const output, const unsigned long n) {
		if (input == nullptr)
			return NULL_INPUT;

		if (output == nullptr)
			return NULL_OUTPUT;

		unsigned long i = 0;
		unsigned long k = 0;

		for (const char* c = input; *c != '\0' && k < n; ++c, ++k) {
			if (*c >= 65 && *c <= 90) {
				output[k] = (*c - 65 - (char)(i % 26)) % 26 + 65;

				if (output[k] < 65)
					output[k] += 26;

				++i;
			} else if (*c >= 97 && *c <= 122) {
				output[k] = (*c - 97 - (char)(i % 26)) % 26 + 97;

				if (output[k] < 97)
					output[k] += 26;

				++i;
			} else
				output[k] = *c;
		}

		if (k < n)
			output[k] = '\0';

		return SUCCESS;
	}
}