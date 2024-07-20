#include "Caesar.h"

namespace Caesar {
	ReturnCode Encrypt(const char* const input, const int shift, char* const output, const unsigned long n) {
		if (input == nullptr)
			return NULL_INPUT;

		if (output == nullptr)
			return NULL_OUTPUT;

		unsigned long k = 0;

		for (const char* c = input; *c != '\0' && k < n; ++c, ++k) {
			if (*c >= 65 && *c <= 90) {
				output[k] = (*c - 65 + (long long)shift) % 26 + 65;

				if (output[k] < 65)
					output[k] += 26;
			}
			else if (*c >= 97 && *c <= 122) {
				output[k] = (*c - 97 + (long long)shift) % 26 + 97;

				if (output[k] < 97)
					output[k] += 26;
			}
			else
				output[k] = *c;
		}

		if (k < n)
			output[k] = '\0';

		return SUCCESS;
	}

	ReturnCode Decrypt(const char* const input, const int shift, char* const output, const unsigned long n) {
		if (input == nullptr)
			return NULL_INPUT;

		if (output == nullptr)
			return NULL_OUTPUT;

		unsigned long k = 0;

		for (const char* c = input; *c != '\0' && k < n; ++c, ++k) {
			if (*c >= 65 && *c <= 90) {
				output[k] = (*c - 65 - (long long)shift) % 26 + 65;

				if (output[k] < 65)
					output[k] += 26;
			}
			else if (*c >= 97 && *c <= 122) {
				output[k] = (*c - 97 - (long long)shift) % 26 + 97;

				if (output[k] < 97)
					output[k] += 26;
			}
			else
				output[k] = *c;
		}

		if (k < n)
			output[k] = '\0';

		return SUCCESS;
	}
}