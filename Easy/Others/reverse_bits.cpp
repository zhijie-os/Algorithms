class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
		// swap the higher 16 bits and lower 16 bits
        n = (n >> 16) | (n << 16);
		// swap the higher 8 bits and lower 8 bites in each 2 bytes
		n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
		// sawp the higher 4 bit and lower 4 bits in each byte
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
		// etc
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
		// etc
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
