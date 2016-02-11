; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFlowchart_testView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "flowchart_test.h"
LastPage=0

ClassCount=7
Class1=CFlowchart_testApp
Class2=CFlowchart_testDoc
Class3=CFlowchart_testView
Class4=CMainFrame

ResourceCount=6
Resource1=IDR_MENU2
Resource2=IDR_MAINFRAME
Class5=CChildFrame
Class6=CAboutDlg
Resource3=IDD_ABOUTBOX
Class7=CPropertyDialog
Resource4=IDR_FLOWCHTYPE
Resource5=IDR_MENU1
Resource6=IDD_DIALOG1

[CLS:CFlowchart_testApp]
Type=0
HeaderFile=flowchart_test.h
ImplementationFile=flowchart_test.cpp
Filter=N

[CLS:CFlowchart_testDoc]
Type=0
HeaderFile=flowchart_testDoc.h
ImplementationFile=flowchart_testDoc.cpp
Filter=N
LastObject=CFlowchart_testDoc

[CLS:CFlowchart_testView]
Type=0
HeaderFile=flowchart_testView.h
ImplementationFile=flowchart_testView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_DELETE


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CMDIFrameWnd
VirtualFilter=fWC


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=flowchart_test.cpp
ImplementationFile=flowchart_test.cpp
Filter=D
LastObject=ID_BUTTON32776

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308481
Control3=IDC_STATIC,static,1342308353
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_HELP_FINDER
Command9=ID_APP_ABOUT
CommandCount=9

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_SaveSVG
Command5=ID_SavePNG
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_FILE_PRINT
Command10=ID_CONTEXT_HELP
Command11=ID_BUTTON32775
Command12=ID_BUTTON32778
Command13=ID_BUTTON32776
Command14=ID_BUTTON32777
Command15=ID_BUTTON32782
Command16=ID_BUTTON32790
Command17=ID_APP_ABOUT
Command18=ID_DELETE
CommandCount=18

[MNU:IDR_FLOWCHTYPE]
Type=1
Class=CFlowchart_testView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_SavePNG
Command7=ID_FILE_PRINT
Command8=ID_FILE_PRINT_PREVIEW
Command9=ID_FILE_PRINT_SETUP
Command10=ID_FILE_SEND_MAIL
Command11=ID_FILE_MRU_FILE1
Command12=ID_APP_EXIT
Command13=ID_EDIT_UNDO
Command14=ID_EDIT_CUT
Command15=ID_EDIT_COPY
Command16=ID_EDIT_PASTE
Command17=ID_DELETE
Command18=ID_VIEW_TOOLBAR
Command19=ID_VIEW_STATUS_BAR
Command20=ID_WINDOW_NEW
Command21=ID_WINDOW_CASCADE
Command22=ID_WINDOW_TILE_HORZ
Command23=ID_WINDOW_ARRANGE
Command24=ID_BUTTON32775
Command25=ID_BUTTON32776
Command26=ID_BUTTON32777
Command27=ID_BUTTON32778
Command28=ID_HELP_FINDER
Command29=ID_APP_ABOUT
CommandCount=29

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_ACCELERATOR32807
Command2=ID_CONTEXT_HELP
Command3=ID_DELETE
Command4=ID_EDIT_COPY
Command5=ID_EDIT_COPY
Command6=ID_EDIT_CUT
Command7=ID_EDIT_CUT
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_PASTE
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_UNDO
Command12=ID_FILE_NEW
Command13=ID_FILE_OPEN
Command14=ID_FILE_PRINT
Command15=ID_FILE_SAVE
Command16=ID_HELP
Command17=ID_NEXT_PANE
Command18=ID_PREV_PANE
CommandCount=18

[DLG:IDD_DIALOG1]
Type=1
Class=CPropertyDialog
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_BUTTONFONT,button,1342242816

[CLS:CPropertyDialog]
Type=0
HeaderFile=PropertyDialog.h
ImplementationFile=PropertyDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CPropertyDialog
VirtualFilter=dWC

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_DELETE
Command5=ID_TEXT
CommandCount=5

[MNU:IDR_MENU2]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_BUTTON32775
Command5=ID_BUTTON32778
Command6=ID_BUTTON32776
Command7=ID_BUTTON32777
Command8=ID_BUTTON32782
Command9=ID_BUTTON32790
CommandCount=9

