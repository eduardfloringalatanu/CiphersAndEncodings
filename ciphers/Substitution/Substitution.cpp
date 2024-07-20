#include "Substitution.h"

namespace Substitution {
	bool create_alphabet(const char* const key, char* const output) {
		if (key == nullptr || output == nullptr)
			return false;

		bool used[26] = { };
		unsigned long k = 0;

		for (const char* c = key; *c != '\0' && k < 26; ++c) {
			if (*c >= 65 && *c <= 90) {
				if (!used[*c - 65]) {
					output[k++] = *c;
					used[*c - 65] = true;
				}
			} else if (*c >= 97 && *c <= 122) {
				if (!used[*c - 97]) {
					output[k++] = *c - 32;
					used[*c - 97] = true;
				}
			} else
				return false;
		}

		for (int i = 0; i < 26 && k < 26; ++i) {
			if (!used[i]) {
				output[k++] = i + 65;
				used[i] = true;
			}
		}

		output[26] = '\0';

		return true;
	}

	bool is_alphabet_valid(const char* const alphabet) {
		if (alphabet == nullptr)
			return false;

		unsigned long i = 0;

		while (i < 26) {
			if (alphabet[i] == '\0')
				break;

			if (alphabet[i] < 65 || alphabet[i] > 90)
				return false;

			++i;
		}

		if (i < 26)
			return false;

		return true;
	}

	ReturnCode Encrypt(const char* const input, const char* const alphabet, char* const output, const unsigned long n) {
		if (input == nullptr)
			return NULL_INPUT;

		if (!is_alphabet_valid(alphabet))
			return INVALID_ALPHABET;

		if (output == nullptr)
			return NULL_OUTPUT;
		
		unsigned long k = 0;

		for (const char* c = input; *c != '\0' && k < n; ++c, ++k) {
			if (*c >= 65 && *c <= 90)
				output[k] = alphabet[*c - 65];
			else if (*c >= 97 && *c <= 122)
				output[k] = alphabet[*c - 97] + 32;
			else
				output[k] = *c;
		}

		if (k < n)
			output[k] = '\0';

		return SUCCESS;
	}

	ReturnCode Decrypt(const char* const input, const char* const alphabet, char* const output, const unsigned long n) {
		if (input == nullptr)
			return NULL_INPUT;

		if (!is_alphabet_valid(alphabet))
			return INVALID_ALPHABET;

		if (output == nullptr)
			return NULL_OUTPUT;

		auto create_decryption_map = [](const char* alphabet, char* output) {
			for (int i = 0; i < 26; ++i)
				output[alphabet[i] - 65] = i + 65;

			output[26] = '\0';
		};

		char decryption_map[27];
		create_decryption_map(alphabet, decryption_map);

		unsigned long k = 0;

		for (const char* c = input; *c != '\0' && k < n; ++c, ++k) {
			if (*c >= 65 && *c <= 90)
				output[k] = decryption_map[*c - 65];
			else if (*c >= 97 && *c <= 122)
				output[k] = decryption_map[*c - 97] + 32;
			else
				output[k] = *c;
		}

		if (k < n)
			output[k] = '\0';

		return SUCCESS;
	}
}