/***********************************************************************************
 *  @file tf_cpu.c
 ***********************************************************************************
 *   _  _____ ____  ____  _____
 *  | |/ /_ _/ ___||  _ \| ____|
 *  | ' / | |\___ \| |_) |  _|
 *  | . \ | | ___) |  __/| |___
 *  |_|\_\___|____/|_|   |_____|
 *
 ***********************************************************************************
 *  Copyright (c) 2026 KISPE Space Systems Ltd.
 *
 *  All Rights Reserved
 ***********************************************************************************
 *  Created on: 17th-Aug-2026 14:07:16
 *  Implementation of the CPU utilities module
 *  @author: Andy Cowling
 ***********************************************************************************/

#include "tf_cpu.h"
#include <Pmc/Pmc.h>


/*
 * PUBLIC FUNCTIONS -------------------------------------------------------------------------------------------------
 */


/*
 * Refer to header for function usage docs
 */
bool is_processor_clock_100mhz(void)
{
    // Initialise a pmc variable which we can use to call the Pmc clock config functions
    Pmc pmc;
    Pmc_init(&pmc, Pmc_getDeviceRegisterStartAddress());

    // Master config: Should be: src=Pmc_MasterckSrc_Pllack, presc=Pmc_MasterckPresc_2, divider=Pmc_MasterckDiv_2
    Pmc_MasterckConfig mastcfg;
    Pmc_getMasterckConfig(&pmc, &mastcfg);
    if (mastcfg.src != Pmc_MasterckSrc_Pllack || mastcfg.presc != Pmc_MasterckPresc_2 || mastcfg.divider != Pmc_MasterckDiv_2)
    {
        return false;
    }

    // Main config: Should be: src=Pmc_MainckSrc_XOscBypassed, rcOscFreq=Pmc_RcOscFreq_4M
    Pmc_MainckConfig maincfg;
    Pmc_getMainckConfig(&pmc, &maincfg);
    if (maincfg.src != Pmc_MainckSrc_XOscBypassed || maincfg.rcOscFreq != Pmc_RcOscFreq_4M)
    {
        return false;
    }

    // PLL config: Should be: pllaMul=19, pllaDiv=1
    Pmc_PllConfig pllcfg;
    Pmc_getPllConfig(&pmc, &pllcfg);
    if (pllcfg.pllaMul != 19 || pllcfg.pllaDiv != 1)
    {
        return false;
    }

    // Else we do indeed have a 100 MHz processor clock config
    return true;
}


// Address for ARM CPACR (see samrh71 <fpu.h>)
#define ADDR_CPACR 0xE000ED88

// CPACR Register: (see samrh71 <fpu.h>)
#define REG_CPACR  (*((volatile uint32_t *)ADDR_CPACR))

/*
 * Refer to header for function usage docs
 * Body of function copied from samrh71 manufacturer's distribution <fpu.h>
 */
bool fpu_is_enabled(void)
{
    return (REG_CPACR & (0xFu << 20));
}
