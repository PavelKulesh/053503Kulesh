object AddExpense: TAddExpense
  Left = 0
  Top = 0
  Caption = 'AddExpense'
  ClientHeight = 286
  ClientWidth = 249
  Color = clMaroon
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = OnCloseClick
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 8
    Top = 54
    Width = 113
    Height = 19
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 100
    Width = 126
    Height = 19
    Caption = #1057#1090#1086#1080#1084#1086#1089#1090#1100'(BYN):'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 82
    Height = 19
    Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103':'
    Color = clMaroon
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object Label5: TLabel
    Left = 8
    Top = 146
    Width = 40
    Height = 19
    Caption = #1044#1072#1090#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 8
    Top = 192
    Width = 105
    Height = 19
    Caption = #1050#1086#1084#1084#1077#1085#1090#1072#1088#1080#1081':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 8
    Top = 73
    Width = 121
    Height = 23
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object DateTimePicker1: TDateTimePicker
    Left = 8
    Top = 165
    Width = 186
    Height = 23
    Date = 44334.000000000000000000
    Time = 0.543523888889467300
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object ComboBox1: TComboBox
    Left = 8
    Top = 27
    Width = 145
    Height = 23
    Style = csDropDownList
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Items.Strings = (
      #1055#1088#1086#1076#1091#1082#1090#1099
      #1040#1074#1090#1086#1084#1086#1073#1080#1083#1100
      #1058#1088#1072#1085#1089#1087#1086#1088#1090
      #1045#1076#1072' '#1076#1083#1103' '#1087#1080#1090#1086#1084#1094#1077#1074
      #1058#1077#1093#1085#1080#1082#1072
      #1041#1099#1090#1086#1074#1072#1103' '#1090#1077#1093#1085#1080#1082#1072
      #1054#1076#1077#1078#1076#1072
      #1052#1077#1073#1077#1083#1100
      #1050#1086#1084#1084#1091#1085#1072#1083#1100#1085#1099#1077' '#1091#1089#1083#1091#1075#1080
      #1059#1095#1105#1073#1072
      #1047#1076#1086#1088#1086#1074#1100#1077
      #1054#1090#1076#1099#1093
      #1057#1087#1086#1088#1090
      #1056#1072#1079#1074#1083#1077#1095#1077#1085#1080#1103
      #1041#1072#1085#1082
      #1044#1086#1083#1075#1080
      #1055#1088#1086#1095#1077#1077)
  end
  object Edit2: TEdit
    Left = 8
    Top = 119
    Width = 121
    Height = 23
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object Done: TButton
    Left = 8
    Top = 247
    Width = 75
    Height = 25
    Caption = #1043#1086#1090#1086#1074#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = DoneClick
  end
  object Edit3: TEdit
    Left = 8
    Top = 211
    Width = 233
    Height = 22
    AutoSize = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
end
