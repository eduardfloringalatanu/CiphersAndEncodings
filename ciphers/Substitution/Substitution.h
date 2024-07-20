#pragma once

namespace Substitution {
	static const char atbash_alphabet[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
	static const char albam_alphabet[] = "NOPQRSTUVWXYZABCDEFGHIJKLM";
	static const char atbah_alphabet[] = "IHGFNDCBARQPOEMLKJZYXWVUTS";

	typedef enum ReturnCodes {
		SUCCESS = 0,
		NULL_INPUT,
		INVALID_ALPHABET,
		INVALID_KEY,
		NULL_OUTPUT
	} ReturnCode;

	bool create_alphabet(const char* const key, char* const output);

	ReturnCode Encrypt(const char* const input, const char* const alphabet, char* const output, const unsigned long n);
	ReturnCode Decrypt(const char* const input, const char* const alphabet, char* const output, const unsigned long n);
}