-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !


package body Testsdl08 is
   procedure PI_STARTSDL08(p1: in out asn1SccCounter) is
   begin
      case ctxt.state is
         when others =>
            Execute_Transition (Continuous_Signals);
      end case;
   end PI_STARTSDL08;


   procedure mytime is
   begin
      case ctxt.state is
         when others =>
            Execute_Transition (Continuous_Signals);
      end case;
   end mytime;


   --  CONNECTION rerun (16,8)
   function Branch_rerun return Branches is
      tmp44 : asn1SccT_UInt32;
   begin
      --  set_timer(1000, mytime) (18,13)
      tmp44 := 1000;
      SET_mytime (tmp44);
      --  counter := counter + 1 (20,13)
      ctxt.counter := (ctxt.counter + 1);
      --  DECISION counter > 10 (22,25)
      --  ANSWER false (24,13)
      if not ((ctxt.counter > 10)) then
         --  JOIN rerun (26,21) at 571, 499
         return rerun; -- Join in Process
         --  ANSWER true (28,13)
      else
         --  NEXT_STATE Wait (30,26) at 644, 499
         ctxt.State := asn1SccWait;
         return Continuous_Signals;
      end if;
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
         <<Next_Transition>>
      end loop;
   end Execute_Transition;


   procedure Startup is
   begin
      Execute_Transition (Startup_Transition);
      ctxt.Init_Done := True;
   end Startup;
   begin
      Startup;
end Testsdl08;