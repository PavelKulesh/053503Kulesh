object ExpenseManager: TExpenseManager
  Left = 0
  Top = 0
  Caption = 'ExpenseManager'
  ClientHeight = 461
  ClientWidth = 990
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Times New Roman'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 14
  object Label1: TLabel
    Left = 201
    Top = 17
    Width = 65
    Height = 22
    Caption = #1044#1086#1093#1086#1076#1099
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 712
    Top = 17
    Width = 73
    Height = 22
    Caption = #1056#1072#1089#1093#1086#1076#1099
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 332
    Width = 165
    Height = 19
    Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100' '#1076#1086#1093#1086#1076#1099' '#1087#1086':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 507
    Top = 332
    Width = 171
    Height = 19
    Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100' '#1088#1072#1089#1093#1086#1076#1099' '#1087#1086':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object ExpenseAdd: TButton
    Left = 507
    Top = 398
    Width = 126
    Height = 50
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1088#1072#1089#1093#1086#1076
    TabOrder = 0
    OnClick = ExpenseAddClick
  end
  object ExpenseTable: TStringGrid
    Left = 507
    Top = 45
    Width = 470
    Height = 281
    DefaultRowHeight = 30
    FixedCols = 0
    RowCount = 100
    ScrollBars = ssVertical
    TabOrder = 1
    ColWidths = (
      87
      88
      93
      64
      114)
  end
  object Find1: TButton
    Left = 140
    Top = 398
    Width = 126
    Height = 50
    Caption = #1055#1086#1080#1089#1082' '#1076#1086#1093#1086#1076#1086#1074
    TabOrder = 2
    OnClick = Find1Click
  end
  object IncomeTable: TStringGrid
    Left = 8
    Top = 45
    Width = 470
    Height = 281
    DefaultRowHeight = 30
    FixedCols = 0
    RowCount = 100
    ScrollBars = ssVertical
    TabOrder = 3
    ColWidths = (
      87
      88
      93
      64
      114)
  end
  object ComboBox1: TComboBox
    Left = 179
    Top = 332
    Width = 145
    Height = 22
    Style = csDropDownList
    TabOrder = 4
    TextHint = #1050#1072#1090#1077#1075#1086#1088#1080#1103
    Items.Strings = (
      #1050#1072#1090#1077#1075#1086#1088#1080#1103
      #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
      #1057#1091#1084#1084#1072'(BYN)'
      #1044#1072#1090#1072)
  end
  object ComboBox2: TComboBox
    Left = 684
    Top = 332
    Width = 145
    Height = 22
    Style = csDropDownList
    TabOrder = 5
    TextHint = #1050#1072#1090#1077#1075#1086#1088#1080#1103
    Items.Strings = (
      #1050#1072#1090#1077#1075#1086#1088#1080#1103
      #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
      #1057#1090#1086#1080#1084#1086#1089#1090#1100'(BYN)'
      #1044#1072#1090#1072)
  end
  object Sort1: TButton
    Left = 8
    Top = 357
    Width = 75
    Height = 25
    Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 6
    OnClick = Sort1Click
  end
  object Sort2: TButton
    Left = 507
    Top = 357
    Width = 75
    Height = 25
    Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 7
    OnClick = Sort2Click
  end
  object ComboBox3: TComboBox
    Left = 330
    Top = 332
    Width = 87
    Height = 22
    Style = csDropDownList
    TabOrder = 8
    TextHint = #1042#1086#1079#1088#1072#1089#1090#1072#1085#1080#1077
    Items.Strings = (
      #1042#1086#1079#1088#1072#1089#1090#1072#1085#1080#1077
      #1059#1073#1099#1074#1072#1085#1080#1077)
  end
  object ComboBox4: TComboBox
    Left = 835
    Top = 332
    Width = 86
    Height = 22
    Style = csDropDownList
    TabOrder = 9
    TextHint = #1042#1086#1079#1088#1072#1089#1090#1072#1085#1080#1077
    Items.Strings = (
      #1042#1086#1079#1088#1072#1089#1090#1072#1085#1080#1077
      #1059#1073#1099#1074#1072#1085#1080#1077)
  end
  object Find2: TButton
    Left = 639
    Top = 398
    Width = 126
    Height = 50
    Caption = #1055#1086#1080#1089#1082' '#1088#1072#1089#1093#1086#1076#1086#1074
    TabOrder = 10
    OnClick = Find2Click
  end
  object IncomeStatistics: TButton
    Left = 272
    Top = 398
    Width = 126
    Height = 50
    Caption = #1057#1090#1072#1090#1080#1089#1090#1080#1082#1072' '#1076#1086#1093#1086#1076#1086#1074
    TabOrder = 11
    OnClick = IncomeStatisticsClick
  end
  object ExpenseStatistics: TButton
    Left = 771
    Top = 398
    Width = 126
    Height = 50
    Caption = #1057#1090#1072#1090#1080#1089#1090#1080#1082#1072' '#1088#1072#1089#1093#1086#1076#1086#1074
    TabOrder = 12
    OnClick = ExpenseStatisticsClick
  end
  object IncomeAdd: TButton
    Left = 8
    Top = 398
    Width = 126
    Height = 50
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1076#1086#1093#1086#1076
    TabOrder = 13
    OnClick = IncomeAddClick
  end
  object Timer1: TTimer
    Interval = 1
    OnTimer = Timer1Timer
    Left = 960
    Top = 432
  end
  object MainMenu1: TMainMenu
    Left = 928
    Top = 432
    object fgbf1: TMenuItem
      Caption = #1053#1086#1074#1099#1081' '#1091#1095#1105#1090
      OnClick = fgbf1Click
    end
    object N1: TMenuItem
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      OnClick = N1Click
    end
    object N2: TMenuItem
    end
  end
end
