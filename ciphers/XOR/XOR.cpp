#include "XOR.h"
#include "../../utils.h"

namespace XOR {
	int Encrypt(const unsigned char* const input, const unsigned char* const key, unsigned char* const output, const unsigned long n) {
		if (input == nullptr)
			return NULL_INPUT;

		unsigned long key_length = get_string_length((const char* const)key);

		if (key_length == 0)
			return INVALID_KEY;

		if (output == nullptr)
			return NULL_OUTPUT;

		unsigned long k = 0;

		for (const unsigned char* c = input; *c != '\0' && k < n; ++c, ++k)
			output[k] = *c ^ key[k % key_length];

		if (k < n)
			output[k] = '\0';

		return 0;
	}

	int Decrypt(const unsigned char* const input, const unsigned char* const key, unsigned char* const output, const unsigned long n) {
		return Encrypt(input, key, output, n);
	}
}