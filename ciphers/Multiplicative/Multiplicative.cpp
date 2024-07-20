#include "Multiplicative.h"
#include "../../utils.h"

namespace Multiplicative {
	ReturnCode Encrypt(const char* const input, const int key, char* const output, const unsigned long n) {
		if (input == nullptr)
			return NULL_INPUT;

		if (modular_multiplicative_inverse(key, 26) == 0)
			return INVALID_KEY;

		if (output == nullptr)
			return NULL_OUTPUT;

		unsigned long k = 0;

		for (const char* c = input; *c != '\0' && k < n; ++c, ++k) {
			if (*c >= 65 && *c <= 90) {
				output[k] = ((long long)key * (*c - 65)) % 26 + 65;

				if (output[k] < 65)
					output[k] += 26;
			} else if (*c >= 97 && *c <= 122) {
				output[k] = ((long long)key * (*c - 97)) % 26 + 97;

				if (output[k] < 97)
					output[k] += 26;
			} else
				output[k] = *c;
		}

		if (k < n)
			output[k] = '\0';

		return SUCCESS;
	}

	ReturnCode Decrypt(const char* const input, const int key, char* const output, const unsigned long n) {
		if (input == nullptr)
			return NULL_INPUT;

		int key_inverse = modular_multiplicative_inverse(key, 26);

		if (key_inverse == 0)
			return INVALID_KEY;

		if (output == nullptr)
			return NULL_OUTPUT;

		unsigned long k = 0;

		for (const char* c = input; *c != '\0' && k < n; ++c, ++k) {
			if (*c >= 65 && *c <= 90) {
				output[k] = ((long long)key_inverse * (*c - 65)) % 26 + 65;

				if (output[k] < 65)
					output[k] += 26;
			} else if (*c >= 97 && *c <= 122) {
				output[k] = ((long long)key_inverse * (*c - 97)) % 26 + 97;

				if (output[k] < 97)
					output[k] += 26;
			} else
				output[k] = *c;
		}

		if (k < n)
			output[k] = '\0';

		return SUCCESS;
	}
}