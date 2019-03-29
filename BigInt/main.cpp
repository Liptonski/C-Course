#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class BigInt{
public:
    char *l;
    char sign;
    unsigned long length;
    explicit BigInt(const string& ll);
    explicit BigInt(const long& x);
    BigInt(const BigInt& num);
    ~BigInt(){ delete []l; }
    BigInt operator + (const BigInt& num);
    BigInt operator += (const BigInt& num);
    BigInt operator + (const unsigned long& x);
    BigInt operator - (const BigInt& num);
    BigInt operator -= (const BigInt& num);
    BigInt operator - (const unsigned long& x);
    BigInt operator * (const BigInt& num);
    BigInt operator * (const unsigned long& x);
    BigInt operator *=(const BigInt& num);
    BigInt operator /(const BigInt& num);
    BigInt operator /= (const BigInt& num);
    bool operator ==(const BigInt& num);
    bool operator !=(const BigInt& num);
    bool operator >(const BigInt& num);
    bool operator <(const BigInt& num);
    bool operator >=(const BigInt& num);
    bool operator <=(const BigInt &num);
    char operator [](const unsigned long& idx);
    void operator -();
    void operator ++();
    void operator --();
    BigInt& operator =(const BigInt& num);

    //ostream & operator << (ostream&, BigInt& n);
    void wypisz();
};

BigInt::BigInt(const string& ll){
    if (ll[0]=='-') {
        sign = '-';
        l = new char[ll.size()];
        string help = string(ll.rbegin(), ll.rend());
        string str = help.substr(0,help.size()-1);
        strcpy(l, str.c_str());
        length=str.size();
    }
    else {
        sign = '+';
        l = new char[ll.size()+1];
        string str = string(ll.rbegin(), ll.rend());
        strcpy(l, str.c_str());
        length=ll.size();
    }
}

BigInt::BigInt(const long& x) {
    if (x<0) {
        sign = '-';
        stringstream ss;
        ss << x;
        string str = ss.str();
        reverse(str.begin(), str.end());
        string help = str.substr(0, str.size()-1);
        length=(int)help.size();
        l = new char[length];
        strcpy(l, help.c_str());
    }
    else {
        sign = '+';
        stringstream ss;
        ss << x;
        string str = ss.str();
        reverse(str.begin(), str.end());
        length=(int)str.size();
        l = new char[length];
        strcpy(l, str.c_str());
    }
}

BigInt::BigInt(const BigInt& num) {
    this->sign = num.sign;
    this->length = num.length;
    l=new char[length];
    strcpy(this->l, num.l);
}

BigInt BigInt::operator +(const BigInt& num) {
    string sum;
    int number;
    if(this->length<num.length){
        unsigned long n1 = this->length;
        unsigned long n2 = num.length;
        int temp = 0;
        for (int i = 0; i < n1; i++) {
            number = (*(l + i) - '0') + (*(num.l + i) - '0') + temp;
            sum.push_back(number % 10 + '0');
            temp = number / 10;
        }
        for (int i = n1; i < n2; i++) {
            number = (*(num.l + i) - '0') + temp;
            sum.push_back(number % 10 + '0');
            temp = number / 10;
        }
        if (temp) sum.push_back(temp + '0');
    }
    else if(this->length>=num.length){
        unsigned long n1 = num.length;
        unsigned long n2 = this->length;
        int temp=0;
        for(int i=0; i<n1; i++){
            number = (*(l+i)-'0') + (*(num.l+i)-'0') + temp;
            sum.push_back(number%10 +'0');
            temp=number/10;
        }
        for(int i=n1; i<n2; i++){
            number = (*(this->l + i) -'0') + temp;
            sum.push_back(number%10 + '0');
            temp = number/10;
        }
        if(temp) sum.push_back(temp+'0');
    }
    reverse(sum.begin(), sum.end());
    return BigInt(sum);
}

