/*
Problem:    204. Sleepwalker
Judge:      spoj
Author:     Alchemist
Date:       2011/8/2
Category:   Divide And Conquer
Difficulty: **
*/
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <cmath>

/*
follow copy from bigint
https://mattmccutchen.net/index.html
It's a good lib. And i have cut some notes. Now It's only 48000B.
*/
#ifndef NUMBERLIKEARRAY_H
#define NUMBERLIKEARRAY_H
#ifndef NULL
#define NULL 0
#endif
template <class Blk>
class NumberlikeArray {
public:
	typedef unsigned int Index;
	static const unsigned int N;
	Index cap;
	Index len;
	Blk *blk;
	NumberlikeArray(Index c) : cap(c), len(0) {
		blk = (cap > 0) ? (new Blk[cap]) : NULL;
	}
	NumberlikeArray() : cap(0), len(0) {
		blk = NULL;
	}
	~NumberlikeArray() {
		delete [] blk;
	}
	void allocate(Index c);
	void allocateAndCopy(Index c);
	NumberlikeArray(const NumberlikeArray<Blk> &x);
	void operator=(const NumberlikeArray<Blk> &x);
	NumberlikeArray(const Blk *b, Index blen);
	Index getCapacity()     const { return cap;      }
	Index getLength()       const { return len;      }
	Blk   getBlock(Index i) const { return blk[i];   }
	bool  isEmpty()         const { return len == 0; }
	bool operator ==(const NumberlikeArray<Blk> &x) const;

	bool operator !=(const NumberlikeArray<Blk> &x) const {
		return !operator ==(x);
	}
};

template <class Blk>
const unsigned int NumberlikeArray<Blk>::N = 8 * sizeof(Blk);

template <class Blk>
void NumberlikeArray<Blk>::allocate(Index c) {
	if (c > cap) {
		delete [] blk;
		cap = c;
		blk = new Blk[cap];
	}
}

template <class Blk>
void NumberlikeArray<Blk>::allocateAndCopy(Index c) {
	if (c > cap) {
		Blk *oldBlk = blk;
		cap = c;
		blk = new Blk[cap];
		Index i;
		for (i = 0; i < len; i++)
			blk[i] = oldBlk[i];
		delete [] oldBlk;
	}
}

template <class Blk>
NumberlikeArray<Blk>::NumberlikeArray(const NumberlikeArray<Blk> &x)
		: len(x.len) {
	cap = len;
	blk = new Blk[cap];
	Index i;
	for (i = 0; i < len; i++)
		blk[i] = x.blk[i];
}

template <class Blk>
void NumberlikeArray<Blk>::operator=(const NumberlikeArray<Blk> &x) {
	if (this == &x)
		return;
	len = x.len;
	allocate(len);
	Index i;
	for (i = 0; i < len; i++)
		blk[i] = x.blk[i];
}

template <class Blk>
NumberlikeArray<Blk>::NumberlikeArray(const Blk *b, Index blen)
		: cap(blen), len(blen) {
	blk = new Blk[cap];
	Index i;
	for (i = 0; i < len; i++)
		blk[i] = b[i];
}

template <class Blk>
bool NumberlikeArray<Blk>::operator ==(const NumberlikeArray<Blk> &x) const {
	if (len != x.len)
		return false;
	else {
		Index i;
		for (i = 0; i < len; i++)
			if (blk[i] != x.blk[i])
				return false;
		return true;
	}
}

#endif

#ifndef BIGUNSIGNED_H
#define BIGUNSIGNED_H

class BigUnsigned : protected NumberlikeArray<unsigned long> {

public:
	enum CmpRes { less = -1, equal = 0, greater = 1 };

	typedef unsigned long Blk;

	typedef NumberlikeArray<Blk>::Index Index;
	NumberlikeArray<Blk>::N;

protected:
	BigUnsigned(int, Index c) : NumberlikeArray<Blk>(0, c) {}
	void zapLeadingZeros() {
		while (len > 0 && blk[len - 1] == 0)
			len--;
	}

public:
	BigUnsigned() : NumberlikeArray<Blk>() {}

	BigUnsigned(const BigUnsigned &x) : NumberlikeArray<Blk>(x) {}

	void operator=(const BigUnsigned &x) {
		NumberlikeArray<Blk>::operator =(x);
	}

	BigUnsigned(const Blk *b, Index blen) : NumberlikeArray<Blk>(b, blen) {
		zapLeadingZeros();
	}
	~BigUnsigned() {}
	BigUnsigned(unsigned long  x);
	BigUnsigned(         long  x);
	BigUnsigned(unsigned int   x);
	BigUnsigned(         int   x);
	BigUnsigned(unsigned short x);
	BigUnsigned(         short x);
protected:
	template <class X> void initFromPrimitive      (X x);
	template <class X> void initFromSignedPrimitive(X x);
public:
	unsigned long  toUnsignedLong () const;
	long           toLong         () const;
	unsigned int   toUnsignedInt  () const;
	int            toInt          () const;
	unsigned short toUnsignedShort() const;
	short          toShort        () const;
protected:
	// Helpers
	template <class X> X convertToSignedPrimitive() const;
	template <class X> X convertToPrimitive      () const;
public:

