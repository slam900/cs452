void setBit(int bits[], int index) {
	bits[index / 32] |= 1 << (index % 32);
}

void clearBit(int bits[], int index) {
	bits[index / 32] &= ~(1 << (index % 32));
}

int getBit(int bits[], int index) {
	return ((bits[index / 32] & (1 << (index % 32))) != 0);
}
