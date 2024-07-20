#include "Autokey.h"
#include "../../utils.h"

namespace Autokey {
	ReturnCode Encrypt(const char* const input, const char* const key, char* output, const unsigned long n) {
		if (input == nullptr)
			return NULL_INPUT;

		unsigned long key_length = get_string_length(key);

		if (!is_string_valid(key) || key_length == 0)
			return INVALID_KEY;

		if (output == nullptr)
			return NULL_OUTPUT;

		const char* c = input;
		unsigned long k = 0;

		for (unsigned long i = 0; *c != '\0' && k < n && i < key_length; ++c, ++k) {
			if (*c >= 65 && *c <= 90) {
				if (key[i] >= 65 && key[i] <= 90) {
					output[k] = (*c - 65 + key[i] - 65) % 26 + 65;

					++i;
				} else if (key[i] >= 97 && key[i] <= 122) {
					output[k] = (*c - 65 + key[i] - 97) % 26 + 65;

					++i;
				}
			} else if (*c >= 97 && *c <= 122) {
				if (key[i] >= 65 && key[i] <= 90) {
					output[k] = (*c - 97 + key[i] - 65) % 26 + 97;

					++i;
				} else if (key[i] >= 97 && key[i] <= 122) {
					output[k] = (*c - 97 + key[i] - 97) % 26 + 97;

					++i;
				}
			} else
				output[k] = *c;
		}

		unsigned long i = 0;

		while (*c != '\0' && k < n) {
			if (*c >= 65 && *c <= 90) {
				if (input[i] >= 65 && input[i] <= 90) {
					output[k] = (*c - 65 + input[i] - 65) % 26 + 65;

					++i;
				} else if (input[i] >= 97 && input[i] <= 122) {
					output[k] = (*c - 65 + input[i] - 97) % 26 + 65;

					++i;
				} else {
					++i;
					continue;
				}

			} else if (*c >= 97 && *c <= 122) {
				if (input[i] >= 65 && input[i] <= 90) {
					output[k] = (*c - 97 + input[i] - 65) % 26 + 97;

					++i;
				} else if (input[i] >= 97 && input[i] <= 122) {
					output[k] = (*c - 97 + input[i] - 97) % 26 + 97;

					++i;
				} else {
					++i;
					continue;
				}
			} else
				output[k] = *c;

			++c;
			++k;
		}

		if (k < n)
			output[k] = '\0';

		return SUCCESS;
	}

	ReturnCode Decrypt(const char* const input, const char* const key, char* output, const unsigned long n) {
		if (input == nullptr)
			return NULL_INPUT;

		unsigned long key_length = get_string_length(key);

		if (!is_string_valid(key) || key_length == 0)
			return INVALID_KEY;

		if (output == nullptr)
			return NULL_OUTPUT;

		const char* c = input;
		unsigned long k = 0;

		for (unsigned long i = 0; *c != '\0' && k < n && i < key_length; ++c, ++k) {
			if (*c >= 65 && *c <= 90) {
				if (key[i] >= 65 && key[i] <= 90) {
					output[k] = (*c - 65 - (key[i] - 65)) % 26 + 65;

					if (output[k] < 65)
						output[k] += 26;

					++i;
				} else if (key[i] >= 97 && key[i] <= 122) {
					output[k] = (*c - 65 - (key[i] - 97)) % 26 + 65;

					if (output[k] < 65)
						output[k] += 26;

					++i;
				}
			} else if (*c >= 97 && *c <= 122) {
				if (key[i] >= 65 && key[i] <= 90) {
					output[k] = (*c - 97 - (key[i] - 65)) % 26 + 97;

					if (output[k] < 97)
						output[k] += 26;

					++i;
				} else if (key[i] >= 97 && key[i] <= 122) {
					output[k] = (*c - 97 - (key[i] - 97)) % 26 + 97;

					if (output[k] < 97)
						output[k] += 26;

					++i;
				}
			} else
				output[k] = *c;
		}

		unsigned long i = 0;

		while (*c != '\0' && k < n) {
			if (*c >= 65 && *c <= 90) {
				if (output[i] >= 65 && output[i] <= 90) {
					output[k] = (*c - 65 - (output[i] - 65)) % 26 + 65;

					if (output[k] < 65)
						output[k] += 26;

					++i;
				} else if (output[i] >= 97 && output[i] <= 122) {
					output[k] = (*c - 65 - (output[i] - 97)) % 26 + 65;

					if (output[k] < 65)
						output[k] += 26;

					++i;
				} else {
					++i;
					continue;
				}

			} else if (*c >= 97 && *c <= 122) {
				if (output[i] >= 65 && output[i] <= 90) {
					output[k] = (*c - 97 - (output[i] - 65)) % 26 + 97;

					if (output[k] < 97)
						output[k] += 26;

					++i;
				} else if (output[i] >= 97 && output[i] <= 122) {
					output[k] = (*c - 97 - (output[i] - 97)) % 26 + 97;

					if (output[k] < 97)
						output[k] += 26;

					++i;
				} else {
					++i;
					continue;
				}
			} else
				output[k] = *c;

			++c;
			++k;
		}

		if (k < n)
			output[k] = '\0';

		return SUCCESS;
	}
}