#include <iostream>

int basicPow(int x, int y);
int getDigitSize(int number);
void addOne(short* binary, int length);
short* noiceBitPrinter(int num);
short* noiceInverseBitPrinter(double num);
template <class T>
void bitPrinter(T *bits,int size);

int main() {
    int decimal, adecimal;
    std::cout << "Before the comma: ";
    std::cin >> decimal;
    std::cout << "After the comma: ";
    std::cin >> adecimal;

    short* bits = noiceBitPrinter(std::abs(decimal));
    int exp = 0;
    int length = 0;
    for(int i = 0; i < sizeof(decimal)*8;i++) {
        if(bits[i] == 1) {
            exp = 23-i;
            bits = &bits[i+1];
            length = i;
            break;
        }
    }

    std::cout << std::endl;
    std::cout << (decimal < 0 ? 1 : 0) << " ";
    short *iBits = noiceInverseBitPrinter(((double)adecimal)/basicPow(10, getDigitSize(adecimal)));
    addOne(iBits,22-(23-length));
    bitPrinter<short>(&noiceBitPrinter(127+exp)[16],8);
    std::cout << " ";
    bitPrinter<short>(bits,23-length);
    bitPrinter<short>(iBits,23-(23-length));

    std::cout << std::endl << std::endl;
    system("pause");


    return 0;
}

template <class T>
void bitPrinter(T *bits,int size) {
    for(int i = 0; i < size;i++) {
        std::cout << bits[i];
    }
}

short* noiceBitPrinter(int num) {
    short *bits = new short[24];
    for(int i = 23; i != -1; i--) {
        *(bits+(23-i)) = ((num & 1 << i) ? (short)1 : (short)0);
    }
    return bits;
}

short* noiceInverseBitPrinter(double num) {
    if(!(num < 1 & num > 0)) {
        throw "Num must be in between 1 < num < 0, KNOW YOUR MATH!!!";
    }
    short *bits = new short[23];
    short *result = bits;
    for(bits;bits < result+23;bits++) *bits = 0;
    bits = result;
    double alpha = 0.5;
    double x = 0;
    while(x != num && bits-result < 23) {
        x = x + alpha;
        if(x > num) {
            x = x -alpha;
            *bits = 0;
        } else {*bits = 1;}
        alpha = alpha * 1/2;
        bits++;

    }
    return result;
}

void addOne(short* binary, int length) {
    for(short* bin = (binary+length);bin > binary;bin--) {
        if(*bin == 0) {
            *bin = 1;
            break;
        } else {
            *bin = 0;
        }
    }
}

int getDigitSize(int number) {
    int digits = 0;
    while(number != 0) {
        number /= 10;
        digits++;
    }
    return digits;
}

int basicPow(int x, int y) {
    int result = x;
    for(y;y > 1;y--) {
        result *= x;
    }
    return result;
}