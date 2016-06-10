//-----------------------------------------------------
// name: "mixer"
// version: "1.0"
// author: "Grame"
// license: "BSD"
// copyright: "(c)GRAME 2006"
//
// Code generated with Faust 0.9.70 (http://faust.grame.fr)
//-----------------------------------------------------
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  

typedef long double quad;
/* link with  */
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

class mydsp : public dsp {
  private:
	float 	fConst0;
	FAUSTFLOAT 	fslider0;
	float 	fRec2[2];
	FAUSTFLOAT 	fcheckbox0;
	float 	fRec1[2];
	FAUSTFLOAT 	fbargraph0;
	FAUSTFLOAT 	fentry0;
	FAUSTFLOAT 	fslider1;
	float 	fRec4[2];
	FAUSTFLOAT 	fcheckbox1;
	float 	fRec3[2];
	FAUSTFLOAT 	fbargraph1;
	FAUSTFLOAT 	fentry1;
	FAUSTFLOAT 	fslider2;
	float 	fRec6[2];
	FAUSTFLOAT 	fcheckbox2;
	float 	fRec5[2];
	FAUSTFLOAT 	fbargraph2;
	FAUSTFLOAT 	fentry2;
	FAUSTFLOAT 	fslider3;
	float 	fRec8[2];
	FAUSTFLOAT 	fcheckbox3;
	float 	fRec7[2];
	FAUSTFLOAT 	fbargraph3;
	FAUSTFLOAT 	fentry3;
	FAUSTFLOAT 	fslider4;
	float 	fRec10[2];
	FAUSTFLOAT 	fcheckbox4;
	float 	fRec9[2];
	FAUSTFLOAT 	fbargraph4;
	FAUSTFLOAT 	fentry4;
	FAUSTFLOAT 	fslider5;
	float 	fRec12[2];
	FAUSTFLOAT 	fcheckbox5;
	float 	fRec11[2];
	FAUSTFLOAT 	fbargraph5;
	FAUSTFLOAT 	fentry5;
	FAUSTFLOAT 	fslider6;
	float 	fRec14[2];
	FAUSTFLOAT 	fcheckbox6;
	float 	fRec13[2];
	FAUSTFLOAT 	fbargraph6;
	FAUSTFLOAT 	fentry6;
	FAUSTFLOAT 	fslider7;
	float 	fRec16[2];
	FAUSTFLOAT 	fcheckbox7;
	float 	fRec15[2];
	FAUSTFLOAT 	fbargraph7;
	FAUSTFLOAT 	fentry7;
	FAUSTFLOAT 	fslider8;
	float 	fRec17[2];
	float 	fRec0[2];
	FAUSTFLOAT 	fbargraph8;
	float 	fRec18[2];
	FAUSTFLOAT 	fbargraph9;
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "mixer");
		m->declare("version", "1.0");
		m->declare("author", "Grame");
		m->declare("license", "BSD");
		m->declare("copyright", "(c)GRAME 2006");
		m->declare("vumeter.dsp/name", "vumeter");
		m->declare("vumeter.dsp/version", "1.0");
		m->declare("vumeter.dsp/author", "Grame");
		m->declare("vumeter.dsp/license", "BSD");
		m->declare("vumeter.dsp/copyright", "(c)GRAME 2006");
		m->declare("math.lib/name", "Math Library");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/version", "1.0");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("music.lib/name", "Music Library");
		m->declare("music.lib/author", "GRAME");
		m->declare("music.lib/copyright", "GRAME");
		m->declare("music.lib/version", "1.0");
		m->declare("music.lib/license", "LGPL with exception");
		m->declare("volume.dsp/name", "volume");
		m->declare("volume.dsp/version", "1.0");
		m->declare("volume.dsp/author", "Grame");
		m->declare("volume.dsp/license", "BSD");
		m->declare("volume.dsp/copyright", "(c)GRAME 2006");
		m->declare("panpot.dsp/name", "panpot");
		m->declare("panpot.dsp/version", "1.0");
		m->declare("panpot.dsp/author", "Grame");
		m->declare("panpot.dsp/license", "BSD");
		m->declare("panpot.dsp/copyright", "(c)GRAME 2006");
	}

	virtual int getNumInputs() 	{ return 8; }
	virtual int getNumOutputs() 	{ return 2; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = (1.0f / float(min(192000, max(1, fSamplingFreq))));
		fslider0 = 0.0f;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		fcheckbox0 = 0.0;
		for (int i=0; i<2; i++) fRec1[i] = 0;
		fentry0 = 0.0f;
		fslider1 = 0.0f;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		fcheckbox1 = 0.0;
		for (int i=0; i<2; i++) fRec3[i] = 0;
		fentry1 = 0.0f;
		fslider2 = 0.0f;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		fcheckbox2 = 0.0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		fentry2 = 0.0f;
		fslider3 = 0.0f;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		fcheckbox3 = 0.0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		fentry3 = 0.0f;
		fslider4 = 0.0f;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		fcheckbox4 = 0.0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		fentry4 = 0.0f;
		fslider5 = 0.0f;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		fcheckbox5 = 0.0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		fentry5 = 0.0f;
		fslider6 = 0.0f;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		fcheckbox6 = 0.0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		fentry6 = 0.0f;
		fslider7 = 0.0f;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		fcheckbox7 = 0.0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		fentry7 = 0.0f;
		fslider8 = 0.0f;
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) fRec0[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openHorizontalBox("mixer");
		interface->openVerticalBox("Ch 0");
		interface->declare(&fentry7, "1", "");
		interface->declare(&fentry7, "style", "knob");
		interface->addNumEntry("pan", &fentry7, 0.0f, -9e+01f, 9e+01f, 1.0f);
		interface->declare(0, "2", "");
		interface->openHorizontalBox("0x00");
		interface->declare(&fslider7, "1", "");
		interface->addVerticalSlider("0x00", &fslider7, 0.0f, -7e+01f, 4.0f, 0.1f);
		interface->declare(&fbargraph7, "2", "");
		interface->declare(&fbargraph7, "unit", "dB");
		interface->addVerticalBargraph("0x3775630", &fbargraph7, -7e+01f, 5.0f);
		interface->closeBox();
		interface->addCheckButton("mute", &fcheckbox7);
		interface->closeBox();
		interface->openVerticalBox("Ch 1");
		interface->declare(&fentry6, "1", "");
		interface->declare(&fentry6, "style", "knob");
		interface->addNumEntry("pan", &fentry6, 0.0f, -9e+01f, 9e+01f, 1.0f);
		interface->declare(0, "2", "");
		interface->openHorizontalBox("0x00");
		interface->declare(&fslider6, "1", "");
		interface->addVerticalSlider("0x00", &fslider6, 0.0f, -7e+01f, 4.0f, 0.1f);
		interface->declare(&fbargraph6, "2", "");
		interface->declare(&fbargraph6, "unit", "dB");
		interface->addVerticalBargraph("0x3770510", &fbargraph6, -7e+01f, 5.0f);
		interface->closeBox();
		interface->addCheckButton("mute", &fcheckbox6);
		interface->closeBox();
		interface->openVerticalBox("Ch 2");
		interface->declare(&fentry5, "1", "");
		interface->declare(&fentry5, "style", "knob");
		interface->addNumEntry("pan", &fentry5, 0.0f, -9e+01f, 9e+01f, 1.0f);
		interface->declare(0, "2", "");
		interface->openHorizontalBox("0x00");
		interface->declare(&fslider5, "1", "");
		interface->addVerticalSlider("0x00", &fslider5, 0.0f, -7e+01f, 4.0f, 0.1f);
		interface->declare(&fbargraph5, "2", "");
		interface->declare(&fbargraph5, "unit", "dB");
		interface->addVerticalBargraph("0x376b3f0", &fbargraph5, -7e+01f, 5.0f);
		interface->closeBox();
		interface->addCheckButton("mute", &fcheckbox5);
		interface->closeBox();
		interface->openVerticalBox("Ch 3");
		interface->declare(&fentry4, "1", "");
		interface->declare(&fentry4, "style", "knob");
		interface->addNumEntry("pan", &fentry4, 0.0f, -9e+01f, 9e+01f, 1.0f);
		interface->declare(0, "2", "");
		interface->openHorizontalBox("0x00");
		interface->declare(&fslider4, "1", "");
		interface->addVerticalSlider("0x00", &fslider4, 0.0f, -7e+01f, 4.0f, 0.1f);
		interface->declare(&fbargraph4, "2", "");
		interface->declare(&fbargraph4, "unit", "dB");
		interface->addVerticalBargraph("0x3766450", &fbargraph4, -7e+01f, 5.0f);
		interface->closeBox();
		interface->addCheckButton("mute", &fcheckbox4);
		interface->closeBox();
		interface->openVerticalBox("Ch 4");
		interface->declare(&fentry3, "1", "");
		interface->declare(&fentry3, "style", "knob");
		interface->addNumEntry("pan", &fentry3, 0.0f, -9e+01f, 9e+01f, 1.0f);
		interface->declare(0, "2", "");
		interface->openHorizontalBox("0x00");
		interface->declare(&fslider3, "1", "");
		interface->addVerticalSlider("0x00", &fslider3, 0.0f, -7e+01f, 4.0f, 0.1f);
		interface->declare(&fbargraph3, "2", "");
		interface->declare(&fbargraph3, "unit", "dB");
		interface->addVerticalBargraph("0x3761390", &fbargraph3, -7e+01f, 5.0f);
		interface->closeBox();
		interface->addCheckButton("mute", &fcheckbox3);
		interface->closeBox();
		interface->openVerticalBox("Ch 5");
		interface->declare(&fentry2, "1", "");
		interface->declare(&fentry2, "style", "knob");
		interface->addNumEntry("pan", &fentry2, 0.0f, -9e+01f, 9e+01f, 1.0f);
		interface->declare(0, "2", "");
		interface->openHorizontalBox("0x00");
		interface->declare(&fslider2, "1", "");
		interface->addVerticalSlider("0x00", &fslider2, 0.0f, -7e+01f, 4.0f, 0.1f);
		interface->declare(&fbargraph2, "2", "");
		interface->declare(&fbargraph2, "unit", "dB");
		interface->addVerticalBargraph("0x375c300", &fbargraph2, -7e+01f, 5.0f);
		interface->closeBox();
		interface->addCheckButton("mute", &fcheckbox2);
		interface->closeBox();
		interface->openVerticalBox("Ch 6");
		interface->declare(&fentry1, "1", "");
		interface->declare(&fentry1, "style", "knob");
		interface->addNumEntry("pan", &fentry1, 0.0f, -9e+01f, 9e+01f, 1.0f);
		interface->declare(0, "2", "");
		interface->openHorizontalBox("0x00");
		interface->declare(&fslider1, "1", "");
		interface->addVerticalSlider("0x00", &fslider1, 0.0f, -7e+01f, 4.0f, 0.1f);
		interface->declare(&fbargraph1, "2", "");
		interface->declare(&fbargraph1, "unit", "dB");
		interface->addVerticalBargraph("0x3756fc0", &fbargraph1, -7e+01f, 5.0f);
		interface->closeBox();
		interface->addCheckButton("mute", &fcheckbox1);
		interface->closeBox();
		interface->openVerticalBox("Ch 7");
		interface->declare(&fentry0, "1", "");
		interface->declare(&fentry0, "style", "knob");
		interface->addNumEntry("pan", &fentry0, 0.0f, -9e+01f, 9e+01f, 1.0f);
		interface->declare(0, "2", "");
		interface->openHorizontalBox("0x00");
		interface->declare(&fslider0, "1", "");
		interface->addVerticalSlider("0x00", &fslider0, 0.0f, -7e+01f, 4.0f, 0.1f);
		interface->declare(&fbargraph0, "2", "");
		interface->declare(&fbargraph0, "unit", "dB");
		interface->addVerticalBargraph("0x3751a40", &fbargraph0, -7e+01f, 5.0f);
		interface->closeBox();
		interface->addCheckButton("mute", &fcheckbox0);
		interface->closeBox();
		interface->openHorizontalBox("stereo out");
		interface->openVerticalBox("L");
		interface->declare(&fbargraph8, "2", "");
		interface->declare(&fbargraph8, "unit", "dB");
		interface->addVerticalBargraph("0x377a170", &fbargraph8, -7e+01f, 5.0f);
		interface->closeBox();
		interface->openVerticalBox("R");
		interface->declare(&fbargraph9, "2", "");
		interface->declare(&fbargraph9, "unit", "dB");
		interface->addVerticalBargraph("0x377edf0", &fbargraph9, -7e+01f, 5.0f);
		interface->closeBox();
		interface->declare(&fslider8, "1", "");
		interface->addVerticalSlider("0x00", &fslider8, 0.0f, -7e+01f, 4.0f, 0.1f);
		interface->closeBox();
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (0.0010000000000000009f * powf(10,(0.05f * float(fslider0))));
		float 	fSlow1 = (1 - float(fcheckbox0));
		float 	fSlow2 = (0.005555555555555556f * (float(fentry0) - 9e+01f));
		float 	fSlow3 = sqrtf((0 - fSlow2));
		float 	fSlow4 = (0.0010000000000000009f * powf(10,(0.05f * float(fslider1))));
		float 	fSlow5 = (1 - float(fcheckbox1));
		float 	fSlow6 = (0.005555555555555556f * (float(fentry1) - 9e+01f));
		float 	fSlow7 = sqrtf((0 - fSlow6));
		float 	fSlow8 = (0.0010000000000000009f * powf(10,(0.05f * float(fslider2))));
		float 	fSlow9 = (1 - float(fcheckbox2));
		float 	fSlow10 = (0.005555555555555556f * (float(fentry2) - 9e+01f));
		float 	fSlow11 = sqrtf((0 - fSlow10));
		float 	fSlow12 = (0.0010000000000000009f * powf(10,(0.05f * float(fslider3))));
		float 	fSlow13 = (1 - float(fcheckbox3));
		float 	fSlow14 = (0.005555555555555556f * (float(fentry3) - 9e+01f));
		float 	fSlow15 = sqrtf((0 - fSlow14));
		float 	fSlow16 = (0.0010000000000000009f * powf(10,(0.05f * float(fslider4))));
		float 	fSlow17 = (1 - float(fcheckbox4));
		float 	fSlow18 = (0.005555555555555556f * (float(fentry4) - 9e+01f));
		float 	fSlow19 = sqrtf((0 - fSlow18));
		float 	fSlow20 = (0.0010000000000000009f * powf(10,(0.05f * float(fslider5))));
		float 	fSlow21 = (1 - float(fcheckbox5));
		float 	fSlow22 = (0.005555555555555556f * (float(fentry5) - 9e+01f));
		float 	fSlow23 = sqrtf((0 - fSlow22));
		float 	fSlow24 = (0.0010000000000000009f * powf(10,(0.05f * float(fslider6))));
		float 	fSlow25 = (1 - float(fcheckbox6));
		float 	fSlow26 = (0.005555555555555556f * (float(fentry6) - 9e+01f));
		float 	fSlow27 = sqrtf((0 - fSlow26));
		float 	fSlow28 = (0.0010000000000000009f * powf(10,(0.05f * float(fslider7))));
		float 	fSlow29 = (1 - float(fcheckbox7));
		float 	fSlow30 = (0.005555555555555556f * (float(fentry7) - 9e+01f));
		float 	fSlow31 = sqrtf((0 - fSlow30));
		float 	fSlow32 = (0.0010000000000000009f * powf(10,(0.05f * float(fslider8))));
		float 	fSlow33 = sqrtf((1 + fSlow2));
		float 	fSlow34 = sqrtf((1 + fSlow6));
		float 	fSlow35 = sqrtf((1 + fSlow10));
		float 	fSlow36 = sqrtf((1 + fSlow14));
		float 	fSlow37 = sqrtf((1 + fSlow18));
		float 	fSlow38 = sqrtf((1 + fSlow22));
		float 	fSlow39 = sqrtf((1 + fSlow26));
		float 	fSlow40 = sqrtf((1 + fSlow30));
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* input1 = input[1];
		FAUSTFLOAT* input2 = input[2];
		FAUSTFLOAT* input3 = input[3];
		FAUSTFLOAT* input4 = input[4];
		FAUSTFLOAT* input5 = input[5];
		FAUSTFLOAT* input6 = input[6];
		FAUSTFLOAT* input7 = input[7];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			fRec2[0] = ((0.999f * fRec2[1]) + fSlow0);
			float fTemp0 = (fSlow1 * ((float)input7[i] * fRec2[0]));
			fRec1[0] = max((fRec1[1] - fConst0), fabsf(fTemp0));
			fbargraph0 = (20 * log10f(max(0.00031622776601683794f, fRec1[0])));
			float fTemp1 = fTemp0;
			fRec4[0] = ((0.999f * fRec4[1]) + fSlow4);
			float fTemp2 = (fSlow5 * ((float)input6[i] * fRec4[0]));
			fRec3[0] = max((fRec3[1] - fConst0), fabsf(fTemp2));
			fbargraph1 = (20 * log10f(max(0.00031622776601683794f, fRec3[0])));
			float fTemp3 = fTemp2;
			fRec6[0] = ((0.999f * fRec6[1]) + fSlow8);
			float fTemp4 = (fSlow9 * ((float)input5[i] * fRec6[0]));
			fRec5[0] = max((fRec5[1] - fConst0), fabsf(fTemp4));
			fbargraph2 = (20 * log10f(max(0.00031622776601683794f, fRec5[0])));
			float fTemp5 = fTemp4;
			fRec8[0] = ((0.999f * fRec8[1]) + fSlow12);
			float fTemp6 = (fSlow13 * ((float)input4[i] * fRec8[0]));
			fRec7[0] = max((fRec7[1] - fConst0), fabsf(fTemp6));
			fbargraph3 = (20 * log10f(max(0.00031622776601683794f, fRec7[0])));
			float fTemp7 = fTemp6;
			fRec10[0] = ((0.999f * fRec10[1]) + fSlow16);
			float fTemp8 = (fSlow17 * ((float)input3[i] * fRec10[0]));
			fRec9[0] = max((fRec9[1] - fConst0), fabsf(fTemp8));
			fbargraph4 = (20 * log10f(max(0.00031622776601683794f, fRec9[0])));
			float fTemp9 = fTemp8;
			fRec12[0] = ((0.999f * fRec12[1]) + fSlow20);
			float fTemp10 = (fSlow21 * ((float)input2[i] * fRec12[0]));
			fRec11[0] = max((fRec11[1] - fConst0), fabsf(fTemp10));
			fbargraph5 = (20 * log10f(max(0.00031622776601683794f, fRec11[0])));
			float fTemp11 = fTemp10;
			fRec14[0] = ((0.999f * fRec14[1]) + fSlow24);
			float fTemp12 = (fSlow25 * ((float)input1[i] * fRec14[0]));
			fRec13[0] = max((fRec13[1] - fConst0), fabsf(fTemp12));
			fbargraph6 = (20 * log10f(max(0.00031622776601683794f, fRec13[0])));
			float fTemp13 = fTemp12;
			fRec16[0] = ((0.999f * fRec16[1]) + fSlow28);
			float fTemp14 = (fSlow29 * ((float)input0[i] * fRec16[0]));
			fRec15[0] = max((fRec15[1] - fConst0), fabsf(fTemp14));
			fbargraph7 = (20 * log10f(max(0.00031622776601683794f, fRec15[0])));
			float fTemp15 = fTemp14;
			fRec17[0] = ((0.999f * fRec17[1]) + fSlow32);
			float fTemp16 = (fRec17[0] * ((((((((fSlow31 * fTemp15) + (fSlow27 * fTemp13)) + (fSlow23 * fTemp11)) + (fSlow19 * fTemp9)) + (fSlow15 * fTemp7)) + (fSlow11 * fTemp5)) + (fSlow7 * fTemp3)) + (fSlow3 * fTemp1)));
			fRec0[0] = max((fRec0[1] - fConst0), fabsf(fTemp16));
			fbargraph8 = (20 * log10f(max(0.00031622776601683794f, fRec0[0])));
			output0[i] = (FAUSTFLOAT)fTemp16;
			float fTemp17 = (fRec17[0] * ((((((((fSlow40 * fTemp15) + (fSlow39 * fTemp13)) + (fSlow38 * fTemp11)) + (fSlow37 * fTemp9)) + (fSlow36 * fTemp7)) + (fSlow35 * fTemp5)) + (fSlow34 * fTemp3)) + (fSlow33 * fTemp1)));
			fRec18[0] = max((fRec18[1] - fConst0), fabsf(fTemp17));
			fbargraph9 = (20 * log10f(max(0.00031622776601683794f, fRec18[0])));
			output1[i] = (FAUSTFLOAT)fTemp17;
			// post processing
			fRec18[1] = fRec18[0];
			fRec0[1] = fRec0[0];
			fRec17[1] = fRec17[0];
			fRec15[1] = fRec15[0];
			fRec16[1] = fRec16[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
		}
	}
};