	NumberlikeArray<Blk>::getCapacity;
	NumberlikeArray<Blk>::getLength;
	Blk getBlock(Index i) const { return i >= len ? 0 : blk[i]; }
	void setBlock(Index i, Blk newBlock);
	bool isZero() const { return NumberlikeArray<Blk>::isEmpty(); }
	Index bitLength() const;
	bool getBit(Index bi) const {
		return (getBlock(bi / N) & (Blk(1) << (bi % N))) != 0;
	}
	void setBit(Index bi, bool newBit);
	CmpRes compareTo(const BigUnsigned &x) const;
	bool operator ==(const BigUnsigned &x) const {
		return NumberlikeArray<Blk>::operator ==(x);
	}
	bool operator !=(const BigUnsigned &x) const {
		return NumberlikeArray<Blk>::operator !=(x);
	}
	bool operator < (const BigUnsigned &x) const { return compareTo(x) == less   ; }
	bool operator <=(const BigUnsigned &x) const { return compareTo(x) != greater; }
	bool operator >=(const BigUnsigned &x) const { return compareTo(x) != less   ; }
	bool operator > (const BigUnsigned &x) const { return compareTo(x) == greater; }
	void add(const BigUnsigned &a, const BigUnsigned &b);
	void subtract(const BigUnsigned &a, const BigUnsigned &b);
	void multiply(const BigUnsigned &a, const BigUnsigned &b);
	void bitAnd(const BigUnsigned &a, const BigUnsigned &b);
	void bitOr(const BigUnsigned &a, const BigUnsigned &b);
	void bitXor(const BigUnsigned &a, const BigUnsigned &b);
	void bitShiftLeft(const BigUnsigned &a, int b);
	void bitShiftRight(const BigUnsigned &a, int b);
	void divideWithRemainder(const BigUnsigned &b, BigUnsigned &q);
	BigUnsigned operator +(const BigUnsigned &x) const;
	BigUnsigned operator -(const BigUnsigned &x) const;
	BigUnsigned operator *(const BigUnsigned &x) const;
	BigUnsigned operator /(const BigUnsigned &x) const;
	BigUnsigned operator %(const BigUnsigned &x) const;
	BigUnsigned operator &(const BigUnsigned &x) const;
	BigUnsigned operator |(const BigUnsigned &x) const;
	BigUnsigned operator ^(const BigUnsigned &x) const;
	BigUnsigned operator <<(int b) const;
	BigUnsigned operator >>(int b) const;
	void operator +=(const BigUnsigned &x);
	void operator -=(const BigUnsigned &x);
	void operator *=(const BigUnsigned &x);
	void operator /=(const BigUnsigned &x);
	void operator %=(const BigUnsigned &x);
	void operator &=(const BigUnsigned &x);
	void operator |=(const BigUnsigned &x);
	void operator ^=(const BigUnsigned &x);
	void operator <<=(int b);
	void operator >>=(int b);
	void operator ++(   );
	void operator ++(int);
	void operator --(   );
	void operator --(int);
	friend Blk getShiftedBlock(const BigUnsigned &num, Index x,
			unsigned int y);
	template <class X>
	friend X convertBigUnsignedToPrimitiveAccess(const BigUnsigned &a);
};
inline BigUnsigned BigUnsigned::operator +(const BigUnsigned &x) const {
	BigUnsigned ans;
	ans.add(*this, x);
	return ans;
}
inline BigUnsigned BigUnsigned::operator -(const BigUnsigned &x) const {
	BigUnsigned ans;
	ans.subtract(*this, x);
	return ans;
}
inline BigUnsigned BigUnsigned::operator *(const BigUnsigned &x) const {
	BigUnsigned ans;
	ans.multiply(*this, x);
	return ans;
}
inline BigUnsigned BigUnsigned::operator /(const BigUnsigned &x) const {
	if (x.isZero()) throw "BigUnsigned::operator /: division by zero";
	BigUnsigned q, r;
	r = *this;
	r.divideWithRemainder(x, q);
	return q;
}
inline BigUnsigned BigUnsigned::operator %(const BigUnsigned &x) const {
	if (x.isZero()) throw "BigUnsigned::operator %: division by zero";
	BigUnsigned q, r;
	r = *this;
	r.divideWithRemainder(x, q);
	return r;
}
inline BigUnsigned BigUnsigned::operator &(const BigUnsigned &x) const {
	BigUnsigned ans;
	ans.bitAnd(*this, x);
	return ans;
}
inline BigUnsigned BigUnsigned::operator |(const BigUnsigned &x) const {
	BigUnsigned ans;
	ans.bitOr(*this, x);
	return ans;
}
inline BigUnsigned BigUnsigned::operator ^(const BigUnsigned &x) const {
	BigUnsigned ans;
	ans.bitXor(*this, x);
	return ans;
}
inline BigUnsigned BigUnsigned::operator <<(int b) const {
	BigUnsigned ans;
	ans.bitShiftLeft(*this, b);
	return ans;
}
inline BigUnsigned BigUnsigned::operator >>(int b) const {
	BigUnsigned ans;
	ans.bitShiftRight(*this, b);
	return ans;
}

inline void BigUnsigned::operator +=(const BigUnsigned &x) {
	add(*this, x);
}
inline void BigUnsigned::operator -=(const BigUnsigned &x) {
	subtract(*this, x);
}
inline void BigUnsigned::operator *=(const BigUnsigned &x) {
	multiply(*this, x);
}
inline void BigUnsigned::operator /=(const BigUnsigned &x) {
	if (x.isZero()) throw "BigUnsigned::operator /=: division by zero";
	BigUnsigned q;
	divideWithRemainder(x, q);
	*this = q;
}
inline void BigUnsigned::operator %=(const BigUnsigned &x) {
	if (x.isZero()) throw "BigUnsigned::operator %=: division by zero";
	BigUnsigned q;
	divideWithRemainder(x, q);
}
inline void BigUnsigned::operator &=(const BigUnsigned &x) {
	bitAnd(*this, x);
}
inline void BigUnsigned::operator |=(const BigUnsigned &x) {
	bitOr(*this, x);
}
inline void BigUnsigned::operator ^=(const BigUnsigned &x) {
	bitXor(*this, x);
}
inline void BigUnsigned::operator <<=(int b) {
	bitShiftLeft(*this, b);
}
inline void BigUnsigned::operator >>=(int b) {
	bitShiftRight(*this, b);
}
template <class X>
void BigUnsigned::initFromPrimitive(X x) {
	if (x == 0)
		; // NumberlikeArray already initialized us to zero.
	else {
		// Create a single block.  blk is NULL; no need to delete it.
		cap = 1;
		blk = new Blk[1];
		len = 1;
		blk[0] = Blk(x);
	}
}
template <class X>
void BigUnsigned::initFromSignedPrimitive(X x) {
	if (x < 0)
		throw "BigUnsigned constructor: "
			"Cannot construct a BigUnsigned from a negative number";
	else
		initFromPrimitive(x);
}
template <class X>
X BigUnsigned::convertToPrimitive() const {
	if (len == 0)
		// The number is zero; return zero.
		return 0;
	else if (len == 1) {
		// The single block might fit in an X.  Try the conversion.
		X x = X(blk[0]);
		// Make sure the result accurately represents the block.
		if (Blk(x) == blk[0])
			// Successful conversion.
			return x;
		// Otherwise fall through.
	}
	throw "BigUnsigned::to<Primitive>: "
		"Value is too big to fit in the requested type";
}
template <class X>
X BigUnsigned::convertToSignedPrimitive() const {
	X x = convertToPrimitive<X>();
	if (x >= 0)
		return x;
	else
		throw "BigUnsigned::to(Primitive): "
			"Value is too big to fit in the requested type";
}

#endif

BigUnsigned::BigUnsigned(unsigned long  x) { initFromPrimitive      (x); }
BigUnsigned::BigUnsigned(unsigned int   x) { initFromPrimitive      (x); }
BigUnsigned::BigUnsigned(unsigned short x) { initFromPrimitive      (x); }
BigUnsigned::BigUnsigned(         long  x) { initFromSignedPrimitive(x); }
BigUnsigned::BigUnsigned(         int   x) { initFromSignedPrimitive(x); }
BigUnsigned::BigUnsigned(         short x) { initFromSignedPrimitive(x); }

unsigned long  BigUnsigned::toUnsignedLong () const { return convertToPrimitive      <unsigned long >(); }
unsigned int   BigUnsigned::toUnsignedInt  () const { return convertToPrimitive      <unsigned int  >(); }
unsigned short BigUnsigned::toUnsignedShort() const { return convertToPrimitive      <unsigned short>(); }
long           BigUnsigned::toLong         () const { return convertToSignedPrimitive<         long >(); }
int            BigUnsigned::toInt          () const { return convertToSignedPrimitive<         int  >(); }
short          BigUnsigned::toShort        () const { return convertToSignedPrimitive<         short>(); }

