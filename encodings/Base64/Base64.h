#pragma once

namespace Base64 {
	typedef enum ReturnCodes {
		SUCCESS = 0,
		NULL_INPUT,
		NULL_OUTPUT
	} ReturnCode;

	ReturnCode Encode(const unsigned char* const input, char* const output, const unsigned long n);
	ReturnCode Decode(const char* const input, unsigned char* const output, const unsigned long n);
}