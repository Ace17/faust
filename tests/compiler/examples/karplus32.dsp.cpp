//-----------------------------------------------------
// name: "karplus32"
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

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

class mydsp : public dsp {
  private:
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT 	fbutton0;
	float 	fVec0[2];
	float 	fRec1[2];
	int 	iRec2[2];
	FAUSTFLOAT 	fslider2;
	int 	IOTA;
	float 	fVec1[4096];
	FAUSTFLOAT 	fslider3;
	FAUSTFLOAT 	fslider4;
	float 	fRec0[3];
	FAUSTFLOAT 	fslider5;
	float 	fVec2[4096];
	float 	fRec3[3];
	float 	fVec3[4096];
	float 	fRec4[3];
	float 	fVec4[4096];
	float 	fRec5[3];
	float 	fVec5[4096];
	float 	fRec6[3];
	float 	fVec6[4096];
	float 	fRec7[3];
	float 	fVec7[4096];
	float 	fRec8[3];
	float 	fVec8[4096];
	float 	fRec9[3];
	float 	fVec9[4096];
	float 	fRec10[3];
	float 	fVec10[4096];
	float 	fRec11[3];
	float 	fVec11[4096];
	float 	fRec12[3];
	float 	fVec12[4096];
	float 	fRec13[3];
	float 	fVec13[4096];
	float 	fRec14[3];
	float 	fVec14[4096];
	float 	fRec15[3];
	float 	fVec15[2048];
	float 	fRec16[3];
	float 	fVec16[512];
	float 	fRec17[3];
	FAUSTFLOAT 	fslider6;
	float 	fVec17[4096];
	float 	fRec18[3];
	float 	fVec18[4096];
	float 	fRec19[3];
	float 	fVec19[4096];
	float 	fRec20[3];
	float 	fVec20[4096];
	float 	fRec21[3];
	float 	fVec21[4096];
	float 	fRec22[3];
	float 	fVec22[4096];
	float 	fRec23[3];
	float 	fVec23[4096];
	float 	fRec24[3];
	float 	fVec24[4096];
	float 	fRec25[3];
	float 	fVec25[4096];
	float 	fRec26[3];
	float 	fVec26[4096];
	float 	fRec27[3];
	float 	fVec27[4096];
	float 	fRec28[3];
	float 	fVec28[4096];
	float 	fRec29[3];
	float 	fVec29[4096];
	float 	fRec30[3];
	float 	fVec30[4096];
	float 	fRec31[3];
	float 	fVec31[2048];
	float 	fRec32[3];
	float 	fVec32[1024];
	float 	fRec33[3];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "karplus32");
		m->declare("version", "1.0");
		m->declare("author", "Grame");
		m->declare("license", "BSD");
		m->declare("copyright", "(c)GRAME 2006");
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
	}

	virtual int getNumInputs() 	{ return 0; }
	virtual int getNumOutputs() 	{ return 2; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fslider0 = 0.1f;
		fslider1 = 128.0f;
		fbutton0 = 0.0;
		for (int i=0; i<2; i++) fVec0[i] = 0;
		for (int i=0; i<2; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) iRec2[i] = 0;
		fslider2 = 0.5f;
		IOTA = 0;
		for (int i=0; i<4096; i++) fVec1[i] = 0;
		fslider3 = 32.0f;
		fslider4 = 128.0f;
		for (int i=0; i<3; i++) fRec0[i] = 0;
		fslider5 = 1.0f;
		for (int i=0; i<4096; i++) fVec2[i] = 0;
		for (int i=0; i<3; i++) fRec3[i] = 0;
		for (int i=0; i<4096; i++) fVec3[i] = 0;
		for (int i=0; i<3; i++) fRec4[i] = 0;
		for (int i=0; i<4096; i++) fVec4[i] = 0;
		for (int i=0; i<3; i++) fRec5[i] = 0;
		for (int i=0; i<4096; i++) fVec5[i] = 0;
		for (int i=0; i<3; i++) fRec6[i] = 0;
		for (int i=0; i<4096; i++) fVec6[i] = 0;
		for (int i=0; i<3; i++) fRec7[i] = 0;
		for (int i=0; i<4096; i++) fVec7[i] = 0;
		for (int i=0; i<3; i++) fRec8[i] = 0;
		for (int i=0; i<4096; i++) fVec8[i] = 0;
		for (int i=0; i<3; i++) fRec9[i] = 0;
		for (int i=0; i<4096; i++) fVec9[i] = 0;
		for (int i=0; i<3; i++) fRec10[i] = 0;
		for (int i=0; i<4096; i++) fVec10[i] = 0;
		for (int i=0; i<3; i++) fRec11[i] = 0;
		for (int i=0; i<4096; i++) fVec11[i] = 0;
		for (int i=0; i<3; i++) fRec12[i] = 0;
		for (int i=0; i<4096; i++) fVec12[i] = 0;
		for (int i=0; i<3; i++) fRec13[i] = 0;
		for (int i=0; i<4096; i++) fVec13[i] = 0;
		for (int i=0; i<3; i++) fRec14[i] = 0;
		for (int i=0; i<4096; i++) fVec14[i] = 0;
		for (int i=0; i<3; i++) fRec15[i] = 0;
		for (int i=0; i<2048; i++) fVec15[i] = 0;
		for (int i=0; i<3; i++) fRec16[i] = 0;
		for (int i=0; i<512; i++) fVec16[i] = 0;
		for (int i=0; i<3; i++) fRec17[i] = 0;
		fslider6 = 0.5f;
		for (int i=0; i<4096; i++) fVec17[i] = 0;
		for (int i=0; i<3; i++) fRec18[i] = 0;
		for (int i=0; i<4096; i++) fVec18[i] = 0;
		for (int i=0; i<3; i++) fRec19[i] = 0;
		for (int i=0; i<4096; i++) fVec19[i] = 0;
		for (int i=0; i<3; i++) fRec20[i] = 0;
		for (int i=0; i<4096; i++) fVec20[i] = 0;
		for (int i=0; i<3; i++) fRec21[i] = 0;
		for (int i=0; i<4096; i++) fVec21[i] = 0;
		for (int i=0; i<3; i++) fRec22[i] = 0;
		for (int i=0; i<4096; i++) fVec22[i] = 0;
		for (int i=0; i<3; i++) fRec23[i] = 0;
		for (int i=0; i<4096; i++) fVec23[i] = 0;
		for (int i=0; i<3; i++) fRec24[i] = 0;
		for (int i=0; i<4096; i++) fVec24[i] = 0;
		for (int i=0; i<3; i++) fRec25[i] = 0;
		for (int i=0; i<4096; i++) fVec25[i] = 0;
		for (int i=0; i<3; i++) fRec26[i] = 0;
		for (int i=0; i<4096; i++) fVec26[i] = 0;
		for (int i=0; i<3; i++) fRec27[i] = 0;
		for (int i=0; i<4096; i++) fVec27[i] = 0;
		for (int i=0; i<3; i++) fRec28[i] = 0;
		for (int i=0; i<4096; i++) fVec28[i] = 0;
		for (int i=0; i<3; i++) fRec29[i] = 0;
		for (int i=0; i<4096; i++) fVec29[i] = 0;
		for (int i=0; i<3; i++) fRec30[i] = 0;
		for (int i=0; i<4096; i++) fVec30[i] = 0;
		for (int i=0; i<3; i++) fRec31[i] = 0;
		for (int i=0; i<2048; i++) fVec31[i] = 0;
		for (int i=0; i<3; i++) fRec32[i] = 0;
		for (int i=0; i<1024; i++) fVec32[i] = 0;
		for (int i=0; i<3; i++) fRec33[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("karplus32");
		interface->openVerticalBox("excitator");
		interface->addHorizontalSlider("excitation (samples)", &fslider1, 128.0f, 2.0f, 512.0f, 1.0f);
		interface->addButton("play", &fbutton0);
		interface->closeBox();
		interface->openVerticalBox("noise generator");
		interface->addHorizontalSlider("level", &fslider2, 0.5f, 0.0f, 1.0f, 0.1f);
		interface->closeBox();
		interface->addHorizontalSlider("output volume", &fslider6, 0.5f, 0.0f, 1.0f, 0.1f);
		interface->openVerticalBox("resonator x32");
		interface->addHorizontalSlider("attenuation", &fslider0, 0.1f, 0.0f, 1.0f, 0.01f);
		interface->addHorizontalSlider("detune", &fslider3, 32.0f, 0.0f, 512.0f, 1.0f);
		interface->addHorizontalSlider("duration (samples)", &fslider4, 128.0f, 2.0f, 512.0f, 1.0f);
		interface->addHorizontalSlider("polyphony", &fslider5, 1.0f, 0.0f, 32.0f, 1.0f);
		interface->closeBox();
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (0.5f * (1.0f - float(fslider0)));
		float 	fSlow1 = (1.0f / float(fslider1));
		float 	fSlow2 = float(fbutton0);
		float 	fSlow3 = (4.656612875245797e-10f * float(fslider2));
		float 	fSlow4 = float(fslider3);
		float 	fSlow5 = float(fslider4);
		int 	iSlow6 = int((int(((fSlow5 + (30 * fSlow4)) - 1.5f)) & 4095));
		float 	fSlow7 = float(fslider5);
		int 	iSlow8 = (fSlow7 > 30);
		int 	iSlow9 = int((int(((fSlow5 + (28 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow10 = (fSlow7 > 28);
		int 	iSlow11 = int((int(((fSlow5 + (26 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow12 = (fSlow7 > 26);
		int 	iSlow13 = int((int(((fSlow5 + (24 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow14 = (fSlow7 > 24);
		int 	iSlow15 = int((int(((fSlow5 + (22 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow16 = (fSlow7 > 22);
		int 	iSlow17 = int((int(((fSlow5 + (20 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow18 = (fSlow7 > 20);
		int 	iSlow19 = int((int(((fSlow5 + (18 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow20 = (fSlow7 > 18);
		int 	iSlow21 = int((int(((fSlow5 + (16 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow22 = (fSlow7 > 16);
		int 	iSlow23 = int((int(((fSlow5 + (14 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow24 = (fSlow7 > 14);
		int 	iSlow25 = int((int(((fSlow5 + (12 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow26 = (fSlow7 > 12);
		int 	iSlow27 = int((int(((fSlow5 + (10 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow28 = (fSlow7 > 10);
		int 	iSlow29 = int((int(((fSlow5 + (8 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow30 = (fSlow7 > 8);
		int 	iSlow31 = int((int(((fSlow5 + (6 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow32 = (fSlow7 > 6);
		int 	iSlow33 = int((int(((fSlow5 + (4 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow34 = (fSlow7 > 4);
		int 	iSlow35 = int((int(((fSlow5 + (2 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow36 = (fSlow7 > 2);
		int 	iSlow37 = int((int((fSlow5 - 1.5f)) & 4095));
		int 	iSlow38 = (fSlow7 > 0);
		float 	fSlow39 = float(fslider6);
		int 	iSlow40 = int((int((((31 * fSlow4) + fSlow5) - 1.5f)) & 4095));
		int 	iSlow41 = (fSlow7 > 31);
		int 	iSlow42 = int((int(((fSlow5 + (29 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow43 = (fSlow7 > 29);
		int 	iSlow44 = int((int(((fSlow5 + (27 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow45 = (fSlow7 > 27);
		int 	iSlow46 = int((int(((fSlow5 + (25 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow47 = (fSlow7 > 25);
		int 	iSlow48 = int((int(((fSlow5 + (23 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow49 = (fSlow7 > 23);
		int 	iSlow50 = int((int(((fSlow5 + (21 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow51 = (fSlow7 > 21);
		int 	iSlow52 = int((int(((fSlow5 + (19 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow53 = (fSlow7 > 19);
		int 	iSlow54 = int((int(((fSlow5 + (17 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow55 = (fSlow7 > 17);
		int 	iSlow56 = int((int(((fSlow5 + (15 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow57 = (fSlow7 > 15);
		int 	iSlow58 = int((int(((fSlow5 + (13 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow59 = (fSlow7 > 13);
		int 	iSlow60 = int((int(((fSlow5 + (11 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow61 = (fSlow7 > 11);
		int 	iSlow62 = int((int(((fSlow5 + (9 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow63 = (fSlow7 > 9);
		int 	iSlow64 = int((int(((fSlow5 + (7 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow65 = (fSlow7 > 7);
		int 	iSlow66 = int((int(((fSlow5 + (5 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow67 = (fSlow7 > 5);
		int 	iSlow68 = int((int(((fSlow5 + (3 * fSlow4)) - 1.5f)) & 4095));
		int 	iSlow69 = (fSlow7 > 3);
		int 	iSlow70 = int((int(((fSlow4 + fSlow5) - 1.5f)) & 4095));
		int 	iSlow71 = (fSlow7 > 1);
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			fVec0[0] = fSlow2;
			fRec1[0] = ((fRec1[1] + ((fSlow2 - fVec0[1]) > 0.0f)) - (fSlow1 * (fRec1[1] > 0)));
			iRec2[0] = (12345 + (1103515245 * iRec2[1]));
			float fTemp0 = (fSlow3 * (iRec2[0] * ((fRec1[0] > 0.0f) + 1.52587890625e-05f)));
			fVec1[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec0[1] + fRec0[2])));
			fRec0[0] = fVec1[(IOTA-iSlow6)&4095];
			fVec2[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec3[1] + fRec3[2])));
			fRec3[0] = fVec2[(IOTA-iSlow9)&4095];
			fVec3[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec4[1] + fRec4[2])));
			fRec4[0] = fVec3[(IOTA-iSlow11)&4095];
			fVec4[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec5[1] + fRec5[2])));
			fRec5[0] = fVec4[(IOTA-iSlow13)&4095];
			fVec5[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec6[1] + fRec6[2])));
			fRec6[0] = fVec5[(IOTA-iSlow15)&4095];
			fVec6[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec7[1] + fRec7[2])));
			fRec7[0] = fVec6[(IOTA-iSlow17)&4095];
			fVec7[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec8[1] + fRec8[2])));
			fRec8[0] = fVec7[(IOTA-iSlow19)&4095];
			fVec8[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec9[1] + fRec9[2])));
			fRec9[0] = fVec8[(IOTA-iSlow21)&4095];
			fVec9[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec10[1] + fRec10[2])));
			fRec10[0] = fVec9[(IOTA-iSlow23)&4095];
			fVec10[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec11[1] + fRec11[2])));
			fRec11[0] = fVec10[(IOTA-iSlow25)&4095];
			fVec11[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec12[1] + fRec12[2])));
			fRec12[0] = fVec11[(IOTA-iSlow27)&4095];
			fVec12[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec13[1] + fRec13[2])));
			fRec13[0] = fVec12[(IOTA-iSlow29)&4095];
			fVec13[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec14[1] + fRec14[2])));
			fRec14[0] = fVec13[(IOTA-iSlow31)&4095];
			fVec14[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec15[1] + fRec15[2])));
			fRec15[0] = fVec14[(IOTA-iSlow33)&4095];
			fVec15[IOTA&2047] = (fTemp0 + (fSlow0 * (fRec16[1] + fRec16[2])));
			fRec16[0] = fVec15[(IOTA-iSlow35)&2047];
			fVec16[IOTA&511] = ((fSlow0 * (fRec17[1] + fRec17[2])) + fTemp0);
			fRec17[0] = fVec16[(IOTA-iSlow37)&511];
			output0[i] = (FAUSTFLOAT)(fSlow39 * ((((((((((((((((iSlow38 * fRec17[0]) + (iSlow36 * fRec16[0])) + (iSlow34 * fRec15[0])) + (iSlow32 * fRec14[0])) + (iSlow30 * fRec13[0])) + (iSlow28 * fRec12[0])) + (iSlow26 * fRec11[0])) + (iSlow24 * fRec10[0])) + (iSlow22 * fRec9[0])) + (iSlow20 * fRec8[0])) + (iSlow18 * fRec7[0])) + (iSlow16 * fRec6[0])) + (iSlow14 * fRec5[0])) + (iSlow12 * fRec4[0])) + (iSlow10 * fRec3[0])) + (iSlow8 * fRec0[0])));
			fVec17[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec18[1] + fRec18[2])));
			fRec18[0] = fVec17[(IOTA-iSlow40)&4095];
			fVec18[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec19[1] + fRec19[2])));
			fRec19[0] = fVec18[(IOTA-iSlow42)&4095];
			fVec19[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec20[1] + fRec20[2])));
			fRec20[0] = fVec19[(IOTA-iSlow44)&4095];
			fVec20[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec21[1] + fRec21[2])));
			fRec21[0] = fVec20[(IOTA-iSlow46)&4095];
			fVec21[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec22[1] + fRec22[2])));
			fRec22[0] = fVec21[(IOTA-iSlow48)&4095];
			fVec22[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec23[1] + fRec23[2])));
			fRec23[0] = fVec22[(IOTA-iSlow50)&4095];
			fVec23[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec24[1] + fRec24[2])));
			fRec24[0] = fVec23[(IOTA-iSlow52)&4095];
			fVec24[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec25[1] + fRec25[2])));
			fRec25[0] = fVec24[(IOTA-iSlow54)&4095];
			fVec25[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec26[1] + fRec26[2])));
			fRec26[0] = fVec25[(IOTA-iSlow56)&4095];
			fVec26[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec27[1] + fRec27[2])));
			fRec27[0] = fVec26[(IOTA-iSlow58)&4095];
			fVec27[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec28[1] + fRec28[2])));
			fRec28[0] = fVec27[(IOTA-iSlow60)&4095];
			fVec28[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec29[1] + fRec29[2])));
			fRec29[0] = fVec28[(IOTA-iSlow62)&4095];
			fVec29[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec30[1] + fRec30[2])));
			fRec30[0] = fVec29[(IOTA-iSlow64)&4095];
			fVec30[IOTA&4095] = (fTemp0 + (fSlow0 * (fRec31[1] + fRec31[2])));
			fRec31[0] = fVec30[(IOTA-iSlow66)&4095];
			fVec31[IOTA&2047] = (fTemp0 + (fSlow0 * (fRec32[1] + fRec32[2])));
			fRec32[0] = fVec31[(IOTA-iSlow68)&2047];
			fVec32[IOTA&1023] = (fTemp0 + (fSlow0 * (fRec33[1] + fRec33[2])));
			fRec33[0] = fVec32[(IOTA-iSlow70)&1023];
			output1[i] = (FAUSTFLOAT)(fSlow39 * ((((((((((((((((iSlow71 * fRec33[0]) + (iSlow69 * fRec32[0])) + (iSlow67 * fRec31[0])) + (iSlow65 * fRec30[0])) + (iSlow63 * fRec29[0])) + (iSlow61 * fRec28[0])) + (iSlow59 * fRec27[0])) + (iSlow57 * fRec26[0])) + (iSlow55 * fRec25[0])) + (iSlow53 * fRec24[0])) + (iSlow51 * fRec23[0])) + (iSlow49 * fRec22[0])) + (iSlow47 * fRec21[0])) + (iSlow45 * fRec20[0])) + (iSlow43 * fRec19[0])) + (iSlow41 * fRec18[0])));
			// post processing
			fRec33[2] = fRec33[1]; fRec33[1] = fRec33[0];
			fRec32[2] = fRec32[1]; fRec32[1] = fRec32[0];
			fRec31[2] = fRec31[1]; fRec31[1] = fRec31[0];
			fRec30[2] = fRec30[1]; fRec30[1] = fRec30[0];
			fRec29[2] = fRec29[1]; fRec29[1] = fRec29[0];
			fRec28[2] = fRec28[1]; fRec28[1] = fRec28[0];
			fRec27[2] = fRec27[1]; fRec27[1] = fRec27[0];
			fRec26[2] = fRec26[1]; fRec26[1] = fRec26[0];
			fRec25[2] = fRec25[1]; fRec25[1] = fRec25[0];
			fRec24[2] = fRec24[1]; fRec24[1] = fRec24[0];
			fRec23[2] = fRec23[1]; fRec23[1] = fRec23[0];
			fRec22[2] = fRec22[1]; fRec22[1] = fRec22[0];
			fRec21[2] = fRec21[1]; fRec21[1] = fRec21[0];
			fRec20[2] = fRec20[1]; fRec20[1] = fRec20[0];
			fRec19[2] = fRec19[1]; fRec19[1] = fRec19[0];
			fRec18[2] = fRec18[1]; fRec18[1] = fRec18[0];
			fRec17[2] = fRec17[1]; fRec17[1] = fRec17[0];
			fRec16[2] = fRec16[1]; fRec16[1] = fRec16[0];
			fRec15[2] = fRec15[1]; fRec15[1] = fRec15[0];
			fRec14[2] = fRec14[1]; fRec14[1] = fRec14[0];
			fRec13[2] = fRec13[1]; fRec13[1] = fRec13[0];
			fRec12[2] = fRec12[1]; fRec12[1] = fRec12[0];
			fRec11[2] = fRec11[1]; fRec11[1] = fRec11[0];
			fRec10[2] = fRec10[1]; fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1]; fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1]; fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1]; fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1]; fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1]; fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			IOTA = IOTA+1;
			iRec2[1] = iRec2[0];
			fRec1[1] = fRec1[0];
			fVec0[1] = fVec0[0];
		}
	}
};


