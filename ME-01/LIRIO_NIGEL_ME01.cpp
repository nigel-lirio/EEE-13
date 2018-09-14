/*
 * Returns an integer with the the first n least significant bits the same as x's, and the rest as 0
 * Example: getNBits(13,3) = 5
 * 13 (0000 1101) => 5 (0000 0101)
 */
int getNBits(int x, int n)
{
    unsigned int z = (1 << n) -1; //Generates n-bit mask 
    int y = x & z; //Apply mask to number
    return y;
}

/*
 * Returns an integer which is x, but with the first n least significant bits flipped (0->1, 1->0)
 * Example: flip_n(13,3) = 10
 * 13 (0000 1101) => 10 (0000 1010)
 */
int flip_n(int x, int n)
{
    unsigned int z = (1 << n) -1; //Generates n-bit mask 
    unsigned int y = x ^ z; //XOR functions similar to toggle to flip
    return y; //Entire function is basically getNBits flipped
}

/*
 * Returns an integer which is x, but with the a range of bits flipped
 * from a to b, inclusive, starting from the least significant bit (bit 0)
 * Example: flip_range(13,2,5) = 10
 * 13 (0000 1101) => 49 (0011 0001)
 */
int flip_range(int x, int a, int b)
{

    int length = (b-a) + 1;
    unsigned int z = (1 << length) -1; //Generates length-bit mask
    unsigned int range = (x>>a) ^ z; //x is offset to starting point a and then the range is inverted via toggle XOR
    //x is subdivided into three regions and each region is appended onto each other
    unsigned int top = 0 ^ (x>>b); //top region are the bits on the left of b (00)
    unsigned int bot = getNBits(x, a); //bot region are the bits before a (01)
    unsigned int final = (top<<length) ^ range; //append top to range (00) (11 00)
    final = final << a; //make space for bot region (0011 00) (00)
    final = final ^ bot; //append bot region(0011 0000) (01)
    return final;
}

/*
 * Returns an integer which is the most significant on-bit of x
 * If it does not exist, return 0
 * Example: getMSOB(74) = 64
 * 74 (0100 1010) => 64 (0100 0000)
 */
int getMSOB(int x)
{
    if(__builtin_popcount(x) > 0){ //__builtin_popcount(x) is a gcc function that returns number of ones in an int; source: https://www.geeksforgeeks.org/builtin-functions-gcc-compiler/
        int z, a=0;
        do{
            
            if(x & 1){
                z = a;
            }
            x= x >> 1;
            a++;
        }while(x != 0);
        return (1 << z);
    }
    else{
        return 0;
    }
}

/*
 * Returns an integer which is the *second* most significant on-bit of x
 * If it does not exist, return 0
 * Example: getMSOB2(74) = 8
 * 74 (0100 1010) => 8 (0000 1000)
 */
int getMSOB2(int x){
    if(__builtin_popcount(x) > 0){ 
        unsigned int x2 = x ^ getMSOB(x); //XOR with largest bit to enliminate it, new largest bit is second largest 
        int z, a=0;
        do{
            
            if(x2 & 1){
                z = a;
            }
            x2= x2 >> 1;
            a++;
        }while(x2 != 0);
        return (1 << z);
    }
    else{
        return 0;
    }    
}

/*
 * Returns an integer which is the least significant on-bit of x
 * If it does not exist, return 0
 * Example: getLSOB(74) = 2
 * 74 (0100 1010) => 2 (0000 0010)
 */
int getLSOB(int x)
{
    if(__builtin_popcount(x) > 0){
       return (1<<__builtin_ctz(x)); // __builtin_ctz(x) is a gcc function that counts number of trailing zeroes from first occurance of 1; source: https://www.geeksforgeeks.org/builtin-functions-gcc-compiler/
    }
    else{
        return 0;
    }
}

/*
 * Bonus challenge:
 * Implement all functions (except getMSOB and getMSOB2) without using any loops.
 */