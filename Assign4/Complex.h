#ifndef COMPLEX_H
   #define COMPLEX_H


	//*****************************************************************
   // FILE:      Complex.h
   // AUTHOR:    Andrew Scheel
   // LOGON ID:  z1790270
   // DUE DATE:  10/19/17
   //
   // PURPOSE:   Declaration for the Complex class.
   //*****************************************************************
   #include <iostream>
   #include <cstdlib>
	using namespace std;
	
	class Complex
		{
			//data members
			private:	
				double realNum;
				double imaginNum;
			
			//Constuctor(s)
			public:
			Complex(double real = 0.0, double imagin = 0.0);
			
			//accessor methods
			void setComplex(double, double);
			void getComplex(double&, double&) const;

			void setRealPart(double);
			double getRealPart() const;

			void setImaginaryPart(double);
			double getImaginaryPart() const;

			Complex &operator+(const Complex &complex) const;
			Complex &operator*(const Complex &complex) const;
			bool operator==(const Complex &complex) const;

			friend ostream& operator<<(ostream&, const Complex&);
			friend istream& operator>>(istream&, Complex&);
			
		};

	
	#endif
