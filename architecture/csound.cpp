/************************************************************************
 
 IMPORTANT NOTE : this file contains two clearly delimited sections : 
 the ARCHITECTURE section (in two parts) and the USER section. Each section 
 is governed by its own copyright and license. Please check individually 
 each section for license and copyright information.
 *************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2010-2011 V. Lazzarini and GRAME
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it 
 and/or modify it under the terms of the GNU General Public License 
 as published by the Free Software Foundation; either version 3 of 
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License 
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work 
 that contains this FAUST architecture section and distribute  
 that work under terms of your choice, so long as this FAUST 
 architecture section is not modified. 
 
 
 ************************************************************************
 ************************************************************************/

//==============================================================================
//
//          CSOUND6 architecture file for FAUST
//          Y. Orlarey & V. Lazzarini
//          
//          Usage : faust -uim -a csound.cpp <myfx>.dsp -o <myfx>.cpp
//                  g++ -O3 -DOPCODE_NAME=<myfx> -c <myfx>.cpp -o <myfx>.o
//                  ld -E --shared <myfx>.o -o <myfx>.so
//
//          History :
//          - 28/04/09 : first version
//          - 29/04/09 : dynamic allocation
//          - 10/07/14 : updated to csound6 (Paul Batchelor)
//
//==============================================================================

#include <new>
#include <vector>
#include "csdl.h"                       /* CSOUND plugin API header */

// used to transform a symbol in a string
#define sym(name) xsym(name)
#define xsym(name) #name

// make sure we use csound floats
#define FAUSTFLOAT MYFLT

// we require macro declarations
#define FAUST_UIMACROS

// but we will ignore most of them 
#define FAUST_ADDBUTTON(l,f)
#define FAUST_ADDCHECKBOX(l,f)
#define FAUST_ADDVERTICALSLIDER(l,f,i,a,b,s)
#define FAUST_ADDHORIZONTALSLIDER(l,f,i,a,b,s)
#define FAUST_ADDNUMENTRY(l,f,i,a,b,s)
#define FAUST_ADDVERTICALBARGRAPH(l,f,a,b)
#define FAUST_ADDHORIZONTALBARGRAPH(l,f,a,b)

#include "faust/misc.h"
#include "faust/audio/dsp.h"
#include "faust/gui/meta.h"
#include "faust/gui/UI.h"

/******************************************************************************
 *******************************************************************************
 
 VECTOR INTRINSICS
 
 *******************************************************************************
 *******************************************************************************/

<<includeIntrinsic>>

/**
 * A UI that simply collects the active zones in a vector
 * and provides a method to copy the csound controls
 */
class CSUI : public UI
{
    std::vector<FAUSTFLOAT*>  vZone;
    
public:
    
    // -- widget's layouts
    
    virtual void openTabBox(const char* label)                                                          {}
    virtual void openHorizontalBox(const char* label)                                                   {}
    virtual void openVerticalBox(const char* label)                                                     {}
    virtual void closeBox()                                                                             {}
    
    // -- active widgets
    
    virtual void addButton(const char* label, FAUSTFLOAT* zone)                                                          { vZone.push_back(zone); }
    virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)                                                     { vZone.push_back(zone); }
    virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)    { vZone.push_back(zone); }
    virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)  { vZone.push_back(zone); }
    virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)          { vZone.push_back(zone); }
    
    // -- passive widgets
    
    virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)            {}
    virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)              {}
    
    void copyfrom(MYFLT* mem[]) {
        for (unsigned int i=0; i<vZone.size(); i++) { *vZone[i] = *(mem[i]); }
    }
    
    int size()                  { return vZone.size(); }
};

/********************END ARCHITECTURE SECTION (part 1/2)****************/

/**************************BEGIN USER SECTION **************************/

<<includeclass>>

/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

struct dataspace {
    OPDS      h;                          /* basic attributes */
    MYFLT*    aout[FAUST_OUTPUTS];        /* output buffers   */
    MYFLT*    ain[FAUST_INPUTS];          /* input buffers    */
    MYFLT*    ktl[FAUST_ACTIVES];         /* controls         */
    dsp*      DSP;                        /* the Faust generated object */
    CSUI*     interface;                  /* do the mapping between CSound controls and DSP fields */
    AUXCH     dspmem;                     /* aux memory allocated once to store the DSP object */
    AUXCH     intmem;                     /* aux memory allocated once to store the interface object */
};

/**
 * Creates a "aaakkkk" CSound description string. Note that
 * these string will never be released. Potential memory leak
 */
static char* makeDescription(int numa, int numk=0)
{
    char* str = (char*)malloc(numa+numk+1); // NEED TO BE CHANGED ?
    if (str) {
        for (int i=0; i<numa; i++) str[i] = 'a';
        for (int i=0; i<numk; i++) str[numa+i] = 'k';
        str[numa+numk] = 0;
    }
    return str;
}

/**
 * CSOUND callback that allocates and initializes
 * the FAUST generated DSP object and it's CSound interface
 */
static int init(CSOUND *csound, dataspace *p)
{
    if (p->dspmem.auxp == NULL)
        csound->AuxAlloc(csound, sizeof(mydsp), &p->dspmem);
    
    if(p->intmem.auxp == NULL)
        csound->AuxAlloc(csound, sizeof(CSUI), &p->intmem);
    
    p->DSP = new (p->dspmem.auxp) mydsp;
    p->interface = new (p->intmem.auxp) CSUI;
    
    if ((p->DSP == 0) | (p->interface == 0)) return NOTOK;
    
    p->DSP->init((int)csound->GetSr(csound));   
    p->DSP->buildUserInterface(p->interface);
    
    return OK;
}

/**
 * CSound callback that process the samples by updating
 * the controls values and calling the compute() method
 * of the DSP object. (Assume MYFLT = FAUSTFLOAT)
 */
static int process32bits(CSOUND *csound, dataspace *p)
{
    AVOIDDENORMALS;
    
    // update all the control values
    p->interface->copyfrom(p->ktl);
    
    p->DSP->compute(csound->GetKsmps(csound), p->ain, p->aout);
    return OK;
}

extern "C" {
    static OENTRY localops[] = {
        {(char*)sym(OPCODE_NAME), sizeof(dataspace), 0, 7, makeDescription(FAUST_OUTPUTS), makeDescription(FAUST_INPUTS, FAUST_ACTIVES),
            (SUBR)init, NULL, (SUBR)process32bits }
    };
    LINKAGE
}


/********************END ARCHITECTURE SECTION (part 2/2)****************/



