/*
    Header: script_macros_common.hpp

    Description:
        A general set of useful macro functions for use by CBA itself or by any module that uses CBA.

    Authors:
        Sickboy <sb_at_dev-heaven.net> and Spooner
*/

/* ****************************************************
 New - Should be exported to general addon
 Aim:
   - Simplify (shorten) the amount of characters required for repetitive tasks
   - Provide a solid structure that can be dynamic and easy editable (Which sometimes means we cannot adhere to Aim #1 ;-)
     An example is the path that is built from defines. Some available in this file, others in mods and addons.

 Follows  Standard:
   Object variables: PREFIX_COMPONENT
   Main-object variables: PREFIX_main
   Paths: MAINPREFIX\PREFIX\SUBPREFIX\COMPONENT\SCRIPTNAME.sqf
   e.g: x\six\addons\sys_menu\fDate.sqf

 Usage:
   define PREFIX and COMPONENT, then include this file
   (Note, you could have a main addon for your mod, define the PREFIX in a macros.hpp,
   and include this script_macros_common.hpp file.
   Then in your addons, add a component.hpp, define the COMPONENT,
   and include your mod's script_macros.hpp
   In your scripts you can then include the addon's component.hpp with relative path)

 TODO:
   - Try only to use 1 string type " vs '
   - Evaluate double functions, and simplification
   - Evaluate naming scheme; current = prototype
   - Evaluate "Debug" features..
   - Evaluate "create mini function per precompiled script, that will load the script on first usage, rather than on init"
   - Also saw "Namespace" typeName, evaluate which we need :P
   - Single/Multi player gamelogics? (Incase of MP, you would want only 1 gamelogic per component, which is pv'ed from server, etc)
 */

#ifndef MAINPREFIX
    #define MAINPREFIX x
#endif

#ifndef SUBPREFIX
    #define SUBPREFIX addons
#endif

#ifndef MAINLOGIC
    #define MAINLOGIC main
#endif

#define ADDON DOUBLES(PREFIX,COMPONENT)
#define MAIN_ADDON DOUBLES(PREFIX,main)

/* -------------------------------------------
Macro: VERSION_CONFIG
    Define CBA Versioning System config entries.

    VERSION should be a floating-point number (1 separator).
    VERSION_STR is a string representation of the version.
    VERSION_AR is an array representation of the version.

    VERSION must always be defined, otherwise it is 0.
    VERSION_STR and VERSION_AR default to VERSION if undefined.

Parameters:
    None

Example:
    (begin example)
        #define VERSION 1.0
        #define VERSION_STR 1.0.1
        #define VERSION_AR 1,0,1

        class CfgPatches {
            class MyMod_main {
                VERSION_CONFIG;
            };
        };
    (end)

Author:
    ?, Jonpas
------------------------------------------- */
#ifndef VERSION
    #define VERSION 0
#endif

#ifndef VERSION_STR
    #define VERSION_STR VERSION
#endif

#ifndef VERSION_AR
    #define VERSION_AR VERSION
#endif

#ifndef VERSION_CONFIG
    #define VERSION_CONFIG version = VERSION; versionStr = QUOTE(VERSION_STR); versionAr[] = {VERSION_AR}
#endif

/* -------------------------------------------
Group: General
------------------------------------------- */

// *************************************
// Internal Functions
#define DOUBLES(var1,var2) var1##_##var2
#define TRIPLES(var1,var2,var3) var1##_##var2##_##var3
#define QUOTE(var1) #var1

/* -------------------------------------------
Macro: GVAR()
    Get full variable identifier for a global variable owned by this component.

Parameters:
    VARIABLE - Partial name of global variable owned by this component [Any].

Example:
    (begin example)
        GVAR(frog) = 12;
        // In SPON_FrogDancing component, equivalent to SPON_FrogDancing_frog = 12
    (end)

Author:
    Sickboy
------------------------------------------- */
#define GVAR(var1) DOUBLES(ADDON,var1)
#define EGVAR(var1,var2) TRIPLES(PREFIX,var1,var2)
#define QGVAR(var1) QUOTE(GVAR(var1))
#define QEGVAR(var1,var2) QUOTE(EGVAR(var1,var2))
#define QQGVAR(var1) QUOTE(QGVAR(var1))
#define QQEGVAR(var1,var2) QUOTE(QEGVAR(var1,var2))

#define FUNC(var1) TRIPLES(ADDON,fnc,var1)
#define QFUNC(var1) QUOTE(FUNC(var1))
/* -------------------------------------------
Macro: SCRIPT()
    Sets name of script (relies on PREFIX and COMPONENT values being #defined).
    Define 'SKIP_SCRIPT_NAME' to skip adding scriptName.

Parameters:
    NAME - Name of script [Indentifier]

Example:
    (begin example)
        SCRIPT(eradicateMuppets);
    (end)

Author:
    Spooner
------------------------------------------- */
#ifndef SKIP_SCRIPT_NAME
    #define SCRIPT(NAME) scriptName 'PREFIX\COMPONENT\NAME'
#else
    #define SCRIPT(NAME) /* nope */
#endif

/* -------------------------------------------
Macro: xSTRING()
    Get full string identifier from a stringtable owned by this component.

Parameters:
    VARIABLE - Partial name of global variable owned by this component [Any].

Example:
    ADDON is CBA_Balls.
    (begin example)
        // Localized String (localize command must still be used with it)
        LSTRING(Example); // STR_CBA_Balls_Example;
        // Config String (note the $)
        CSTRING(Example); // $STR_CBA_Balls_Example;
    (end)

Author:
    Jonpas
------------------------------------------- */
#ifndef STRING_MACROS_GUARD
#define STRING_MACROS_GUARD
    #define LSTRING(var1) QUOTE(TRIPLES(STR,ADDON,var1))
    #define ELSTRING(var1,var2) QUOTE(TRIPLES(STR,DOUBLES(PREFIX,var1),var2))
    #define CSTRING(var1) QUOTE(TRIPLES($STR,ADDON,var1))
    #define ECSTRING(var1,var2) QUOTE(TRIPLES($STR,DOUBLES(PREFIX,var1),var2))

    #define LLSTRING(var1) localize QUOTE(TRIPLES(STR,ADDON,var1))
    #define LELSTRING(var1,var2) localize QUOTE(TRIPLES(STR,DOUBLES(PREFIX,var1),var2))
#endif


#define GUI_THEME_RGB_R "(profileNamespace getVariable ['GUI_BCG_RGB_R',0.13])"
#define GUI_THEME_RGB_G "(profileNamespace getVariable ['GUI_BCG_RGB_G',0.54])"
#define GUI_THEME_RGB_B "(profileNamespace getVariable ['GUI_BCG_RGB_B',0.21])"
#define GUI_THEME_ALPHA "(profileNamespace getVariable ['GUI_BCG_RGB_A',0.8])"

#define GUI_THEME_COLOR {GUI_THEME_RGB_R,GUI_THEME_RGB_G,GUI_THEME_RGB_B,GUI_THEME_ALPHA}