void BigUnsigned::setBlock(Index i, Blk newBlock) {
	if (newBlock == 0) {
		if (i < len) {
			blk[i] = 0;
			zapLeadingZeros();
		}
	} else {
		if (i >= len) {
			allocateAndCopy(i+1);
			for (Index j = len; j < i; j++)
				blk[j] = 0;
			len = i+1;
		}
		blk[i] = newBlock;
	}
}
BigUnsigned::Index BigUnsigned::bitLength() const {
	if (isZero())
		return 0;
	else {
		Blk leftmostBlock = getBlock(len - 1);
		Index leftmostBlockLen = 0;
		while (leftmostBlock != 0) {
			leftmostBlock >>= 1;
			leftmostBlockLen++;
		}
		return leftmostBlockLen + (len - 1) * N;
	}
}

void BigUnsigned::setBit(Index bi, bool newBit) {
	Index blockI = bi / N;
	Blk block = getBlock(blockI), mask = Blk(1) << (bi % N);
	block = newBit ? (block | mask) : (block & ~mask);
	setBlock(blockI, block);
}

// COMPARISON
BigUnsigned::CmpRes BigUnsigned::compareTo(const BigUnsigned &x) const {
	if (len < x.len)
		return less;
	else if (len > x.len)
		return greater;
	else {
		Index i = len;
		while (i > 0) {
			i--;
			if (blk[i] == x.blk[i])
				continue;
			else if (blk[i] > x.blk[i])
				return greater;
			else
				return less;
		}
		return equal;
	}
}

// COPY-LESS OPERATIONS
#define DTRT_ALIASED(cond, op) \
	if (cond) { \
		BigUnsigned tmpThis; \
		tmpThis.op; \
		*this = tmpThis; \
		return; \
	}



void BigUnsigned::add(const BigUnsigned &a, const BigUnsigned &b) {
	DTRT_ALIASED(this == &a || this == &b, add(a, b));
	if (a.len == 0) {
		operator =(b);
		return;
	} else if (b.len == 0) {
		operator =(a);
		return;
	}
	bool carryIn, carryOut;
	Blk temp;
	Index i;
	const BigUnsigned *a2, *b2;
	if (a.len >= b.len) {
		a2 = &a;
		b2 = &b;
	} else {
		a2 = &b;
		b2 = &a;
	}
	len = a2->len + 1;
	allocate(len);
	for (i = 0, carryIn = false; i < b2->len; i++) {
		// Add input blocks
		temp = a2->blk[i] + b2->blk[i];
		carryOut = (temp < a2->blk[i]);
		// If a carry was input, handle it
		if (carryIn) {
			temp++;
			carryOut |= (temp == 0);
		}
		blk[i] = temp; // Save the addition result
		carryIn = carryOut; // Pass the carry along
	}
	for (; i < a2->len && carryIn; i++) {
		temp = a2->blk[i] + 1;
		carryIn = (temp == 0);
		blk[i] = temp;
	}
	for (; i < a2->len; i++)
		blk[i] = a2->blk[i];
	// Set the extra block if there's still a carry, decrease length otherwise
	if (carryIn)
		blk[i] = 1;
	else
		len--;
}

void BigUnsigned::subtract(const BigUnsigned &a, const BigUnsigned &b) {
	DTRT_ALIASED(this == &a || this == &b, subtract(a, b));
	if (b.len == 0) {
		// If b is zero, copy a.
		operator =(a);
		return;
	} else if (a.len < b.len)
		throw "BigUnsigned::subtract: "
			"Negative result in unsigned calculation";
	// Some variables...
	bool borrowIn, borrowOut;
	Blk temp;
	Index i;
	// Set preliminary length and make room
	len = a.len;
	allocate(len);
	for (i = 0, borrowIn = false; i < b.len; i++) {
		temp = a.blk[i] - b.blk[i];
		borrowOut = (temp > a.blk[i]);
		// Handle an incoming borrow
		if (borrowIn) {
			borrowOut |= (temp == 0);
			temp--;
		}
		blk[i] = temp; // Save the subtraction result
		borrowIn = borrowOut; // Pass the borrow along
	}
	for (; i < a.len && borrowIn; i++) {
		borrowIn = (a.blk[i] == 0);
		blk[i] = a.blk[i] - 1;
	}
	if (borrowIn) {
		len = 0;
		throw "BigUnsigned::subtract: Negative result in unsigned calculation";
	} else
		// Copy over the rest of the blocks
		for (; i < a.len; i++)
			blk[i] = a.blk[i];
	// Zap leading zeros
	zapLeadingZeros();
}

inline BigUnsigned::Blk getShiftedBlock(const BigUnsigned &num,
	BigUnsigned::Index x, unsigned int y) {
	BigUnsigned::Blk part1 = (x == 0 || y == 0) ? 0 : (num.blk[x - 1] >> (BigUnsigned::N - y));
	BigUnsigned::Blk part2 = (x == num.len) ? 0 : (num.blk[x] << y);
	return part1 | part2;
}

void BigUnsigned::multiply(const BigUnsigned &a, const BigUnsigned &b) {
	DTRT_ALIASED(this == &a || this == &b, multiply(a, b));
	// If either a or b is zero, set to zero.
	if (a.len == 0 || b.len == 0) {
		len = 0;
		return;
	}
	Index i, j, k;
	unsigned int i2;
	Blk temp;
	bool carryIn, carryOut;
	// Set preliminary length and make room
	len = a.len + b.len;
	allocate(len);
	// Zero out this object
	for (i = 0; i < len; i++)
		blk[i] = 0;
	// For each block of the first number...
	for (i = 0; i < a.len; i++) {
		// For each 1-bit of that block...
		for (i2 = 0; i2 < N; i2++) {
			if ((a.blk[i] & (Blk(1) << i2)) == 0)
				continue;

			for (j = 0, k = i, carryIn = false; j <= b.len; j++, k++) {
				temp = blk[k] + getShiftedBlock(b, j, i2);
				carryOut = (temp < blk[k]);
				if (carryIn) {
					temp++;
					carryOut |= (temp == 0);
				}
				blk[k] = temp;
				carryIn = carryOut;
			}
			for (; carryIn; k++) {
				blk[k]++;
				carryIn = (blk[k] == 0);
			}
		}
	}
	// Zap possible leading zero
	if (blk[len - 1] == 0)
		len--;
}

void BigUnsigned::divideWithRemainder(const BigUnsigned &b, BigUnsigned &q) {
	if (this == &q)
		throw "BigUnsigned::divideWithRemainder: Cannot write quotient and remainder into the same variable";
	if (this == &b || &q == &b) {
		BigUnsigned tmpB(b);
		divideWithRemainder(tmpB, q);
		return;
	}
	if (b.len == 0) {
		q.len = 0;
		return;
	}

	if (len < b.len) {
		q.len = 0;
		return;
	}

	Index i, j, k;
	unsigned int i2;
	Blk temp;
	bool borrowIn, borrowOut;

	Index origLen = len;
	allocateAndCopy(len + 1);
	len++;
	blk[origLen] = 0;
	Blk *subtractBuf = new Blk[len];

	q.len = origLen - b.len + 1;
	q.allocate(q.len);
	// Zero out the quotient
	for (i = 0; i < q.len; i++)
		q.blk[i] = 0;

	i = q.len;
	while (i > 0) {
		i--;
		q.blk[i] = 0;
		i2 = N;
		while (i2 > 0) {
			i2--;
			for (j = 0, k = i, borrowIn = false; j <= b.len; j++, k++) {
				temp = blk[k] - getShiftedBlock(b, j, i2);
				borrowOut = (temp > blk[k]);
				if (borrowIn) {
					borrowOut |= (temp == 0);
					temp--;
				}
				subtractBuf[k] = temp;
				borrowIn = borrowOut;
			}
			for (; k < origLen && borrowIn; k++) {
				borrowIn = (blk[k] == 0);
				subtractBuf[k] = blk[k] - 1;
			}
			if (!borrowIn) {
				q.blk[i] |= (Blk(1) << i2);
				while (k > i) {
					k--;
					blk[k] = subtractBuf[k];
				}
			}
		}
	}
	// Zap possible leading zero in quotient
	if (q.blk[q.len - 1] == 0)
		q.len--;
	// Zap any/all leading zeros in remainder
	zapLeadingZeros();
	// Deallocate subtractBuf.
	// (Thanks to Brad Spencer for noticing my accidental omission of this!)
	delete [] subtractBuf;
}

