#include "Vigenere.h"
#include "../../utils.h"

namespace Vigenere {
	ReturnCode Encrypt(const char* const input, const char* const key, char* const output, const unsigned long n) {
		if (input == nullptr)
			return NULL_INPUT;

		unsigned long key_length = get_string_length(key);

		if (!is_string_valid(key) || key_length == 0)
			return INVALID_KEY;

		if (output == nullptr)
			return NULL_OUTPUT;

		unsigned long i = 0, j, k = 0;

		for (const char* c = input; *c != '\0' && k < n; ++c, ++k) {
			j = i % key_length;

			if (*c >= 65 && *c <= 90) {
				if (key[j] >= 65 && key[j] <= 90) {
					output[k] = (*c - 65 + key[j] - 65) % 26 + 65;

					++i;
				} else if (key[j] >= 97 && key[j] <= 122) {
					output[k] = (*c - 65 + key[j] - 97) % 26 + 65;

					++i;
				}
			}
			else if (*c >= 97 && *c <= 122) {
				if (key[j] >= 65 && key[j] <= 90) {
					output[k] = (*c - 97 + key[j] - 65) % 26 + 97;

					++i;
				} else if (key[j] >= 97 && key[j] <= 122) {
					output[k] = (*c - 97 + key[j] - 97) % 26 + 97;

					++i;
				}
			}
			else
				output[k] = *c;
		}

		if (k < n)
			output[k] = '\0';

		return SUCCESS;
	}

	ReturnCode Decrypt(const char* const input, const char* const key, char* const output, const unsigned long n) {
		if (input == nullptr)
			return NULL_INPUT;

		unsigned long key_length = get_string_length(key);

		if (!is_string_valid(key) || key_length == 0)
			return INVALID_KEY;

		if (output == nullptr)
			return NULL_OUTPUT;

		unsigned long i = 0, j, k = 0;

		for (const char* c = input; *c != '\0' && k < n; ++c, ++k) {
			j = i % key_length;

			if (*c >= 65 && *c <= 90) {
				if (key[j] >= 65 && key[j] <= 90) {
					output[k] = (*c - 65 - (key[j] - 65)) % 26 + 65;

					if (output[k] < 65)
						output[k] += 26;

					++i;
				} else if (key[j] >= 97 && key[j] <= 122) {
					output[k] = (*c - 65 - (key[j] - 97)) % 26 + 65;

					if (output[k] < 65)
						output[k] += 26;

					++i;
				}
			} else if (*c >= 97 && *c <= 122) {
				if (key[j] >= 65 && key[j] <= 90) {
					output[k] = (*c - 97 - (key[j] - 65)) % 26 + 97;

					if (output[k] < 97)
						output[k] += 26;

					++i;
				} else if (key[j] >= 97 && key[j] <= 122) {
					output[k] = (*c - 97 - (key[j] - 97)) % 26 + 97;

					if (output[k] < 97)
						output[k] += 26;

					++i;
				}
			} else
				output[k] = *c;
		}

		if (k < n)
			output[k] = '\0';

		return SUCCESS;
	}
}