BigInt BigInt::operator +=(const BigInt& num){
    string sum;
    int number;
    if(this->length<num.length){
        unsigned long n1 = this->length;
        unsigned long n2 = num.length;
        int temp = 0;
        for (int i = 0; i < n1; i++) {
            number = (*(l + i) - '0') + (*(num.l + i) - '0') + temp;
            sum.push_back(number % 10 + '0');
            temp = number / 10;
        }
        for (int i = n1; i < n2; i++) {
            number = (*(num.l + i) - '0') + temp;
            sum.push_back(number % 10 + '0');
            temp = number / 10;
        }
        if (temp) sum.push_back(temp + '0');
    }
    else if(this->length>=num.length){
        unsigned long n1 = num.length;
        unsigned long n2 = this->length;
        int temp=0;
        for(int i=0; i<n1; i++){
            number = (*(l+i)-'0') + (*(num.l+i)-'0') + temp;
            sum.push_back(number%10 +'0');
            temp=number/10;
        }
        for(int i=n1; i<n2; i++){
            number = (*(this->l + i) -'0') + temp;
            sum.push_back(number%10 + '0');
            temp = number/10;
        }
        if(temp) sum.push_back(temp+'0');
    }
    reverse(sum.begin(), sum.end());
    delete []l;
    l = new char[sum.size()+1];
    strcpy(l, sum.c_str());
    length=sum.size();
    return *this;
}

BigInt BigInt::operator +(const unsigned long& x){
    BigInt help(x);
    return *this+help;
}

BigInt BigInt::operator -(const BigInt& num) {
    string dif;
    int number;
    bool check=false;

    if(num.sign == '-' && this->sign=='+') {
        return *this+num;
    }
    else if(this->sign == '-' && num.sign == '+'){
        BigInt help = *this+num;
        help.sign='-';
        return help;
    }
    else if(num.sign=='+' && this->sign =='+') {
        if(this->length<num.length) check = true;
        else if(this->length>num.length) check = false;
        else {
            int i = this->length;
            while (i >= 0) {
                if (*(this->l + i) < *(num.l + i)) check = true;
                else if (*(this->l + i) > *(num.l + i)) check = false;
                i--;
            }
        }
        if (!check) {
            unsigned long n1 = this->length;
            unsigned long n2 = num.length;
            int temp = 0;
            for (int i = 0; i < n2; i++) {
                number = (*(l + i) - '0') - (*(num.l + i) - '0') - temp;
                if (number < 0) {
                    number = number + 10;
                    temp = 1;
                } else temp = 0;
                dif.push_back(number + '0');
            }
            for (int i = n2; i < n1; i++) {
                number = (*(l + i) - '0') - temp;
                if (number < 0) {
                    number = number + 10;
                    temp = 1;
                } else temp = 0;
                if(number!=0) dif.push_back(number + '0');
            }
            reverse(dif.begin(), dif.end());
        } else if (check) {
            unsigned long n1 = num.length;
            unsigned long n2 = this->length;
            int temp = 0;
            for (int i = 0; i < n2; i++) {
                number = (*(num.l + i) - '0') - (*(l + i) - '0') - temp;
                if (number < 0) {
                    number = number + 10;
                    temp = 1;
                } else temp = 0;
                dif.push_back(number + '0');
            }
            for (int i = n2; i < n1; i++) {
                number = (*(num.l + i) - '0') - temp;
                if (number < 0) {
                    number = number + 10;
                    temp = 1;
                } else temp = 0;
                dif.push_back(number + '0');
            }
            reverse(dif.begin(), dif.end());
            int i = 0;
            string help = "-";
            while (dif[i + 1] == '0') i++;
            help += dif.substr(i + 1, dif.size());
            dif = help;
        }
        return BigInt(dif);
    }
    else{
        if(this->length<num.length) check = false;
        else if(this->length>num.length) check = true;
        else {
            int i = this->length;
            while (i >= 0) {
                if (*(this->l + i) < *(num.l + i)) check = false;
                else if (*(this->l + i) > *(num.l + i)) check = true;
                i--;
            }
        }
        if (!check) {
            unsigned long n1 = this->length;
            unsigned long n2 = num.length;
            int temp = 0;
            for (int i = 0; i < n2; i++) {
                number = (*(l + i) - '0') - (*(num.l + i) - '0') - temp;
                if (number < 0) {
                    number = number + 10;
                    temp = 1;
                } else temp = 0;
                dif.push_back(number + '0');
            }
            for (int i = n2; i < n1; i++) {
                number = (*(l + i) - '0') - temp;
                if (number < 0) {
                    number = number + 10;
                    temp = 1;
                } else temp = 0;
                dif.push_back(number + '0');
            }
            reverse(dif.begin(), dif.end());
        } else if (check) {
            unsigned long n1 = num.length;
            unsigned long n2 = this->length;
            int temp = 0;
            for (int i = 0; i < n2; i++) {
                number = (*(num.l + i) - '0') - (*(l + i) - '0') - temp;
                if (number < 0) {
                    number = number + 10;
                    temp = 1;
                } else temp = 0;
                dif.push_back(number + '0');
            }
            for (int i = n2; i < n1; i++) {
                number = (*(num.l + i) - '0') - temp;
                if (number < 0) {
                    number = number + 10;
                    temp = 1;
                } else temp = 0;
                dif.push_back(number + '0');
            }
            reverse(dif.begin(), dif.end());
            int i = 0;
            string help = "-";
            while (dif[i + 1] == '0') i++;
            help += dif.substr(i + 1, dif.size());
            dif = help;
        }
        return BigInt(dif);
    }
}