void BigUnsigned::bitAnd(const BigUnsigned &a, const BigUnsigned &b) {
	DTRT_ALIASED(this == &a || this == &b, bitAnd(a, b));
	// The bitwise & can't be longer than either operand.
	len = (a.len >= b.len) ? b.len : a.len;
	allocate(len);
	Index i;
	for (i = 0; i < len; i++)
		blk[i] = a.blk[i] & b.blk[i];
	zapLeadingZeros();
}

void BigUnsigned::bitOr(const BigUnsigned &a, const BigUnsigned &b) {
	DTRT_ALIASED(this == &a || this == &b, bitOr(a, b));
	Index i;
	const BigUnsigned *a2, *b2;
	if (a.len >= b.len) {
		a2 = &a;
		b2 = &b;
	} else {
		a2 = &b;
		b2 = &a;
	}
	allocate(a2->len);
	for (i = 0; i < b2->len; i++)
		blk[i] = a2->blk[i] | b2->blk[i];
	for (; i < a2->len; i++)
		blk[i] = a2->blk[i];
	len = a2->len;
	// Doesn't need zapLeadingZeros.
}

void BigUnsigned::bitXor(const BigUnsigned &a, const BigUnsigned &b) {
	DTRT_ALIASED(this == &a || this == &b, bitXor(a, b));
	Index i;
	const BigUnsigned *a2, *b2;
	if (a.len >= b.len) {
		a2 = &a;
		b2 = &b;
	} else {
		a2 = &b;
		b2 = &a;
	}
	allocate(a2->len);
	for (i = 0; i < b2->len; i++)
		blk[i] = a2->blk[i] ^ b2->blk[i];
	for (; i < a2->len; i++)
		blk[i] = a2->blk[i];
	len = a2->len;
	zapLeadingZeros();
}

void BigUnsigned::bitShiftLeft(const BigUnsigned &a, int b) {
	DTRT_ALIASED(this == &a, bitShiftLeft(a, b));
	if (b < 0) {
		if (b << 1 == 0)
			throw "BigUnsigned::bitShiftLeft: "
				"Pathological shift amount not implemented";
		else {
			bitShiftRight(a, -b);
			return;
		}
	}
	Index shiftBlocks = b / N;
	unsigned int shiftBits = b % N;
	// + 1: room for high bits nudged left into another block
	len = a.len + shiftBlocks + 1;
	allocate(len);
	Index i, j;
	for (i = 0; i < shiftBlocks; i++)
		blk[i] = 0;
	for (j = 0, i = shiftBlocks; j <= a.len; j++, i++)
		blk[i] = getShiftedBlock(a, j, shiftBits);
	// Zap possible leading zero
	if (blk[len - 1] == 0)
		len--;
}

void BigUnsigned::bitShiftRight(const BigUnsigned &a, int b) {
	DTRT_ALIASED(this == &a, bitShiftRight(a, b));
	if (b < 0) {
		if (b << 1 == 0)
			throw "BigUnsigned::bitShiftRight: "
				"Pathological shift amount not implemented";
		else {
			bitShiftLeft(a, -b);
			return;
		}
	}
	Index rightShiftBlocks = (b + N - 1) / N;
	unsigned int leftShiftBits = N * rightShiftBlocks - b;
	if (rightShiftBlocks >= a.len + 1) {
		len = 0;
		return;
	}
	len = a.len + 1 - rightShiftBlocks;
	allocate(len);
	Index i, j;
	for (j = rightShiftBlocks, i = 0; j <= a.len; j++, i++)
		blk[i] = getShiftedBlock(a, j, leftShiftBits);
	// Zap possible leading zero
	if (blk[len - 1] == 0)
		len--;
}

// INCREMENT/DECREMENT OPERATORS

// Prefix increment
void BigUnsigned::operator ++() {
	Index i;
	bool carry = true;
	for (i = 0; i < len && carry; i++) {
		blk[i]++;
		carry = (blk[i] == 0);
	}
	if (carry) {
		// Allocate and then increase length, as in divideWithRemainder
		allocateAndCopy(len + 1);
		len++;
		blk[i] = 1;
	}
}

// Postfix increment: same as prefix
void BigUnsigned::operator ++(int) {
	operator ++();
}

// Prefix decrement
void BigUnsigned::operator --() {
	if (len == 0)
		throw "BigUnsigned::operator --(): Cannot decrement an unsigned zero";
	Index i;
	bool borrow = true;
	for (i = 0; borrow; i++) {
		borrow = (blk[i] == 0);
		blk[i]--;
	}
	// Zap possible leading zero (there can only be one)
	if (blk[len - 1] == 0)
		len--;
}

// Postfix decrement: same as prefix
void BigUnsigned::operator --(int) {
	operator --();
}

#ifndef BIGINTEGER_H
#define BIGINTEGER_H
class BigInteger {

public:
	typedef BigUnsigned::Blk Blk;
	typedef BigUnsigned::Index Index;
	typedef BigUnsigned::CmpRes CmpRes;
	static const CmpRes
		less    = BigUnsigned::less   ,
		equal   = BigUnsigned::equal  ,
		greater = BigUnsigned::greater;
	enum Sign { negative = -1, zero = 0, positive = 1 };

protected:
	Sign sign;
	BigUnsigned mag;

public:
	// Constructs zero.
	BigInteger() : sign(zero), mag() {}

	// Copy constructor
	BigInteger(const BigInteger &x) : sign(x.sign), mag(x.mag) {};

	// Assignment operator
	void operator=(const BigInteger &x);

	// Constructor that copies from a given array of blocks with a sign.
	BigInteger(const Blk *b, Index blen, Sign s);

	// Nonnegative constructor that copies from a given array of blocks.
	BigInteger(const Blk *b, Index blen) : mag(b, blen) {
		sign = mag.isZero() ? zero : positive;
	}

	// Constructor from a BigUnsigned and a sign
	BigInteger(const BigUnsigned &x, Sign s);

	// Nonnegative constructor from a BigUnsigned
	BigInteger(const BigUnsigned &x) : mag(x) {
		sign = mag.isZero() ? zero : positive;
	}

	// Constructors from primitive integer types
	BigInteger(unsigned long  x);
	BigInteger(         long  x);
	BigInteger(unsigned int   x);
	BigInteger(         int   x);
	BigInteger(unsigned short x);
	BigInteger(         short x);

