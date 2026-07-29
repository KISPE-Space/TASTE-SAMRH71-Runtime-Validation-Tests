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
with Function_6_Datamodel; use Function_6_Datamodel;

with Function_6_RI;
package Function_6 with Elaborate_Body is
   
   self : constant asn1SccPID := asn1Sccfunction_6;
   Default_Context: constant asn1SccFunction_6_Context :=
      (Init_Done => False,
       sender => asn1Sccenv,
       offspring => asn1Sccenv,
       others => <>);
   ctxt : aliased asn1SccFunction_6_Context := Default_Context;
   function To_T_Runtime_Error_Selection (Src : TASTE_BasicTypes.asn1SccT_Runtime_Error_Selection) return Function_6_Datamodel.asn1SccFunction_6_T_Runtime_Error_Selection is (Function_6_Datamodel.asn1SccFunction_6_T_Runtime_Error_Selection'Enum_Val (Src'Enum_Rep));
   function Get_State return Chars_Ptr is (Function_6_RI.To_C_Pointer (asn1SccFunction_6_States'Image (ctxt.State))) with Export, Convention => C, Link_Name => "function_6_state";
   procedure Startup with Export, Convention => C, Link_Name => "function_6_startup";
   --  Provided interface "PI_1"
   procedure PI_1;
   pragma Export(C, PI_1, "function_6_PI_PI_1");
   --  Synchronous Required Interface "get_sender"
   procedure RI_0_get_sender (sender : out asn1SccPID; Dest_PID : asn1SccPID := asn1SccEnv) renames Function_6_RI.get_sender;
   --  Synchronous Required Interface "get_last_error"
   procedure RI_0_get_last_error (err : out asn1SccT_Runtime_Error; Dest_PID : asn1SccPID := asn1SccEnv) renames Function_6_RI.get_last_error;
   type Branches is (Startup_Transition, Continuous_Signals, Branch_End);
   procedure Execute_Transition (Branch : Branches);
   function Branch_Startup_Transition return Branches;
end Function_6;