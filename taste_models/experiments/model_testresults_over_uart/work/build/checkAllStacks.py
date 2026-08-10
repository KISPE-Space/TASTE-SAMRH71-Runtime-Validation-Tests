#!/usr/bin/env python3

import os
import sys
from pathlib import Path

# This system contains the following nodes:
# node_1, node_2

def name_converter(task_name: str):
    task_name_job = task_name
    return task_name_job


def report_node_1():

   error_sentinel = [False]
   functions = []

   
   def report_partition_partition_1():
   
       print("[-] Checking callgraph files' presence in partition_1...")
   
       ci_files =[file.name.strip(' \n\'\"') for file in Path('.').rglob('*.ci')]
   
       if len(ci_files) == 0:
           print(f"[!]\033[93m WARNING: No *.ci files found in {os.path.abspath('.')}, using old stack analyzer.\033[00m")
           version = 9     # GCC == 9.X
       else:
           version = 10    # GCC >= 10.X
   
       print("[-] Checking stack usage of tasks inside partition_1...")
   
       def add_task(task_name):
           task_name_job = name_converter(task_name)
           functions.append(task_name_job)
   
       functions[:] = []
       add_task("testentrypoint_pi_sp_if")
       add_task("teststart00_pi_1_cyclic")
       add_task("teststart00_samrh71rx")
   
       stack_usage = {}
       if version == 9:
           elf_binary = "../binaries/partition_1"
       else:
           elf_binary = ''  # binary not needed for new stack analyzer
   
       shift_offset = 0
       if (version == 9) and (not os.path.exists(elf_binary)):
           print("[x]\033[91m Failed to locate ELF binary:", elf_binary, "\033[00m")
           print("[x]\033[91m Aborting...\033[00m")
           sys.exit(1)
   
       for line in os.popen(f"FindStackUsageMain.py --gcc={version} --binary={elf_binary} --path=./node_1 --roots={','.join(functions)} --verbose"):
           data = line.strip().split(';;')
           try:
               if len(data) == 3:
                   stack_usage[data[1].split(':')[-1].strip()] = int(data[0]), data[2]
           except:
               pass
       pohic_stack_of = {
           
           "testentrypoint_pi_sp_if" :  50,
           
           "teststart00_pi_1_cyclic" :  1024,
           
           "teststart00_samrh71rx" :  1024,
           
       }
   
       def check_task(task_name, version):
           task_name_job = name_converter(task_name)
           if version == 9:
               pass
   
           elif version >= 10:
               pass
           else:
               raise ValueError(f"Invalid GCC Version: {version} ; Must be >= 9")
   
           if task_name not in pohic_stack_of:
               print("[!]\033[93m WARNING: Unable to check stack usage of", task_name_job, "\033[00m")
               return
   
           elif task_name_job not in stack_usage:
               print("[!]\033[93m WARNING: ", task_name_job, " is either recursive or missing\033[00m")
               return
   
           reserved_stack = pohic_stack_of[task_name]
           actual_stack, path = stack_usage[task_name_job]
           actual_stack += shift_offset
           if reserved_stack < actual_stack:
               print("[x]\033[91m ERROR: Stack usage of", task_name_job, "is", actual_stack,
                       "which is higher than", reserved_stack, "\033[00m")
               print("[x]\033[91m ERROR: Call chain is: ", path, "\033[00m")
               error_sentinel[0] = True
           else:
               print("[-]\033[92m Stack usage of %32s" % task_name_job, "is %7d /%7d \033[00m" % (
                   actual_stack, reserved_stack))
   
       check_task("testentrypoint_pi_sp_if", version)
       check_task("teststart00_pi_1_cyclic", version)
       check_task("teststart00_samrh71rx", version)
   

   report_partition_partition_1()
   if error_sentinel[0]:
       sys.exit(1)
def report_node_2():

   error_sentinel = [False]
   functions = []

   
   def report_partition_partition_2():
   
       print("[-] Checking callgraph files' presence in partition_2...")
   
       ci_files =[file.name.strip(' \n\'\"') for file in Path('.').rglob('*.ci')]
   
       if len(ci_files) == 0:
           print(f"[!]\033[93m WARNING: No *.ci files found in {os.path.abspath('.')}, using old stack analyzer.\033[00m")
           version = 9     # GCC == 9.X
       else:
           version = 10    # GCC >= 10.X
   
       print("[-] Checking stack usage of tasks inside partition_2...")
   
       def add_task(task_name):
           task_name_job = name_converter(task_name)
           functions.append(task_name_job)
   
       functions[:] = []
       add_task("uartotherend_samrh71tx")
   
       stack_usage = {}
       if version == 9:
           elf_binary = "../binaries/partition_2"
       else:
           elf_binary = ''  # binary not needed for new stack analyzer
   
       shift_offset = 0
       if (version == 9) and (not os.path.exists(elf_binary)):
           print("[x]\033[91m Failed to locate ELF binary:", elf_binary, "\033[00m")
           print("[x]\033[91m Aborting...\033[00m")
           sys.exit(1)
   
       for line in os.popen(f"FindStackUsageMain.py --gcc={version} --binary={elf_binary} --path=./node_2 --roots={','.join(functions)} --verbose"):
           data = line.strip().split(';;')
           try:
               if len(data) == 3:
                   stack_usage[data[1].split(':')[-1].strip()] = int(data[0]), data[2]
           except:
               pass
       pohic_stack_of = {
           
           "uartotherend_samrh71tx" :  1024,
           
       }
   
       def check_task(task_name, version):
           task_name_job = name_converter(task_name)
           if version == 9:
               pass
   
           elif version >= 10:
               pass
           else:
               raise ValueError(f"Invalid GCC Version: {version} ; Must be >= 9")
   
           if task_name not in pohic_stack_of:
               print("[!]\033[93m WARNING: Unable to check stack usage of", task_name_job, "\033[00m")
               return
   
           elif task_name_job not in stack_usage:
               print("[!]\033[93m WARNING: ", task_name_job, " is either recursive or missing\033[00m")
               return
   
           reserved_stack = pohic_stack_of[task_name]
           actual_stack, path = stack_usage[task_name_job]
           actual_stack += shift_offset
           if reserved_stack < actual_stack:
               print("[x]\033[91m ERROR: Stack usage of", task_name_job, "is", actual_stack,
                       "which is higher than", reserved_stack, "\033[00m")
               print("[x]\033[91m ERROR: Call chain is: ", path, "\033[00m")
               error_sentinel[0] = True
           else:
               print("[-]\033[92m Stack usage of %32s" % task_name_job, "is %7d /%7d \033[00m" % (
                   actual_stack, reserved_stack))
   
       check_task("uartotherend_samrh71tx", version)
   

   report_partition_partition_2()
   if error_sentinel[0]:
       sys.exit(1)

def check_all():
    report_node_1()
    report_node_2()
    return

if __name__ == '__main__':
    ''' Run main application '''
    check_all()