BigInt BigInt::operator -=(const BigInt& num){
    string dif;
    int number;
    bool check=false;

    if(num.sign == '-' && this->sign=='+') {
        return *this+num;
    }
    else if(this->sign == '-' && num.sign == '+'){
        BigInt help = *this+num;
        help.sign='-';
        return help;
    }
    else if(num.sign=='+' && this->sign =='+') {
        if(this->length<num.length) check = true;
        else if(this->length>num.length) check = false;
        else {
            int i = this->length;
            while (i >= 0) {
                if (*(this->l + i) < *(num.l + i)) check = true;
                else if (*(this->l + i) > *(num.l + i)) check = false;
                i--;
            }
        }
        if (!check) {
            unsigned long n1 = this->length;
            unsigned long n2 = num.length;
            int temp = 0;
            for (int i = 0; i < n2; i++) {
                number = (*(l + i) - '0') - (*(num.l + i) - '0') - temp;
                if (number < 0) {
                    number = number + 10;
                    temp = 1;
                } else temp = 0;
                dif.push_back(number + '0');
            }
            for (int i = n2; i < n1; i++) {
                number = (*(l + i) - '0') - temp;
                if (number < 0) {
                    number = number + 10;
                    temp = 1;
                } else temp = 0;
                dif.push_back(number + '0');
            }
            reverse(dif.begin(), dif.end());
        } else if (check) {
            unsigned long n1 = num.length;
            unsigned long n2 = this->length;
            int temp = 0;
            for (int i = 0; i < n2; i++) {
                number = (*(num.l + i) - '0') - (*(l + i) - '0') - temp;
                if (number < 0) {
                    number = number + 10;
                    temp = 1;
                } else temp = 0;
                dif.push_back(number + '0');
            }
            for (int i = n2; i < n1; i++) {
                number = (*(num.l + i) - '0') - temp;
                if (number < 0) {
                    number = number + 10;
                    temp = 1;
                } else temp = 0;
                dif.push_back(number + '0');
            }
            reverse(dif.begin(), dif.end());
            int i = 0;
            string help = "-";
            while (dif[i + 1] == '0') i++;
            help += dif.substr(i + 1, dif.size());
            dif = help;
        }
        return BigInt(dif);
    }
    else{
        if(this->length<num.length) check = false;
        else if(this->length>num.length) check = true;
        else {
            int i = this->length;
            while (i >= 0) {
                if (*(this->l + i) < *(num.l + i)) check = false;
                else if (*(this->l + i) > *(num.l + i)) check = true;
                i--;
            }
        }
        if (!check) {
            unsigned long n1 = this->length;
            unsigned long n2 = num.length;
            int temp = 0;
            for (int i = 0; i < n2; i++) {
                number = (*(l + i) - '0') - (*(num.l + i) - '0') - temp;
                if (number < 0) {
                    number = number + 10;
                    temp = 1;
                } else temp = 0;
                dif.push_back(number + '0');
            }
            for (int i = n2; i < n1; i++) {
                number = (*(l + i) - '0') - temp;
                if (number < 0) {
                    number = number + 10;
                    temp = 1;
                } else temp = 0;
                dif.push_back(number + '0');
            }
            reverse(dif.begin(), dif.end());
        } else if (check) {
            unsigned long n1 = num.length;
            unsigned long n2 = this->length;
            int temp = 0;
            for (int i = 0; i < n2; i++) {
                number = (*(num.l + i) - '0') - (*(l + i) - '0') - temp;
                if (number < 0) {
                    number = number + 10;
                    temp = 1;
                } else temp = 0;
                dif.push_back(number + '0');
            }
            for (int i = n2; i < n1; i++) {
                number = (*(num.l + i) - '0') - temp;
                if (number < 0) {
                    number = number + 10;
                    temp = 1;
                } else temp = 0;
                dif.push_back(number + '0');
            }
            reverse(dif.begin(), dif.end());
            int i = 0;
            string help = "-";
            while (dif[i + 1] == '0') i++;
            help += dif.substr(i + 1, dif.size());
            dif = help;
        }
        delete []l;
        l = new char[dif.size()+1];
        strcpy(l, dif.c_str());
        length=dif.size();
        return *this;
    }
}

