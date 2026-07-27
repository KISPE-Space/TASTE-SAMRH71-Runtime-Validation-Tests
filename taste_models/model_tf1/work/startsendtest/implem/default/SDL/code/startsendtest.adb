-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !


package body Startsendtest is
   procedure Pi_1_Start_Sent_Test(P1: in out asn1SccT_Int32;P2: in out asn1SccT_Boolean) is
   begin
      --  get_sender(sender) (1,5)
      RI_0_get_sender(ctxt.sender);
      --  RETURN 
      return;  -- Exit from procedure
   end Pi_1_Start_Sent_Test;


   procedure Pi_2(P1: in out asn1SccT_Int32;P2: in out asn1SccT_Boolean) is
   begin
      --  get_sender(sender) (1,5)
      RI_0_get_sender(ctxt.sender);
      --  RETURN 
      return;  -- Exit from procedure
   end Pi_2;


   --  CONNECTION Startup_Transition
   function Branch_Startup_Transition return Branches is
   begin
      --  NEXT_STATE Wait (25,15) at None, None
      ctxt.State := asn1SccWait;
      return Continuous_Signals;
   end Branch_Startup_Transition;


   procedure Execute_Transition (Branch : Branches) is
      Next_Branch : Branches := Branch;
   begin
      if not ctxt.Init_Done and Branch /= Startup_Transition then
         return;
      end if;
      while Next_Branch /= Branch_End loop
         case Next_Branch is
            when Startup_Transition => Next_Branch := Branch_Startup_Transition;
            when Continuous_Signals => Next_Branch := Branch_End;
            when Branch_End => null;
         end case;
      end loop;
   end Execute_Transition;


   procedure Startup is
   begin
      Execute_Transition (Startup_Transition);
      ctxt.Init_Done := True;
   end Startup;
end Startsendtest;