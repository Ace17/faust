//-----------------------------------------------------
// name: "dbmeter"
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
	float 	fRec0[2];
	FAUSTFLOAT 	fbargraph0;
	int 	iConst1;
	float 	fRec1[2];
	FAUSTFLOAT 	fbargraph1;
	int 	iConst2;
	float 	fRec2[2];
	FAUSTFLOAT 	fbargraph2;
	int 	iConst3;
	float 	fRec3[2];
	FAUSTFLOAT 	fbargraph3;
	int 	iConst4;
	float 	fRec4[2];
	FAUSTFLOAT 	fbargraph4;
	int 	iConst5;
	float 	fRec5[2];
	FAUSTFLOAT 	fbargraph5;
	int 	iConst6;
	float 	fRec6[2];
	FAUSTFLOAT 	fbargraph6;
	int 	iConst7;
	float 	fRec7[2];
	FAUSTFLOAT 	fbargraph7;
	int 	iConst8;
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "dbmeter");
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

	virtual int getNumInputs() 	{ return 8; }
	virtual int getNumOutputs() 	{ return 8; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = (8e+01f / float(min(192000, max(1, fSamplingFreq))));
		for (int i=0; i<2; i++) fRec0[i] = 0;
		iConst1 = 0;
		for (int i=0; i<2; i++) fRec1[i] = 0;
		iConst2 = 0;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		iConst3 = 0;
		for (int i=0; i<2; i++) fRec3[i] = 0;
		iConst4 = 0;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		iConst5 = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		iConst6 = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		iConst7 = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		iConst8 = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openHorizontalBox("8 channels dB meter");
		interface->openVerticalBox("0");
		interface->declare(&fbargraph0, "unit", "dB");
		interface->addVerticalBargraph("0x35c37a0", &fbargraph0, -7e+01f, 1e+01f);
		interface->closeBox();
		interface->openVerticalBox("1");
		interface->declare(&fbargraph1, "unit", "dB");
		interface->addVerticalBargraph("0x35c54f0", &fbargraph1, -7e+01f, 1e+01f);
		interface->closeBox();
		interface->openVerticalBox("2");
		interface->declare(&fbargraph2, "unit", "dB");
		interface->addVerticalBargraph("0x35c7290", &fbargraph2, -7e+01f, 1e+01f);
		interface->closeBox();
		interface->openVerticalBox("3");
		interface->declare(&fbargraph3, "unit", "dB");
		interface->addVerticalBargraph("0x35c90d0", &fbargraph3, -7e+01f, 1e+01f);
		interface->closeBox();
		interface->openVerticalBox("4");
		interface->declare(&fbargraph4, "unit", "dB");
		interface->addVerticalBargraph("0x35cafb0", &fbargraph4, -7e+01f, 1e+01f);
		interface->closeBox();
		interface->openVerticalBox("5");
		interface->declare(&fbargraph5, "unit", "dB");
		interface->addVerticalBargraph("0x35cd100", &fbargraph5, -7e+01f, 1e+01f);
		interface->closeBox();
		interface->openVerticalBox("6");
		interface->declare(&fbargraph6, "unit", "dB");
		interface->addVerticalBargraph("0x35cf2a0", &fbargraph6, -7e+01f, 1e+01f);
		interface->closeBox();
		interface->openVerticalBox("7");
		interface->declare(&fbargraph7, "unit", "dB");
		interface->addVerticalBargraph("0x35d1330", &fbargraph7, -7e+01f, 1e+01f);
		interface->closeBox();
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
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
		FAUSTFLOAT* output2 = output[2];
		FAUSTFLOAT* output3 = output[3];
		FAUSTFLOAT* output4 = output[4];
		FAUSTFLOAT* output5 = output[5];
		FAUSTFLOAT* output6 = output[6];
		FAUSTFLOAT* output7 = output[7];
		for (int i=0; i<count; i++) {
			float fTemp0 = (float)input0[i];
			fRec0[0] = max((fRec0[1] - fConst0), min((float)10, (20 * log10f(max(0.00031622776601683794f, fabsf(fTemp0))))));
			fbargraph0 = fRec0[0];
			output0[i] = (FAUSTFLOAT)iConst1;
			float fTemp1 = (float)input1[i];
			fRec1[0] = max((fRec1[1] - fConst0), min((float)10, (20 * log10f(max(0.00031622776601683794f, fabsf(fTemp1))))));
			fbargraph1 = fRec1[0];
			output1[i] = (FAUSTFLOAT)iConst2;
			float fTemp2 = (float)input2[i];
			fRec2[0] = max((fRec2[1] - fConst0), min((float)10, (20 * log10f(max(0.00031622776601683794f, fabsf(fTemp2))))));
			fbargraph2 = fRec2[0];
			output2[i] = (FAUSTFLOAT)iConst3;
			float fTemp3 = (float)input3[i];
			fRec3[0] = max((fRec3[1] - fConst0), min((float)10, (20 * log10f(max(0.00031622776601683794f, fabsf(fTemp3))))));
			fbargraph3 = fRec3[0];
			output3[i] = (FAUSTFLOAT)iConst4;
			float fTemp4 = (float)input4[i];
			fRec4[0] = max((fRec4[1] - fConst0), min((float)10, (20 * log10f(max(0.00031622776601683794f, fabsf(fTemp4))))));
			fbargraph4 = fRec4[0];
			output4[i] = (FAUSTFLOAT)iConst5;
			float fTemp5 = (float)input5[i];
			fRec5[0] = max((fRec5[1] - fConst0), min((float)10, (20 * log10f(max(0.00031622776601683794f, fabsf(fTemp5))))));
			fbargraph5 = fRec5[0];
			output5[i] = (FAUSTFLOAT)iConst6;
			float fTemp6 = (float)input6[i];
			fRec6[0] = max((fRec6[1] - fConst0), min((float)10, (20 * log10f(max(0.00031622776601683794f, fabsf(fTemp6))))));
			fbargraph6 = fRec6[0];
			output6[i] = (FAUSTFLOAT)iConst7;
			float fTemp7 = (float)input7[i];
			fRec7[0] = max((fRec7[1] - fConst0), min((float)10, (20 * log10f(max(0.00031622776601683794f, fabsf(fTemp7))))));
			fbargraph7 = fRec7[0];
			output7[i] = (FAUSTFLOAT)iConst8;
			// post processing
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
		}
	}
};


