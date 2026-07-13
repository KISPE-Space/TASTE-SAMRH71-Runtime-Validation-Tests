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
with Receiveacn02_Datamodel; use Receiveacn02_Datamodel;

with Receiveacn02_RI;
package Receiveacn02 with Elaborate_Body is
   
   self : constant asn1SccPID := asn1Sccreceiveacn02;
   Default_Context: constant asn1SccReceiveacn02_Context :=
      (Init_Done => False,
       sender => asn1Sccenv,
       offspring => asn1Sccenv,
       others => <>);
   ctxt : aliased asn1SccReceiveacn02_Context := Default_Context;
   function To_T_Runtime_Error_Selection (Src : TASTE_BasicTypes.asn1SccT_Runtime_Error_Selection) return Receiveacn02_Datamodel.asn1SccReceiveacn02_T_Runtime_Error_Selection is (Receiveacn02_Datamodel.asn1SccReceiveacn02_T_Runtime_Error_Selection'Enum_Val (Src'Enum_Rep));
   function Get_State return Chars_Ptr is (Receiveacn02_RI.To_C_Pointer (asn1SccReceiveacn02_States'Image (ctxt.State))) with Export, Convention => C, Link_Name => "receiveacn02_state";
   procedure Startup with Export, Convention => C, Link_Name => "receiveacn02_startup";
   procedure Pi_1(P1: in out asn1SccT_UInt8;P2: in out asn1SccT_UInt8);
   pragma Export (C, Pi_1, "receiveacn02_PI_PI_1");
   --  Provided interface "PI_1"
   procedure PI_1_Transition;
   --  Synchronous Required Interface "get_sender"
   procedure RI_0_get_sender (sender : out asn1SccPID; Dest_PID : asn1SccPID := asn1SccEnv) renames Receiveacn02_RI.get_sender;
   --  Synchronous Required Interface "get_last_error"
   procedure RI_0_get_last_error (err : out asn1SccT_Runtime_Error; Dest_PID : asn1SccPID := asn1SccEnv) renames Receiveacn02_RI.get_last_error;
   type Branches is (Startup_Transition, Continuous_Signals, Branch_End);
   procedure Execute_Transition (Branch : Branches);
   function Branch_Startup_Transition return Branches;
end Receiveacn02;