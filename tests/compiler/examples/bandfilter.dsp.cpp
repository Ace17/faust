//-----------------------------------------------------
// name: "bandfilter"
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
	float 	fRec0[3];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "bandfilter");
		m->declare("version", "1.0");
		m->declare("author", "Grame");
		m->declare("license", "BSD");
		m->declare("copyright", "(c)GRAME 2006");
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
		fentry0 = 1e+03f;
		fConst0 = (3.141592653589793f / float(min(192000, max(1, fSamplingFreq))));
		fentry1 = 5e+01f;
		fslider0 = 0.0f;
		for (int i=0; i<3; i++) fRec0[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("Bandfilter");
		interface->declare(&fentry1, "style", "knob");
		interface->addNumEntry("Q factor", &fentry1, 5e+01f, 0.1f, 1e+02f, 0.1f);
		interface->declare(&fentry0, "style", "knob");
		interface->declare(&fentry0, "unit", "Hz");
		interface->addNumEntry("freq", &fentry0, 1e+03f, 2e+01f, 2e+04f, 1.0f);
		interface->declare(&fslider0, "unit", "dB");
		interface->addVerticalSlider("gain", &fslider0, 0.0f, -5e+01f, 5e+01f, 0.1f);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = tanf((fConst0 * float(fentry0)));
		float 	fSlow1 = (2 * (faustpower<2>(fSlow0) - 1));
		float 	fSlow2 = float(fentry1);
		float 	fSlow3 = (powf(10,(0.05f * (0 - float(fslider0)))) / fSlow2);
		float 	fSlow4 = (1 + (fSlow0 * (fSlow0 - fSlow3)));
		float 	fSlow5 = (1.0f / (1 + (fSlow0 * (fSlow0 + fSlow3))));
		float 	fSlow6 = (1.0f / fSlow2);
		float 	fSlow7 = (1 + (fSlow0 * (fSlow0 - fSlow6)));
		float 	fSlow8 = (1 + (fSlow0 * (fSlow0 + fSlow6)));
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* output0 = output[0];
		for (int i=0; i<count; i++) {
			float fTemp0 = (fSlow1 * fRec0[1]);
			fRec0[0] = ((float)input0[i] - (fSlow5 * ((fSlow4 * fRec0[2]) + fTemp0)));
			output0[i] = (FAUSTFLOAT)(fSlow5 * ((fTemp0 + (fSlow8 * fRec0[0])) + (fSlow7 * fRec0[2])));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		}
	}
};


