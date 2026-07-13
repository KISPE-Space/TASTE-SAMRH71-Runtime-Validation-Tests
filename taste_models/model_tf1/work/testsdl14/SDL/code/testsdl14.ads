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
with Testsdl14_Datamodel; use Testsdl14_Datamodel;

with Testsdl14_RI;
package Testsdl14 with Elaborate_Body is
   
   self : constant asn1SccPID := asn1Scctestsdl14;
   Default_Context: constant asn1SccTestsdl14_Context :=
      (Init_Done => False,
       sender => asn1Sccenv,
       offspring => asn1Sccenv,
       others => <>);
   ctxt : aliased asn1SccTestsdl14_Context := Default_Context;

   function To_T_Runtime_Error_Selection (Src : TASTE_BasicTypes.asn1SccT_Runtime_Error_Selection) return Testsdl14_Datamodel.asn1SccTestsdl14_T_Runtime_Error_Selection is (Testsdl14_Datamodel.asn1SccTestsdl14_T_Runtime_Error_Selection'Enum_Val (Src'Enum_Rep));
   function Get_State return Chars_Ptr is (Testsdl14_RI.To_C_Pointer (asn1SccTestsdl14_States'Image(ctxt.State))) with Export, Convention => C, Link_Name => "testsdl14_state";
   procedure Startup with Export, Convention => C, Link_Name => "testsdl14_startup";
   --  Provided interface "PI_1_STARTSDL14"
   procedure PI_1_STARTSDL14(p1: in out asn1SccCounter);
   pragma Export(C, PI_1_STARTSDL14, "testsdl14_PI_PI_1_STARTSDL14");
   --  Provided interface "mytime"
   procedure mytime;
   pragma Export(C, mytime, "testsdl14_PI_mytime");
   --  Synchronous Required Interface "get_sender"
   procedure RI_0_get_sender (sender : out asn1SccPID; Dest_PID : asn1SccPID := asn1SccEnv) renames Testsdl14_RI.get_sender;
   --  Synchronous Required Interface "get_last_error"
   procedure RI_0_get_last_error (err : out asn1SccT_Runtime_Error; Dest_PID : asn1SccPID := asn1SccEnv) renames Testsdl14_RI.get_last_error;
   --  Timer mytime SET and RESET functions
   procedure SET_mytime (Val : in out asn1SccT_UInt32; Dest_PID : asn1SccPID := asn1SccEnv) renames Testsdl14_RI.Set_mytime;
   procedure RESET_mytime (Dest_PID : asn1SccPID := asn1SccEnv) renames Testsdl14_RI.Reset_mytime;
   type Branches is (rerun, Startup_Transition, Continuous_Signals, Branch_End);
   procedure Execute_Transition (Branch : Branches);
   function Branch_rerun return Branches;
   function Branch_Startup_Transition return Branches;
end Testsdl14;