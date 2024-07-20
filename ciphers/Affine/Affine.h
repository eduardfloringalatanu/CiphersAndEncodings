#pragma once

namespace Affine {
	typedef enum ReturnCodes {
		SUCCESS = 0,
		NULL_INPUT,
		INVALID_SLOPE,
		NULL_OUTPUT
	} ReturnCode;

	ReturnCode Encrypt(const char* const input, const int slope, const int intercept, char* const output, const unsigned long n);
	ReturnCode Decrypt(const char* const input, const int slope, const int intercept, char* const output, const unsigned long n);
}