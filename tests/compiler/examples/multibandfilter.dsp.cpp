//-----------------------------------------------------
// name: "multibandfilter"
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
	FAUSTFLOAT 	fentry0;
	float 	fConst0;
	FAUSTFLOAT 	fentry1;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT 	fentry2;
	FAUSTFLOAT 	fentry3;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT 	fentry4;
	FAUSTFLOAT 	fentry5;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT 	fentry6;
	FAUSTFLOAT 	fentry7;
	FAUSTFLOAT 	fslider3;
	FAUSTFLOAT 	fentry8;
	FAUSTFLOAT 	fentry9;
	FAUSTFLOAT 	fslider4;
	FAUSTFLOAT 	fentry10;
	FAUSTFLOAT 	fentry11;
	FAUSTFLOAT 	fslider5;
	FAUSTFLOAT 	fentry12;
	FAUSTFLOAT 	fentry13;
	FAUSTFLOAT 	fslider6;
	FAUSTFLOAT 	fentry14;
	FAUSTFLOAT 	fentry15;
	FAUSTFLOAT 	fslider7;
	FAUSTFLOAT 	fentry16;
	FAUSTFLOAT 	fentry17;
	FAUSTFLOAT 	fslider8;
	FAUSTFLOAT 	fentry18;
	FAUSTFLOAT 	fentry19;
	FAUSTFLOAT 	fslider9;
	float 	fRec9[3];
	float 	fRec8[3];
	float 	fRec7[3];
	float 	fRec6[3];
	float 	fRec5[3];
	float 	fRec4[3];
	float 	fRec3[3];
	float 	fRec2[3];
	float 	fRec1[3];
	float 	fRec0[3];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "multibandfilter");
		m->declare("version", "1.0");
		m->declare("author", "Grame");
		m->declare("license", "BSD");
		m->declare("copyright", "(c)GRAME 2006");
		m->declare("bandfilter.dsp/name", "bandfilter");
		m->declare("bandfilter.dsp/version", "1.0");
		m->declare("bandfilter.dsp/author", "Grame");
		m->declare("bandfilter.dsp/license", "BSD");
		m->declare("bandfilter.dsp/copyright", "(c)GRAME 2006");
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
	}

	virtual int getNumInputs() 	{ return 1; }
	virtual int getNumOutputs() 	{ return 1; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fentry0 = 1e+04f;
		fConst0 = (3.141592653589793f / float(min(192000, max(1, fSamplingFreq))));
		fentry1 = 5e+01f;
		fslider0 = 0.0f;
		fentry2 = 9e+03f;
		fentry3 = 5e+01f;
		fslider1 = 0.0f;
		fentry4 = 8e+03f;
		fentry5 = 5e+01f;
		fslider2 = 0.0f;
		fentry6 = 7e+03f;
		fentry7 = 5e+01f;
		fslider3 = 0.0f;
		fentry8 = 6e+03f;
		fentry9 = 5e+01f;
		fslider4 = 0.0f;
		fentry10 = 5e+03f;
		fentry11 = 5e+01f;
		fslider5 = 0.0f;
		fentry12 = 4e+03f;
		fentry13 = 5e+01f;
		fslider6 = 0.0f;
		fentry14 = 3e+03f;
		fentry15 = 5e+01f;
		fslider7 = 0.0f;
		fentry16 = 2e+03f;
		fentry17 = 5e+01f;
		fslider8 = 0.0f;
		fentry18 = 1e+03f;
		fentry19 = 5e+01f;
		fslider9 = 0.0f;
		for (int i=0; i<3; i++) fRec9[i] = 0;
		for (int i=0; i<3; i++) fRec8[i] = 0;
		for (int i=0; i<3; i++) fRec7[i] = 0;
		for (int i=0; i<3; i++) fRec6[i] = 0;
		for (int i=0; i<3; i++) fRec5[i] = 0;
		for (int i=0; i<3; i++) fRec4[i] = 0;
		for (int i=0; i<3; i++) fRec3[i] = 0;
		for (int i=0; i<3; i++) fRec2[i] = 0;
		for (int i=0; i<3; i++) fRec1[i] = 0;
		for (int i=0; i<3; i++) fRec0[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openHorizontalBox("Multi Band Filter");
		interface->openVerticalBox("peak 0");
		interface->declare(&fentry19, "style", "knob");
		interface->addNumEntry("Q factor", &fentry19, 5e+01f, 0.1f, 1e+02f, 0.1f);
		interface->declare(&fentry18, "style", "knob");
		interface->declare(&fentry18, "unit", "Hz");
		interface->addNumEntry("freq", &fentry18, 1e+03f, 2e+01f, 2e+04f, 1.0f);
		interface->declare(&fslider9, "unit", "dB");
		interface->addVerticalSlider("gain", &fslider9, 0.0f, -5e+01f, 5e+01f, 0.1f);
		interface->closeBox();
		interface->openVerticalBox("peak 1");
		interface->declare(&fentry17, "style", "knob");
		interface->addNumEntry("Q factor", &fentry17, 5e+01f, 0.1f, 1e+02f, 0.1f);
		interface->declare(&fentry16, "style", "knob");
		interface->declare(&fentry16, "unit", "Hz");
		interface->addNumEntry("freq", &fentry16, 2e+03f, 2e+01f, 2e+04f, 1.0f);
		interface->declare(&fslider8, "unit", "dB");
		interface->addVerticalSlider("gain", &fslider8, 0.0f, -5e+01f, 5e+01f, 0.1f);
		interface->closeBox();
		interface->openVerticalBox("peak 2");
		interface->declare(&fentry15, "style", "knob");
		interface->addNumEntry("Q factor", &fentry15, 5e+01f, 0.1f, 1e+02f, 0.1f);
		interface->declare(&fentry14, "style", "knob");
		interface->declare(&fentry14, "unit", "Hz");
		interface->addNumEntry("freq", &fentry14, 3e+03f, 2e+01f, 2e+04f, 1.0f);
		interface->declare(&fslider7, "unit", "dB");
		interface->addVerticalSlider("gain", &fslider7, 0.0f, -5e+01f, 5e+01f, 0.1f);
		interface->closeBox();
		interface->openVerticalBox("peak 3");
		interface->declare(&fentry13, "style", "knob");
		interface->addNumEntry("Q factor", &fentry13, 5e+01f, 0.1f, 1e+02f, 0.1f);
		interface->declare(&fentry12, "style", "knob");
		interface->declare(&fentry12, "unit", "Hz");
		interface->addNumEntry("freq", &fentry12, 4e+03f, 2e+01f, 2e+04f, 1.0f);
		interface->declare(&fslider6, "unit", "dB");
		interface->addVerticalSlider("gain", &fslider6, 0.0f, -5e+01f, 5e+01f, 0.1f);
		interface->closeBox();
		interface->openVerticalBox("peak 4");
		interface->declare(&fentry11, "style", "knob");
		interface->addNumEntry("Q factor", &fentry11, 5e+01f, 0.1f, 1e+02f, 0.1f);
		interface->declare(&fentry10, "style", "knob");
		interface->declare(&fentry10, "unit", "Hz");
		interface->addNumEntry("freq", &fentry10, 5e+03f, 2e+01f, 2e+04f, 1.0f);
		interface->declare(&fslider5, "unit", "dB");
		interface->addVerticalSlider("gain", &fslider5, 0.0f, -5e+01f, 5e+01f, 0.1f);
		interface->closeBox();
		interface->openVerticalBox("peak 5");
		interface->declare(&fentry9, "style", "knob");
		interface->addNumEntry("Q factor", &fentry9, 5e+01f, 0.1f, 1e+02f, 0.1f);
		interface->declare(&fentry8, "style", "knob");
		interface->declare(&fentry8, "unit", "Hz");
		interface->addNumEntry("freq", &fentry8, 6e+03f, 2e+01f, 2e+04f, 1.0f);
		interface->declare(&fslider4, "unit", "dB");
		interface->addVerticalSlider("gain", &fslider4, 0.0f, -5e+01f, 5e+01f, 0.1f);
		interface->closeBox();
		interface->openVerticalBox("peak 6");
		interface->declare(&fentry7, "style", "knob");
		interface->addNumEntry("Q factor", &fentry7, 5e+01f, 0.1f, 1e+02f, 0.1f);
		interface->declare(&fentry6, "style", "knob");
		interface->declare(&fentry6, "unit", "Hz");
		interface->addNumEntry("freq", &fentry6, 7e+03f, 2e+01f, 2e+04f, 1.0f);
		interface->declare(&fslider3, "unit", "dB");
		interface->addVerticalSlider("gain", &fslider3, 0.0f, -5e+01f, 5e+01f, 0.1f);
		interface->closeBox();
		interface->openVerticalBox("peak 7");
		interface->declare(&fentry5, "style", "knob");
		interface->addNumEntry("Q factor", &fentry5, 5e+01f, 0.1f, 1e+02f, 0.1f);
		interface->declare(&fentry4, "style", "knob");
		interface->declare(&fentry4, "unit", "Hz");
		interface->addNumEntry("freq", &fentry4, 8e+03f, 2e+01f, 2e+04f, 1.0f);
		interface->declare(&fslider2, "unit", "dB");
		interface->addVerticalSlider("gain", &fslider2, 0.0f, -5e+01f, 5e+01f, 0.1f);
		interface->closeBox();
		interface->openVerticalBox("peak 8");
		interface->declare(&fentry3, "style", "knob");
		interface->addNumEntry("Q factor", &fentry3, 5e+01f, 0.1f, 1e+02f, 0.1f);
		interface->declare(&fentry2, "style", "knob");
		interface->declare(&fentry2, "unit", "Hz");
		interface->addNumEntry("freq", &fentry2, 9e+03f, 2e+01f, 2e+04f, 1.0f);
		interface->declare(&fslider1, "unit", "dB");
		interface->addVerticalSlider("gain", &fslider1, 0.0f, -5e+01f, 5e+01f, 0.1f);
		interface->closeBox();
		interface->openVerticalBox("peak 9");
		interface->declare(&fentry1, "style", "knob");
		interface->addNumEntry("Q factor", &fentry1, 5e+01f, 0.1f, 1e+02f, 0.1f);
		interface->declare(&fentry0, "style", "knob");
		interface->declare(&fentry0, "unit", "Hz");
		interface->addNumEntry("freq", &fentry0, 1e+04f, 2e+01f, 2e+04f, 1.0f);
		interface->declare(&fslider0, "unit", "dB");
		interface->addVerticalSlider("gain", &fslider0, 0.0f, -5e+01f, 5e+01f, 0.1f);
		interface->closeBox();
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = tanf((fConst0 * float(fentry0)));
		float 	fSlow1 = (2 * (faustpower<2>(fSlow0) - 1));
		float 	fSlow2 = float(fentry1);
		float 	fSlow3 = (powf(10,(0.05f * (0 - float(fslider0)))) / fSlow2);
		float 	fSlow4 = (1 + (fSlow0 * (fSlow0 - fSlow3)));
		float 	fSlow5 = (1.0f / (1 + (fSlow0 * (fSlow0 + fSlow3))));
		float 	fSlow6 = tanf((fConst0 * float(fentry2)));
		float 	fSlow7 = (2 * (faustpower<2>(fSlow6) - 1));
		float 	fSlow8 = float(fentry3);
		float 	fSlow9 = (powf(10,(0.05f * (0 - float(fslider1)))) / fSlow8);
		float 	fSlow10 = (1 + (fSlow6 * (fSlow6 - fSlow9)));
		float 	fSlow11 = (1.0f / (1 + (fSlow6 * (fSlow6 + fSlow9))));
		float 	fSlow12 = tanf((fConst0 * float(fentry4)));
		float 	fSlow13 = (2 * (faustpower<2>(fSlow12) - 1));
		float 	fSlow14 = float(fentry5);
		float 	fSlow15 = (powf(10,(0.05f * (0 - float(fslider2)))) / fSlow14);
		float 	fSlow16 = (1 + (fSlow12 * (fSlow12 - fSlow15)));
		float 	fSlow17 = (1.0f / (1 + (fSlow12 * (fSlow12 + fSlow15))));
		float 	fSlow18 = tanf((fConst0 * float(fentry6)));
		float 	fSlow19 = (2 * (faustpower<2>(fSlow18) - 1));
		float 	fSlow20 = float(fentry7);
		float 	fSlow21 = (powf(10,(0.05f * (0 - float(fslider3)))) / fSlow20);
		float 	fSlow22 = (1 + (fSlow18 * (fSlow18 - fSlow21)));
		float 	fSlow23 = (1.0f / (1 + (fSlow18 * (fSlow18 + fSlow21))));
		float 	fSlow24 = tanf((fConst0 * float(fentry8)));
		float 	fSlow25 = (2 * (faustpower<2>(fSlow24) - 1));
		float 	fSlow26 = float(fentry9);
		float 	fSlow27 = (powf(10,(0.05f * (0 - float(fslider4)))) / fSlow26);
		float 	fSlow28 = (1 + (fSlow24 * (fSlow24 - fSlow27)));
		float 	fSlow29 = (1.0f / (1 + (fSlow24 * (fSlow24 + fSlow27))));
		float 	fSlow30 = tanf((fConst0 * float(fentry10)));
		float 	fSlow31 = (2 * (faustpower<2>(fSlow30) - 1));
		float 	fSlow32 = float(fentry11);
		float 	fSlow33 = (powf(10,(0.05f * (0 - float(fslider5)))) / fSlow32);
		float 	fSlow34 = (1 + (fSlow30 * (fSlow30 - fSlow33)));
		float 	fSlow35 = (1.0f / (1 + (fSlow30 * (fSlow30 + fSlow33))));
		float 	fSlow36 = tanf((fConst0 * float(fentry12)));
		float 	fSlow37 = (2 * (faustpower<2>(fSlow36) - 1));
		float 	fSlow38 = float(fentry13);
		float 	fSlow39 = (powf(10,(0.05f * (0 - float(fslider6)))) / fSlow38);
		float 	fSlow40 = (1 + (fSlow36 * (fSlow36 - fSlow39)));
		float 	fSlow41 = (1.0f / (1 + (fSlow36 * (fSlow36 + fSlow39))));
		float 	fSlow42 = tanf((fConst0 * float(fentry14)));
		float 	fSlow43 = (2 * (faustpower<2>(fSlow42) - 1));
		float 	fSlow44 = float(fentry15);
		float 	fSlow45 = (powf(10,(0.05f * (0 - float(fslider7)))) / fSlow44);
		float 	fSlow46 = (1 + (fSlow42 * (fSlow42 - fSlow45)));
		float 	fSlow47 = (1.0f / (1 + (fSlow42 * (fSlow42 + fSlow45))));
		float 	fSlow48 = tanf((fConst0 * float(fentry16)));
		float 	fSlow49 = (2 * (faustpower<2>(fSlow48) - 1));
		float 	fSlow50 = float(fentry17);
		float 	fSlow51 = (powf(10,(0.05f * (0 - float(fslider8)))) / fSlow50);
		float 	fSlow52 = (1 + (fSlow48 * (fSlow48 - fSlow51)));
		float 	fSlow53 = (1.0f / (1 + (fSlow48 * (fSlow48 + fSlow51))));
		float 	fSlow54 = tanf((fConst0 * float(fentry18)));
		float 	fSlow55 = (2 * (faustpower<2>(fSlow54) - 1));
		float 	fSlow56 = float(fentry19);
		float 	fSlow57 = (powf(10,(0.05f * (0 - float(fslider9)))) / fSlow56);
		float 	fSlow58 = (1 + (fSlow54 * (fSlow54 - fSlow57)));
		float 	fSlow59 = (1.0f / (1 + (fSlow54 * (fSlow54 + fSlow57))));
		float 	fSlow60 = (1.0f / fSlow56);
		float 	fSlow61 = (1 + (fSlow54 * (fSlow54 - fSlow60)));
		float 	fSlow62 = (1 + (fSlow54 * (fSlow54 + fSlow60)));
		float 	fSlow63 = (1.0f / fSlow50);
		float 	fSlow64 = (1 + (fSlow48 * (fSlow48 - fSlow63)));
		float 	fSlow65 = (1 + (fSlow48 * (fSlow48 + fSlow63)));
		float 	fSlow66 = (1.0f / fSlow44);
		float 	fSlow67 = (1 + (fSlow42 * (fSlow42 - fSlow66)));
		float 	fSlow68 = (1 + (fSlow42 * (fSlow42 + fSlow66)));
		float 	fSlow69 = (1.0f / fSlow38);
		float 	fSlow70 = (1 + (fSlow36 * (fSlow36 - fSlow69)));
		float 	fSlow71 = (1 + (fSlow36 * (fSlow36 + fSlow69)));
		float 	fSlow72 = (1.0f / fSlow32);
		float 	fSlow73 = (1 + (fSlow30 * (fSlow30 - fSlow72)));
		float 	fSlow74 = (1 + (fSlow30 * (fSlow30 + fSlow72)));
		float 	fSlow75 = (1.0f / fSlow26);
		float 	fSlow76 = (1 + (fSlow24 * (fSlow24 - fSlow75)));
		float 	fSlow77 = (1 + (fSlow24 * (fSlow24 + fSlow75)));
		float 	fSlow78 = (1.0f / fSlow20);
		float 	fSlow79 = (1 + (fSlow18 * (fSlow18 - fSlow78)));
		float 	fSlow80 = (1 + (fSlow18 * (fSlow18 + fSlow78)));
		float 	fSlow81 = (1.0f / fSlow14);
		float 	fSlow82 = (1 + (fSlow12 * (fSlow12 - fSlow81)));
		float 	fSlow83 = (1 + (fSlow12 * (fSlow12 + fSlow81)));
		float 	fSlow84 = (1.0f / fSlow8);
		float 	fSlow85 = (1 + (fSlow6 * (fSlow6 - fSlow84)));
		float 	fSlow86 = (1 + (fSlow6 * (fSlow6 + fSlow84)));
		float 	fSlow87 = (1.0f / fSlow2);
		float 	fSlow88 = (1 + (fSlow0 * (fSlow0 - fSlow87)));
		float 	fSlow89 = (1 + (fSlow0 * (fSlow0 + fSlow87)));
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* output0 = output[0];
		for (int i=0; i<count; i++) {
			float fTemp0 = (fSlow1 * fRec0[1]);
			float fTemp1 = (fSlow7 * fRec1[1]);
			float fTemp2 = (fSlow13 * fRec2[1]);
			float fTemp3 = (fSlow19 * fRec3[1]);
			float fTemp4 = (fSlow25 * fRec4[1]);
			float fTemp5 = (fSlow31 * fRec5[1]);
			float fTemp6 = (fSlow37 * fRec6[1]);
			float fTemp7 = (fSlow43 * fRec7[1]);
			float fTemp8 = (fSlow49 * fRec8[1]);
			float fTemp9 = (fSlow55 * fRec9[1]);
			fRec9[0] = ((float)input0[i] - (fSlow59 * ((fSlow58 * fRec9[2]) + fTemp9)));
			fRec8[0] = ((fSlow59 * ((fTemp9 + (fSlow62 * fRec9[0])) + (fSlow61 * fRec9[2]))) - (fSlow53 * ((fSlow52 * fRec8[2]) + fTemp8)));
			fRec7[0] = ((fSlow53 * ((fTemp8 + (fSlow65 * fRec8[0])) + (fSlow64 * fRec8[2]))) - (fSlow47 * ((fSlow46 * fRec7[2]) + fTemp7)));
			fRec6[0] = ((fSlow47 * ((fTemp7 + (fSlow68 * fRec7[0])) + (fSlow67 * fRec7[2]))) - (fSlow41 * ((fSlow40 * fRec6[2]) + fTemp6)));
			fRec5[0] = ((fSlow41 * ((fTemp6 + (fSlow71 * fRec6[0])) + (fSlow70 * fRec6[2]))) - (fSlow35 * ((fSlow34 * fRec5[2]) + fTemp5)));
			fRec4[0] = ((fSlow35 * ((fTemp5 + (fSlow74 * fRec5[0])) + (fSlow73 * fRec5[2]))) - (fSlow29 * ((fSlow28 * fRec4[2]) + fTemp4)));
			fRec3[0] = ((fSlow29 * ((fTemp4 + (fSlow77 * fRec4[0])) + (fSlow76 * fRec4[2]))) - (fSlow23 * ((fSlow22 * fRec3[2]) + fTemp3)));
			fRec2[0] = ((fSlow23 * ((fTemp3 + (fSlow80 * fRec3[0])) + (fSlow79 * fRec3[2]))) - (fSlow17 * ((fSlow16 * fRec2[2]) + fTemp2)));
			fRec1[0] = ((fSlow17 * ((fTemp2 + (fSlow83 * fRec2[0])) + (fSlow82 * fRec2[2]))) - (fSlow11 * ((fSlow10 * fRec1[2]) + fTemp1)));
			fRec0[0] = ((fSlow11 * ((fTemp1 + (fSlow86 * fRec1[0])) + (fSlow85 * fRec1[2]))) - (fSlow5 * ((fSlow4 * fRec0[2]) + fTemp0)));
			output0[i] = (FAUSTFLOAT)(fSlow5 * ((fTemp0 + (fSlow89 * fRec0[0])) + (fSlow88 * fRec0[2])));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
			fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1]; fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1]; fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1]; fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1]; fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1]; fRec9[1] = fRec9[0];
		}
	}
};


