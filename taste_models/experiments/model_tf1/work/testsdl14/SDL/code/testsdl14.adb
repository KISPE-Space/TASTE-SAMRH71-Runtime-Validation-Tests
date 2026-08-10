-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !


package body Testsdl14 is
   procedure PI_1_STARTSDL14(p1: in out asn1SccCounter) is
   begin
      null;
   end PI_1_STARTSDL14;


   procedure mytime is
   begin
      null;
   end mytime;


   --  CONNECTION rerun (16,8)
   function Branch_rerun return Branches is
   begin
      --  set_timer(5000, mytime) (18,13)
      declare
         tmp8 : asn1SccT_UInt32 := 5000;
      begin
         SET_mytime (tmp8);
      end;
      --  counter := counter + 1 (20,13)
      ctxt.counter := (ctxt.counter + 1);
      --  DECISION counter > 20 (22,25)
      --  ANSWER false (24,13)
      if not ((ctxt.counter > 20)) then
         --  JOIN rerun (26,21) at 391, 412
         return rerun; -- Join in Process
         --  ANSWER true (28,13)
      else
         null;
      end if;
      --  NEXT_STATE Wait (31,18) at 418, 502
      ctxt.State := asn1SccWait;
      return Continuous_Signals;
   end Branch_rerun;


   --  CONNECTION Startup_Transition
   function Branch_Startup_Transition return Branches is
   begin
      --  counter := 0 (14,13)
      ctxt.counter := 0;
      --  JOIN rerun
      return rerun; -- Join in Process
   end Branch_Startup_Transition;


   procedure Execute_Transition (Branch : Branches) is
      Next_Branch : Branches := Branch;
   begin
      if not ctxt.Init_Done and Branch /= Startup_Transition then
         return;
      end if;
      while Next_Branch /= Branch_End loop
         case Next_Branch is
            when rerun => Next_Branch := Branch_rerun;
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
end Testsdl14;