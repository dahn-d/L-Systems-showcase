//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TTurtlePaintBox.h"
#include "TurtleMath.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------
static inline void ValidCtrCheck(TTurtlePaintBox *)
{
	new TTurtlePaintBox(NULL);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
__fastcall TTurtle::TTurtle(TCanvas* C)
	: TObject()
{
	FCanvas = C;
	FTurtlePos = new TPointExt();
	FCommands = new TList();
//	FPositions = new TStack__1<TPoint>(0);
}
//---------------------------------------------------------------------------
__fastcall TTurtle::~TTurtle()
{
	delete FTurtlePos;
	delete FCommands;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
__fastcall TTurtle::TPrimeCommand::TPrimeCommand(
	TTurtle::prime_cmd_t c)
	: TObject()
{
	cmd = c;
}
//---------------------------------------------------------------------------
void __fastcall TTurtle::InitCommands(String* Axiom)
{
	FCommands->Clear();
	for (int i = 0; i < Axiom->Length(); i++) {
		AddCommand(Axiom->c_str()[i]);
	}
}
//---------------------------------------------------------------------------
void __fastcall TTurtle::AddCommand(const char cmd)
{
	switch (cmd) {
	case 'F': {
		FCommands->Add(new TPrimeCommand(&TTurtle::DrawForth));
		break;
	}
	case 'f': {
		FCommands->Add(new TPrimeCommand(&TTurtle::MoveForth));
		break;
	}
	case 'B': {
		FCommands->Add(new TPrimeCommand(&TTurtle::DrawBack));
		break;
	}
	case 'b': {
		FCommands->Add(new TPrimeCommand(&TTurtle::MoveBack));
		break;
	}
	case '+': {
		FCommands->Add(new TPrimeCommand(&TTurtle::TurnLeft));
		break;
	}
	case '-': {
		FCommands->Add(new TPrimeCommand(&TTurtle::TurnRight));
		break;
	}
	case '[': {
		FCommands->Add(new TPrimeCommand(&TTurtle::PushState));
		break;
	}
	case ']': {
		FCommands->Add(new TPrimeCommand(&TTurtle::PopState));
		break;
	}
	case 'M': {
		FCommands->Add(new TPrimeCommand(&TTurtle::Sm));
		break;
	}
	case 'D': {
		FCommands->Add(new TPrimeCommand(&TTurtle::Sd));
		break;
	}
	default:
		;
	}
}
//---------------------------------------------------------------------------
void __fastcall TTurtle::InsertCommand(int i, const char cmd)
{
	switch (cmd){
	case 'F': {
		FCommands->Insert(i, new TPrimeCommand(&TTurtle::DrawForth));
		break;
	}
	case 'B': {
		FCommands->Insert(i, new TPrimeCommand(&TTurtle::DrawBack));
		break;
	}
	case 'b': {
		FCommands->Insert(i, new TPrimeCommand(&TTurtle::MoveBack));
		break;
	}
	case '+': {
		FCommands->Insert(i, new TPrimeCommand(&TTurtle::TurnLeft));
		break;
	}
	case '-': {
		FCommands->Insert(i, new TPrimeCommand(&TTurtle::TurnRight));
		break;
	}
	default:
		;
	}
}
//---------------------------------------------------------------------------
void __fastcall TTurtle::InvokeCommands()
{
	for (int i = 0; i < FCommands->Count; i++) {
		TPrimeCommand* t = (TPrimeCommand*)FCommands->Items[i];
		(this->*(t->cmd))();
	}
}
//---------------------------------------------------------------------------
void __fastcall TTurtle::ClearCommands()
{
    FCommands->Clear();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
__fastcall TTurtlePaintBox::TTurtlePaintBox(TComponent* Owner)
	: TGraphicControl(Owner)
{
	FTurtle = new TTurtle(Canvas);
	FPen = Canvas->Pen;
}
//---------------------------------------------------------------------------
__fastcall TTurtlePaintBox::~TTurtlePaintBox()
{
	delete FTurtle;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TTurtle::SetTurtlePos(const TPointExt* P)
{	FTurtlePos = &TPointExt(P->X, P->Y);
	FCanvas->MoveTo(int(P->X), int(P->Y));
}
//---------------------------------------------------------------------------
void __fastcall TTurtle::TurnRight()
{
	FOrientAngle += FAngleIncr;
}
//---------------------------------------------------------------------------
void __fastcall TTurtle::TurnLeft()
{
	FOrientAngle -= FAngleIncr;
}
//---------------------------------------------------------------------------
void __fastcall TTurtle::MoveForth()
{
	FTurtlePos->Add(FStepSize * cosl(FOrientAngle * M_PI / 180.0),
		FStepSize * sinl(FOrientAngle * M_PI / 180.0));
	FCanvas->MoveTo(int(FTurtlePos->X), int(FTurtlePos->Y));
}
//---------------------------------------------------------------------------
void __fastcall TTurtle::MoveBack()
{
	FTurtlePos->Add(-FStepSize * cosl(FOrientAngle * M_PI / 180.0),
		-FStepSize * sinl(FOrientAngle * M_PI / 180.0));
	FCanvas->MoveTo(int(FTurtlePos->X), int(FTurtlePos->Y));
}
//---------------------------------------------------------------------------
void __fastcall TTurtle::DrawForth()
{
	FTurtlePos->Add(FStepSize * cosl(FOrientAngle * M_PI / 180.0),
		FStepSize * sinl(FOrientAngle * M_PI / 180.0));
	int x = int(FTurtlePos->X), y = int(FTurtlePos->Y);
	FCanvas->LineTo(x, y);
//	FCanvas->TextOutA(x, y + 20,
//		String(FloatToStr(FTurtlePos->X) + ";" + FloatToStr(FTurtlePos->Y)));
//	FCanvas->MoveTo(x, y);
}
//---------------------------------------------------------------------------
void __fastcall TTurtle::DrawBack()
{
	FTurtlePos->Add(-FStepSize * cosl(FOrientAngle * M_PI / 180.0),
		-FStepSize * sinl(FOrientAngle * M_PI / 180.0));
	FCanvas->LineTo(int(FTurtlePos->X), int(FTurtlePos->Y));
}
//---------------------------------------------------------------------------
void __fastcall TTurtle::PushState()
{
	FXs.push(FTurtlePos->X);
	FYs.push(FTurtlePos->Y);
	FAs.push(FOrientAngle);
	FSs.push(FStepSize);
}
//---------------------------------------------------------------------------
void __fastcall TTurtle::PopState()
{
	TurtlePos = &TPointExt(FXs.top(), FYs.top());
	FOrientAngle = FAs.top();
	FStepSize = FSs.top();
	FXs.pop(); FYs.pop(); FAs.pop(); FSs.pop();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TTurtle::Sm() { FStepSize *= SCoefficient; };
void __fastcall TTurtle::Sd() { FStepSize /= SCoefficient; };
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

namespace Tturtlepaintbox
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TTurtlePaintBox)};
		RegisterComponents(L"Turtle2", classes, 0);
	}
}
//---------------------------------------------------------------------------