	/* Converters to primitive integer types
	 * The implicit conversion operators caused trouble, so these are now
	 * named. */
	unsigned long  toUnsignedLong () const;
	long           toLong         () const;
	unsigned int   toUnsignedInt  () const;
	int            toInt          () const;
	unsigned short toUnsignedShort() const;
	short          toShort        () const;
protected:
	// Helper
	template <class X> X convertToUnsignedPrimitive() const;
	template <class X, class UX> X convertToSignedPrimitive() const;
public:

	// ACCESSORS
	Sign getSign() const { return sign; }
	/* The client can't do any harm by holding a read-only reference to the
	 * magnitude. */
	const BigUnsigned &getMagnitude() const { return mag; }

	// Some accessors that go through to the magnitude
	Index getLength() const { return mag.getLength(); }
	Index getCapacity() const { return mag.getCapacity(); }
	Blk getBlock(Index i) const { return mag.getBlock(i); }
	bool isZero() const { return sign == zero; } // A bit special

	CmpRes compareTo(const BigInteger &x) const;

	// Ordinary comparison operators
	bool operator ==(const BigInteger &x) const {
		return sign == x.sign && mag == x.mag;
	}
	bool operator !=(const BigInteger &x) const { return !operator ==(x); };
	bool operator < (const BigInteger &x) const { return compareTo(x) == less   ; }
	bool operator <=(const BigInteger &x) const { return compareTo(x) != greater; }
	bool operator >=(const BigInteger &x) const { return compareTo(x) != less   ; }
	bool operator > (const BigInteger &x) const { return compareTo(x) == greater; }

	// OPERATORS -- See the discussion in BigUnsigned.hh.
	void add     (const BigInteger &a, const BigInteger &b);
	void subtract(const BigInteger &a, const BigInteger &b);
	void multiply(const BigInteger &a, const BigInteger &b);
	void divideWithRemainder(const BigInteger &b, BigInteger &q);
	void negate(const BigInteger &a);


	BigInteger operator +(const BigInteger &x) const;
	BigInteger operator -(const BigInteger &x) const;
	BigInteger operator *(const BigInteger &x) const;
	BigInteger operator /(const BigInteger &x) const;
	BigInteger operator %(const BigInteger &x) const;
	BigInteger operator -() const;

	void operator +=(const BigInteger &x);
	void operator -=(const BigInteger &x);
	void operator *=(const BigInteger &x);
	void operator /=(const BigInteger &x);
	void operator %=(const BigInteger &x);
	void flipSign();

	// INCREMENT/DECREMENT OPERATORS
	void operator ++(   );
	void operator ++(int);
	void operator --(   );
	void operator --(int);
};

inline BigInteger BigInteger::operator +(const BigInteger &x) const {
	BigInteger ans;
	ans.add(*this, x);
	return ans;
}
inline BigInteger BigInteger::operator -(const BigInteger &x) const {
	BigInteger ans;
	ans.subtract(*this, x);
	return ans;
}
inline BigInteger BigInteger::operator *(const BigInteger &x) const {
	BigInteger ans;
	ans.multiply(*this, x);
	return ans;
}
inline BigInteger BigInteger::operator /(const BigInteger &x) const {
	if (x.isZero()) throw "BigInteger::operator /: division by zero";
	BigInteger q, r;
	r = *this;
	r.divideWithRemainder(x, q);
	return q;
}
inline BigInteger BigInteger::operator %(const BigInteger &x) const {
	if (x.isZero()) throw "BigInteger::operator %: division by zero";
	BigInteger q, r;
	r = *this;
	r.divideWithRemainder(x, q);
	return r;
}
inline BigInteger BigInteger::operator -() const {
	BigInteger ans;
	ans.negate(*this);
	return ans;
}


inline void BigInteger::operator +=(const BigInteger &x) {
	add(*this, x);
}
inline void BigInteger::operator -=(const BigInteger &x) {
	subtract(*this, x);
}
inline void BigInteger::operator *=(const BigInteger &x) {
	multiply(*this, x);
}
inline void BigInteger::operator /=(const BigInteger &x) {
	if (x.isZero()) throw "BigInteger::operator /=: division by zero";
	/* The following technique is slightly faster than copying *this first
	 * when x is large. */
	BigInteger q;
	divideWithRemainder(x, q);
	// *this contains the remainder, but we overwrite it with the quotient.
	*this = q;
}
inline void BigInteger::operator %=(const BigInteger &x) {
	if (x.isZero()) throw "BigInteger::operator %=: division by zero";
	BigInteger q;
	// Mods *this by x.  Don't care about quotient left in q.
	divideWithRemainder(x, q);
}
// This one is trivial
inline void BigInteger::flipSign() {
	sign = Sign(-sign);
}

#endif

void BigInteger::operator =(const BigInteger &x) {
	// Calls like a = a have no effect
	if (this == &x)
		return;
	// Copy sign
	sign = x.sign;
	// Copy the rest
	mag = x.mag;
}

BigInteger::BigInteger(const Blk *b, Index blen, Sign s) : mag(b, blen) {
	switch (s) {
	case zero:
		if (!mag.isZero())
			throw "BigInteger::BigInteger(const Blk *, Index, Sign): Cannot use a sign of zero with a nonzero magnitude";
		sign = zero;
		break;
	case positive:
	case negative:
		// If the magnitude is zero, force the sign to zero.
		sign = mag.isZero() ? zero : s;
		break;
	default:
		throw "BigInteger::BigInteger(const Blk *, Index, Sign): Invalid sign";
	}
}

BigInteger::BigInteger(const BigUnsigned &x, Sign s) : mag(x) {
	switch (s) {
	case zero:
		if (!mag.isZero())
			throw "BigInteger::BigInteger(const BigUnsigned &, Sign): Cannot use a sign of zero with a nonzero magnitude";
		sign = zero;
		break;
	case positive:
	case negative:
		// If the magnitude is zero, force the sign to zero.
		sign = mag.isZero() ? zero : s;
		break;
	default:
		throw "BigInteger::BigInteger(const BigUnsigned &, Sign): Invalid sign";
	}
}

BigInteger::BigInteger(unsigned long  x) : mag(x) { sign = mag.isZero() ? zero : positive; }
BigInteger::BigInteger(unsigned int   x) : mag(x) { sign = mag.isZero() ? zero : positive; }
BigInteger::BigInteger(unsigned short x) : mag(x) { sign = mag.isZero() ? zero : positive; }

// For signed input, determine the desired magnitude and sign separately.

namespace {
	template <class X, class UX>
	BigInteger::Blk magOf(X x) {
		return BigInteger::Blk(x < 0 ? UX(-x) : x);
	}
	template <class X>
	BigInteger::Sign signOf(X x) {
		return (x == 0) ? BigInteger::zero
			: (x > 0) ? BigInteger::positive
			: BigInteger::negative;
	}
}

BigInteger::BigInteger(long  x) : sign(signOf(x)), mag(magOf<long , unsigned long >(x)) {}
BigInteger::BigInteger(int   x) : sign(signOf(x)), mag(magOf<int  , unsigned int  >(x)) {}
BigInteger::BigInteger(short x) : sign(signOf(x)), mag(magOf<short, unsigned short>(x)) {}

template <class X>
inline X convertBigUnsignedToPrimitiveAccess(const BigUnsigned &a) {
	return a.convertToPrimitive<X>();
}

