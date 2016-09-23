object Lab2MainForm: TLab2MainForm
  Left = 293
  Top = 55
  BorderStyle = bsNone
  BorderWidth = 1
  ClientHeight = 696
  ClientWidth = 857
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 13
  object TurtlePaintBoxPanel: TPanel
    Left = 241
    Top = 0
    Width = 616
    Height = 696
    Align = alClient
    AutoSize = True
    Caption = 'TurtlePaintBoxPanel'
    ShowCaption = False
    TabOrder = 0
    object TurtlePaintBox: TTurtlePaintBox
      Left = 1
      Top = 24
      Width = 614
      Height = 652
      Align = alClient
      OnMouseUp = TurtlePaintBoxMouseUp
      ExplicitLeft = 64
      ExplicitTop = 1
      ExplicitWidth = 456
      ExplicitHeight = 521
    end
    object StatusBar: TStatusBar
      Left = 1
      Top = 676
      Width = 614
      Height = 19
      Panels = <
        item
          Width = 50
        end
        item
          Width = 50
        end>
    end
    object ToolBar: TToolBar
      Left = 1
      Top = 1
      Width = 614
      Height = 23
      AutoSize = True
      BorderWidth = 1
      ButtonHeight = 19
      ButtonWidth = 37
      Caption = 'ToolBar'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      Indent = 10
      List = True
      ParentFont = False
      ShowCaptions = True
      TabOrder = 1
      Transparent = False
      Wrapable = False
      object DrawToolButton: TToolButton
        Left = 10
        Top = 0
        AutoSize = True
        Caption = 'Draw'
        ImageIndex = 0
        OnClick = DrawToolButtonClick
      end
      object ToolButton1: TToolButton
        Left = 51
        Top = 0
        Width = 8
        Caption = 'ToolButton1'
        ImageIndex = 2
        Style = tbsSeparator
      end
      object ExitToolButton: TToolButton
        Left = 59
        Top = 0
        AutoSize = True
        Caption = 'Exit'
        ImageIndex = 2
        OnClick = ExitToolButtonClick
      end
    end
  end
  object InputCategoryPanelGroup: TCategoryPanelGroup
    Left = 0
    Top = 0
    Width = 241
    Height = 696
    VertScrollBar.Tracking = True
    HeaderFont.Charset = DEFAULT_CHARSET
    HeaderFont.Color = clWindowText
    HeaderFont.Height = -11
    HeaderFont.Name = 'Tahoma'
    HeaderFont.Style = []
    TabOrder = 1
    object FileListCategoryPanel: TCategoryPanel
      Top = 447
      Height = 210
      Caption = 'File list'
      TabOrder = 0
      object FileListBox: TFileListBox
        Left = 0
        Top = 21
        Width = 237
        Height = 163
        Align = alClient
        ItemHeight = 13
        Mask = 'L-Systems\*.txt'
        TabOrder = 0
        OnClick = FileListBoxClick
      end
      object FilesParentFolerEdit: TEdit
        Left = 0
        Top = 0
        Width = 237
        Height = 21
        Align = alTop
        TabOrder = 1
        OnChange = FilesParentFolerEditChange
      end
    end
    object FractalStringCategoryPanel: TCategoryPanel
      Top = 281
      Height = 166
      Caption = 'Fractal string'
      TabOrder = 1
      object FractalStringMemo: TMemo
        Left = 0
        Top = 21
        Width = 237
        Height = 119
        Align = alClient
        ScrollBars = ssVertical
        TabOrder = 0
      end
      object FractalStringLengthEdit: TEdit
        Left = 0
        Top = 0
        Width = 237
        Height = 21
        Align = alTop
        ReadOnly = True
        TabOrder = 1
      end
    end
    object FileCategoryPanel: TCategoryPanel
      Top = 0
      Height = 281
      Caption = 'File'
      TabOrder = 2
      object FileGridPanel: TGridPanel
        Left = 0
        Top = 0
        Width = 237
        Height = 250
        Align = alTop
        BevelOuter = bvNone
        Caption = 'FileGridPanel'
        ColumnCollection = <
          item
            SizeStyle = ssAbsolute
            Value = 80.000000000000000000
          end
          item
            Value = 100.000000000000000000
          end>
        ControlCollection = <
          item
            Column = 0
            Control = TurtleLabel
            Row = 1
          end
          item
            Column = 1
            Control = DOLSystemMemo
            Row = 0
          end
          item
            Column = 1
            Control = InitialTurtleStateMemo
            Row = 1
          end
          item
            Column = 0
            Control = IterationLabel
            Row = 2
          end
          item
            Column = 0
            Control = DOLSystemGridPanel
            Row = 0
          end
          item
            Column = 1
            Control = IterationPanel
            Row = 2
          end>
        RowCollection = <
          item
            SizeStyle = ssAbsolute
            Value = 100.000000000000000000
          end
          item
            SizeStyle = ssAbsolute
            Value = 100.000000000000000000
          end
          item
            SizeStyle = ssAbsolute
            Value = 40.000000000000000000
          end
          item
            SizeStyle = ssAuto
          end>
        ShowCaption = False
        TabOrder = 0
        DesignSize = (
          237
          250)
        object TurtleLabel: TLabel
          Left = 11
          Top = 137
          Width = 58
          Height = 26
          Alignment = taCenter
          Anchors = []
          Caption = 'Initial turtle state'
          WordWrap = True
          ExplicitLeft = 6
          ExplicitTop = 118
        end
        object DOLSystemMemo: TMemo
          Left = 80
          Top = 0
          Width = 157
          Height = 100
          Align = alClient
          ScrollBars = ssVertical
          TabOrder = 0
        end
        object InitialTurtleStateMemo: TMemo
          Left = 80
          Top = 100
          Width = 157
          Height = 100
          Align = alClient
          ScrollBars = ssVertical
          TabOrder = 1
        end
        object IterationLabel: TLabel
          Left = 19
          Top = 213
          Width = 42
          Height = 13
          Alignment = taCenter
          Anchors = []
          Caption = 'Iteration'
          ExplicitLeft = 7
          ExplicitTop = 181
        end
        object DOLSystemGridPanel: TGridPanel
          Left = 0
          Top = 0
          Width = 80
          Height = 100
          Align = alClient
          BevelOuter = bvNone
          Caption = 'DOLSystemGridPanel'
          ColumnCollection = <
            item
              Value = 100.000000000000000000
            end>
          ControlCollection = <
            item
              Column = 0
              Control = DOLSystemLabel
              Row = 0
            end>
          RowCollection = <
            item
              SizeStyle = ssAbsolute
              Value = 50.000000000000000000
            end
            item
              Value = 100.000000000000000000
            end>
          ShowCaption = False
          TabOrder = 2
          DesignSize = (
            80
            100)
          object DOLSystemLabel: TLabel
            Left = 11
            Top = 18
            Width = 58
            Height = 13
            Anchors = []
            AutoSize = False
            Caption = 'DOL-System'
            Layout = tlCenter
            ExplicitLeft = 16
            ExplicitTop = 68
          end
        end
        object IterationPanel: TPanel
          Left = 80
          Top = 200
          Width = 157
          Height = 40
          Align = alClient
          BevelOuter = bvNone
          Caption = 'IterationPanel'
          ShowCaption = False
          TabOrder = 3
          object IterationMaskEdit: TMaskEdit
            Left = 18
            Top = 9
            Width = 121
            Height = 21
            TabOrder = 0
            Text = '0'
          end
        end
      end
    end
  end
end
