#include <stdio.h>
#define NL printf("\n");
#define cout Lout
#define cin Lin
class ostream {
public:
    ostream(char c = 0) :data(c) {}
    ostream& operator << (char a) { return printf("%c", a), * this; }
    ostream& operator << (int a) { return printf("%d", a), * this; }
    ostream& operator << (long a) { return printf("%ld", a), * this; }
    ostream& operator << (long long a) { return printf("%lld", a), * this; }
    ostream& operator << (unsigned a) { return printf("%u", a), * this; }
    ostream& operator << (unsigned long a){ return printf("%lu", a), * this; }
    ostream& operator << (unsigned long long a){ return printf("%llu", a), * this; }
    ostream& operator << (float a) { return printf("%f", a), * this; }
    ostream& operator << (double a) { return printf("%lf", a), * this; }
    ostream& operator << (const char* s){return printf("%s", s), * this; }

private:
    char data;
}Lout, endl('\n'), ends;
class istream {
public:
    istream(int a = 1) :data(a) {}
    istream& operator >> (char& a) { return scanf("%c", &a) == EOF ? data=0:data=1,(*this); }    
    istream& operator >> (int& a){ return scanf("%d", &a) == EOF ? data=0:data=1,(*this); }
    istream& operator >> (long& a) { return scanf("%ld", &a) == EOF?data=0:data=1,(*this); }
    istream& operator >> (long long& a) { return scanf("%lld", &a) == EOF ? data=0:data=1,(*this); }
    istream& operator >> (unsigned& a) { return scanf("%u", &a) == EOF ? data=0:data=1,(*this); }
    istream& operator >> (unsigned long& a) { return scanf("%lu", &a) == EOF ? data=0:data=1,(*this); }
    istream& operator >> (unsigned long long& a){ return scanf("%llu", &a) == EOF ? data=0:data=1,(*this); }
    istream& operator >> (float& a) { return scanf("%f", &a) == EOF ? data=0:data=1,(*this); }
    istream& operator >> (double& a) { return scanf("%lf", &a) == EOF ?data=0:data=1,(*this); }
    istream& operator >> (char* s) { return scanf("%s", s) == EOF ?data=0:data=1,(*this); }
    operator bool() const { return !!data; }
    operator int() const { return data; }
private:
    int data;
}Lin;