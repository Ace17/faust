/************************************************************************

	IMPORTANT NOTE : this file contains two clearly delimited sections :
	the ARCHITECTURE section (in two parts) and the USER section. Each section
	is governed by its own copyright and license. Please check individually
	each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
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

#include <libgen.h>
#include <stdlib.h>
#include <iostream>

#include "gui/FUI.h"
#include "misc.h"
#include "gui/faustqt.h"
#include "audio/netjack-dsp.h"

#ifdef OSCCTRL
#include "gui/OSCUI.h"
#endif

/**************************BEGIN USER SECTION **************************/

/******************************************************************************
*******************************************************************************

							       VECTOR INTRINSICS

*******************************************************************************
*******************************************************************************/

<<includeIntrinsic>>


<<includeclass>>

/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

mydsp DSP;

netjackaudio* netjack;

list<GUI*> GUI::fGuiList;

static void net_restart(void *)
{
    netjack->stop();
    if (!netjack->start()) {
        printf("restart failed...");
        exit(1);
    }
}

static void net_shutdown(void *)
{
    exit(1);
}

//-------------------------------------------------------------------------
// 									MAIN
//-------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	char	appname[256];
	char	rcfilename[256];
	char* 	home = getenv("HOME");

    int	celt = lopt(argv, "--celt", -1);
    bool restart = lopt(argv, "--restart", false);

	snprintf(appname, 255, "%s", basename(argv[0]));
	snprintf(rcfilename, 255, "%s/.%src", home, appname);

	GUI* interface = new QTGUI(argc, argv);
	FUI* finterface	= new FUI();
	DSP.buildUserInterface(interface);
	DSP.buildUserInterface(finterface);

#ifdef OSCCTRL
	GUI*	oscinterface = new OSCUI(appname, argc, argv);
	DSP.buildUserInterface(oscinterface);
#endif

	netjack = new netjackaudio(celt, (restart) ? net_restart : net_shutdown);
	if (!netjack->init(appname, &DSP)) {
        return 0;
    }
	finterface->recallState(rcfilename);
	if (!netjack->start()) {
        return 0;
    }

#ifdef OSCCTRL
	oscinterface->run();
#endif
	interface->run();

	netjack->stop();
	finterface->saveState(rcfilename);
  	return 0;
}


/********************END ARCHITECTURE SECTION (part 2/2)****************/
