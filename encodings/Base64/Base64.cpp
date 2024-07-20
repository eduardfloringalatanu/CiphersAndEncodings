#include "Base64.h"

namespace Base64 {
	static const char base64_encode_table[] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
		'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
		'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
		'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
		'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
		'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
		'w', 'x', 'y', 'z', '0', '1', '2', '3',
		'4', '5', '6', '7', '8', '9', '+', '/',
	};

	static const unsigned char base64_decode_table[] = {
		0x3E, 0xFF, 0xFF, 0xFF, 0x3F, 0x34, 0x35, 0x36, 0x37, 0x38,
		0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
		0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11,
		0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
		0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29,
		0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33
	};

	int Encode(const unsigned char* const input, char* const output, const unsigned long n) {
		if (input == nullptr)
			return NULL_INPUT;

		if (output == nullptr)
			return NULL_OUTPUT;

		unsigned long i = 0, j = 0, k;
		unsigned char plain[3];
		unsigned long plain_length;
		char encoded[4];

		while (input[i] != '\0') {
			plain_length = 0;

			for (k = 0; k < 3; ++k) {
				if (input[i] != '\0') {
					plain[k] = input[i++];
					++plain_length;
				} else
					plain[k] = '\0';
			}

			encoded[0] = base64_encode_table[plain[0] >> 2];
			encoded[1] = base64_encode_table[((plain[0] & 0x03) << 4) | (plain[1] >> 4)];
			encoded[2] = base64_encode_table[((plain[1] & 0x0F) << 2) | (plain[2] >> 6)];
			encoded[3] = base64_encode_table[plain[2] & 0x3F];

			for (k = 0; k < 4; ++k) {
				if (j >= n)
					break;

				if (k <= plain_length)
					output[j++] = encoded[k];
				else
					output[j++] = '=';
			}
		}

		if (j < n)
			output[j] = '\0';

		return 0;
	}

	int Decode(const char* const input, unsigned char* const output, const unsigned long n) {
		if (input == nullptr)
			return NULL_INPUT;

		if (output == nullptr)
			return NULL_OUTPUT;

		unsigned long i = 0, j = 0, k;
		char encoded[4];
		unsigned char plain[3];

		while (input[i] != '\0') {
			for (k = 0; k < 4; ++k) {
				if (input[i] != '=')
					encoded[k] = base64_decode_table[input[i++] - 43];
				else {
					encoded[k] = '\0';
					++i;
				}
			}

			plain[0] = (encoded[0] << 2) | (encoded[1] >> 4);
			plain[1] = (encoded[1] << 4) | (encoded[2] >> 2);
			plain[2] = (encoded[2] << 6) | encoded[3];

			for (k = 0; k < 3; ++k) {
				if (j >= n)
					break;

				output[j++] = plain[k];
			}
		}

		if (j < n)
			output[j] = '\0';

		return 0;
	}
}