#pragma once

namespace Trithemius {
	typedef enum ReturnCodes {
		SUCCESS = 0,
		NULL_INPUT,
		NULL_OUTPUT
	} ReturnCode;

	ReturnCode Encrypt(const char* const input, char* const output, const unsigned long n);
	ReturnCode Decrypt(const char* const input, char* const output, const unsigned long n);
}