//---------------------------------------------------------------------------
#include "TPointExt.h"
#include <math.h>
#pragma package(smart_init)
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
__fastcall TPointExt::TPointExt()
	: TPersistent(), FX(0), FY(0)
{
}
//---------------------------------------------------------------------------
__fastcall TPointExt::TPointExt(double X, double Y)
	: TPersistent(), FX(X), FY(Y)
{
}
//---------------------------------------------------------------------------
__fastcall TPointExt::TPointExt(const TPointExt* P)
	: TPersistent(), FX(P->X), FY(P->Y)

{
}
//---------------------------------------------------------------------------
__fastcall TPointExt::TPointExt(const TPointExt& P)
	: TPersistent(), FX(P.X), FY(P.Y)
{
}
//---------------------------------------------------------------------------
bool TPointExt::operator==(const TPointExt& rhs) const
{
	return FX == rhs.FX && FY == rhs.FY;
}
//---------------------------------------------------------------------------
bool TPointExt::operator!=(const TPointExt& rhs) const
{
	return !operator ==(rhs);
}
/*/---------------------------------------------------------------------------
TPointExt& TPointExt::operator+=(const TPointExt& rhs)
{
	FX += rhs.FX;
	FY += rhs.FY;
	return *this;
}//*/
//---------------------------------------------------------------------------
TPointExt* TPointExt::operator+=(const TPointExt& rhs)
{
	FX += rhs.FX;
	FY += rhs.FY;
	return this;
}
//---------------------------------------------------------------------------
void TPointExt::Add(const double x, const double y)
{
	FX += x;
	FY += y;
}
//---------------------------------------------------------------------------
void TPointExt::Multiply(const double multiplier)
{
	FX *= multiplier;
	FY *= multiplier;
}
//---------------------------------------------------------------------------
void TPointExt::Rotate(const double angle)
{
	FX = FX * cos(angle) - FY * sin(angle);
	FY = FX * sin(angle) + FY * cos(angle);
}
//---------------------------------------------------------------------------
void TPointExt::Shear(double xFactor, double yFactor)
{
	FX += FY * xFactor;
	FY += FX * yFactor;
}
//---------------------------------------------------------------------------
void TPointExt::RotateAround(const TPointExt& Center,
	const double angle)
{
	FX = (FX - Center.FX) * cos(angle) - (FY - Center.FY) * sin(angle)
		+ Center.FX;
	FY = (FX - Center.FX) * sin(angle) + (FY - Center.FY) * cos(angle)
		+ Center.FY;
}
//---------------------------------------------------------------------------
void TPointExt::ShearAround(const TPointExt& Center,
	double xFactor, double yFactor)
{
	FX += (FY - Center.FY) * xFactor;
	FY += (FX - Center.FX) * yFactor;
}
//---------------------------------------------------------------------------