template <class X>
X BigInteger::convertToUnsignedPrimitive() const {
	if (sign == negative)
		throw "BigInteger::to<Primitive>: "
			"Cannot convert a negative integer to an unsigned type";
	else
		return convertBigUnsignedToPrimitiveAccess<X>(mag);
}

template <class X, class UX>
X BigInteger::convertToSignedPrimitive() const {
	if (sign == zero)
		return 0;
	else if (mag.getLength() == 1) {
		// The single block might fit in an X.  Try the conversion.
		Blk b = mag.getBlock(0);
		if (sign == positive) {
			X x = X(b);
			if (x >= 0 && Blk(x) == b)
				return x;
		} else {
			X x = -X(b);
			if (x < 0 && Blk(UX(-x)) == b)
				return x;
		}
	}
	throw "BigInteger::to<Primitive>: "
		"Value is too big to fit in the requested type";
}

unsigned long  BigInteger::toUnsignedLong () const { return convertToUnsignedPrimitive<unsigned long >       (); }
unsigned int   BigInteger::toUnsignedInt  () const { return convertToUnsignedPrimitive<unsigned int  >       (); }
unsigned short BigInteger::toUnsignedShort() const { return convertToUnsignedPrimitive<unsigned short>       (); }
long           BigInteger::toLong         () const { return convertToSignedPrimitive  <long , unsigned long> (); }
int            BigInteger::toInt          () const { return convertToSignedPrimitive  <int  , unsigned int>  (); }
short          BigInteger::toShort        () const { return convertToSignedPrimitive  <short, unsigned short>(); }

// COMPARISON
BigInteger::CmpRes BigInteger::compareTo(const BigInteger &x) const {
	if (sign < x.sign)
		return less;
	else if (sign > x.sign)
		return greater;
	else switch (sign) {
	case zero:
		return equal; // Two zeros are equal
	case positive:
		return mag.compareTo(x.mag);
	case negative:
		return CmpRes(-mag.compareTo(x.mag));
	default:
		throw "BigInteger internal error";
	}
}

#define DTRT_ALIASED(cond, op) \
	if (cond) { \
		BigInteger tmpThis; \
		tmpThis.op; \
		*this = tmpThis; \
		return; \
	}

void BigInteger::add(const BigInteger &a, const BigInteger &b) {
	DTRT_ALIASED(this == &a || this == &b, add(a, b));
	if (a.sign == zero)
		operator =(b);
	else if (b.sign == zero)
		operator =(a);
	else if (a.sign == b.sign) {
		sign = a.sign;
		mag.add(a.mag, b.mag);
	} else {
		switch (a.mag.compareTo(b.mag)) {
		case equal:
			mag = 0;
			sign = zero;
			break;
		case greater:
			sign = a.sign;
			mag.subtract(a.mag, b.mag);
			break;
		case less:
			sign = b.sign;
			mag.subtract(b.mag, a.mag);
			break;
		}
	}
}

void BigInteger::subtract(const BigInteger &a, const BigInteger &b) {
	DTRT_ALIASED(this == &a || this == &b, subtract(a, b));
	if (a.sign == zero) {
		mag = b.mag;
		sign = Sign(-b.sign);
	} else if (b.sign == zero)
		operator =(a);
	else if (a.sign != b.sign) {
		sign = a.sign;
		mag.add(a.mag, b.mag);
	} else {
		switch (a.mag.compareTo(b.mag)) {
		case equal:
			mag = 0;
			sign = zero;
			break;
		case greater:
			sign = a.sign;
			mag.subtract(a.mag, b.mag);
			break;
		case less:
			sign = Sign(-b.sign);
			mag.subtract(b.mag, a.mag);
			break;
		}
	}
}

void BigInteger::multiply(const BigInteger &a, const BigInteger &b) {
	DTRT_ALIASED(this == &a || this == &b, multiply(a, b));
	// If one object is zero, copy zero and return.
	if (a.sign == zero || b.sign == zero) {
		sign = zero;
		mag = 0;
		return;
	}
	sign = (a.sign == b.sign) ? positive : negative;
	// Multiply the magnitudes.
	mag.multiply(a.mag, b.mag);
}

void BigInteger::divideWithRemainder(const BigInteger &b, BigInteger &q) {
	if (this == &q)
		throw "BigInteger::divideWithRemainder: Cannot write quotient and remainder into the same variable";
	if (this == &b || &q == &b) {
		BigInteger tmpB(b);
		divideWithRemainder(tmpB, q);
		return;
	}
	if (b.sign == zero) {
		q.mag = 0;
		q.sign = zero;
		return;
	}
	if (sign == zero) {
		q.mag = 0;
		q.sign = zero;
		return;
	}

	if (sign == b.sign) {
		q.sign = positive;
	} else {
		q.sign = negative;
		mag--;

	}

	// Divide the magnitudes.
	mag.divideWithRemainder(b.mag, q.mag);

	if (sign != b.sign) {
		q.mag++;
		// Modify the remainder.
		mag.subtract(b.mag, mag);
		mag--;
	}

	sign = b.sign;
	if (mag.isZero())
		sign = zero;
	if (q.mag.isZero())
		q.sign = zero;

	// WHEW!!!
}

// Negation
void BigInteger::negate(const BigInteger &a) {
	DTRT_ALIASED(this == &a, negate(a));
	// Copy a's magnitude
	mag = a.mag;
	// Copy the opposite of a.sign
	sign = Sign(-a.sign);
}
void BigInteger::operator ++() {
	if (sign == negative) {
		mag--;
		if (mag == 0)
			sign = zero;
	} else {
		mag++;
		sign = positive; // if not already
	}
}

void BigInteger::operator ++(int) {
	operator ++();
}

// Prefix decrement
void BigInteger::operator --() {
	if (sign == positive) {
		mag--;
		if (mag == 0)
			sign = zero;
	} else {
		mag++;
		sign = negative;
	}
}

// Postfix decrement: same as prefix
void BigInteger::operator --(int) {
	operator --();
}

#ifndef BIGINTEGERALGORITHMS_H
#define BIGINTEGERALGORITHMS_H

BigUnsigned gcd(BigUnsigned a, BigUnsigned b);
void extendedEuclidean(BigInteger m, BigInteger n,
		BigInteger &g, BigInteger &r, BigInteger &s);

BigUnsigned modinv(const BigInteger &x, const BigUnsigned &n);

// Returns (base ^ exponent) % modulus.
BigUnsigned modexp(const BigInteger &base, const BigUnsigned &exponent,
		const BigUnsigned &modulus);

#endif

BigUnsigned gcd(BigUnsigned a, BigUnsigned b) {
	BigUnsigned trash;
	// Neat in-place alternating technique.
	for (;;) {
		if (b.isZero())
			return a;
		a.divideWithRemainder(b, trash);
		if (a.isZero())
			return b;
		b.divideWithRemainder(a, trash);
	}
}

