========================================================================
    CONSOLE APPLICATION : ChatBot Project Overview
========================================================================

AppWizard has created this ChatBot application for you.

This file contains a summary of what you will find in each of the files that
make up your ChatBot application.


ChatBot.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

ChatBot.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

ChatBot.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named ChatBot.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
------------------------->>>>>>READ THIS<<<<<<-------------------------------
-Created using Visual Studio 2015 (VC14).

-Using CasablancaCore 2.9.1 C++ REST Client SDK (Nuget)

-To support new conversation types, do the following steps:
1. ChatBotCommon.h - add a new enum type EInputParserResponseType.
2. If needed, create a new class for new type, inherit from InputParserResponse
3. InputParser.cpp - add implementation to switch in CompareInputTokens()
4. ChatBotApp.cpp - add implementation to switch in Start()

/////////////////////////////////////////////////////////////////////////////
