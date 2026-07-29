-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with Interfaces,
     Interfaces.C.Strings,
     Ada.Characters.Handling;

use Interfaces,
    Interfaces.C.Strings,
    Ada.Characters.Handling;

with MODEL_TF1_DATAVIEW;
use MODEL_TF1_DATAVIEW;
with TASTE_BasicTypes;
use TASTE_BasicTypes;
with System_Dataview;
use System_Dataview;
with adaasn1rtl;
use adaasn1rtl;
with Startsendtest_Datamodel; use Startsendtest_Datamodel;

with Startsendtest_RI;
package Startsendtest with Elaborate_Body is
   
   self : constant asn1SccPID := asn1Sccstartsendtest;
   Default_Context: constant asn1SccStartsendtest_Context :=
      (Init_Done => False,
       sender => asn1Sccenv,
       offspring => asn1Sccenv,
       others => <>);
   ctxt : aliased asn1SccStartsendtest_Context := Default_Context;

   function To_T_Runtime_Error_Selection (Src : TASTE_BasicTypes.asn1SccT_Runtime_Error_Selection) return Startsendtest_Datamodel.asn1SccStartsendtest_T_Runtime_Error_Selection is (Startsendtest_Datamodel.asn1SccStartsendtest_T_Runtime_Error_Selection'Enum_Val (Src'Enum_Rep));
   function Get_State return Chars_Ptr is (Startsendtest_RI.To_C_Pointer (asn1SccStartsendtest_States'Image(ctxt.State))) with Export, Convention => C, Link_Name => "startsendtest_state";
   procedure Startup with Export, Convention => C, Link_Name => "startsendtest_startup";
   procedure Pi_1_Start_Sent_Test(P1: in out asn1SccT_Int32;P2: in out asn1SccT_Boolean);
   pragma Export (C, Pi_1_Start_Sent_Test, "startsendtest_PI_PI_1_Start_Sent_Test");
   procedure Pi_2(P1: in out asn1SccT_Int32;P2: in out asn1SccT_Boolean);
   pragma Export (C, Pi_2, "startsendtest_PI_PI_2");
   --  Synchronous Required Interface "PI_1"
   procedure RI_0_PI_1 (P1 : out asn1SccT_Int32; P2 : out asn1SccT_Boolean; Dest_PID : asn1SccPID := asn1SccEnv) renames Startsendtest_RI.PI_1;
   --  Synchronous Required Interface "get_sender"
   procedure RI_0_get_sender (sender : out asn1SccPID; Dest_PID : asn1SccPID := asn1SccEnv) renames Startsendtest_RI.get_sender;
   --  Synchronous Required Interface "get_last_error"
   procedure RI_0_get_last_error (err : out asn1SccT_Runtime_Error; Dest_PID : asn1SccPID := asn1SccEnv) renames Startsendtest_RI.get_last_error;
   type Branches is (Startup_Transition, Continuous_Signals, Branch_End);
   procedure Execute_Transition (Branch : Branches);
   function Branch_Startup_Transition return Branches;
end Startsendtest;