void extendedEuclidean(BigInteger m, BigInteger n,
		BigInteger &g, BigInteger &r, BigInteger &s) {
	if (&g == &r || &g == &s || &r == &s)
		throw "BigInteger extendedEuclidean: Outputs are aliased";
	BigInteger r1(1), s1(0), r2(0), s2(1), q;
	for (;;) {
		if (n.isZero()) {
			r = r1; s = s1; g = m;
			return;
		}
		m.divideWithRemainder(n, q);
		r1 -= q*r2; s1 -= q*s2;

		if (m.isZero()) {
			r = r2; s = s2; g = n;
			return;
		}
		n.divideWithRemainder(m, q);
		r2 -= q*r1; s2 -= q*s1;
	}
}

BigUnsigned modinv(const BigInteger &x, const BigUnsigned &n) {
	BigInteger g, r, s;
	extendedEuclidean(x, n, g, r, s);
	if (g == 1)
		return (r % n).getMagnitude(); // (r % n) will be nonnegative
	else
		throw "BigInteger modinv: x and n have a common factor";
}

BigUnsigned modexp(const BigInteger &base, const BigUnsigned &exponent,
		const BigUnsigned &modulus) {
	BigUnsigned ans = 1, base2 = (base % modulus).getMagnitude();
	BigUnsigned::Index i = exponent.bitLength();
	while (i > 0) {
		i--;
		// Square.
		ans *= ans;
		ans %= modulus;
		// And multiply if the bit is a 1.
		if (exponent.getBit(i)) {
			ans *= base2;
			ans %= modulus;
		}
	}
	return ans;
}

#ifndef BIGUNSIGNEDINABASE_H
#define BIGUNSIGNEDINABASE_H

#include <string>


class BigUnsignedInABase : protected NumberlikeArray<unsigned short> {

public:
	// The digits of a BigUnsignedInABase are unsigned shorts.
	typedef unsigned short Digit;
	// That's also the type of a base.
	typedef Digit Base;

protected:
	Base base;
	BigUnsignedInABase(int, Index c) : NumberlikeArray<Digit>(0, c) {}

	// Decreases len to eliminate any leading zero digits.
	void zapLeadingZeros() {
		while (len > 0 && blk[len - 1] == 0)
			len--;
	}

public:
	// Constructs zero in base 2.
	BigUnsignedInABase() : NumberlikeArray<Digit>(), base(2) {}

	// Copy constructor
	BigUnsignedInABase(const BigUnsignedInABase &x) : NumberlikeArray<Digit>(x), base(x.base) {}

	// Assignment operator
	void operator =(const BigUnsignedInABase &x) {
		NumberlikeArray<Digit>::operator =(x);
		base = x.base;
	}

	BigUnsignedInABase(const Digit *d, Index l, Base base);

	~BigUnsignedInABase() {}

	// LINKS TO BIGUNSIGNED
	BigUnsignedInABase(const BigUnsigned &x, Base base);
	operator BigUnsigned() const;

	operator std::string() const;
	BigUnsignedInABase(const std::string &s, Base base);

public:

	// ACCESSORS
	Base getBase() const { return base; }
	NumberlikeArray<Digit>::getCapacity;
	NumberlikeArray<Digit>::getLength;
	Digit getDigit(Index i) const { return i >= len ? 0 : blk[i]; }
	bool isZero() const { return NumberlikeArray<Digit>::isEmpty(); }
	bool operator ==(const BigUnsignedInABase &x) const {
		return base == x.base && NumberlikeArray<Digit>::operator ==(x);
	}
	bool operator !=(const BigUnsignedInABase &x) const { return !operator ==(x); }

};

#endif

BigUnsignedInABase::BigUnsignedInABase(const Digit *d, Index l, Base base)
	: NumberlikeArray<Digit>(d, l), base(base) {
	// Check the base
	if (base < 2)
		throw "BigUnsignedInABase::BigUnsignedInABase(const Digit *, Index, Base): The base must be at least 2";

	// Validate the digits.
	for (Index i = 0; i < l; i++)
		if (blk[i] >= base)
			throw "BigUnsignedInABase::BigUnsignedInABase(const Digit *, Index, Base): A digit is too large for the specified base";

	zapLeadingZeros();
}

namespace {
	unsigned int bitLen(unsigned int x) {
		unsigned int len = 0;
		while (x > 0) {
			x >>= 1;
			len++;
		}
		return len;
	}
	unsigned int ceilingDiv(unsigned int a, unsigned int b) {
		return (a + b - 1) / b;
	}
}

BigUnsignedInABase::BigUnsignedInABase(const BigUnsigned &x, Base base) {
	// Check the base
	if (base < 2)
		throw "BigUnsignedInABase(BigUnsigned, Base): The base must be at least 2";
	this->base = base;

	int maxBitLenOfX = x.getLength() * BigUnsigned::N;
	int minBitsPerDigit = bitLen(base) - 1;
	int maxDigitLenOfX = ceilingDiv(maxBitLenOfX, minBitsPerDigit);
	len = maxDigitLenOfX; // Another change to comply with `staying in bounds'.
	allocate(len); // Get the space

	BigUnsigned x2(x), buBase(base);
	Index digitNum = 0;

	while (!x2.isZero()) {
		BigUnsigned lastDigit(x2);
		lastDigit.divideWithRemainder(buBase, x2);
		// Save the digit.
		blk[digitNum] = lastDigit.toUnsignedShort();
		digitNum++;
	}

	// Save the actual length.
	len = digitNum;
}

BigUnsignedInABase::operator BigUnsigned() const {
	BigUnsigned ans(0), buBase(base), temp;
	Index digitNum = len;
	while (digitNum > 0) {
		digitNum--;
		temp.multiply(ans, buBase);
		ans.add(temp, BigUnsigned(blk[digitNum]));
	}
	return ans;
}

BigUnsignedInABase::BigUnsignedInABase(const std::string &s, Base base) {
	// Check the base.
	if (base > 36)
		throw "BigUnsignedInABase(std::string, Base): The default string conversion routines use the symbol set 0-9, A-Z and therefore support only up to base 36.  You tried a conversion with a base over 36; write your own string conversion routine.";

	this->base = base;
	len = Index(s.length());
	allocate(len);

	Index digitNum, symbolNumInString;
	for (digitNum = 0; digitNum < len; digitNum++) {
		symbolNumInString = len - 1 - digitNum;
		char theSymbol = s[symbolNumInString];
		if (theSymbol >= '0' && theSymbol <= '9')
			blk[digitNum] = theSymbol - '0';
		else if (theSymbol >= 'A' && theSymbol <= 'Z')
			blk[digitNum] = theSymbol - 'A' + 10;
		else if (theSymbol >= 'a' && theSymbol <= 'z')
			blk[digitNum] = theSymbol - 'a' + 10;
		else
			throw "BigUnsignedInABase(std::string, Base): Bad symbol in input.  Only 0-9, A-Z, a-z are accepted.";

		if (blk[digitNum] >= base)
			throw "BigUnsignedInABase::BigUnsignedInABase(const Digit *, Index, Base): A digit is too large for the specified base";
	}
	zapLeadingZeros();
}

