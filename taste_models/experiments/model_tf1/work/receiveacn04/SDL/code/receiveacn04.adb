-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !


package body Receiveacn04 is
   procedure Pi_1(P1: in out asn1SccPID;P2: in out asn1SccPID) is
   begin
      --  get_sender(sender) (1,5)
      RI_0_get_sender(ctxt.sender);
      --  Pi_1_Transition (None,None)
      Pi_1_Transition;
      --  RETURN 
      return;  -- Exit from procedure
   end Pi_1;


   procedure PI_1_Transition is
   begin
      case ctxt.state is
         when others =>
            Execute_Transition (Continuous_Signals);
      end case;
   end PI_1_Transition;


   --  CONNECTION Startup_Transition
   function Branch_Startup_Transition return Branches is
   begin
      --  NEXT_STATE Wait (14,15) at None, None
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
         <<Next_Transition>>
      end loop;
   end Execute_Transition;


   procedure Startup is
   begin
      Execute_Transition (Startup_Transition);
      ctxt.Init_Done := True;
   end Startup;
end Receiveacn04;