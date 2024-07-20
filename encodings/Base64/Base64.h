#pragma once

namespace Base64 {
	enum {
		NULL_INPUT = 1,
		NULL_OUTPUT
	};

	int Encode(const unsigned char* const input, char* const output, const unsigned long n);
	int Decode(const char* const input, unsigned char* const output, const unsigned long n);
}