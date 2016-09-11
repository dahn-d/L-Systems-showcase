//---------------------------------------------------------------------------
#ifndef TTurtlePaintBoxH
#define TTurtlePaintBoxH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Vcl.Controls.hpp>
#include <stack>
//---------------------------------------------------------------------------
#include "TPointExt.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class PACKAGE TTurtle : public TObject
{
	typedef void __fastcall (TTurtle:: *prime_cmd_t)();
	struct TPrimeCommand : private TObject {
		__fastcall TPrimeCommand(prime_cmd_t);
		prime_cmd_t cmd;
	};
private:
	//-----------------------------------------------------------------------
	TCanvas* FCanvas;
	TList* FCommands;
	std::stack<double> FXs;
	std::stack<double> FYs;
	std::stack<double> FAs;
	std::stack<double> FSs;
	//-----------------------------------------------------------------------
	TPointExt* 	FTurtlePos;		// still not sure about TPointExt* :(
	double FOrientAngle;
	double FStepSize;
	double FAngleIncr;
	//-----------------------------------------------------------------------
	void __fastcall SetTurtlePos(const TPointExt* P);
	//-----------------------------------------------------------------------
public:
	//-----------------------------------------------------------------------
	__fastcall TTurtle(TCanvas*);
	__fastcall ~TTurtle();
	//-----------------------------------------------------------------------
	// Primary commands to the turtle
	void __fastcall TurnRight();
	void __fastcall TurnLeft();
	void __fastcall MoveForth();
	void __fastcall MoveBack();
	void __fastcall DrawForth();
	void __fastcall DrawBack();
	void __fastcall PushState();
	void __fastcall PopState();
	double SCoefficient;
	void __fastcall Sm();
	void __fastcall Sd();
	//-----------------------------------------------------------------------
	__property TPointExt* TurtlePos = {
		read = 		FTurtlePos,
		write = 	SetTurtlePos};
	//-----------------------------------------------------------------------
	__property TList* Commands = {read=FCommands};
	//-----------------------------------------------------------------------
	void __fastcall InitCommands(String* Axiom);
	void __fastcall AddCommand(const char cmd);
	void __fastcall InsertCommand(int i, const char cmd);
	void __fastcall InvokeCommands();
	void __fastcall ClearCommands();
	//-----------------------------------------------------------------------
__published:
	//-----------------------------------------------------------------------
	__property double OrientAngle = {
		read = 		FOrientAngle,
		write = 	FOrientAngle};
	__property double StepSize = {
		read = 		FStepSize,
		write = 	FStepSize};
	__property double AngleIncr = {
		read = 		FAngleIncr,
		write =		FAngleIncr};
	//-----------------------------------------------------------------------
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class PACKAGE TTurtlePaintBox : public TGraphicControl
{
	//-----------------------------------------------------------------------
private:
	//-----------------------------------------------------------------------
	TTurtle* FTurtle;
	//-----------------------------------------------------------------------
	TPen* FPen;
	//-----------------------------------------------------------------------
public:
	//-----------------------------------------------------------------------
	__fastcall TTurtlePaintBox(TComponent* Owner);
	__fastcall ~TTurtlePaintBox();
	//-----------------------------------------------------------------------
	__property TPen* Pen = {read=FPen};
	//-----------------------------------------------------------------------
	__property TTurtle* Turtle = {read=FTurtle};
	//-----------------------------------------------------------------------
__published:
	//-----------------------------------------------------------------------
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property Color = {default=-16777211};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property ParentColor = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property Touch;
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnGesture;
	__property OnMouseActivate;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
};
//---------------------------------------------------------------------------
#endif
