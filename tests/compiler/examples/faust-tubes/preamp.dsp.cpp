//-----------------------------------------------------
// name: "Tube Preamp"
// version: "0.28"
// author: "Guitarix project"
//
// Code generated with Faust 0.9.70 (http://faust.grame.fr)
//-----------------------------------------------------
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  

typedef long double quad;
/* link with : "" */
#include "valve.h"
#include <math.h>
#ifndef FAUSTPOWER
#define FAUSTPOWER
#include <cmath>
template <int N> inline float faustpower(float x)          { return powf(x,N); } 
template <int N> inline double faustpower(double x)        { return pow(x,N); }
template <int N> inline int faustpower(int x)              { return faustpower<N/2>(x) * faustpower<N-N/2>(x); } 
template <>   inline int faustpower<0>(int x)            { return 1; }
template <>   inline int faustpower<1>(int x)            { return x; }
#endif

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

class mydsp : public dsp {
  private:
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT 	fslider1;
	int 	iConst0;
	float 	fConst1;
	float 	fConst2;
	float 	fConst3;
	FAUSTFLOAT 	fslider2;
	float 	fRec1[2];
	FAUSTFLOAT 	fslider3;
	float 	fRec8[2];
	float 	fConst4;
	float 	fConst5;
	float 	fConst6;
	float 	fConst7;
	float 	fRec11[2];
	float 	fRec10[3];
	float 	fConst8;
	float 	fConst9;
	float 	fConst10;
	float 	fConst11;
	float 	fConst12;
	float 	fRec9[2];
	float 	fVec0[2];
	float 	fConst13;
	float 	fConst14;
	float 	fConst15;
	float 	fConst16;
	float 	fRec7[2];
	float 	fConst17;
	float 	fConst18;
	float 	fConst19;
	float 	fConst20;
	float 	fRec12[2];
	float 	fRec6[3];
	float 	fRec5[2];
	float 	fVec1[2];
	float 	fRec4[2];
	float 	fConst21;
	float 	fConst22;
	float 	fConst23;
	float 	fConst24;
	float 	fRec13[2];
	float 	fRec3[3];
	float 	fRec2[2];
	float 	fRec0[4];
	FAUSTFLOAT 	fslider4;
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "Tube Preamp");
		m->declare("version", "0.28");
		m->declare("author", "Guitarix project");
		m->declare("tonestack.lib/name", "Tonestack Emulation Library");
		m->declare("tonestack.lib/author", "Guitarix project (http://guitarix.sourceforge.net/)");
		m->declare("tonestack.lib/copyright", "Guitarix project");
		m->declare("tonestack.lib/version", "0.28");
		m->declare("tonestack.lib/license", "LGPL");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("filter.lib/copyright", "Julius O. Smith III");
		m->declare("filter.lib/version", "1.29");
		m->declare("filter.lib/license", "STK-4.3");
		m->declare("filter.lib/reference", "https://ccrma.stanford.edu/~jos/filters/");
		m->declare("music.lib/name", "Music Library");
		m->declare("music.lib/author", "GRAME");
		m->declare("music.lib/copyright", "GRAME");
		m->declare("music.lib/version", "1.0");
		m->declare("music.lib/license", "LGPL with exception");
		m->declare("math.lib/name", "Math Library");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/version", "1.0");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("tube.lib/name", "Tube Emulation Library");
		m->declare("tube.lib/author", "Guitarix project (http://guitarix.sourceforge.net/)");
		m->declare("tube.lib/copyright", "Guitarix project");
		m->declare("tube.lib/version", "0.28");
		m->declare("tube.lib/license", "LGPL");
	}

	virtual int getNumInputs() 	{ return 1; }
	virtual int getNumOutputs() 	{ return 1; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fslider0 = 0.5f;
		fslider1 = 0.5f;
		iConst0 = min(192000, max(1, fSamplingFreq));
		fConst1 = (2 * float(iConst0));
		fConst2 = faustpower<2>(fConst1);
		fConst3 = (3 * fConst1);
		fslider2 = -6.0f;
		for (int i=0; i<2; i++) fRec1[i] = 0;
		fslider3 = -6.0f;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		fConst4 = (1.0f / tanf((270.1769682087222f / float(iConst0))));
		fConst5 = (1 + fConst4);
		fConst6 = (0.027f / fConst5);
		fConst7 = (0 - ((1 - fConst4) / fConst5));
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<3; i++) fRec10[i] = 0;
		fConst8 = (1.0f / tanf((97.38937226128358f / float(iConst0))));
		fConst9 = (0 - fConst8);
		fConst10 = (1 + fConst8);
		fConst11 = (0.025f / fConst10);
		fConst12 = (0 - ((1 - fConst8) / fConst10));
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<2; i++) fVec0[i] = 0;
		fConst13 = (1.0f / tanf((20517.741620594938f / float(iConst0))));
		fConst14 = (1 + fConst13);
		fConst15 = (1.0f / fConst14);
		fConst16 = (0 - ((1 - fConst13) / fConst14));
		for (int i=0; i<2; i++) fRec7[i] = 0;
		fConst17 = (1.0f / tanf((414.6902302738527f / float(iConst0))));
		fConst18 = (1 + fConst17);
		fConst19 = (0.015f / fConst18);
		fConst20 = (0 - ((1 - fConst17) / fConst18));
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<3; i++) fRec6[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		fConst21 = (1.0f / tanf((609.4689747964198f / float(iConst0))));
		fConst22 = (1 + fConst21);
		fConst23 = (0.0082f / fConst22);
		fConst24 = (0 - ((1 - fConst21) / fConst22));
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<3; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		for (int i=0; i<4; i++) fRec0[i] = 0;
		fslider4 = 0.5f;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openHorizontalBox("preamp: 12AX7");
		interface->declare(&fslider3, "0", "");
		interface->declare(&fslider3, "style", "knob");
		interface->addVerticalSlider("Pregain", &fslider3, -6.0f, -2e+01f, 2e+01f, 0.1f);
		interface->declare(&fslider2, "1", "");
		interface->declare(&fslider2, "style", "knob");
		interface->addVerticalSlider("Gain", &fslider2, -6.0f, -2e+01f, 2e+01f, 0.1f);
		interface->openHorizontalBox("tonestack: jcm2000");
		interface->declare(&fslider4, "2", "");
		interface->declare(&fslider4, "style", "knob");
		interface->addVerticalSlider("Treble", &fslider4, 0.5f, 0.0f, 1.0f, 0.01f);
		interface->declare(&fslider1, "3", "");
		interface->declare(&fslider1, "style", "knob");
		interface->addVerticalSlider("Middle", &fslider1, 0.5f, 0.0f, 1.0f, 0.01f);
		interface->declare(&fslider0, "4", "");
		interface->declare(&fslider0, "style", "knob");
		interface->addVerticalSlider("Bass", &fslider0, 0.5f, 0.0f, 1.0f, 0.01f);
		interface->closeBox();
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = expf((3.4f * (float(fslider0) - 1)));
		float 	fSlow1 = float(fslider1);
		float 	fSlow2 = (3.0937500000000006e-07f * fSlow1);
		float 	fSlow3 = (((fSlow1 * (((1.2375000000000003e-05f * fSlow0) - 2.99475e-07f) - fSlow2)) + (3.108600000000001e-05f * fSlow0)) + 1.08515e-06f);
		float 	fSlow4 = (3.3880000000000003e-09f * fSlow0);
		float 	fSlow5 = ((1.8513000000000002e-09f * fSlow0) - (4.628250000000001e-11f * fSlow1));
		float 	fSlow6 = (8.470000000000002e-11f + ((fSlow1 * (fSlow5 - 3.8417500000000006e-11f)) + fSlow4));
		float 	fSlow7 = (fConst1 * fSlow6);
		float 	fSlow8 = (0.022500000000000003f * fSlow0);
		float 	fSlow9 = (0.00055f * fSlow1);
		float 	fSlow10 = (fConst1 * (0.0031515000000000002f + (fSlow9 + fSlow8)));
		float 	fSlow11 = ((fSlow10 + (fConst2 * (fSlow7 - fSlow3))) - 1);
		float 	fSlow12 = (fConst3 * fSlow6);
		float 	fSlow13 = ((fSlow10 + (fConst2 * (fSlow3 - fSlow12))) - 3);
		float 	fSlow14 = ((fConst2 * (fSlow3 + fSlow12)) - (3 + fSlow10));
		float 	fSlow15 = (1.0f / (0 - (1 + (fSlow10 + (fConst2 * (fSlow3 + fSlow7))))));
		float 	fSlow16 = (0.0010000000000000009f * powf(10,(0.05f * float(fslider2))));
		float 	fSlow17 = (0.0010000000000000009f * powf(10,(0.05f * float(fslider3))));
		float 	fSlow18 = float(fslider4);
		float 	fSlow19 = ((((3.08e-07f * fSlow18) + (fSlow1 * (3.781250000000001e-07f - fSlow2))) + (fSlow0 * (3.982e-06f + (1.2375000000000003e-05f * fSlow1)))) + 9.955000000000001e-08f);
		float 	fSlow20 = ((fSlow1 * (4.628250000000001e-11f + fSlow5)) + (fSlow18 * (fSlow4 + (8.470000000000002e-11f - (8.470000000000002e-11f * fSlow1)))));
		float 	fSlow21 = (fConst1 * fSlow20);
		float 	fSlow22 = ((fSlow8 + (fSlow9 + (0.000125f * fSlow18))) + 0.0005625000000000001f);
		float 	fSlow23 = (fConst1 * fSlow22);
		float 	fSlow24 = (fSlow23 + (fConst2 * (fSlow21 - fSlow19)));
		float 	fSlow25 = (fConst3 * fSlow20);
		float 	fSlow26 = (fSlow23 + (fConst2 * (fSlow19 - fSlow25)));
		float 	fSlow27 = (fConst1 * (0 - fSlow22));
		float 	fSlow28 = (fSlow27 + (fConst2 * (fSlow19 + fSlow25)));
		float 	fSlow29 = (fSlow27 - (fConst2 * (fSlow19 + fSlow21)));
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* output0 = output[0];
		for (int i=0; i<count; i++) {
			fRec1[0] = ((0.999f * fRec1[1]) + fSlow16);
			fRec8[0] = ((0.999f * fRec8[1]) + fSlow17);
			fRec11[0] = ((fConst7 * fRec11[1]) + (fConst6 * (fRec10[1] + fRec10[2])));
			fRec10[0] = (Ftube(TUBE_TABLE_12AX7_68k, (((float)input0[i] + fRec11[0]) - 1.581656f)) - 191.42014814814814f);
			fRec9[0] = ((fConst12 * fRec9[1]) + (fConst11 * ((fConst8 * fRec10[0]) + (fConst9 * fRec10[1]))));
			float fTemp0 = (fRec9[0] * fRec8[0]);
			fVec0[0] = fTemp0;
			fRec7[0] = ((fConst16 * fRec7[1]) + (fConst15 * (fVec0[0] + fVec0[1])));
			fRec12[0] = ((fConst20 * fRec12[1]) + (fConst19 * (fRec6[1] + fRec6[2])));
			fRec6[0] = (Ftube(TUBE_TABLE_12AX7_250k, ((fRec12[0] + fRec7[0]) - 1.204285f)) - 169.71433333333334f);
			fRec5[0] = ((fConst12 * fRec5[1]) + (fConst11 * ((fConst8 * fRec6[0]) + (fConst9 * fRec6[1]))));
			float fTemp1 = (fRec8[0] * fRec5[0]);
			fVec1[0] = fTemp1;
			fRec4[0] = ((fConst16 * fRec4[1]) + (fConst15 * (fVec1[0] + fVec1[1])));
			fRec13[0] = ((fConst24 * fRec13[1]) + (fConst23 * (fRec3[1] + fRec3[2])));
			fRec3[0] = (Ftube(TUBE_TABLE_12AX7_250k, ((fRec13[0] + fRec4[0]) - 0.840703f)) - 147.47524390243905f);
			fRec2[0] = ((fConst12 * fRec2[1]) + (fConst11 * ((fConst8 * fRec3[0]) + (fConst9 * fRec3[1]))));
			fRec0[0] = ((fRec2[0] * fRec1[0]) - (fSlow15 * (((fSlow14 * fRec0[1]) + (fSlow13 * fRec0[2])) + (fSlow11 * fRec0[3]))));
			output0[i] = (FAUSTFLOAT)(fSlow15 * ((((fSlow29 * fRec0[0]) + (fSlow28 * fRec0[1])) + (fSlow26 * fRec0[2])) + (fSlow24 * fRec0[3])));
			// post processing
			for (int i=3; i>0; i--) fRec0[i] = fRec0[i-1];
			fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
			fRec13[1] = fRec13[0];
			fRec4[1] = fRec4[0];
			fVec1[1] = fVec1[0];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1]; fRec6[1] = fRec6[0];
			fRec12[1] = fRec12[0];
			fRec7[1] = fRec7[0];
			fVec0[1] = fVec0[0];
			fRec9[1] = fRec9[0];
			fRec10[2] = fRec10[1]; fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec8[1] = fRec8[0];
			fRec1[1] = fRec1[0];
		}
	}
};


