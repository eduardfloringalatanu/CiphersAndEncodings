#pragma once

namespace VariantBeaufort {
	typedef enum ReturnCodes {
		SUCCESS = 0,
		NULL_INPUT,
		INVALID_KEY,
		NULL_OUTPUT
	} ReturnCode;

	ReturnCode Encrypt(const char* const input, const char* const key, char* const output, const unsigned long n);
	ReturnCode Decrypt(const char* const input, const char* const key, char* const output, const unsigned long n);
}