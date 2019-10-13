Option Explicit

Dim strMorning_Session
Dim strProblems_Solved
Dim strWork_Out
Dim strCoding_Sheet
Dim strProgramming_Build_up

' Prompt for morning_session, problems_solved, work_out, coding_sheet, programming_build_up

strMorning_Session = Inputbox( "How many minutes did you study today? (Min):" )
strProblems_Solved = Inputbox( "Enter the number of MCQs you solved today (Num):" )
strWork_Out = Inputbox( "How many minutes did you work out today? (Min):" )
strCoding_Sheet = Inputbox( "How many problems did you solve from the Coding Sheet today? (Num):" )
strProgramming_Build_Up = InputBox( "What new topics did you explore today? (Words):" )

Dim objFSO, objFolder, objShell, objTextFile, objFile
Dim strDirectory, strFile, strText
strDirectory = "e:\dailyupdate"
strFile = "\MyDailyLog.csv"
strText = strMorning_Session & "," & strProblems_Solved & "," & strWork_Out & "," & strCoding_Sheet & "," & strProgramming_Build_up

' Create the File System Object
Set objFSO = CreateObject("Scripting.FileSystemObject")

' OpenTextFile Method needs a Const value
' ForAppending = 8 ForReading = 1, ForWriting = 2
Const ForAppending = 8

Set objTextFile = objFSO.OpenTextFile _
(strDirectory & strFile, ForAppending, True)

' Key Section to write the strText to the file.
' Writes strText every time you run this VBScript
objTextFile.WriteLine(strText)
objTextFile.Close

WScript.Quit