BigUnsignedInABase::operator std::string() const {
	if (base > 36)
		throw "BigUnsignedInABase ==> std::string: The default string conversion routines use the symbol set 0-9, A-Z and therefore support only up to base 36.  You tried a conversion with a base over 36; write your own string conversion routine.";
	if (len == 0)
		return std::string("0");
	// Some compilers don't have push_back, so use a char * buffer instead.
	char *s = new char[len + 1];
	s[len] = '\0';
	Index digitNum, symbolNumInString;
	for (symbolNumInString = 0; symbolNumInString < len; symbolNumInString++) {
		digitNum = len - 1 - symbolNumInString;
		Digit theDigit = blk[digitNum];
		if (theDigit < 10)
			s[symbolNumInString] = char('0' + theDigit);
		else
			s[symbolNumInString] = char('A' + theDigit - 10);
	}
	std::string s2(s);
	delete [] s;
	return s2;
}


#ifndef BIGINTEGERUTILS_H
#define BIGINTEGERUTILS_H

#include <string>
#include <iostream>

std::string bigUnsignedToString(const BigUnsigned &x);
std::string bigIntegerToString(const BigInteger &x);
BigUnsigned stringToBigUnsigned(const std::string &s);
BigInteger stringToBigInteger(const std::string &s);

template <class T>
BigInteger dataToBigInteger(const T* data, BigInteger::Index length, BigInteger::Sign sign);

std::ostream &operator <<(std::ostream &os, const BigUnsigned &x);

std::ostream &operator <<(std::ostream &os, const BigInteger &x);

template <class T>
BigInteger dataToBigInteger(const T* data, BigInteger::Index length, BigInteger::Sign sign) {
	// really ceiling(numBytes / sizeof(BigInteger::Blk))
	unsigned int pieceSizeInBits = 8 * sizeof(T);
	unsigned int piecesPerBlock = sizeof(BigInteger::Blk) / sizeof(T);
	unsigned int numBlocks = (length + piecesPerBlock - 1) / piecesPerBlock;

	// Allocate our block array
	BigInteger::Blk *blocks = new BigInteger::Blk[numBlocks];

	BigInteger::Index blockNum, pieceNum, pieceNumHere;

	// Convert
	for (blockNum = 0, pieceNum = 0; blockNum < numBlocks; blockNum++) {
		BigInteger::Blk curBlock = 0;
		for (pieceNumHere = 0; pieceNumHere < piecesPerBlock && pieceNum < length;
			pieceNumHere++, pieceNum++)
			curBlock |= (BigInteger::Blk(data[pieceNum]) << (pieceSizeInBits * pieceNumHere));
		blocks[blockNum] = curBlock;
	}

	// Create the BigInteger.
	BigInteger x(blocks, numBlocks, sign);

	delete [] blocks;
	return x;
}

#endif

std::string bigUnsignedToString(const BigUnsigned &x) {
	return std::string(BigUnsignedInABase(x, 10));
}

std::string bigIntegerToString(const BigInteger &x) {
	return (x.getSign() == BigInteger::negative)
		? (std::string("-") + bigUnsignedToString(x.getMagnitude()))
		: (bigUnsignedToString(x.getMagnitude()));
}

BigUnsigned stringToBigUnsigned(const std::string &s) {
	return BigUnsigned(BigUnsignedInABase(s, 10));
}

BigInteger stringToBigInteger(const std::string &s) {
	// Recognize a sign followed by a BigUnsigned.
	return (s[0] == '-') ? BigInteger(stringToBigUnsigned(s.substr(1, s.length() - 1)), BigInteger::negative)
		: (s[0] == '+') ? BigInteger(stringToBigUnsigned(s.substr(1, s.length() - 1)))
		: BigInteger(stringToBigUnsigned(s));
}

std::ostream &operator <<(std::ostream &os, const BigUnsigned &x) {
	BigUnsignedInABase::Base base;
	long osFlags = os.flags();
	if (osFlags & os.dec)
		base = 10;
	else if (osFlags & os.hex) {
		base = 16;
		if (osFlags & os.showbase)
			os << "0x";
	} else if (osFlags & os.oct) {
		base = 8;
		if (osFlags & os.showbase)
			os << '0';
	} else
		throw "std::ostream << BigUnsigned: Could not determine the desired base from output-stream flags";
	std::string s = std::string(BigUnsignedInABase(x, base));
	os << s;
	return os;
}

std::ostream &operator <<(std::ostream &os, const BigInteger &x) {
	if (x.getSign() == BigInteger::negative)
		os << '-';
	os << x.getMagnitude();
	return os;
}



#define fo(a,b,c) for( a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )
#define PI 3.1415926
using namespace std;
int ni() { int a; scanf( "%d", &a ); return a; }
double nf() { double a; scanf( "%lf", &a ); return a; }
char sbuf[100005]; string ns() { scanf( "%s", sbuf ); return sbuf; }
long long nll() { long long a; scanf( "%lld", &a ); return a; }

template <class T> void out( T a, T b ) { bool first = true; for( T i = a; i != b; ++ i ) { if( !first ) printf( " " ); first = false; cout << * i; } printf( "\n" ); }
template <class T> void outl( T a, T b ) { for( T i = a; i != b; ++ i ) { cout << * i << "\n"; } }
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef map<string,int> msi;

/* main */
const int maxn = 60 + 1;
const int m[9] = {1,2,3,8,7,4,9,6,5};
const int transt[9] = {1,1,0,0,0,3,2,2,0};
const int transf[3][9] = {{1,8,9,6,5,4,7,2,3},{5,4,3,2,1,8,7,6,9},{5,6,9,8,1,2,7,4,3}};
int n;

void trans(int m[9], int x, int y)
{
    int nmap[9], t;
    t = transt[m[x*3 + y] - 1];
    //cout << t << endl;
    t --;
    if(t < 0) return ;
    int i, j, k;
    fi(9)
    {
        int x = transf[t][i],y;
        fk(9)
            if(m[k] == i + 1)
            {
                y = k;
                break;
            }
        fj(9)
            if(m[j] == x)
            {
                nmap[j] = m[y];
                break;
            }
    }
    //fi(9)
    //    cout << nmap[i] << ' ';
    //cout << endl;
    memcpy(m, nmap, sizeof(nmap));
}

BigInteger expand(int step, int m[9], BigInteger x, BigInteger y, BigInteger p)
{
    int i, j, xn, yn;
    if(step == 0)
    {
        return 0;
    }
    xn = (x / p).toInt();
    yn = (y / p).toInt();
    //cout << xn << ' ' << yn << endl;
    BigInteger l = p * p * (m[xn*3 + yn] - 1);
    trans(m, xn, yn);
    return l + expand(step - 1, m, x % p, y % p, p / 3);
    return 0;
}

int main()
{
    int i, j, k, tt;
    BigInteger vx, vy, ux, uy;
    tt = ni();
    while(tt > 0)
    {
        cin >> n;
        BigInteger p = 1;
        fi(n)
            p *= 3;
        p /= 3;
        string s;
        cin >> s;
        vx = stringToBigInteger(s);
        cin >> s;
        vy = stringToBigInteger(s);
        cin >> s;
        ux = stringToBigInteger(s);
        cin >> s;
        uy = stringToBigInteger(s);
        vx --;
        vy --;
        swap(vx,vy);
        ux --;
        uy --;
        swap(ux,uy);

        int nmap[9];
        fi(9)
            nmap[i] = m[i];
        BigInteger a = expand(n, nmap, ux, uy, p);
        fi(9)
            nmap[i] = m[i];
        BigInteger b = expand(n, nmap, vx, vy, p);
        cout << (a - b) << endl;
        tt --;
    }
    return 0;
}

