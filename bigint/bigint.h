#pragma once

#include <fstream>

const std::string MAX_BIGINT("170141183460469231731687303715884105727");
const std::string MIN_BIGINT("-170141183460469231731687303715884105727");

class bigint
{
public:
	// constructors
	bigint();

	bigint& operator+=(const bigint&);
	bigint& operator-=(const bigint&);
	bigint& operator*=(const bigint&);
	bigint& operator/=(const bigint&);
	bool operator<(const bigint&);
	bool operator>(const bigint&);
	bool operator==(const bigint&);
	bool& operator!=(const bigint&);
	bool operator!() const;

	void ReadConsole();
	void DisplayConsole();
	void Clear();
	bool CheckSize();
	bool GetSign() const;
	int GetSize() const;



private:
	/*
	*	signed int can store up to 39 digits
	*	1 digit for sign
	*	1 digit for null termination char
	*/
	uint16_t base;

	char digit[41];
	bool negative;
};