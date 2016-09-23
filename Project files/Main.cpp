//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TTurtlePaintBox"
#pragma resource "*.dfm"
TLab2MainForm *Lab2MainForm;
//---------------------------------------------------------------------------
__fastcall TLab2MainForm::TLab2MainForm(TComponent* Owner)
	: TForm(Owner)
{
	FilesParentFolderString = "";
}
//---------------------------------------------------------------------------
void __fastcall TLab2MainForm::CleanState()
{
	TurtlePaintBox->Refresh();
	FractalStringMemo->Lines->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TLab2MainForm::ExitToolButtonClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TLab2MainForm::TurtlePaintBoxMouseUp(TObject *Sender,
	TMouseButton Button, TShiftState Shift, int X, int Y)
{
	String T = InitialTurtleStateMemo->Text;
	if (Button == mbLeft && !T.IsEmpty()) {
		int pos;
		pos = T.Pos("x="); pos += 2;
		T.Delete(pos, T.SubString(pos, T.Length()).Pos(";") - 1);
		T.Insert(IntToStr(X), pos);
		pos = T.Pos("y="); pos += 2;
		T.Delete(pos, T.SubString(pos, T.Length()).Pos(";") - 1);
		T.Insert(IntToStr(Y), pos);
		InitialTurtleStateMemo->Text = T;
	}
}
//---------------------------------------------------------------------------

void __fastcall TLab2MainForm::DrawToolButtonClick(TObject *Sender)
{
	CleanState();

	unsigned short nOfIterations = IterationMaskEdit->Text.TrimRight().ToInt();

	short pos1, pos2, count;
	String V = DOLSystemMemo->Text;
	pos1 = V.Pos("V:") + 2;
	count = V.SubString(pos1, V.Length()).Pos(";") - 1;
	V = V.SubString(pos1, count).Trim();
	String ω = DOLSystemMemo->Text;
	pos1 = ω.Pos(L"ω:") + 2;
	count = ω.SubString(pos1, ω.Length()).Pos(";") - 1;
	ω = ω.SubString(pos1, count).Trim();
	String P = DOLSystemMemo->Text;
	pos1 = P.Pos("P:") + 2;
	pos2 = P.Length();
	count = pos2 - pos1;
	P = P.SubString(pos1, count).Trim();

	pos1 = P.Pos(";");
	unsigned short nOfProductions = P.SubString(1, pos1 - 1).ToInt();
	P.Delete(1, pos1);

	while (!Prods.empty())
		Prods.pop_back();

	for (int i = 0; i < nOfProductions; i++) {
		pos1 = P.Pos(L"→"); pos2 = P.Pos(";");
		Prod N = {
			P.SubString(1, pos1 - 1).Trim(),
			P.SubString(pos1 + 1, pos2 - pos1 - 1).Trim()
		};
		Prods.push_back(N);
		P.Delete(1, pos2); P = P.Trim();
	}

	String FractalStr = ω;
	for (int i = 0; i < nOfIterations; i++) {
		for (int j = 1; j <= FractalStr.Length(); j++) {
			for (It it = Prods.begin(); it != Prods.end(); ++it) {
				Prod& C = *it;
				if (FractalStr.SubString(j, C.Pred.Length()) == C.Pred) {
					FractalStr.Delete(j, C.Pred.Length());
					FractalStr.Insert(C.Succ, j);
					j += C.Succ.Length() - 1;
					break;
				}
			}
		}
	}
	FractalStringLengthEdit->Text = "Lenght = " + IntToStr(FractalStr.Length());
	FractalStringMemo->Text = FractalStr;

	String T = InitialTurtleStateMemo->Text, t;
	T = T.Trim();
	double x, y;
	t = T.SubString(T.Pos("x=") + 2, T.Length()); t.SetLength(t.Pos(";") - 1);
	x = t.ToDouble();
	t = T.SubString(T.Pos("y=") + 2, T.Length()); t.SetLength(t.Pos(";") - 1);
	y = t.ToDouble();
	TurtlePaintBox->Turtle->TurtlePos = &TPointExt(x, y);
	pos1 = T.Pos(L"α");
	if (pos1 != 0) {
		t = T.SubString(pos1 + 2, T.Length()); t.SetLength(t.Pos(";") - 1);
		TurtlePaintBox->Turtle->OrientAngle = t.ToDouble();
	}
	pos1 = T.Pos(L"l");
	if (pos1 != 0) {
		t = T.SubString(pos1 + 2, T.Length()); t.SetLength(t.Pos(";") - 1);
		TurtlePaintBox->Turtle->StepSize = t.ToDouble();
	}
	pos1 = T.Pos(L"δ");
	if (pos1 != 0) {
		t = T.SubString(pos1 + 2, T.Length()); t.SetLength(t.Pos(";") - 1);
		TurtlePaintBox->Turtle->AngleIncr = t.ToDouble();
	}
	pos1 = T.Pos(L"s");
	if (pos1 != 0) {
		t = T.SubString(pos1 + 2, T.Length()); t.SetLength(t.Pos(";") - 1);
		TurtlePaintBox->Turtle->SCoefficient = t.ToDouble();
	}

	TurtlePaintBox->Turtle->InitCommands(&FractalStr);
	TurtlePaintBox->Turtle->InvokeCommands();
}
//---------------------------------------------------------------------------
void __fastcall TLab2MainForm::FileListBoxClick(TObject *Sender)
{
	TFileStream* File = new TFileStream(FileListBox->FileName, fmOpenRead);
	wchar_t* buffer = new wchar_t(File->Size);
	File->Read(buffer, File->Size);
	File->Free();
	String FileStr(buffer);
	delete buffer;

	String DOLSystemStr(FileStr.SubString(FileStr.Pos("DOL-System:{") + 12,
		FileStr.Length()).Trim());
	DOLSystemStr.SetLength(DOLSystemStr.Pos("}") - 1);
	String TurtleStr(FileStr.SubString(FileStr.Pos("Turtle:") + 8,
		FileStr.Length()).Trim());
	TurtleStr.SetLength(TurtleStr.Pos("}") - 1);
	String IterationStr(FileStr.SubString(FileStr.Pos("Iteration:") + 10,
		FileStr.Length()).Trim());
	IterationStr.SetLength(IterationStr.Pos(";") - 1);

	DOLSystemMemo->Lines->Clear();
	InitialTurtleStateMemo->Lines->Clear();

	DOLSystemMemo->Lines->Add(DOLSystemStr.Trim());
	InitialTurtleStateMemo->Lines->Add(TurtleStr.Trim());
	IterationMaskEdit->Text = IterationStr;
}
//---------------------------------------------------------------------------

void __fastcall TLab2MainForm::FilesParentFolerEditChange(TObject *Sender)
{
	FileListBox->Mask = FilesParentFolerEdit->Text + "*.txt";
}
//---------------------------------------------------------------------------