BigInt BigInt::operator -(const unsigned long& x){
    BigInt help(x);
    return *this-help;
}

BigInt BigInt::operator *(const BigInt& num){
    string mult;
    unsigned long n1 = this->length;
    unsigned long n2 = num.length;
    if (n1==0 || n2 ==0) return BigInt('0');
    int curr_n1 = 0;
    int curr_n2 = 0;
    vector<long> res(n1+n2,0);

    for(int i=0; i<n1; i++){
        unsigned long temp = 0;
        unsigned long num1 = (unsigned long)(*(l+i) - '0');
        curr_n2 = 0;

        for(int j = 0; j<n2; j++){
            unsigned long num2 = (unsigned long)(*(num.l+j) - '0');
            unsigned long sum = num1*num2 + res[curr_n1+curr_n2] + temp;
            temp = sum/10;
            res[curr_n1 + curr_n2] = sum%10;
            curr_n2++;
        }
        if(temp>0) res[curr_n1 + curr_n2] += temp;
        curr_n1++;
    }
    int i = res.size() -1;
    while(i>=0 && res[i]==0) i--;
    if(i==-1) return BigInt('0');
    while(i>=0){
        stringstream ss;
        ss << res[i--];
        mult += ss.str();
    }
    return BigInt(mult);
}

BigInt BigInt::operator *(const unsigned long& x){
    BigInt help(x);
    return *this*help;
}

BigInt BigInt::operator *=(const BigInt& num){
    string mult;
    unsigned long n1 = this->length;
    unsigned long n2 = num.length;
    if (n1==0 || n2 ==0) return BigInt('0');
    int curr_n1 = 0;
    int curr_n2 = 0;
    vector<unsigned long> res(n1+n2,0);

    for(int i=0; i<n1; i++){
        unsigned long temp = 0;
        unsigned long num1 = (unsigned long)(*(l+i) - '0');
        curr_n2 = 0;

        for(int j = 0; j<n2; j++){
            unsigned long num2 = (unsigned long)(*(num.l+j) - '0');
            unsigned long sum = num1*num2 + res[curr_n1+curr_n2] + temp;
            temp = sum/10;
            res[curr_n1 + curr_n2] = sum%10;
            curr_n2++;
        }
        if(temp>0) res[curr_n1 + curr_n2] += temp;
        curr_n1++;
    }
    int i = res.size() -1;
    while(i>=0 && res[i]==0) i--;
    if(i==-1) return BigInt('0');
    while(i>=0){
        stringstream ss;
        ss << res[i--];
        mult += ss.str();
    }
    delete []l;
    l = new char[mult.size()+1];
    string str = string(mult.rbegin(), mult.rend());
    strcpy(l, str.c_str());
    length=str.size();
    return *this;
}

