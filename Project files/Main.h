//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "TTurtlePaintBox.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.FileCtrl.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.Samples.Spin.hpp>
#include <list>
#include <string>
//---------------------------------------------------------------------------
class TLab2MainForm : public TForm
{
__published:	// IDE-managed Components
	TTurtlePaintBox *TurtlePaintBox;
	TPanel *TurtlePaintBoxPanel;
	TCategoryPanelGroup *InputCategoryPanelGroup;
	TCategoryPanel *FileCategoryPanel;
	TCategoryPanel *FileListCategoryPanel;
	TGridPanel *FileGridPanel;
	TLabel *DOLSystemLabel;
	TStatusBar *StatusBar;
	TLabel *TurtleLabel;
	TMemo *DOLSystemMemo;
	TMemo *InitialTurtleStateMemo;
	TLabel *IterationLabel;
	TFileListBox *FileListBox;
	TToolBar *ToolBar;
	TToolButton *DrawToolButton;
	TToolButton *ToolButton1;
	TToolButton *ExitToolButton;
	TGridPanel *DOLSystemGridPanel;
	TCategoryPanel *FractalStringCategoryPanel;
	TMemo *FractalStringMemo;
	TEdit *FractalStringLengthEdit;
	TPanel *IterationPanel;
	TMaskEdit *IterationMaskEdit;
	TEdit *FilesParentFolerEdit;
	void __fastcall ExitToolButtonClick(TObject *Sender);
	void __fastcall TurtlePaintBoxMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall DrawToolButtonClick(TObject *Sender);
	void __fastcall FileListBoxClick(TObject *Sender);
	void __fastcall FilesParentFolerEditChange(TObject *Sender);




private:
	struct Prod {//uction
		String	Pred;//ecessor
		String	Succ;//essor
	};
	typedef std::list<Prod>::iterator It;
	std::list<Prod> Prods;
	void __fastcall CleanState();
    std::string FilesParentFolderString;
public:		// User declarations
	__fastcall TLab2MainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLab2MainForm *Lab2MainForm;
//---------------------------------------------------------------------------
#endif
