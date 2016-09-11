//---------------------------------------------------------------------------
#ifndef PointExtH
#define PointExtH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class PACKAGE TPointExt : public TPersistent
{
private:
	double FX;
	double FY;
public:
	//-----------------------------------------------------------------------
	// Constructors
	__fastcall TPointExt();
	__fastcall TPointExt(double x, double y);
	__fastcall TPointExt(const TPointExt* P);
	__fastcall TPointExt(const TPointExt& P);
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	void Add(const double x, const double y);
	void Multiply(const double multiplier);
	void Rotate(const double angle);
	void Shear(double xFactor, double yFactor);
	void RotateAround(const TPointExt& Center,
		const double angle);
	void ShearAround(const TPointExt& Center,
		double xFactor, double yFactor);
	//-----------------------------------------------------------------------
	double Distance(const TPointExt& P) const;
	//-----------------------------------------------------------------------
	// OPERATORS BEHAVES WEIRDLY IN DELPHI CLASSES :(
	bool operator==(const TPointExt& rhs) const;
	bool operator!=(const TPointExt& rhs) const;
//	TPointExt& operator+=(const TPointExt& rhs);
	TPointExt* operator+=(const TPointExt& rhs);
//-----------------------------------------------------------------------
__published:
	__property double X = {read = FX, write = FX, default = 0};
	__property double Y = {read = FY, write = FY, default = 0};
};
//---------------------------------------------------------------------------
#endif




