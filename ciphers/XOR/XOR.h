#pragma once

namespace XOR {
	enum {
		NULL_INPUT = 1,
		INVALID_KEY,
		NULL_OUTPUT
	};

	int Encrypt(const unsigned char* const input, const unsigned char* const key, unsigned char* const output, const unsigned long n);
	int Decrypt(const unsigned char* const input, const unsigned char* const key, unsigned char* const output, const unsigned long n);
}