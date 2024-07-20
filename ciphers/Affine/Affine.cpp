#include "Affine.h"
#include "../../utils.h"

namespace Affine {
	ReturnCode Encrypt(const char* const input, const int slope, const int intercept, char* const output, const unsigned long n) {
		if (input == nullptr)
			return NULL_INPUT;

		if (modular_multiplicative_inverse(slope, 26) == 0)
			return INVALID_SLOPE;

		if (output == nullptr)
			return NULL_OUTPUT;

		unsigned long k = 0;

		for (const char* c = input; *c != '\0' && k < n; ++c, ++k) {
			if (*c >= 65 && *c <= 90) {
				output[k] = (slope * (*c - 65) + (long long)intercept) % 26 + 65;

				if (output[k] < 65)
					output[k] += 26;
			}
			else if (*c >= 97 && *c <= 122) {
				output[k] = (slope * (*c - 97) + (long long)intercept) % 26 + 97;

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

	ReturnCode Decrypt(const char* const input, const int slope, const int intercept, char* const output, const unsigned long n) {
		if (input == nullptr)
			return NULL_INPUT;

		int slope_inverse = modular_multiplicative_inverse(slope, 26);

		if (slope_inverse == 0)
			return INVALID_SLOPE;

		if (output == nullptr)
			return NULL_OUTPUT;

		unsigned long k = 0;

		for (const char* c = input; *c != '\0' && k < n; ++c, ++k) {
			if (*c >= 65 && *c <= 90) {
				output[k] = (slope_inverse * (*c - 65) - slope_inverse * (long long)intercept) % 26 + 65;

				if (output[k] < 65)
					output[k] += 26;
			} else if (*c >= 97 && *c <= 122) {
				output[k] = (slope_inverse * (*c - 97) - slope_inverse * (long long)intercept) % 26 + 97;

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