BigInt BigInt::operator /(const BigInt& num){
    BigInt help(0);
    int res=0;
    while (help+num <= *this){
        help = help + num;
        res++;
    }
    return BigInt(res);
}

BigInt BigInt::operator /=(const BigInt& num){
    BigInt help(0);
    int res=0;
    while (help+num <= *this){
        help = help + num;
        res++;
    }
    stringstream ss;
    ss << res;
    string str = ss.str();
    reverse(str.begin(), str.end());
    length=(int)str.size();
    l = new char[length];
    strcpy(l, str.c_str());
    return *this;
}

bool BigInt::operator ==(const BigInt& num){
    int i = 0;
    if(length!=num.length) return false;
    while(i<=length){
        if(*(l+i)!=*(num.l+i)) return false;
        i++;
    }
    return true;
}

bool BigInt::operator !=(const BigInt& num){
    int i = 0;
    if(length!=num.length) return true;
    while(i<=length){
        if(*(l+i)!=*(num.l+i)) return true;
        i++;
    }
    return false;
}

bool BigInt::operator>(const BigInt &num) {
    if(length<num.length) return false;
    if(length>num.length) return true;
    int i=length;
    while(i>=0){
        if(*(l+i)<*(num.l+i)) return false;
        if(*(l+i)>*(num.l+i)) return true;
        i--;
    }
    return false;
}

bool BigInt::operator<(const BigInt &num) {
    if(length>num.length) return false;
    if(length<num.length) return true;
    int i=length;
    while(i>=0){
        if(*(l+i)>*(num.l+i)) return false;
        if(*(l+i)<*(num.l+i)) return true;
        i--;
    }
    return false;
}

bool BigInt::operator>=(const BigInt &num) {
    if(length<num.length) return false;
    if(length>num.length) return true;
    int i=length;
    while(i>=0){
        if(*(l+i)<*(num.l+i)) return false;
        if(*(l+i)>*(num.l+i)) return true;
        i--;
    }
    return true;
}

bool BigInt::operator<=(const BigInt &num) {
    if(length>num.length) return false;
    if(length<num.length) return true;
    int i=length;
    while(i>=0){
        if(*(l+i)>*(num.l+i)) return false;
        if(*(l+i)<*(num.l+i)) return true;
        i--;
    }
    return true;
}

char BigInt::operator[](const unsigned long &idx) {
    return *(l+length-1-idx);
}

void BigInt::operator -(){
    if(this->sign=='-') this->sign='+';
    else this->sign='-';
}

BigInt& BigInt::operator =(const BigInt& num){
    delete []l;
    this->sign = num.sign;
    this->length = num.length;
    l = new char[length];
    strcpy(this->l, num.l);
    return *this;
}

void BigInt::operator ++(){
    BigInt i(1);
    *this = *this+i;
}

void BigInt::operator --(){
    BigInt i(1);
    *this = *this-i;
}

void BigInt::wypisz() {
    if(this->sign == '-') cout<< "-";
    for(int i=length-1; i>=0; i--){
        cout << *(l+i);
    }
    cout << endl;
}

BigInt factorial(BigInt num){
    BigInt help = num-1;
    BigInt zero(0);
    while(help>zero){
        num *= help;
        //this->wypisz();
        help=help-1;
    }
    return num;
}

int main() {
    BigInt nowy(6);
    BigInt drugi("440");
    nowy.wypisz();
    drugi.wypisz();
    BigInt trzeci = nowy + 200;
    BigInt czwarty = drugi-nowy;
    BigInt piaty = nowy*drugi;
    BigInt szosty(20);
    BigInt siodmy = factorial(nowy);
    szosty*=nowy;
    trzeci.wypisz();
    czwarty.wypisz();
    piaty.wypisz();
    char c = nowy[0];
    szosty.wypisz();
    siodmy.wypisz();
    bool check = nowy >= drugi;
    cout << check << endl << c << endl;
}