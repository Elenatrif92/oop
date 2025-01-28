
#include <iostream>
#include <cmath>
using namespace std;
class Complex {
private:
	float a;
	float b;
	void _copy(const Complex& orig)
	{
		a = orig.a;
		b = orig.b;
	}

public:
	//Complex(){}
	Complex(float a=1, float b=0) {
		this->a=a;
		this->b=b;
	}
	Complex(Complex const &c) {
		if(this!=&c) {
			_copy(c);
		}
		//else 

	}
	Complex& operator=(Complex c) {
		if(this!=&c) {
			_copy(c);
		}
		return *this;
	}
	bool operator==(Complex c) {
		if(this==&c) return true;
		else if(this->a==c.a && this->b==c.b) return true;
		else return false;
	}
	bool operator!=(Complex c) {
		if(this==&c) return false;
		else if(this->a==c.a && this->b==c.b) return false;
		else return true;
	}
	Complex operator-() {
		Complex c(*this);
		c.a=-c.a;
		c.b=-c.b;
		return c;
	}
	Complex operator+(const Complex c) const {
		Complex r(*this);
		r.a+=c.a;
		r.b+=c.b;
		return r;
	}
	Complex operator-(const Complex c) const {
		Complex r(*this);
		r.a-=c.a;
		r.b-=c.b;
		return r;
	}
	Complex operator*(const Complex vtor) const {
		Complex r;
		r.a=(this->a)*vtor.a-(this->b)*vtor.b;
		r.b=(this->a)*vtor.b+(this->b)*vtor.a;
		return r;

	}
	Complex operator~() const {
		Complex r(*this);
		r.b=-r.b;
		return r;
	}
	Complex& operator++(){//prefix
	    a++;
	    return *this;
	}
	Complex& operator++(int){//postfix
	    a++;
	    return *this;
	}
	
	float operator!() {
		float modul=sqrt(a*a+b*b);
		return modul;
	}
	Complex operator/(const Complex vtor) const {
		Complex r;
		r.a=((this->a)*vtor.a+(this->b)*vtor.b)/(vtor.a*vtor.a+vtor.b*vtor.b);
		r.b=((this->b)*vtor.a-(this->a)*vtor.b)/(vtor.a*vtor.a+vtor.b*vtor.b);
		return r;
	}
	void print() {
		cout << (this->a) << (b>=0?"+":"") << (this->b) << "i" << endl;
	}

};


int main()
{
	Complex x(6,3);
	cout << "x=";
	x.print();
	Complex z(2,5);
	cout << "z=";
	z.print();
	cout << "kolic=";
	Complex kolic=x/z;
	kolic.print();
	cout << "proiz=";
	Complex proiz=x*z;
	proiz.print();
	z=(-x); //za zbirot da e 0
	cout << "zbir=";
	Complex zbir=x+z;
	zbir.print();
	z=Complex(2,5); //ja vrakjam prvobitnata vrednost na z
	cout << "proiz_konjugiran=";
	(~proiz).print();

	cout << (z!=x) << (x==x) << (z==x) << endl;
	Complex razlika=x-z;
	cout << "razlika=";
	razlika.print();
	cout << "modul_na(1+i)=";
	cout << !(Complex(1,1)) << endl;
	razlika++;
	razlika.print();
	return 0;
}